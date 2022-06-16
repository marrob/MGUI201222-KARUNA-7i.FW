/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#ifndef SERVICESCREENVIEWBASE_HPP
#define SERVICESCREENVIEWBASE_HPP

#include <gui/common/FrontendApplication.hpp>
#include <mvp/View.hpp>
#include <gui/servicescreen_screen/ServiceScreenPresenter.hpp>
#include <touchgfx/widgets/Box.hpp>
#include <touchgfx/containers/buttons/Buttons.hpp>
#include <touchgfx/widgets/TextArea.hpp>
#include <touchgfx/widgets/BoxWithBorder.hpp>
#include <touchgfx/containers/ScrollableContainer.hpp>
#include <touchgfx/widgets/TextAreaWithWildcard.hpp>
#include <touchgfx/widgets/canvas/Line.hpp>
#include <touchgfx/widgets/canvas/PainterRGB565.hpp>

class ServiceScreenViewBase : public touchgfx::View<ServiceScreenPresenter>
{
public:
    ServiceScreenViewBase();
    virtual ~ServiceScreenViewBase() {}
    virtual void setupScreen();

    /*
     * Virtual Action Handlers
     */
    virtual void OnClickFactoryReset()
    {
        // Override and implement this function in ServiceScreen
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
    touchgfx::TextButtonStyle< touchgfx::ImageButtonStyle< touchgfx::BoxWithBorderButtonStyle< touchgfx::ClickButtonTrigger >  >  >  btnBack;
    touchgfx::TextButtonStyle< touchgfx::BoxWithBorderButtonStyle< touchgfx::ClickButtonTrigger >  >  btnLog;
    touchgfx::TextArea lblTitle;
    touchgfx::BoxWithBorder boxWithBorder1;
    touchgfx::ScrollableContainer scrlContainerService;
    touchgfx::TextArea lblKarunaUptimeTitle;
    touchgfx::TextAreaWithOneWildcard lblKarunaUptime;
    touchgfx::TextArea lblDASClockUptimeTitle;
    touchgfx::TextAreaWithOneWildcard lblClockUptime;
    touchgfx::TextArea lblDASClockTempTitle_0;
    touchgfx::TextAreaWithOneWildcard lblClocktemp_0;
    touchgfx::TextArea lblDASClockTempTitle_1;
    touchgfx::TextAreaWithOneWildcard lblClocktemp_1;
    touchgfx::TextAreaWithOneWildcard lblClocktemp_2;
    touchgfx::TextArea lblDASClockCurrentTitle_0;
    touchgfx::TextAreaWithOneWildcard lblClockCurrent_0;
    touchgfx::TextArea lblDASClockCurrentTitle_1;
    touchgfx::TextAreaWithOneWildcard lblClockCurrent_1;
    touchgfx::TextArea lblDASClockCurrentTitle_2;
    touchgfx::TextArea lblDASClockTempTitle_2;
    touchgfx::TextAreaWithOneWildcard lblClockCurrent_2;
    touchgfx::TextArea lblKarunaTitle;
    touchgfx::TextArea lblDASClockTitle;
    touchgfx::TextArea lblDASClockSupplyVoltageTitle;
    touchgfx::TextAreaWithOneWildcard lblDASClockSupplyVoltage;
    touchgfx::Line line4;
    touchgfx::PainterRGB565 line4Painter;
    touchgfx::Line line3;
    touchgfx::PainterRGB565 line3Painter;
    touchgfx::Line line2;
    touchgfx::PainterRGB565 line2Painter;
    touchgfx::Line line1;
    touchgfx::PainterRGB565 line1Painter;
    touchgfx::TextArea lblGUITitle;
    touchgfx::TextArea lblGUIFwVerTitle;
    touchgfx::TextAreaWithOneWildcard lblGUIFwVersion;
    touchgfx::Line line0;
    touchgfx::PainterRGB565 line0Painter;
    touchgfx::TextArea lblKarunaFwVerTitle;
    touchgfx::TextArea lblDASFwVerTitle;
    touchgfx::TextAreaWithOneWildcard lblKarunaFwVersion;
    touchgfx::TextAreaWithOneWildcard lblDASClockFwVersion;
    touchgfx::TextButtonStyle< touchgfx::BoxWithBorderButtonStyle< touchgfx::ClickButtonTrigger >  >  btnFactoryReset;

    /*
     * Wildcard Buffers
     */
    static const uint16_t LBLKARUNAUPTIME_SIZE = 12;
    touchgfx::Unicode::UnicodeChar lblKarunaUptimeBuffer[LBLKARUNAUPTIME_SIZE];
    static const uint16_t LBLCLOCKUPTIME_SIZE = 12;
    touchgfx::Unicode::UnicodeChar lblClockUptimeBuffer[LBLCLOCKUPTIME_SIZE];
    static const uint16_t LBLCLOCKTEMP_0_SIZE = 12;
    touchgfx::Unicode::UnicodeChar lblClocktemp_0Buffer[LBLCLOCKTEMP_0_SIZE];
    static const uint16_t LBLCLOCKTEMP_1_SIZE = 12;
    touchgfx::Unicode::UnicodeChar lblClocktemp_1Buffer[LBLCLOCKTEMP_1_SIZE];
    static const uint16_t LBLCLOCKTEMP_2_SIZE = 12;
    touchgfx::Unicode::UnicodeChar lblClocktemp_2Buffer[LBLCLOCKTEMP_2_SIZE];
    static const uint16_t LBLCLOCKCURRENT_0_SIZE = 12;
    touchgfx::Unicode::UnicodeChar lblClockCurrent_0Buffer[LBLCLOCKCURRENT_0_SIZE];
    static const uint16_t LBLCLOCKCURRENT_1_SIZE = 12;
    touchgfx::Unicode::UnicodeChar lblClockCurrent_1Buffer[LBLCLOCKCURRENT_1_SIZE];
    static const uint16_t LBLCLOCKCURRENT_2_SIZE = 12;
    touchgfx::Unicode::UnicodeChar lblClockCurrent_2Buffer[LBLCLOCKCURRENT_2_SIZE];
    static const uint16_t LBLDASCLOCKSUPPLYVOLTAGE_SIZE = 12;
    touchgfx::Unicode::UnicodeChar lblDASClockSupplyVoltageBuffer[LBLDASCLOCKSUPPLYVOLTAGE_SIZE];
    static const uint16_t LBLGUIFWVERSION_SIZE = 50;
    touchgfx::Unicode::UnicodeChar lblGUIFwVersionBuffer[LBLGUIFWVERSION_SIZE];
    static const uint16_t LBLKARUNAFWVERSION_SIZE = 50;
    touchgfx::Unicode::UnicodeChar lblKarunaFwVersionBuffer[LBLKARUNAFWVERSION_SIZE];
    static const uint16_t LBLDASCLOCKFWVERSION_SIZE = 50;
    touchgfx::Unicode::UnicodeChar lblDASClockFwVersionBuffer[LBLDASCLOCKFWVERSION_SIZE];

private:

    /*
     * Callback Declarations
     */
    touchgfx::Callback<ServiceScreenViewBase, const touchgfx::AbstractButtonContainer&> flexButtonCallback;

    /*
     * Callback Handler Declarations
     */
    void flexButtonCallbackHandler(const touchgfx::AbstractButtonContainer& src);

    /*
     * Canvas Buffer Size
     */
    static const uint16_t CANVAS_BUFFER_SIZE = 15360;
    uint8_t canvasBuffer[CANVAS_BUFFER_SIZE];
};

#endif // SERVICESCREENVIEWBASE_HPP
