/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#include <gui_generated/containers/ServiceContainerBase.hpp>
#include <texts/TextKeysAndLanguages.hpp>
#include <touchgfx/Color.hpp>

ServiceContainerBase::ServiceContainerBase() :
    flexButtonCallback(this, &ServiceContainerBase::flexButtonCallbackHandler)
{
    setWidth(1024);
    setHeight(1082);
    lblKarunaUptimeTitle.setPosition(32, 255, 295, 44);
    lblKarunaUptimeTitle.setColor(touchgfx::Color::getColorFromRGB(200, 200, 200));
    lblKarunaUptimeTitle.setLinespacing(0);
    lblKarunaUptimeTitle.setTypedText(touchgfx::TypedText(T___SINGLEUSE_QYPN));

    lblKarunaUptime.setPosition(367, 255, 184, 44);
    lblKarunaUptime.setColor(touchgfx::Color::getColorFromRGB(200, 200, 200));
    lblKarunaUptime.setLinespacing(0);
    Unicode::snprintf(lblKarunaUptimeBuffer, LBLKARUNAUPTIME_SIZE, "%s", touchgfx::TypedText(T___SINGLEUSE_IA01).getText());
    lblKarunaUptime.setWildcard(lblKarunaUptimeBuffer);
    lblKarunaUptime.setTypedText(touchgfx::TypedText(T___SINGLEUSE_27WL));

    lblDASClockUptimeTitle.setPosition(32, 405, 326, 44);
    lblDASClockUptimeTitle.setColor(touchgfx::Color::getColorFromRGB(200, 200, 200));
    lblDASClockUptimeTitle.setLinespacing(0);
    lblDASClockUptimeTitle.setTypedText(touchgfx::TypedText(T___SINGLEUSE_K6AT));

    lblClockUptime.setPosition(367, 405, 184, 44);
    lblClockUptime.setColor(touchgfx::Color::getColorFromRGB(200, 200, 200));
    lblClockUptime.setLinespacing(0);
    Unicode::snprintf(lblClockUptimeBuffer, LBLCLOCKUPTIME_SIZE, "%s", touchgfx::TypedText(T___SINGLEUSE_XAJB).getText());
    lblClockUptime.setWildcard(lblClockUptimeBuffer);
    lblClockUptime.setTypedText(touchgfx::TypedText(T___SINGLEUSE_5L4A));

    lblDASClockTempTitle_0.setPosition(32, 458, 399, 44);
    lblDASClockTempTitle_0.setColor(touchgfx::Color::getColorFromRGB(200, 200, 200));
    lblDASClockTempTitle_0.setLinespacing(0);
    lblDASClockTempTitle_0.setTypedText(touchgfx::TypedText(T___SINGLEUSE_AR9N));

    lblClocktemp_0.setPosition(446, 458, 184, 44);
    lblClocktemp_0.setColor(touchgfx::Color::getColorFromRGB(200, 200, 200));
    lblClocktemp_0.setLinespacing(0);
    Unicode::snprintf(lblClocktemp_0Buffer, LBLCLOCKTEMP_0_SIZE, "%s", touchgfx::TypedText(T___SINGLEUSE_1E1R).getText());
    lblClocktemp_0.setWildcard(lblClocktemp_0Buffer);
    lblClocktemp_0.setTypedText(touchgfx::TypedText(T___SINGLEUSE_Q4R5));

    lblDASClockTempTitle_1.setPosition(32, 502, 399, 44);
    lblDASClockTempTitle_1.setColor(touchgfx::Color::getColorFromRGB(200, 200, 200));
    lblDASClockTempTitle_1.setLinespacing(0);
    lblDASClockTempTitle_1.setTypedText(touchgfx::TypedText(T___SINGLEUSE_A8ML));

    lblClocktemp_1.setPosition(446, 502, 184, 44);
    lblClocktemp_1.setColor(touchgfx::Color::getColorFromRGB(200, 200, 200));
    lblClocktemp_1.setLinespacing(0);
    Unicode::snprintf(lblClocktemp_1Buffer, LBLCLOCKTEMP_1_SIZE, "%s", touchgfx::TypedText(T___SINGLEUSE_9ZXU).getText());
    lblClocktemp_1.setWildcard(lblClocktemp_1Buffer);
    lblClocktemp_1.setTypedText(touchgfx::TypedText(T___SINGLEUSE_JVYW));

    lblClocktemp_2.setPosition(446, 546, 184, 44);
    lblClocktemp_2.setColor(touchgfx::Color::getColorFromRGB(200, 200, 200));
    lblClocktemp_2.setLinespacing(0);
    Unicode::snprintf(lblClocktemp_2Buffer, LBLCLOCKTEMP_2_SIZE, "%s", touchgfx::TypedText(T___SINGLEUSE_1FFP).getText());
    lblClocktemp_2.setWildcard(lblClocktemp_2Buffer);
    lblClocktemp_2.setTypedText(touchgfx::TypedText(T___SINGLEUSE_GT75));

    lblDASClockCurrentTitle_0.setPosition(28, 603, 399, 44);
    lblDASClockCurrentTitle_0.setColor(touchgfx::Color::getColorFromRGB(200, 200, 200));
    lblDASClockCurrentTitle_0.setLinespacing(0);
    lblDASClockCurrentTitle_0.setTypedText(touchgfx::TypedText(T___SINGLEUSE_PNNL));

    lblClockCurrent_0.setPosition(442, 603, 184, 44);
    lblClockCurrent_0.setColor(touchgfx::Color::getColorFromRGB(200, 200, 200));
    lblClockCurrent_0.setLinespacing(0);
    Unicode::snprintf(lblClockCurrent_0Buffer, LBLCLOCKCURRENT_0_SIZE, "%s", touchgfx::TypedText(T___SINGLEUSE_S5AG).getText());
    lblClockCurrent_0.setWildcard(lblClockCurrent_0Buffer);
    lblClockCurrent_0.setTypedText(touchgfx::TypedText(T___SINGLEUSE_8J5N));

    lblDASClockCurrentTitle_1.setPosition(28, 647, 399, 44);
    lblDASClockCurrentTitle_1.setColor(touchgfx::Color::getColorFromRGB(200, 200, 200));
    lblDASClockCurrentTitle_1.setLinespacing(0);
    lblDASClockCurrentTitle_1.setTypedText(touchgfx::TypedText(T___SINGLEUSE_FST6));

    lblClockCurrent_1.setPosition(442, 647, 184, 44);
    lblClockCurrent_1.setColor(touchgfx::Color::getColorFromRGB(200, 200, 200));
    lblClockCurrent_1.setLinespacing(0);
    Unicode::snprintf(lblClockCurrent_1Buffer, LBLCLOCKCURRENT_1_SIZE, "%s", touchgfx::TypedText(T___SINGLEUSE_LWCL).getText());
    lblClockCurrent_1.setWildcard(lblClockCurrent_1Buffer);
    lblClockCurrent_1.setTypedText(touchgfx::TypedText(T___SINGLEUSE_8T1B));

    lblDASClockCurrentTitle_2.setPosition(28, 691, 399, 44);
    lblDASClockCurrentTitle_2.setColor(touchgfx::Color::getColorFromRGB(200, 200, 200));
    lblDASClockCurrentTitle_2.setLinespacing(0);
    lblDASClockCurrentTitle_2.setTypedText(touchgfx::TypedText(T___SINGLEUSE_3OH6));

    lblDASClockTempTitle_2.setPosition(32, 546, 399, 44);
    lblDASClockTempTitle_2.setColor(touchgfx::Color::getColorFromRGB(200, 200, 200));
    lblDASClockTempTitle_2.setLinespacing(0);
    lblDASClockTempTitle_2.setTypedText(touchgfx::TypedText(T___SINGLEUSE_6WEV));

    lblClockCurrent_2.setPosition(442, 691, 184, 44);
    lblClockCurrent_2.setColor(touchgfx::Color::getColorFromRGB(200, 200, 200));
    lblClockCurrent_2.setLinespacing(0);
    Unicode::snprintf(lblClockCurrent_2Buffer, LBLCLOCKCURRENT_2_SIZE, "%s", touchgfx::TypedText(T___SINGLEUSE_VBNA).getText());
    lblClockCurrent_2.setWildcard(lblClockCurrent_2Buffer);
    lblClockCurrent_2.setTypedText(touchgfx::TypedText(T___SINGLEUSE_9LCW));

    lblKarunaTitle.setPosition(15, 161, 294, 44);
    lblKarunaTitle.setColor(touchgfx::Color::getColorFromRGB(200, 200, 200));
    lblKarunaTitle.setLinespacing(0);
    lblKarunaTitle.setTypedText(touchgfx::TypedText(T___SINGLEUSE_0LDD));

    lblDASClockTitle.setPosition(15, 311, 294, 44);
    lblDASClockTitle.setColor(touchgfx::Color::getColorFromRGB(200, 200, 200));
    lblDASClockTitle.setLinespacing(0);
    lblDASClockTitle.setTypedText(touchgfx::TypedText(T___SINGLEUSE_YROX));

    lblDASClockSupplyVoltageTitle.setPosition(28, 743, 399, 44);
    lblDASClockSupplyVoltageTitle.setColor(touchgfx::Color::getColorFromRGB(200, 200, 200));
    lblDASClockSupplyVoltageTitle.setLinespacing(0);
    lblDASClockSupplyVoltageTitle.setTypedText(touchgfx::TypedText(T___SINGLEUSE_AB6H));

    lblDASClockSupplyVoltage.setPosition(442, 743, 184, 44);
    lblDASClockSupplyVoltage.setColor(touchgfx::Color::getColorFromRGB(200, 200, 200));
    lblDASClockSupplyVoltage.setLinespacing(0);
    Unicode::snprintf(lblDASClockSupplyVoltageBuffer, LBLDASCLOCKSUPPLYVOLTAGE_SIZE, "%s", touchgfx::TypedText(T___SINGLEUSE_LCRT).getText());
    lblDASClockSupplyVoltage.setWildcard(lblDASClockSupplyVoltageBuffer);
    lblDASClockSupplyVoltage.setTypedText(touchgfx::TypedText(T___SINGLEUSE_OEE2));

    line4.setPosition(45, 451, 920, 15);
    line4Painter.setColor(touchgfx::Color::getColorFromRGB(32, 32, 32));
    line4.setPainter(line4Painter);
    line4.setStart(0, 0);
    line4.setEnd(920, 1);
    line4.setLineWidth(2);
    line4.setLineEndingStyle(touchgfx::Line::BUTT_CAP_ENDING);

    line2.setPosition(45, 736, 920, 15);
    line2Painter.setColor(touchgfx::Color::getColorFromRGB(32, 32, 32));
    line2.setPainter(line2Painter);
    line2.setStart(0, 0);
    line2.setEnd(920, 1);
    line2.setLineWidth(2);
    line2.setLineEndingStyle(touchgfx::Line::BUTT_CAP_ENDING);

    line1.setPosition(45, 305, 920, 15);
    line1Painter.setColor(touchgfx::Color::getColorFromRGB(64, 64, 64));
    line1.setPainter(line1Painter);
    line1.setStart(0, 0);
    line1.setEnd(920, 1);
    line1.setLineWidth(2);
    line1.setLineEndingStyle(touchgfx::Line::BUTT_CAP_ENDING);

    lblGUITitle.setPosition(15, 13, 294, 44);
    lblGUITitle.setColor(touchgfx::Color::getColorFromRGB(200, 200, 200));
    lblGUITitle.setLinespacing(0);
    lblGUITitle.setTypedText(touchgfx::TypedText(T___SINGLEUSE_C8R6));

    lblGUIFwVerTitle.setPosition(32, 57, 295, 44);
    lblGUIFwVerTitle.setColor(touchgfx::Color::getColorFromRGB(200, 200, 200));
    lblGUIFwVerTitle.setLinespacing(0);
    lblGUIFwVerTitle.setTypedText(touchgfx::TypedText(T___SINGLEUSE_1OG4));

    lblGUIFwVersion.setPosition(387, 63, 596, 33);
    lblGUIFwVersion.setColor(touchgfx::Color::getColorFromRGB(200, 200, 200));
    lblGUIFwVersion.setLinespacing(0);
    lblGUIFwVersion.setAlpha(100);
    lblGUIFwVersionBuffer[0] = 0;
    lblGUIFwVersion.setWildcard(lblGUIFwVersionBuffer);
    lblGUIFwVersion.setTypedText(touchgfx::TypedText(T___SINGLEUSE_Q6L7));

    line0.setPosition(45, 157, 920, 15);
    line0Painter.setColor(touchgfx::Color::getColorFromRGB(64, 64, 64));
    line0.setPainter(line0Painter);
    line0.setStart(0, 0);
    line0.setEnd(920, 1);
    line0.setLineWidth(2);
    line0.setLineEndingStyle(touchgfx::Line::BUTT_CAP_ENDING);

    lblKarunaFwVerTitle.setPosition(32, 209, 306, 44);
    lblKarunaFwVerTitle.setColor(touchgfx::Color::getColorFromRGB(200, 200, 200));
    lblKarunaFwVerTitle.setLinespacing(0);
    lblKarunaFwVerTitle.setTypedText(touchgfx::TypedText(T___SINGLEUSE_G1LA));

    lblDASFwVerTitle.setPosition(32, 359, 345, 44);
    lblDASFwVerTitle.setColor(touchgfx::Color::getColorFromRGB(200, 200, 200));
    lblDASFwVerTitle.setLinespacing(0);
    lblDASFwVerTitle.setTypedText(touchgfx::TypedText(T___SINGLEUSE_T8WL));

    lblKarunaFwVersion.setPosition(387, 215, 596, 33);
    lblKarunaFwVersion.setColor(touchgfx::Color::getColorFromRGB(200, 200, 200));
    lblKarunaFwVersion.setLinespacing(0);
    lblKarunaFwVersion.setAlpha(100);
    lblKarunaFwVersionBuffer[0] = 0;
    lblKarunaFwVersion.setWildcard(lblKarunaFwVersionBuffer);
    lblKarunaFwVersion.setTypedText(touchgfx::TypedText(T___SINGLEUSE_AT65));

    lblDASClockFwVersion.setPosition(387, 365, 596, 33);
    lblDASClockFwVersion.setColor(touchgfx::Color::getColorFromRGB(200, 200, 200));
    lblDASClockFwVersion.setLinespacing(0);
    lblDASClockFwVersion.setAlpha(100);
    lblDASClockFwVersionBuffer[0] = 0;
    lblDASClockFwVersion.setWildcard(lblDASClockFwVersionBuffer);
    lblDASClockFwVersion.setTypedText(touchgfx::TypedText(T___SINGLEUSE_Z6G5));

    btnFactoryReset.setBoxWithBorderPosition(0, 0, 974, 90);
    btnFactoryReset.setBorderSize(1);
    btnFactoryReset.setBoxWithBorderColors(touchgfx::Color::getColorFromRGB(0, 0, 0), touchgfx::Color::getColorFromRGB(32, 32, 32), touchgfx::Color::getColorFromRGB(100, 100, 100), touchgfx::Color::getColorFromRGB(100, 100, 100));
    btnFactoryReset.setText(TypedText(T___SINGLEUSE_GKKS));
    btnFactoryReset.setTextPosition(-17, 20, 974, 90);
    btnFactoryReset.setTextColors(touchgfx::Color::getColorFromRGB(150, 118, 73), touchgfx::Color::getColorFromRGB(64, 64, 64));
    btnFactoryReset.setPosition(28, 933, 974, 90);
    btnFactoryReset.setAction(flexButtonCallback);

    btnSoftReset.setBoxWithBorderPosition(0, 0, 974, 90);
    btnSoftReset.setBorderSize(1);
    btnSoftReset.setBoxWithBorderColors(touchgfx::Color::getColorFromRGB(0, 0, 0), touchgfx::Color::getColorFromRGB(32, 32, 32), touchgfx::Color::getColorFromRGB(100, 100, 100), touchgfx::Color::getColorFromRGB(100, 100, 100));
    btnSoftReset.setText(TypedText(T___SINGLEUSE_T381));
    btnSoftReset.setTextPosition(-20, 20, 974, 90);
    btnSoftReset.setTextColors(touchgfx::Color::getColorFromRGB(150, 118, 73), touchgfx::Color::getColorFromRGB(64, 64, 64));
    btnSoftReset.setPosition(28, 829, 974, 90);
    btnSoftReset.setAction(flexButtonCallback);

    line2_1.setPosition(45, 1049, 920, 15);
    line2_1Painter.setColor(touchgfx::Color::getColorFromRGB(64, 64, 64));
    line2_1.setPainter(line2_1Painter);
    line2_1.setStart(0, 0);
    line2_1.setEnd(920, 1);
    line2_1.setLineWidth(2);
    line2_1.setLineEndingStyle(touchgfx::Line::BUTT_CAP_ENDING);

    lblBootUpCountTitle.setXY(32, 105);
    lblBootUpCountTitle.setColor(touchgfx::Color::getColorFromRGB(200, 200, 200));
    lblBootUpCountTitle.setLinespacing(0);
    lblBootUpCountTitle.setTypedText(touchgfx::TypedText(T___SINGLEUSE_3GMJ));

    lblBootupCnt.setPosition(377, 105, 174, 44);
    lblBootupCnt.setColor(touchgfx::Color::getColorFromRGB(200, 200, 200));
    lblBootupCnt.setLinespacing(0);
    Unicode::snprintf(lblBootupCntBuffer, LBLBOOTUPCNT_SIZE, "%s", touchgfx::TypedText(T___SINGLEUSE_Z9BW).getText());
    lblBootupCnt.setWildcard(lblBootupCntBuffer);
    lblBootupCnt.setTypedText(touchgfx::TypedText(T___SINGLEUSE_KTHD));

    lblDasClocUartErrorTitle.setXY(551, 409);
    lblDasClocUartErrorTitle.setColor(touchgfx::Color::getColorFromRGB(200, 200, 200));
    lblDasClocUartErrorTitle.setLinespacing(0);
    lblDasClocUartErrorTitle.setTypedText(touchgfx::TypedText(T___SINGLEUSE_PGTS));

    DasClockErrorCnt.setPosition(909, 408, 93, 44);
    DasClockErrorCnt.setColor(touchgfx::Color::getColorFromRGB(200, 200, 200));
    DasClockErrorCnt.setLinespacing(0);
    Unicode::snprintf(DasClockErrorCntBuffer, DASCLOCKERRORCNT_SIZE, "%s", touchgfx::TypedText(T___SINGLEUSE_ILXF).getText());
    DasClockErrorCnt.setWildcard(DasClockErrorCntBuffer);
    DasClockErrorCnt.setTypedText(touchgfx::TypedText(T___SINGLEUSE_CVH5));

    lblBusUartErrorCntTitle.setXY(551, 105);
    lblBusUartErrorCntTitle.setColor(touchgfx::Color::getColorFromRGB(200, 200, 200));
    lblBusUartErrorCntTitle.setLinespacing(0);
    lblBusUartErrorCntTitle.setTypedText(touchgfx::TypedText(T___SINGLEUSE_W2OM));

    lblBusUartErrorCnt.setPosition(909, 105, 93, 44);
    lblBusUartErrorCnt.setColor(touchgfx::Color::getColorFromRGB(200, 200, 200));
    lblBusUartErrorCnt.setLinespacing(0);
    Unicode::snprintf(lblBusUartErrorCntBuffer, LBLBUSUARTERRORCNT_SIZE, "%s", touchgfx::TypedText(T___SINGLEUSE_WMAQ).getText());
    lblBusUartErrorCnt.setWildcard(lblBusUartErrorCntBuffer);
    lblBusUartErrorCnt.setTypedText(touchgfx::TypedText(T___SINGLEUSE_3TGM));

    lblKarunaUptimeCntTitle.setXY(551, 259);
    lblKarunaUptimeCntTitle.setColor(touchgfx::Color::getColorFromRGB(200, 200, 200));
    lblKarunaUptimeCntTitle.setLinespacing(0);
    lblKarunaUptimeCntTitle.setTypedText(touchgfx::TypedText(T___SINGLEUSE_KPYH));

    lblKarunaUartErrorCnt.setPosition(909, 259, 93, 44);
    lblKarunaUartErrorCnt.setColor(touchgfx::Color::getColorFromRGB(200, 200, 200));
    lblKarunaUartErrorCnt.setLinespacing(0);
    Unicode::snprintf(lblKarunaUartErrorCntBuffer, LBLKARUNAUARTERRORCNT_SIZE, "%s", touchgfx::TypedText(T___SINGLEUSE_6BR6).getText());
    lblKarunaUartErrorCnt.setWildcard(lblKarunaUartErrorCntBuffer);
    lblKarunaUartErrorCnt.setTypedText(touchgfx::TypedText(T___SINGLEUSE_9QB9));

    line1_1.setPosition(45, 798, 920, 15);
    line1_1Painter.setColor(touchgfx::Color::getColorFromRGB(64, 64, 64));
    line1_1.setPainter(line1_1Painter);
    line1_1.setStart(0, 0);
    line1_1.setEnd(920, 1);
    line1_1.setLineWidth(2);
    line1_1.setLineEndingStyle(touchgfx::Line::BUTT_CAP_ENDING);

    line1_1_1.setPosition(45, 1255, 920, 15);
    line1_1_1Painter.setColor(touchgfx::Color::getColorFromRGB(64, 64, 64));
    line1_1_1.setPainter(line1_1_1Painter);
    line1_1_1.setStart(0, 0);
    line1_1_1.setEnd(920, 1);
    line1_1_1.setLineWidth(2);
    line1_1_1.setLineEndingStyle(touchgfx::Line::BUTT_CAP_ENDING);

    add(lblKarunaUptimeTitle);
    add(lblKarunaUptime);
    add(lblDASClockUptimeTitle);
    add(lblClockUptime);
    add(lblDASClockTempTitle_0);
    add(lblClocktemp_0);
    add(lblDASClockTempTitle_1);
    add(lblClocktemp_1);
    add(lblClocktemp_2);
    add(lblDASClockCurrentTitle_0);
    add(lblClockCurrent_0);
    add(lblDASClockCurrentTitle_1);
    add(lblClockCurrent_1);
    add(lblDASClockCurrentTitle_2);
    add(lblDASClockTempTitle_2);
    add(lblClockCurrent_2);
    add(lblKarunaTitle);
    add(lblDASClockTitle);
    add(lblDASClockSupplyVoltageTitle);
    add(lblDASClockSupplyVoltage);
    add(line4);
    add(line2);
    add(line1);
    add(lblGUITitle);
    add(lblGUIFwVerTitle);
    add(lblGUIFwVersion);
    add(line0);
    add(lblKarunaFwVerTitle);
    add(lblDASFwVerTitle);
    add(lblKarunaFwVersion);
    add(lblDASClockFwVersion);
    add(btnFactoryReset);
    add(btnSoftReset);
    add(line2_1);
    add(lblBootUpCountTitle);
    add(lblBootupCnt);
    add(lblDasClocUartErrorTitle);
    add(DasClockErrorCnt);
    add(lblBusUartErrorCntTitle);
    add(lblBusUartErrorCnt);
    add(lblKarunaUptimeCntTitle);
    add(lblKarunaUartErrorCnt);
    add(line1_1);
    add(line1_1_1);
}

void ServiceContainerBase::initialize()
{

}

void ServiceContainerBase::flexButtonCallbackHandler(const touchgfx::AbstractButtonContainer& src)
{
    if (&src == &btnFactoryReset)
    {
        //FactoryReset
        //When btnFactoryReset clicked call virtual function
        //Call OnClickFactoryReset
        OnClickFactoryReset();
    }
    else if (&src == &btnSoftReset)
    {
        //SoftReset
        //When btnSoftReset clicked call virtual function
        //Call OnClickSoftReset
        OnClickSoftReset();
    }
}
