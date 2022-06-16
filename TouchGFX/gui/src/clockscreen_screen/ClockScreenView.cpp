#include <gui/clockscreen_screen/ClockScreenView.hpp>
#include <time.h>


#ifdef SIMULATOR

time_t simDateTime;

void ClockScreenView::GuiItfSetRtc(time_t dt)
{
	simDateTime = dt;
}

void ClockScreenView::GuiItfGetRtc(time_t* dt)
{
	if (simDateTime == 0)
	{ 
		tm tm_info;
		tm_info.tm_year = 2022 - 1900;
		tm_info.tm_mon = 6-1;
		tm_info.tm_mday = 16;
		tm_info.tm_hour = 20;
		tm_info.tm_min = 21;
		tm_info.tm_sec = 22;
		tm_info.tm_isdst = 0;

		simDateTime = mktime(&tm_info);
	}
	dt = &simDateTime;
	dt = dt;
}

#else
extern "C"
{
	/*** RTC ***/
	void GuiItfSetRtc(time_t dt);
	void GuiItfGetRtc(time_t* dt);
}
#endif

int mClockTickCount;

ClockScreenView::ClockScreenView()
{

}

void ClockScreenView::setupScreen()
{
	ClockScreenViewBase::setupScreen();

	GetClockTime();
}

void ClockScreenView::tearDownScreen()
{
	ClockScreenViewBase::tearDownScreen();
}


// CLOCK SETTINGS

//DATE
void ClockScreenView::scrollYearUpdateItem(textContainer& item, int16_t itemIndex)
{
	item.updateText(itemIndex + 2000);
}

void ClockScreenView::scrollYearUpdateCenterItem(TextContainerHigh& item, int16_t itemIndex)
{
	item.updateText(itemIndex + 2000);
}

void ClockScreenView::scrollMonthUpdateItem(textContainer& item, int16_t itemIndex)
{
	item.updateText(itemIndex + 1);
}

void ClockScreenView::scrollMonthUpdateCenterItem(TextContainerHigh& item, int16_t itemIndex)
{
	item.updateText(itemIndex + 1);
}

void ClockScreenView::scrollDayUpdateItem(textContainer& item, int16_t itemIndex)
{
	item.updateText(itemIndex + 1);
}

void ClockScreenView::scrollDayUpdateCenterItem(TextContainerHigh& item, int16_t itemIndex)
{
	item.updateText(itemIndex + 1);
}

//TIME
void ClockScreenView::scrollHourUpdateItem(textContainer& item, int16_t itemIndex)
{
	item.updateText(itemIndex);
}

void ClockScreenView::scrollHourUpdateCenterItem(TextContainerHigh& item, int16_t itemIndex)
{
	item.updateText(itemIndex);
}

void ClockScreenView::scrollMinUpdateItem(textContainer& item, int16_t itemIndex)
{
	item.updateText(itemIndex);
}

void ClockScreenView::scrollMinUpdateCenterItem(TextContainerHigh& item, int16_t itemIndex)
{
	item.updateText(itemIndex);
}

void ClockScreenView::scrollSecUpdateItem(textContainer& item, int16_t itemIndex)
{
	item.updateText(itemIndex);
}

void ClockScreenView::scrollSecUpdateCenterItem(TextContainerHigh& item, int16_t itemIndex)
{
	item.updateText(itemIndex);
}

//Set Time

void ClockScreenView::handleTickEvent()
{
	mClockTickCount++;

	//Wait for 
	if (mClockTickCount % 10 == 0)
	{
		time_t dt = 1655407282;
		time_t* dtp = &dt;
		GuiItfGetRtc(dtp);
		struct tm* tm_info = gmtime(dtp);
		char strDateTime[25];
		strftime(strDateTime, 25, "%Y.%m.%d %H:%M:%S", tm_info);


		Unicode::UnicodeChar uni_DateTime[25];
		Unicode::fromUTF8((const uint8_t*)strDateTime, uni_DateTime, sizeof(uni_DateTime));
		Unicode::snprintf(lblDateTimeBuffer, sizeof(lblDateTimeBuffer), "%s", uni_DateTime);
		lblDateTime.invalidate();
	}
}

void ClockScreenView::SetClockTime()
{
	int year = scrollYear.getSelectedItem();
	int month = scrollMonth.getSelectedItem() + 1;
	int day = scrollDay.getSelectedItem() + 1;

	int hour = scrollHour.getSelectedItem();
	int min = scrollMin.getSelectedItem();
	int sec = scrollSec.getSelectedItem();


	tm tm_info;
	tm_info.tm_year = year + 2000;
	tm_info.tm_mon = month;
	tm_info.tm_mday = day;
	tm_info.tm_hour = hour;
	tm_info.tm_min = min;
	tm_info.tm_sec = sec;
	tm_info.tm_isdst = 0;
	tm* ptm = &tm_info;

	time_t setTime = mktime(ptm);
	GuiItfSetRtc(setTime);
}

void ClockScreenView::GetClockTime()
{ 
	time_t dt = 1655407282;
	time_t* dtp = &dt;
	GuiItfGetRtc(dtp);
	struct tm* tm_info = gmtime(dtp);

	uint16_t year = tm_info->tm_year + 1900;
	uint8_t mon = tm_info->tm_mon;
	uint8_t day = tm_info->tm_mday-1;

	uint8_t hour = tm_info->tm_hour;
	uint8_t min = tm_info->tm_min;
	uint8_t sec = tm_info->tm_sec;
	 
	scrollYear.animateToItem(year-2000);
	scrollMonth.animateToItem(mon);
	scrollDay.animateToItem(day);

	scrollHour.animateToItem(hour);
	scrollMin.animateToItem(min);
	scrollSec.animateToItem(sec); 
}