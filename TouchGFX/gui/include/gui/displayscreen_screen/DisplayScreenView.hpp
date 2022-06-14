#ifndef DISPLAYSCREENVIEW_HPP
#define DISPLAYSCREENVIEW_HPP

#include <gui_generated/displayscreen_screen/DisplayScreenViewBase.hpp>
#include <gui/displayscreen_screen/DisplayScreenPresenter.hpp>
#include <gui/common/BackendCommunicator.hpp>

class DisplayScreenView : public DisplayScreenViewBase 
{


public:

    DisplayScreenView();
    virtual ~DisplayScreenView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();

private:
     
protected: 
    BackendCommunicator mCommunicator;


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