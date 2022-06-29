#include <gui/clockscreen_screen/ClockScreenView.hpp>
#include <time.h>
#include <stdlib.h>

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
	simDateTime++;
	*dt = simDateTime;
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
	RequestCurrentTime();
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
		RequestCurrentTime();
	}
}

void ClockScreenView::RequestCurrentTime()
{
  time_t dtp;
  GuiItfGetRtc(&dtp);
  struct tm* tm_info = gmtime(&dtp);
  char strDateTime[LBLDATETIME_SIZE];
  //06.29.2022 17:08:01
  strftime(strDateTime, LBLDATETIME_SIZE, "%d.%m.%Y %H:%M:%S", tm_info);

  Unicode::UnicodeChar uni_DateTime[LBLDATETIME_SIZE];
  Unicode::fromUTF8((const uint8_t*)strDateTime, uni_DateTime, LBLDATETIME_SIZE);
  Unicode::snprintf(lblDateTimeBuffer, LBLDATETIME_SIZE, "%s", uni_DateTime);
  lblDateTime.invalidate();
}

void ClockScreenView::SetClockTime()
{
  /*               Day   Month   Year   Hour    Min    Sec
  *  komponens:    02       06   2022    10      21    42
  *  tm:            2       5     122    10      21    42
  */
  struct tm tm_info;
  tm_info.tm_year = scrollYear.getSelectedItem() + 100;//tm_year 1900-tól eltelet sec száma
  tm_info.tm_mon = scrollMonth.getSelectedItem(); //tm_mon: 0..11 és a 0-indexen a jobb oldalon 1 van.
  tm_info.tm_mday = scrollDay.getSelectedItem() + 1; //tm_mday:1..31 és + 1 mert nincs nulla
  tm_info.tm_hour = scrollHour.getSelectedItem();
  tm_info.tm_min = scrollMin.getSelectedItem();
  tm_info.tm_sec = scrollSec.getSelectedItem();
  tm_info.tm_isdst = 0;

  _timezone = 0;
  time_t setTime = mktime(&tm_info);
  GuiItfSetRtc(setTime);
}

void ClockScreenView::GetClockTime()
{
  time_t dt;
  GuiItfGetRtc(&dt);
  struct tm* tm_info = gmtime(&dt);

  uint16_t year = tm_info->tm_year + 1900;
  uint8_t mon = tm_info->tm_mon;
  uint8_t day = tm_info->tm_mday;

  uint8_t hour = tm_info->tm_hour;
  uint8_t min = tm_info->tm_min;
  uint8_t sec = tm_info->tm_sec;

  scrollYear.animateToItem(year - 2000);
  scrollMonth.animateToItem(mon);
  scrollDay.animateToItem(day - 1);

  scrollHour.animateToItem(hour);
  scrollMin.animateToItem(min);
  scrollSec.animateToItem(sec);
}
