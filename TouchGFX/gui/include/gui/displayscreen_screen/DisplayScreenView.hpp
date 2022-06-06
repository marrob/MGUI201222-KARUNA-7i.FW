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

#ifdef SIMULATOR
    uint8_t GuiItfSetBacklight(uint8_t percent);
    uint8_t GuiItfGetBacklight(void);
#endif

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
