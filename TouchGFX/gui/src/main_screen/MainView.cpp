#include <gui/main_screen/MainView.hpp>
#include <touchgfx/Color.hpp>
#include <touchgfx/containers/buttons/ImageButtonStyle.hpp>
#include "BitmapDatabase.hpp"
#include <time.h> 

time_t saverDateTime;

#ifdef SIMULATOR

//Sumlated Time
time_t simMainDateTime;

//Simulated flash memory
static uint8_t  SimIsHdmiON;
static uint8_t  SimIsRcaON;
static uint8_t  SimIsXlrON;
static uint8_t  SimIsBncON;

/*** Karuna ***/
uint8_t MainView::GuiItfGetKarunaStatus()
{
	return 0b00000001;
}

void MainView::GuiItfSetKarunaHdmi(uint8_t onfoff)
{
	SimIsHdmiON = onfoff;
}

uint8_t MainView::GuitIfGetKarunaIsHdmiSet(void)
{
	return 1; //SimIsHdmiON;
}

void MainView::GuiItfSetKarunaRca(uint8_t onfoff)
{
	SimIsRcaON = onfoff;
}

uint8_t MainView::GuitIfGetKarunaIsRcaSet(void)
{
	return 0;// SimIsRcaON;
}

void MainView::GuiItfSetKarunaBnc(uint8_t onfoff)
{
	SimIsBncON = onfoff;
}

uint8_t MainView::GuitIfGetKarunaIsBncSet(void)
{
	return SimIsBncON;
}

void MainView::GuiItfSetKarunaXlr(uint8_t onfoff)
{
	SimIsXlrON = onfoff;
}

uint8_t MainView::GuitIfGetKarunaIsXlrSet(void)
{
	return SimIsXlrON;
}

uint8_t MainView::GuiItfGetKarunaMclkOutIsEanbled(void)
{
	return 1;
}

/*** Das Clock ***/

float MainView::GuiItfGetDasClockMV341Temp(void)
{
	return 52.8f;
}
uint8_t MainView::GuiItfGetDasClockStatusLock1(void)
{
	return true;
}
uint8_t MainView::GuiItfGetDasClockStatusLock2(void)
{
	return true;
}
uint8_t MainView::GuiItfGetDasClockIsExt(void)
{
	return false;
}

/*** Time ***/

void MainView::GuiItfGetRtc(time_t* dt)
{
	if (simMainDateTime == 0)
	{
		tm tm_info;
		tm_info.tm_year = 2022 - 1900;
		tm_info.tm_mon = 6 - 1;
		tm_info.tm_mday = 16;
		tm_info.tm_hour = 20;
		tm_info.tm_min = 21;
		tm_info.tm_sec = 22;
		tm_info.tm_isdst = 0;

		simMainDateTime = mktime(&tm_info);
	}
	simMainDateTime++;
	*dt = simMainDateTime;
}

/*** Display ***/
uint8_t MainView::GuiItfGetScreenSaverEnable()
{
	return false;
}


/*** Clock Temp ***/
uint32_t  MainView::GuiItfGetDasClockHeatedTemperature()
{
	return 55;
}

void MainView::GuiItfSetDasClockHeatedTemperature(uint32_t temp)
{

}

#else
extern "C"
{
	/*** Karuna ***/
	uint8_t GuiItfGetKarunaStatus();
	void GuiItfSetKarunaHdmi(uint8_t onfoff);
	uint8_t GuitIfGetKarunaIsHdmiSet(void);
	void GuiItfSetKarunaRca(uint8_t onfoff);
	uint8_t GuitIfGetKarunaIsRcaSet(void);
	void GuiItfSetKarunaBnc(uint8_t onfoff);
	uint8_t GuitIfGetKarunaIsBncSet(void);
	void GuiItfSetKarunaXlr(uint8_t onfoff);
	uint8_t GuitIfGetKarunaIsXlrSet(void);
	uint8_t GuiItfGetKarunaMclkOutIsEanbled(void);

	/*** DasClock***/
	float GuiItfGetDasClockMV341Temp();
	uint8_t GuiItfGetDasClockStatusLock1();
	uint8_t GuiItfGetDasClockStatusLock2();
	uint8_t GuiItfGetDasClockIsExt();

	/*** Time ***/
	void GuiItfGetRtc(time_t* dt);

	/*** Display ***/
	uint8_t GuiItfGetScreenSaverEnable();

	/*** Clock Temp ***/
	uint32_t GuiItfGetDasClockHeatedTemperature();
	void GuiItfSetDasClockHeatedTemperature(uint32_t temp);
}
#endif

//OUTPUTS
static bool  mIsHdmiON;
static bool  mIsRcaON;
static bool  mIsXlrON;
static bool  mIsBncON;

//CLOCKS
static bool mIs24Locked;
static bool mIs245Locked;
static bool mIs22Locked;
static bool mIsIntExt;

//Default colors
colortype GRAYCOLOR;
colortype MIDGRAYCOLOR;
colortype BLACKCOLOR;
colortype CORECOLOR;
colortype DARKGRAYCOLOR;
colortype REDCOLOR;

//Buttons
uint8_t mKarunaControl;

//Temperature
int mTemp;

//Audio
int mAudioFormat;

//Gui Refresh
int mTickCount;

MainView::MainView()
{
	GRAYCOLOR = touchgfx::Color::getColorFrom24BitRGB(128, 128, 128);
	CORECOLOR = touchgfx::Color::getColorFrom24BitRGB(150, 118, 73);
	BLACKCOLOR = touchgfx::Color::getColorFrom24BitRGB(0, 0, 0);
	DARKGRAYCOLOR = touchgfx::Color::getColorFrom24BitRGB(32, 32, 32);
	MIDGRAYCOLOR = touchgfx::Color::getColorFrom24BitRGB(64, 64, 64);
	REDCOLOR = touchgfx::Color::getColorFrom24BitRGB(0x8B, 0, 0);

	//Audio and Clocks temperature
	RefreshKarunaAndClockInfo();
	GuiItfGetRtc(&saverDateTime);
	RequestCurrentTime();
}


//Toogle outputs

void MainView::ToggleHDMI()
{
	mIsHdmiON = !mIsHdmiON;
	GuiItfSetKarunaHdmi(mIsHdmiON);
}

void MainView::ToggleRCA()
{
	mIsRcaON = !mIsRcaON;
	GuiItfSetKarunaRca(mIsRcaON);
}

void MainView::ToggleBNC()
{
	mIsBncON = !mIsBncON;
	GuiItfSetKarunaBnc(mIsBncON);
}

void MainView::ToggleXLR()
{
	mIsXlrON = !mIsXlrON;
	GuiItfSetKarunaXlr(mIsXlrON);
}

//AUDIO OUTPUTS
void MainView::RefreshHDMIOutput()
{
	btnHDMI.setBoxWithBorderColors(GetOutputPressColor(mIsHdmiON), GetOutputReleaseColor(mIsHdmiON), BLACKCOLOR, BLACKCOLOR);
	if (mIsHdmiON)
	{
		btnHDMI.setBitmaps(Bitmap(BITMAP_HDMI_80X80_FB_ID), Bitmap(BITMAP_HDMI_80X80_S_ID));
	}
	else
	{
		btnHDMI.setBitmaps(Bitmap(BITMAP_HDMI_80X80_S_ID), Bitmap(BITMAP_HDMI_80X80_S_ID));
	}
	btnHDMI.invalidate();
}

void MainView::RefreshRCAOutput()
{
	btnRCA.setBoxWithBorderColors(GetOutputPressColor(mIsRcaON), GetOutputReleaseColor(mIsRcaON), BLACKCOLOR, BLACKCOLOR);
	if (mIsRcaON)
	{
		btnRCA.setBitmaps(Bitmap(BITMAP_RCA_80X80_FB_ID), Bitmap(BITMAP_RCA_80X80_S_ID));
	}
	else
	{
		btnRCA.setBitmaps(Bitmap(BITMAP_RCA_80X80_S_ID), Bitmap(BITMAP_RCA_80X80_S_ID));
	}
	btnRCA.invalidate();
}

void MainView::RefreshBNCOutput()
{
	btnBNC.setBoxWithBorderColors(GetOutputPressColor(mIsBncON), GetOutputReleaseColor(mIsBncON), BLACKCOLOR, BLACKCOLOR);
	if (mIsBncON)
	{
		btnBNC.setBitmaps(Bitmap(BITMAP_BNC_80X80_FB_ID), Bitmap(BITMAP_BNC_80X80_S_ID));
	}
	else
	{
		btnBNC.setBitmaps(Bitmap(BITMAP_BNC_80X80_S_ID), Bitmap(BITMAP_BNC_80X80_S_ID));
	}
	btnBNC.invalidate();
}

void MainView::RefreshXLROutput()
{
	btnXLR.setBoxWithBorderColors(GetOutputPressColor(mIsXlrON), GetOutputReleaseColor(mIsXlrON), BLACKCOLOR, BLACKCOLOR);
	if (mIsXlrON)
	{
		btnXLR.setBitmaps(Bitmap(BITMAP_XLR_80X80_FB_ID), Bitmap(BITMAP_XLR_80X80_S_ID));
	}
	else
	{
		btnXLR.setBitmaps(Bitmap(BITMAP_XLR_80X80_S_ID), Bitmap(BITMAP_XLR_80X80_S_ID));
	}
	btnXLR.invalidate();
}

// CLOCK PROPS

void MainView::Refresh24Lock()
{
	box24.setColor(GetLockColor(mIs24Locked));
	box24.invalidate();
}

void MainView::Refresh245Lock()
{
	box245.setColor(GetLockColor(mIs245Locked));
	box245.invalidate();
}

void MainView::Refresh22Lock()
{
	box22.setColor(GetLockColor(mIs22Locked));
	box22.invalidate();
}

void MainView::RefreshIntExt()
{
	boxIntExt.setColor(GetLockColor(mIsIntExt));
	if (mIsIntExt)
	{
		imgIntExt.setBitmap(Bitmap(BITMAP_CLOCKEXT_80X80_I_ID));
	}
	else
	{
		imgIntExt.setBitmap(Bitmap(BITMAP_CLOCKINT_80X80_I_ID));
	}
	boxIntExt.invalidate();
}

// CLOCK TEMP

void  MainView::SetTemp(int p_Temp)
{
	int heatedTemp = GuiItfGetDasClockHeatedTemperature();

	if (p_Temp < heatedTemp - 30)
	{
		PaintDot(MIDGRAYCOLOR, MIDGRAYCOLOR, MIDGRAYCOLOR);
	}
	else if (p_Temp >= heatedTemp - 30 && p_Temp < heatedTemp - 20)
	{
		PaintDot(CORECOLOR, MIDGRAYCOLOR, MIDGRAYCOLOR);
	}
	else if (p_Temp >= heatedTemp - 20 && p_Temp < heatedTemp - 10)
	{
		PaintDot(CORECOLOR, CORECOLOR, MIDGRAYCOLOR);
	}
	else if (p_Temp >= heatedTemp - 10 && p_Temp < heatedTemp + 10)
	{
		PaintDot(CORECOLOR, CORECOLOR, CORECOLOR);
	}
	else if (p_Temp >= heatedTemp +  10 && p_Temp < heatedTemp + 15)
	{
		PaintDot(REDCOLOR, CORECOLOR, CORECOLOR);
	}
	else if (p_Temp >= heatedTemp + 15 && p_Temp < heatedTemp + 20)
	{
		PaintDot(REDCOLOR, REDCOLOR, CORECOLOR);
	}
	else if (p_Temp >= heatedTemp + 20)
	{
		PaintDot(REDCOLOR, REDCOLOR, REDCOLOR);
	}
}

void MainView::PaintDot(colortype p_Dot1, colortype p_Dot2, colortype p_Dot3)
{
	circTemp1Painter.setColor(p_Dot1);
	circTemp2Painter.setColor(p_Dot2);
	circTemp3Painter.setColor(p_Dot3);

	circTemp1.invalidate();
	circTemp2.invalidate();
	circTemp3.invalidate();
}


//SET GUI AUDIO VALUE

/// <summary>
/// DSD_PCM , SEL_3_ISO , SEL_2_ISO , SEL_1_ISO , SEL_0_ISO - 5 bites  inform�ci�
/// </summary>
/// <param name="p_AudiFormat"></param>
void  MainView::SetDSDPCM(int p_AudiFormat)
{
	bool isDsd = ToBinary(p_AudiFormat, 4);

	if (isDsd)
	{
		bool isDoP = !ToBinary(p_AudiFormat, 3);
		if (isDoP)
		{
			Unicode::strncpy(lblValueFormatBuffer, "DoP", LBLVALUEFORMAT_SIZE);
		}
		else
		{
			Unicode::strncpy(lblValueFormatBuffer, "DSD", LBLVALUEFORMAT_SIZE);
		}
		//Unicode::snprintf(lblValueFormatBuffer, 3, "%s", "DSD");
		int dsdFormat = p_AudiFormat >> 1;
		dsdFormat = dsdFormat & 0b00000011;

		Unicode::strncpy(lblDSDValueBuffer, "N.A.", LBLDSDVALUE_SIZE);


		switch (dsdFormat)
		{
		case 0b10:
		{
			Unicode::strncpy(lblDSDValueBuffer, "64", LBLDSDVALUE_SIZE);
		}break;
		case 0b11:
		{
			Unicode::strncpy(lblDSDValueBuffer, "128", LBLDSDVALUE_SIZE);
		}break;
		case 0b01:
		{
			Unicode::strncpy(lblDSDValueBuffer, "256", LBLDSDVALUE_SIZE);
		}break;
		case 0b00:
		{
			Unicode::strncpy(lblDSDValueBuffer, "512", LBLDSDVALUE_SIZE);
		}break;

		default:
			break;
		}
	}
	else
	{
		Unicode::strncpy(lblValueFormatBuffer, "PCM", LBLVALUEFORMAT_SIZE);
	}

	lblDSDValue.setVisible(isDsd);
	lblDSDValue.invalidate();
	lblValueFormat.invalidate();
}

void  MainView::SetBitDepth(int p_AudiFormat)
{
	bool isDsd = ToBinary(p_AudiFormat, 4);

	if (isDsd)
	{
		Unicode::strncpy(lblValueBitDepthBuffer, "1 bit", LBLVALUEBITDEPTH_SIZE);
	}
	else
	{
		Unicode::strncpy(lblValueBitDepthBuffer, "24 bit", LBLVALUEBITDEPTH_SIZE);
	}

	//Ezt kell majd meghivni ha Lyuben kijavította a hibát de addig hazudunk

		/*int BitDepth = p_AudiFormat >> 5;
		BitDepth = BitDepth & 0b00000011;

		switch (BitDepth)
		{
		case 0b00:
		{
			Unicode::strncpy(lblValueBitDepthBuffer, "1 bit", 6);
		}break;
		case 0b01:
		{
			Unicode::strncpy(lblValueBitDepthBuffer, "16 bit", 7);
		}break;
		case 0b10:
		{
			Unicode::strncpy(lblValueBitDepthBuffer, "24 bit", 7);
		}break;
		case 0b11:
		{
			Unicode::strncpy(lblValueBitDepthBuffer, "32 bit", 7);
		}break;

		default:
			break;
		}*/


	lblValueBitDepth.invalidate();
}

void  MainView::SetFreq(int p_AudiFormat)
{
	bool isDsd = ToBinary(p_AudiFormat, 4);

	Unicode::strncpy(lblValueFreqBuffer, "N.A.", LBLVALUEFREQ_SIZE);

	if (!isDsd)
	{
		//PCM FREQ.

		int freqVal = p_AudiFormat & 0b00001111;

		switch (freqVal)
		{
		case 0b0000:
		{
			Unicode::strncpy(lblValueFreqBuffer, "44.1 kHz", LBLVALUEFREQ_SIZE);
		}break;
		case 0b0001:
		{
			Unicode::strncpy(lblValueFreqBuffer, "48 kHz", LBLVALUEFREQ_SIZE);
		}break;
		case 0b0010:
		{
			Unicode::strncpy(lblValueFreqBuffer, "88.2 kHz", LBLVALUEFREQ_SIZE);
		}break;
		case 0b0011:
		{
			Unicode::strncpy(lblValueFreqBuffer, "96 kHz", LBLVALUEFREQ_SIZE);
		}break;
		case 0b0100:
		{
			Unicode::strncpy(lblValueFreqBuffer, "176.4 kHz", LBLVALUEFREQ_SIZE);
		}break;
		case 0b0101:
		{
			Unicode::strncpy(lblValueFreqBuffer, "192 kHz", LBLVALUEFREQ_SIZE);
		}break;
		case 0b0110:
		{
			Unicode::strncpy(lblValueFreqBuffer, "352.8 kHz", LBLVALUEFREQ_SIZE);
		}break;
		case 0b0111:
		{
			Unicode::strncpy(lblValueFreqBuffer, "384 kHz", LBLVALUEFREQ_SIZE);
		}break;
		case 0b1000:
		{
			Unicode::strncpy(lblValueFreqBuffer, "705.6 kHz", LBLVALUEFREQ_SIZE);
		}break;
		case 0b1001:
		{
			Unicode::strncpy(lblValueFreqBuffer, "768 kHz", LBLVALUEFREQ_SIZE);
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
			Unicode::strncpy(lblValueFreqBuffer, "2.8 MHz", LBLVALUEFREQ_SIZE);
		}break;
		case 0b11:
		{
			Unicode::strncpy(lblValueFreqBuffer, "5.8 MHz", LBLVALUEFREQ_SIZE);
		}break;
		case 0b01:
		{
			Unicode::strncpy(lblValueFreqBuffer, "11.2 MHz", LBLVALUEFREQ_SIZE);
		}break;
		case 0b00:
		{
			Unicode::strncpy(lblValueFreqBuffer, "22.6 MHz", LBLVALUEFREQ_SIZE);
		}break;

		default:
			break;
		}
	}
	lblValueFreq.invalidate();
}

colortype MainView::GetOutputPressColor(bool p_State)
{
	if (!p_State)
	{
		return BLACKCOLOR;
	}
	else
	{
		return CORECOLOR;
	}
}

colortype MainView::GetOutputReleaseColor(bool p_State)
{
	if (!p_State)
	{
		return DARKGRAYCOLOR;
	}
	else
	{
		return CORECOLOR;
	}
}

colortype MainView::GetLockColor(bool p_State)
{
	if (!p_State)
	{
		return MIDGRAYCOLOR;
	}
	else
	{
		return CORECOLOR;
	}
}

bool MainView::ToBinary(int number, int position)
{
	bool ret = ((1 << position) & number) != 0;
	return ret;
}

// Tick event

void MainView::handleTickEvent()
{
	mTickCount++;

	RefreshKarunaAndClockInfo();
	//Wait for 0.5sec
	if (mTickCount % 10 == 0)
	{
		time_t actualTime = RequestCurrentTime();

		if (!GuiItfGetScreenSaverEnable() && (actualTime - saverDateTime > 60))
		{
			application().gotoSaverScreenScreenWipeTransitionEast();
		}
	}
}

void MainView::RefreshKarunaAndClockInfo()
{
	//Read audio format
	uint8_t  KRN_STAT = GuiItfGetKarunaStatus();

	SetDSDPCM(KRN_STAT);
	SetBitDepth(KRN_STAT);
	SetFreq(KRN_STAT);

	float temp = GuiItfGetDasClockMV341Temp();
	SetTemp((int)temp);

	//Refresh Clock Status
	mIs22Locked = GuiItfGetDasClockStatusLock1();
	mIs245Locked = GuiItfGetDasClockStatusLock2();
	mIs24Locked = mIs245Locked && mIs22Locked;
	mIsIntExt = GuiItfGetDasClockIsExt();

	Refresh24Lock();
	Refresh245Lock();
	Refresh22Lock();
	RefreshIntExt();

	//Refresh Karuna outputs
	mIsBncON = GuitIfGetKarunaIsBncSet();
	mIsHdmiON = GuitIfGetKarunaIsHdmiSet();
	mIsRcaON = GuitIfGetKarunaIsRcaSet();
	mIsXlrON = GuitIfGetKarunaIsXlrSet();

	RefreshHDMIOutput();
	RefreshRCAOutput();
	RefreshBNCOutput();
	RefreshXLROutput();

	lblMCLKON.setVisible(GuiItfGetKarunaMclkOutIsEanbled() > 0);
	lblMCLKON.invalidate();
}

time_t MainView::RequestCurrentTime()
{
	time_t dtp;
	GuiItfGetRtc(&dtp);
	struct tm* tm_info = gmtime(&dtp);
	char strDateTime[LBLDATETIME_SIZE];
	strftime(strDateTime, LBLDATETIME_SIZE, "%d.%m.%Y  %H:%M", tm_info);

	Unicode::UnicodeChar uni_DateTime[LBLDATETIME_SIZE];
	Unicode::fromUTF8((const uint8_t*)strDateTime, uni_DateTime, LBLDATETIME_SIZE);
	Unicode::snprintf(lblDateTimeBuffer, LBLDATETIME_SIZE, "%s", uni_DateTime);
	lblDateTime.invalidate();

	return dtp;
}
