/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#ifndef SETTINGSSCREENVIEWBASE_HPP
#define SETTINGSSCREENVIEWBASE_HPP

#include <gui/common/FrontendApplication.hpp>
#include <mvp/View.hpp>
#include <gui/settingsscreen_screen/SettingsScreenPresenter.hpp>
#include <touchgfx/widgets/Box.hpp>
#include <touchgfx/containers/buttons/Buttons.hpp>
#include <touchgfx/widgets/BoxWithBorder.hpp>
#include <touchgfx/widgets/RadioButton.hpp>
#include <touchgfx/widgets/TextArea.hpp>
#include <touchgfx/widgets/ToggleButton.hpp>
#include <touchgfx/widgets/canvas/Line.hpp>
#include <touchgfx/widgets/canvas/PainterRGB565.hpp>
#include <touchgfx/widgets/TextAreaWithWildcard.hpp>
#include <touchgfx/widgets/RadioButtonGroup.hpp>

class SettingsScreenViewBase : public touchgfx::View<SettingsScreenPresenter>
{
public:
    SettingsScreenViewBase();
    virtual ~SettingsScreenViewBase() {}
    virtual void setupScreen();

protected:
    FrontendApplication& application() {
        return *static_cast<FrontendApplication*>(touchgfx::Application::getInstance());
    }

    /*
     * Member Declarations
     */
    touchgfx::Box __background;
    touchgfx::Box box1;
    touchgfx::TextButtonStyle< touchgfx::ImageButtonStyle< touchgfx::BoxWithBorderButtonStyle< touchgfx::ClickButtonTrigger >  >  >  btnDisplay;
    touchgfx::BoxWithBorder boxWithBorder1;
    touchgfx::RadioButton rdbtnEnableAll;
    touchgfx::TextArea textArea1;
    touchgfx::TextArea textArea2;
    touchgfx::TextArea textArea2_1;
    touchgfx::ToggleButton chbxMCLKON;
    touchgfx::RadioButton rdbtnEnableSelected;
    touchgfx::TextArea textArea2_1_1;
    touchgfx::Line line1;
    touchgfx::PainterRGB565 line1Painter;
    touchgfx::Line line1_1;
    touchgfx::PainterRGB565 line1_1Painter;
    touchgfx::TextArea textArea2_1_1_1;
    touchgfx::TextAreaWithOneWildcard lblKarunaUptime;
    touchgfx::TextArea textArea2_1_1_1_1;
    touchgfx::TextAreaWithOneWildcard lblClockUptime;
    touchgfx::RadioButtonGroup<2> radioButtonGroup1;

    /*
     * Wildcard Buffers
     */
    static const uint16_t LBLKARUNAUPTIME_SIZE = 12;
    touchgfx::Unicode::UnicodeChar lblKarunaUptimeBuffer[LBLKARUNAUPTIME_SIZE];
    static const uint16_t LBLCLOCKUPTIME_SIZE = 12;
    touchgfx::Unicode::UnicodeChar lblClockUptimeBuffer[LBLCLOCKUPTIME_SIZE];

private:

    /*
     * Callback Declarations
     */
    touchgfx::Callback<SettingsScreenViewBase, const touchgfx::AbstractButton&> buttonCallback;
    touchgfx::Callback<SettingsScreenViewBase, const touchgfx::AbstractButtonContainer&> flexButtonCallback;

    /*
     * Callback Handler Declarations
     */
    void buttonCallbackHandler(const touchgfx::AbstractButton& src);
    void flexButtonCallbackHandler(const touchgfx::AbstractButtonContainer& src);

    /*
     * Canvas Buffer Size
     */
    static const uint16_t CANVAS_BUFFER_SIZE = 15360;
    uint8_t canvasBuffer[CANVAS_BUFFER_SIZE];
};

#endif // SETTINGSSCREENVIEWBASE_HPP
