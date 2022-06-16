#ifndef CLOCKSCREENVIEW_HPP
#define CLOCKSCREENVIEW_HPP

#include <gui_generated/clockscreen_screen/ClockScreenViewBase.hpp>
#include <gui/clockscreen_screen/ClockScreenPresenter.hpp>

class ClockScreenView : public ClockScreenViewBase
{
public:
    ClockScreenView();
    virtual ~ClockScreenView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
    virtual void handleTickEvent();
     
    virtual void scrollYearUpdateItem(textContainer& item, int16_t itemIndex);
    virtual void scrollYearUpdateCenterItem(TextContainerHigh& item, int16_t itemIndex);
    virtual void scrollMonthUpdateItem(textContainer& item, int16_t itemIndex);
    virtual void scrollMonthUpdateCenterItem(TextContainerHigh& item, int16_t itemIndex);
    virtual void scrollDayUpdateItem(textContainer& item, int16_t itemIndex);
    virtual void scrollDayUpdateCenterItem(TextContainerHigh& item, int16_t itemIndex);


    virtual void scrollHourUpdateItem(textContainer& item, int16_t itemIndex);
    virtual void scrollHourUpdateCenterItem(TextContainerHigh& item, int16_t itemIndex);
    virtual void scrollMinUpdateItem(textContainer& item, int16_t itemIndex);
    virtual void scrollMinUpdateCenterItem(TextContainerHigh& item, int16_t itemIndex);
    virtual void scrollSecUpdateItem(textContainer& item, int16_t itemIndex);
    virtual void scrollSecUpdateCenterItem(TextContainerHigh& item, int16_t itemIndex);

    virtual void SetClockTime();
    void GetClockTime();

#ifdef SIMULATOR
 
    /*** RTC ***/
    void GuiItfSetRtc(time_t dt);
    void GuiItfGetRtc(time_t* dt);
#endif
  
protected:
};

#endif // CLOCKSCREENVIEW_HPP
