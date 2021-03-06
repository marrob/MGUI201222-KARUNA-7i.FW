/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#ifndef SERVICECONTAINERBASE_HPP
#define SERVICECONTAINERBASE_HPP

#include <gui/common/FrontendApplication.hpp>
#include <touchgfx/containers/Container.hpp>
#include <touchgfx/widgets/TextArea.hpp>
#include <touchgfx/widgets/TextAreaWithWildcard.hpp>
#include <touchgfx/widgets/canvas/Line.hpp>
#include <touchgfx/widgets/canvas/PainterRGB565.hpp>
#include <touchgfx/containers/buttons/Buttons.hpp>
#include <gui/containers/UpDownContainer.hpp>

class ServiceContainerBase : public touchgfx::Container
{
public:
    ServiceContainerBase();
    virtual ~ServiceContainerBase() {}
    virtual void initialize();

    /*
     * Virtual Action Handlers
     */
    virtual void OnClickSoftReset()
    {
        // Override and implement this function in ServiceContainer
    }

    virtual void OnClickFactoryReset()
    {
        // Override and implement this function in ServiceContainer
    }

    virtual void OnOffsetValueChanged(uint32_t value)
    {
        // Override and implement this function in ServiceContainer
    }

protected:
    FrontendApplication& application() {
        return *static_cast<FrontendApplication*>(touchgfx::Application::getInstance());
    }

    /*
     * Member Declarations
     */
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
    touchgfx::TextButtonStyle< touchgfx::BoxWithBorderButtonStyle< touchgfx::ClickButtonTrigger >  >  btnSoftReset;
    touchgfx::Line line2_1;
    touchgfx::PainterRGB565 line2_1Painter;
    touchgfx::TextArea lblBootUpCountTitle;
    touchgfx::TextAreaWithOneWildcard lblBootupCnt;
    touchgfx::TextArea lblDasClocUartErrorTitle;
    touchgfx::TextAreaWithOneWildcard DasClockErrorCnt;
    touchgfx::TextArea lblBusUartErrorCntTitle;
    touchgfx::TextAreaWithOneWildcard lblBusUartErrorCnt;
    touchgfx::TextArea lblKarunaUptimeCntTitle;
    touchgfx::TextAreaWithOneWildcard lblKarunaUartErrorCnt;
    touchgfx::Line line1_1;
    touchgfx::PainterRGB565 line1_1Painter;
    touchgfx::Line line1_1_1;
    touchgfx::PainterRGB565 line1_1_1Painter;
    touchgfx::TextButtonStyle< touchgfx::BoxWithBorderButtonStyle< touchgfx::ClickButtonTrigger >  >  btnDebug;
    touchgfx::TextArea lblDASClockSupplyVoltageTitle_1;
    UpDownContainer OffsetUpDownContainer;
    touchgfx::TextArea lblDASClockSupplyVoltageTitle_1_1;
    touchgfx::TextAreaWithOneWildcard lblTempOffsetRanges;

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
    static const uint16_t LBLBOOTUPCNT_SIZE = 12;
    touchgfx::Unicode::UnicodeChar lblBootupCntBuffer[LBLBOOTUPCNT_SIZE];
    static const uint16_t DASCLOCKERRORCNT_SIZE = 12;
    touchgfx::Unicode::UnicodeChar DasClockErrorCntBuffer[DASCLOCKERRORCNT_SIZE];
    static const uint16_t LBLBUSUARTERRORCNT_SIZE = 12;
    touchgfx::Unicode::UnicodeChar lblBusUartErrorCntBuffer[LBLBUSUARTERRORCNT_SIZE];
    static const uint16_t LBLKARUNAUARTERRORCNT_SIZE = 12;
    touchgfx::Unicode::UnicodeChar lblKarunaUartErrorCntBuffer[LBLKARUNAUARTERRORCNT_SIZE];
    static const uint16_t LBLTEMPOFFSETRANGES_SIZE = 100;
    touchgfx::Unicode::UnicodeChar lblTempOffsetRangesBuffer[LBLTEMPOFFSETRANGES_SIZE];

private:

    /*
     * Callback Declarations
     */
    touchgfx::Callback<ServiceContainerBase, const touchgfx::AbstractButtonContainer&> flexButtonCallback;
    touchgfx::Callback<ServiceContainerBase, uint32_t> OffsetUpDownContainerValueChangedTriggerCallback;

    /*
     * Callback Handler Declarations
     */
    void flexButtonCallbackHandler(const touchgfx::AbstractButtonContainer& src);
    void OffsetUpDownContainerValueChangedTriggerCallbackHandler(uint32_t value);

};

#endif // SERVICECONTAINERBASE_HPP
