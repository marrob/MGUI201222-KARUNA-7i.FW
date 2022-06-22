#include <gui/saverscreen_screen/SaverScreenView.hpp>
#include <time.h>
#include <stdio.h>

int mTickSaverCount;
char FormatStr[10];
char BitDepth[10];
char Freq[12];
int contDir = -1;


#ifdef SIMULATOR

time_t simSaverDateTime;


void SaverScreenView::GuiItfGetRtc(time_t* dt)
{
	if (simSaverDateTime == 0)
	{
		tm tm_info;
		tm_info.tm_year = 2022 - 1900;
		tm_info.tm_mon = 6 - 1;
		tm_info.tm_mday = 16;
		tm_info.tm_hour = 20;
		tm_info.tm_min = 21;
		tm_info.tm_sec = 22;
		tm_info.tm_isdst = 0;

		simSaverDateTime = mktime(&tm_info);
	}
	simSaverDateTime++;
	*dt = simSaverDateTime;
}
/*** Karuna ****/
uint8_t SaverScreenView::GuiItfGetKarunaStatus()
{
	return 0b00011011;
}

#else
extern "C"
{
	/*** RTC ***/
	void GuiItfGetRtc(time_t* dt);
	/*** Karuna ****/
	uint8_t GuiItfGetKarunaStatus();
}
#endif


SaverScreenView::SaverScreenView()
{

}

void SaverScreenView::setupScreen()
{
	SaverScreenViewBase::setupScreen();

	RequestCurrentTime();
	RefreshCurrentAudio();
}

void SaverScreenView::tearDownScreen()
{
	SaverScreenViewBase::tearDownScreen();
}

void SaverScreenView::handleTickEvent()
{
	mTickSaverCount++;

	//Wait for 0.5sec
	if (mTickSaverCount % 10 == 0)
	{
		RequestCurrentTime();
		RefreshCurrentAudio();

	}

	if (mTickSaverCount % (60) == 0)
	{ 
		if (containerInfo.getY() < 0)
		{
			contDir = 1;
		}
		else if(containerInfo.getY() + containerInfo.getHeight() > this->getScreenHeight())
		{
			contDir = -1;
		}
		containerInfo.moveRelative(0, contDir*1); 
	}
}

bool SaverScreenView::ToBinary(int number, int position)
{
	bool ret = ((1 << position) & number) != 0;
	return ret;
}


void SaverScreenView::RequestCurrentTime()
{
	time_t dtp;
	GuiItfGetRtc(&dtp);
	struct tm* tm_info = gmtime(&dtp);
	char strDateTime[25];
	strftime(strDateTime, 25, "%d.%m.%Y %H:%M:%S", tm_info);

	Unicode::UnicodeChar uni_DateTime[25];
	Unicode::fromUTF8((const uint8_t*)strDateTime, uni_DateTime, sizeof(uni_DateTime));
	Unicode::snprintf(lblDateTimeBuffer, sizeof(lblDateTimeBuffer), "%s", uni_DateTime);
	lblDateTime.invalidate();
}

void SaverScreenView::RefreshCurrentAudio()
{
	uint8_t  KRN_STAT = GuiItfGetKarunaStatus();

	char audioFormat[35];
	snprintf(audioFormat, 35, "%s - %s - %s", SetDSDPCM(KRN_STAT), SetBitDepth(KRN_STAT), SetFreq(KRN_STAT));

	Unicode::UnicodeChar uniText[35];
	Unicode::fromUTF8((const uint8_t*)audioFormat, uniText, sizeof(uniText));
	Unicode::snprintf(lblAudioFormatBuffer, sizeof(lblAudioFormatBuffer), "%s", uniText);
}
 
char* SaverScreenView::SetDSDPCM(uint8_t p_AudiFormat)
{ 
	char Format[5];
	char Freq[5];

	bool isDsd = ToBinary(p_AudiFormat, 4);

	if (isDsd)
	{
		bool isDoP = !ToBinary(p_AudiFormat, 3);
		if (isDoP)
		{
			strcpy(Format, "DoP");
		}
		else
		{
			strcpy(Format, "DSD");
		}

		int dsdFormat = p_AudiFormat >> 1;
		dsdFormat = dsdFormat & 0b00000011;

		switch (dsdFormat)
		{
		case 0b10:
		{
			strcpy(Freq, "64");
		}break;
		case 0b11:
		{
			strcpy(Freq, "128");
		}break;
		case 0b01:
		{
			strcpy(Freq, "256");
		}break;
		case 0b00:
		{
			strcpy(Freq, "512");
		}break;

		default:
			break;
		}
	}
	else
	{
		strcpy(Format, "PCM");
	}


	snprintf(FormatStr, 10, "%s%s", Format, Freq);

	return FormatStr;
}

char* SaverScreenView::SetBitDepth(uint8_t p_AudiFormat)
{

	int BitDepthVal = p_AudiFormat >> 5;
	BitDepthVal = BitDepthVal & 0b00000011; 

	switch (BitDepthVal)
	{
	case 0b00:
	{
		strcpy(BitDepth, "1 bit");
	}break;
	case 0b01:
	{
		strcpy(BitDepth, "16 bit");
	}break;
	case 0b10:
	{
		strcpy(BitDepth, "24 bit");
	}break;
	case 0b11:
	{
		strcpy(BitDepth, "32 bit");
	}break;

	default:
		break;
	}

	return BitDepth;
}

char* SaverScreenView::SetFreq(uint8_t p_AudiFormat)
{
	bool isDsd = ToBinary(p_AudiFormat, 4);

	strcpy(Freq, "N.A.");

	if (!isDsd)
	{
		//PCM FREQ.

		int freqVal = p_AudiFormat & 0b00001111;

		switch (freqVal)
		{
		case 0b0000:
		{
			strcpy(Freq, "44.1 kHz");
		}break;
		case 0b0001:
		{
			strcpy(Freq, "48 kHz");
		}break;
		case 0b0010:
		{
			strcpy(Freq, "88.2 kHz");
		}break;
		case 0b0011:
		{
			strcpy(Freq, "96 kHz");
		}break;
		case 0b0100:
		{
			strcpy(Freq, "176.4 kHz");
		}break;
		case 0b0101:
		{
			strcpy(Freq, "192 kHz");
		}break;
		case 0b0110:
		{
			strcpy(Freq, "352.8 kHz");
		}break;
		case 0b0111:
		{
			strcpy(Freq, "384 kHz");
		}break;
		case 0b1000:
		{
			strcpy(Freq, "705.6 kHz");
		}break;
		case 0b1001:
		{
			strcpy(Freq, "768 kHz");
		}break;


		default:
			break;
		}
	}
	else
	{
		//DSD FREQ.

		int freqVal = p_AudiFormat >> 1;
		freqVal = freqVal & 0b00000011;

		switch (freqVal)
		{
		case 0b10:
		{
			strcpy(Freq, "2.8 MHz");
		}break;
		case 0b11:
		{
			strcpy(Freq, "5.8 MHz");
		}break;
		case 0b01:
		{
			strcpy(Freq, "11.2 MHz");
		}break;
		case 0b00:
		{
			strcpy(Freq, "22.6 MHz");
		}break;

		default:
			break;
		}
	}

	return Freq;
}