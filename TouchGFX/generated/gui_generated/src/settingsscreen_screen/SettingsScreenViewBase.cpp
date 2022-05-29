/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#include <gui_generated/settingsscreen_screen/SettingsScreenViewBase.hpp>
#include <touchgfx/Color.hpp>
#include <BitmapDatabase.hpp>
#include <texts/TextKeysAndLanguages.hpp>
#include <touchgfx/canvas_widget_renderer/CanvasWidgetRenderer.hpp>


SettingsScreenViewBase::SettingsScreenViewBase() :
    buttonCallback(this, &SettingsScreenViewBase::buttonCallbackHandler),
    flexButtonCallback(this, &SettingsScreenViewBase::flexButtonCallbackHandler)
{

    touchgfx::CanvasWidgetRenderer::setupBuffer(canvasBuffer, CANVAS_BUFFER_SIZE);

    __background.setPosition(0, 0, 1024, 600);
    __background.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));

    box1.setPosition(0, 0, 1024, 600);
    box1.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));

    btnDisplay.setBoxWithBorderPosition(0, 0, 500, 90);
    btnDisplay.setBorderSize(1);
    btnDisplay.setBoxWithBorderColors(touchgfx::Color::getColorFromRGB(0, 0, 0), touchgfx::Color::getColorFromRGB(32, 32, 32), touchgfx::Color::getColorFromRGB(100, 100, 100), touchgfx::Color::getColorFromRGB(100, 100, 100));
    btnDisplay.setBitmaps(Bitmap(BITMAP_GOBACK_ID), Bitmap(BITMAP_GOBACK_ID));
    btnDisplay.setBitmapXY(20, 5);
    btnDisplay.setText(TypedText(T___SINGLEUSE_XWX2));
    btnDisplay.setTextPosition(-20, 20, 500, 90);
    btnDisplay.setTextColors(touchgfx::Color::getColorFromRGB(150, 118, 73), touchgfx::Color::getColorFromRGB(64, 64, 64));
    btnDisplay.setPosition(5, 505, 500, 90);
    btnDisplay.setAction(flexButtonCallback);

    boxWithBorder1.setPosition(5, 100, 1014, 400);
    boxWithBorder1.setColor(touchgfx::Color::getColorFromRGB(25, 25, 25));
    boxWithBorder1.setBorderColor(touchgfx::Color::getColorFromRGB(100, 100, 100));
    boxWithBorder1.setBorderSize(1);

    rdbtnEnableAll.setXY(33, 122);
    rdbtnEnableAll.setBitmaps(touchgfx::Bitmap(BITMAP_OFF_44X44_ID), touchgfx::Bitmap(BITMAP_ON_44X44_ID), touchgfx::Bitmap(BITMAP_ON_44X44_ID), touchgfx::Bitmap(BITMAP_OFF_44X44_ID));
    rdbtnEnableAll.setSelected(true);
    rdbtnEnableAll.setDeselectionEnabled(false);

    textArea1.setPosition(0, 10, 1024, 80);
    textArea1.setColor(touchgfx::Color::getColorFromRGB(128, 128, 128));
    textArea1.setLinespacing(0);
    textArea1.setTypedText(touchgfx::TypedText(T___SINGLEUSE_YPEX));

    textArea2.setPosition(88, 124, 931, 40);
    textArea2.setColor(touchgfx::Color::getColorFromRGB(200, 200, 200));
    textArea2.setLinespacing(0);
    textArea2.setTypedText(touchgfx::TypedText(T___SINGLEUSE_AGOP));

    textArea2_1.setPosition(88, 186, 931, 40);
    textArea2_1.setColor(touchgfx::Color::getColorFromRGB(200, 200, 200));
    textArea2_1.setLinespacing(0);
    textArea2_1.setTypedText(touchgfx::TypedText(T___SINGLEUSE_9IH2));

    chbxMCLKON.setXY(33, 281);
    chbxMCLKON.setBitmaps(touchgfx::Bitmap(BITMAP_ON_44X44_ID), touchgfx::Bitmap(BITMAP_OFF_44X44_ID));

    rdbtnEnableSelected.setXY(33, 184);
    rdbtnEnableSelected.setBitmaps(touchgfx::Bitmap(BITMAP_OFF_44X44_ID), touchgfx::Bitmap(BITMAP_ON_44X44_ID), touchgfx::Bitmap(BITMAP_ON_44X44_ID), touchgfx::Bitmap(BITMAP_OFF_44X44_ID));
    rdbtnEnableSelected.setSelected(false);
    rdbtnEnableSelected.setDeselectionEnabled(false);

    textArea2_1_1.setPosition(88, 283, 931, 40);
    textArea2_1_1.setColor(touchgfx::Color::getColorFromRGB(200, 200, 200));
    textArea2_1_1.setLinespacing(0);
    textArea2_1_1.setTypedText(touchgfx::TypedText(T___SINGLEUSE_4E2A));

    line1.setPosition(64, 253, 920, 15);
    line1Painter.setColor(touchgfx::Color::getColorFromRGB(64, 64, 64));
    line1.setPainter(line1Painter);
    line1.setStart(0, 0);
    line1.setEnd(920, 1);
    line1.setLineWidth(2);
    line1.setLineEndingStyle(touchgfx::Line::BUTT_CAP_ENDING);

    line1_1.setPosition(64, 351, 920, 15);
    line1_1Painter.setColor(touchgfx::Color::getColorFromRGB(64, 64, 64));
    line1_1.setPainter(line1_1Painter);
    line1_1.setStart(0, 0);
    line1_1.setEnd(920, 1);
    line1_1.setLineWidth(2);
    line1_1.setLineEndingStyle(touchgfx::Line::BUTT_CAP_ENDING);

    textArea2_1_1_1.setPosition(40, 384, 295, 44);
    textArea2_1_1_1.setColor(touchgfx::Color::getColorFromRGB(200, 200, 200));
    textArea2_1_1_1.setLinespacing(0);
    textArea2_1_1_1.setTypedText(touchgfx::TypedText(T___SINGLEUSE_9C3M));

    lblKarunaUptime.setPosition(344, 384, 137, 44);
    lblKarunaUptime.setColor(touchgfx::Color::getColorFromRGB(200, 200, 200));
    lblKarunaUptime.setLinespacing(0);
    Unicode::snprintf(lblKarunaUptimeBuffer, LBLKARUNAUPTIME_SIZE, "%s", touchgfx::TypedText(T___SINGLEUSE_P0TG).getText());
    lblKarunaUptime.setWildcard(lblKarunaUptimeBuffer);
    lblKarunaUptime.setTypedText(touchgfx::TypedText(T___SINGLEUSE_542M));

    add(__background);
    add(box1);
    add(btnDisplay);
    add(boxWithBorder1);
    add(rdbtnEnableAll);
    add(textArea1);
    add(textArea2);
    add(textArea2_1);
    add(chbxMCLKON);
    add(rdbtnEnableSelected);
    add(textArea2_1_1);
    add(line1);
    add(line1_1);
    add(textArea2_1_1_1);
    add(lblKarunaUptime);
    radioButtonGroup1.add(rdbtnEnableAll);
    radioButtonGroup1.add(rdbtnEnableSelected);
}

void SettingsScreenViewBase::setupScreen()
{

}

void SettingsScreenViewBase::buttonCallbackHandler(const touchgfx::AbstractButton& src)
{
}

void SettingsScreenViewBase::flexButtonCallbackHandler(const touchgfx::AbstractButtonContainer& src)
{
    if (&src == &btnDisplay)
    {
        //ShowMain
        //When btnDisplay clicked change screen to Main
        //Go to Main with screen transition towards West
        application().gotoMainScreenSlideTransitionWest();
    }
}
