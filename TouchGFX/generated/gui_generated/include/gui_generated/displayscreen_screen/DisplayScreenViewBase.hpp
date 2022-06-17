/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#ifndef DISPLAYSCREENVIEWBASE_HPP
#define DISPLAYSCREENVIEWBASE_HPP

#include <gui/common/FrontendApplication.hpp>
#include <mvp/View.hpp>
#include <gui/displayscreen_screen/DisplayScreenPresenter.hpp>
#include <touchgfx/widgets/Box.hpp>
#include <touchgfx/widgets/BoxWithBorder.hpp>
#include <touchgfx/containers/buttons/Buttons.hpp>
#include <touchgfx/widgets/TextArea.hpp>
#include <touchgfx/containers/Slider.hpp>
#include <touchgfx/containers/Container.hpp>
#include <touchgfx/widgets/RadioButton.hpp>
#include <touchgfx/widgets/TextAreaWithWildcard.hpp>
#include <touchgfx/widgets/canvas/Line.hpp>
#include <touchgfx/widgets/canvas/PainterRGB565.hpp>
#include <touchgfx/widgets/RadioButtonGroup.hpp>

class DisplayScreenViewBase : public touchgfx::View<DisplayScreenPresenter>
{
public:
    DisplayScreenViewBase();
    virtual ~DisplayScreenViewBase() {}
    virtual void setupScreen();

    /*
     * Virtual Action Handlers
     */
    virtual void sldrBrightnesChanged(int value)
    {
        // Override and implement this function in DisplayScreen
    }

    virtual void rbtnSelect0OffTmr()
    {
        // Override and implement this function in DisplayScreen
    }

    virtual void rbtnSelect1OffTmr()
    {
        // Override and implement this function in DisplayScreen
    }

    virtual void rbtnSelect5OffTmr()
    {
        // Override and implement this function in DisplayScreen
    }

    virtual void rbtnSelect10OffTmr()
    {
        // Override and implement this function in DisplayScreen
    }

    virtual void rbtnSelect30OffTmr()
    {
        // Override and implement this function in DisplayScreen
    }

    virtual void rbtnSelect60OffTmr()
    {
        // Override and implement this function in DisplayScreen
    }

    virtual void rbtnSelect120OffTmr()
    {
        // Override and implement this function in DisplayScreen
    }

protected:
    FrontendApplication& application() {
        return *static_cast<FrontendApplication*>(touchgfx::Application::getInstance());
    }

    /*
     * Member Declarations
     */
    touchgfx::Box __background;
    touchgfx::Box box1;
    touchgfx::BoxWithBorder boxWithBorder1;
    touchgfx::TextButtonStyle< touchgfx::ImageButtonStyle< touchgfx::BoxWithBorderButtonStyle< touchgfx::ClickButtonTrigger >  >  >  btnBack;
    touchgfx::TextArea textArea1;
    touchgfx::Slider sldrBrightnes;
    touchgfx::TextButtonStyle< touchgfx::ImageButtonStyle< touchgfx::BoxWithBorderButtonStyle< touchgfx::ClickButtonTrigger >  >  >  btnDisplayOff;
    touchgfx::TextArea textArea2_1;
    touchgfx::Container container1;
    touchgfx::RadioButton rdbtnSet0;
    touchgfx::TextArea textArea2;
    touchgfx::RadioButton rdbtnSet1;
    touchgfx::TextArea textArea2_2;
    touchgfx::RadioButton rdbtnSet5;
    touchgfx::TextArea textArea2_3;
    touchgfx::RadioButton rdbtnSet10;
    touchgfx::TextArea textArea2_3_1;
    touchgfx::RadioButton rdbtnSet30;
    touchgfx::TextArea textArea2_3_2;
    touchgfx::RadioButton rdbtnSet60;
    touchgfx::TextArea textArea2_3_3;
    touchgfx::RadioButton rdbtnSet120;
    touchgfx::TextArea textArea2_3_4;
    touchgfx::TextAreaWithOneWildcard lblBrightness;
    touchgfx::TextArea textArea2_1_1_1;
    touchgfx::TextAreaWithOneWildcard lblTimeToOff;
    touchgfx::Line line1;
    touchgfx::PainterRGB565 line1Painter;
    touchgfx::RadioButtonGroup<7> radioButtonGroup1;

    /*
     * Wildcard Buffers
     */
    static const uint16_t LBLBRIGHTNESS_SIZE = 10;
    touchgfx::Unicode::UnicodeChar lblBrightnessBuffer[LBLBRIGHTNESS_SIZE];
    static const uint16_t LBLTIMETOOFF_SIZE = 10;
    touchgfx::Unicode::UnicodeChar lblTimeToOffBuffer[LBLTIMETOOFF_SIZE];

private:

    /*
     * Callback Declarations
     */
    touchgfx::Callback<DisplayScreenViewBase, const touchgfx::AbstractButtonContainer&> flexButtonCallback;
    touchgfx::Callback<DisplayScreenViewBase, const touchgfx::Slider&, int> sliderValueChangedCallback;
    touchgfx::Callback<DisplayScreenViewBase, const touchgfx::AbstractButton&> radioButtonSelectedCallback;

    /*
     * Callback Handler Declarations
     */
    void flexButtonCallbackHandler(const touchgfx::AbstractButtonContainer& src);
    void sliderValueChangedCallbackHandler(const touchgfx::Slider& src, int value);
    void radioButtonSelectedCallbackHandler(const touchgfx::AbstractButton& src);

    /*
     * Canvas Buffer Size
     */
    static const uint16_t CANVAS_BUFFER_SIZE = 15360;
    uint8_t canvasBuffer[CANVAS_BUFFER_SIZE];
};

#endif // DISPLAYSCREENVIEWBASE_HPP
