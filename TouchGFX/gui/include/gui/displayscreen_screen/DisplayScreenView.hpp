#ifndef DISPLAYSCREENVIEW_HPP
#define DISPLAYSCREENVIEW_HPP

#include <gui_generated/displayscreen_screen/DisplayScreenViewBase.hpp>
#include <gui/displayscreen_screen/DisplayScreenPresenter.hpp>


class DisplayScreenView : public DisplayScreenViewBase 
{


public:

    DisplayScreenView();
    virtual ~DisplayScreenView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();

    virtual void handleTickEvent();

    virtual void rbtnSelect0OffTmr();
    virtual void rbtnSelect1OffTmr();
    virtual void rbtnSelect5OffTmr();
    virtual void rbtnSelect10OffTmr();
    virtual void rbtnSelect30OffTmr();
    virtual void rbtnSelect60OffTmr();
    virtual void rbtnSelect120OffTmr();

    void GetOfTimerValue();


#ifdef SIMULATOR
    uint8_t GuiItfSetBacklight(uint8_t percent);
    uint8_t GuiItfGetBacklight(void);
    void GuiItfSetBackLightAutoOff(uint32_t sec);
    uint32_t GuiItfGetBacklightAutoOff(void);
    uint32_t GuiItfGetRemainingTimeToOff(void);
#endif

private:
     
protected:
    /*
     * Callback Declarations
     */
    touchgfx::Callback<DisplayScreenView, const touchgfx::Slider&, int> sliderValueChangedCallback;

    /*
     * Callback Handler Declarations
     */
    void sliderValueChangedCallbackHandler(const touchgfx::Slider& src, int value);
};

#endif // DISPLAYSCREENVIEW_HPP
