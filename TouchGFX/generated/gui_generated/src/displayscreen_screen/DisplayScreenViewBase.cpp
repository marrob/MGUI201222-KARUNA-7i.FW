/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#include <gui_generated/displayscreen_screen/DisplayScreenViewBase.hpp>
#include <touchgfx/Color.hpp>
#include <BitmapDatabase.hpp>
#include <texts/TextKeysAndLanguages.hpp>
#include <touchgfx/canvas_widget_renderer/CanvasWidgetRenderer.hpp>


DisplayScreenViewBase::DisplayScreenViewBase() :
    flexButtonCallback(this, &DisplayScreenViewBase::flexButtonCallbackHandler),
    sliderValueChangedCallback(this, &DisplayScreenViewBase::sliderValueChangedCallbackHandler),
    radioButtonSelectedCallback(this, &DisplayScreenViewBase::radioButtonSelectedCallbackHandler)
{

    touchgfx::CanvasWidgetRenderer::setupBuffer(canvasBuffer, CANVAS_BUFFER_SIZE);

    __background.setPosition(0, 0, 1024, 600);
    __background.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));

    box1.setPosition(0, -9, 1024, 600);
    box1.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));

    boxWithBorder1.setPosition(5, 100, 1014, 400);
    boxWithBorder1.setColor(touchgfx::Color::getColorFromRGB(25, 25, 25));
    boxWithBorder1.setBorderColor(touchgfx::Color::getColorFromRGB(100, 100, 100));
    boxWithBorder1.setBorderSize(1);

    btnBack.setBoxWithBorderPosition(0, 0, 500, 90);
    btnBack.setBorderSize(1);
    btnBack.setBoxWithBorderColors(touchgfx::Color::getColorFromRGB(0, 0, 0), touchgfx::Color::getColorFromRGB(32, 32, 32), touchgfx::Color::getColorFromRGB(100, 100, 100), touchgfx::Color::getColorFromRGB(100, 100, 100));
    btnBack.setBitmaps(Bitmap(BITMAP_GOBACK_ID), Bitmap(BITMAP_GOBACK_ID));
    btnBack.setBitmapXY(20, 5);
    btnBack.setText(TypedText(T___SINGLEUSE_GIYT));
    btnBack.setTextPosition(-20, 20, 500, 90);
    btnBack.setTextColors(touchgfx::Color::getColorFromRGB(150, 118, 73), touchgfx::Color::getColorFromRGB(64, 64, 64));
    btnBack.setPosition(5, 505, 500, 90);
    btnBack.setAction(flexButtonCallback);

    textArea1.setPosition(0, 10, 1024, 80);
    textArea1.setColor(touchgfx::Color::getColorFromRGB(128, 128, 128));
    textArea1.setLinespacing(0);
    textArea1.setTypedText(touchgfx::TypedText(T___SINGLEUSE_6WFO));

    sldrBrightnes.setXY(25, 433);
    sldrBrightnes.setBitmaps(touchgfx::Bitmap(BITMAP_SLIDER_930_ID), touchgfx::Bitmap(BITMAP_SLIDER_930_ID), touchgfx::Bitmap(BITMAP_ON_44X44_ID));
    sldrBrightnes.setupHorizontalSlider(20, 16, 0, 0, 930);
    sldrBrightnes.setValueRange(0, 100);
    sldrBrightnes.setValue(100);
    sldrBrightnes.setNewValueCallback(sliderValueChangedCallback);

    btnDisplayOff.setBoxWithBorderPosition(0, 0, 500, 90);
    btnDisplayOff.setBorderSize(1);
    btnDisplayOff.setBoxWithBorderColors(touchgfx::Color::getColorFromRGB(0, 0, 0), touchgfx::Color::getColorFromRGB(32, 32, 32), touchgfx::Color::getColorFromRGB(100, 100, 100), touchgfx::Color::getColorFromRGB(100, 100, 100));
    btnDisplayOff.setBitmaps(Bitmap(BITMAP_OFFCORE_72X72_ID), Bitmap(BITMAP_OFFCORE_72X72_ID));
    btnDisplayOff.setBitmapXY(20, 9);
    btnDisplayOff.setText(TypedText(T___SINGLEUSE_BX5F));
    btnDisplayOff.setTextPosition(-20, 20, 500, 90);
    btnDisplayOff.setTextColors(touchgfx::Color::getColorFromRGB(150, 118, 73), touchgfx::Color::getColorFromRGB(64, 64, 64));
    btnDisplayOff.setPosition(519, 505, 500, 90);
    btnDisplayOff.setAction(flexButtonCallback);

    textArea2_1.setPosition(25, 106, 931, 40);
    textArea2_1.setColor(touchgfx::Color::getColorFromRGB(200, 200, 200));
    textArea2_1.setLinespacing(0);
    textArea2_1.setTypedText(touchgfx::TypedText(T___SINGLEUSE_L22C));

    container1.setPosition(25, 146, 974, 259);

    rdbtnSet0.setXY(13, 13);
    rdbtnSet0.setBitmaps(touchgfx::Bitmap(BITMAP_OFF_44X44_ID), touchgfx::Bitmap(BITMAP_ON_44X44_ID), touchgfx::Bitmap(BITMAP_ON_44X44_ID), touchgfx::Bitmap(BITMAP_OFF_44X44_ID));
    rdbtnSet0.setSelected(true);
    rdbtnSet0.setDeselectionEnabled(false);
    container1.add(rdbtnSet0);

    textArea2.setPosition(68, 15, 267, 42);
    textArea2.setColor(touchgfx::Color::getColorFromRGB(200, 200, 200));
    textArea2.setLinespacing(0);
    textArea2.setTypedText(touchgfx::TypedText(T___SINGLEUSE_7ZX9));
    container1.add(textArea2);

    rdbtnSet1.setXY(13, 70);
    rdbtnSet1.setBitmaps(touchgfx::Bitmap(BITMAP_OFF_44X44_ID), touchgfx::Bitmap(BITMAP_ON_44X44_ID), touchgfx::Bitmap(BITMAP_ON_44X44_ID), touchgfx::Bitmap(BITMAP_OFF_44X44_ID));
    rdbtnSet1.setSelected(false);
    rdbtnSet1.setDeselectionEnabled(false);
    container1.add(rdbtnSet1);

    textArea2_2.setPosition(68, 70, 267, 42);
    textArea2_2.setColor(touchgfx::Color::getColorFromRGB(200, 200, 200));
    textArea2_2.setLinespacing(0);
    textArea2_2.setTypedText(touchgfx::TypedText(T___SINGLEUSE_HAQR));
    container1.add(textArea2_2);

    rdbtnSet5.setXY(13, 125);
    rdbtnSet5.setBitmaps(touchgfx::Bitmap(BITMAP_OFF_44X44_ID), touchgfx::Bitmap(BITMAP_ON_44X44_ID), touchgfx::Bitmap(BITMAP_ON_44X44_ID), touchgfx::Bitmap(BITMAP_OFF_44X44_ID));
    rdbtnSet5.setSelected(false);
    rdbtnSet5.setDeselectionEnabled(false);
    container1.add(rdbtnSet5);

    textArea2_3.setPosition(68, 125, 267, 42);
    textArea2_3.setColor(touchgfx::Color::getColorFromRGB(200, 200, 200));
    textArea2_3.setLinespacing(0);
    textArea2_3.setTypedText(touchgfx::TypedText(T___SINGLEUSE_KFWO));
    container1.add(textArea2_3);

    rdbtnSet10.setXY(13, 180);
    rdbtnSet10.setBitmaps(touchgfx::Bitmap(BITMAP_OFF_44X44_ID), touchgfx::Bitmap(BITMAP_ON_44X44_ID), touchgfx::Bitmap(BITMAP_ON_44X44_ID), touchgfx::Bitmap(BITMAP_OFF_44X44_ID));
    rdbtnSet10.setSelected(false);
    rdbtnSet10.setDeselectionEnabled(false);
    container1.add(rdbtnSet10);

    textArea2_3_1.setPosition(68, 180, 267, 42);
    textArea2_3_1.setColor(touchgfx::Color::getColorFromRGB(200, 200, 200));
    textArea2_3_1.setLinespacing(0);
    textArea2_3_1.setTypedText(touchgfx::TypedText(T___SINGLEUSE_7E5B));
    container1.add(textArea2_3_1);

    rdbtnSet30.setXY(259, 69);
    rdbtnSet30.setBitmaps(touchgfx::Bitmap(BITMAP_OFF_44X44_ID), touchgfx::Bitmap(BITMAP_ON_44X44_ID), touchgfx::Bitmap(BITMAP_ON_44X44_ID), touchgfx::Bitmap(BITMAP_OFF_44X44_ID));
    rdbtnSet30.setSelected(false);
    rdbtnSet30.setDeselectionEnabled(false);
    container1.add(rdbtnSet30);

    textArea2_3_2.setPosition(314, 69, 267, 42);
    textArea2_3_2.setColor(touchgfx::Color::getColorFromRGB(200, 200, 200));
    textArea2_3_2.setLinespacing(0);
    textArea2_3_2.setTypedText(touchgfx::TypedText(T___SINGLEUSE_J0VM));
    container1.add(textArea2_3_2);

    rdbtnSet60.setXY(259, 124);
    rdbtnSet60.setBitmaps(touchgfx::Bitmap(BITMAP_OFF_44X44_ID), touchgfx::Bitmap(BITMAP_ON_44X44_ID), touchgfx::Bitmap(BITMAP_ON_44X44_ID), touchgfx::Bitmap(BITMAP_OFF_44X44_ID));
    rdbtnSet60.setSelected(false);
    rdbtnSet60.setDeselectionEnabled(false);
    container1.add(rdbtnSet60);

    textArea2_3_3.setPosition(314, 124, 267, 42);
    textArea2_3_3.setColor(touchgfx::Color::getColorFromRGB(200, 200, 200));
    textArea2_3_3.setLinespacing(0);
    textArea2_3_3.setTypedText(touchgfx::TypedText(T___SINGLEUSE_KJC4));
    container1.add(textArea2_3_3);

    rdbtnSet120.setXY(259, 179);
    rdbtnSet120.setBitmaps(touchgfx::Bitmap(BITMAP_OFF_44X44_ID), touchgfx::Bitmap(BITMAP_ON_44X44_ID), touchgfx::Bitmap(BITMAP_ON_44X44_ID), touchgfx::Bitmap(BITMAP_OFF_44X44_ID));
    rdbtnSet120.setSelected(false);
    rdbtnSet120.setDeselectionEnabled(false);
    container1.add(rdbtnSet120);

    textArea2_3_4.setPosition(314, 179, 267, 42);
    textArea2_3_4.setColor(touchgfx::Color::getColorFromRGB(200, 200, 200));
    textArea2_3_4.setLinespacing(0);
    textArea2_3_4.setTypedText(touchgfx::TypedText(T___SINGLEUSE_AQQB));
    container1.add(textArea2_3_4);

    lblBrightness.setPosition(871, 215, 77, 44);
    lblBrightness.setColor(touchgfx::Color::getColorFromRGB(200, 200, 200));
    lblBrightness.setLinespacing(0);
    Unicode::snprintf(lblBrightnessBuffer, LBLBRIGHTNESS_SIZE, "%s", touchgfx::TypedText(T___SINGLEUSE_8FBD).getText());
    lblBrightness.setWildcard(lblBrightnessBuffer);
    lblBrightness.setTypedText(touchgfx::TypedText(T___SINGLEUSE_ONW5));
    container1.add(lblBrightness);

    textArea2_1_1_1.setPosition(734, 215, 144, 44);
    textArea2_1_1_1.setColor(touchgfx::Color::getColorFromRGB(200, 200, 200));
    textArea2_1_1_1.setLinespacing(0);
    textArea2_1_1_1.setTypedText(touchgfx::TypedText(T___SINGLEUSE_FF38));
    container1.add(textArea2_1_1_1);

    lblTimeToOff.setPosition(259, 15, 267, 42);
    lblTimeToOff.setColor(touchgfx::Color::getColorFromRGB(200, 200, 200));
    lblTimeToOff.setLinespacing(0);
    Unicode::snprintf(lblTimeToOffBuffer, LBLTIMETOOFF_SIZE, "%s", touchgfx::TypedText(T___SINGLEUSE_USF5).getText());
    lblTimeToOff.setWildcard(lblTimeToOffBuffer);
    lblTimeToOff.setTypedText(touchgfx::TypedText(T___SINGLEUSE_SC3P));
    container1.add(lblTimeToOff);

    line1.setPosition(60, 409, 920, 15);
    line1Painter.setColor(touchgfx::Color::getColorFromRGB(64, 64, 64));
    line1.setPainter(line1Painter);
    line1.setStart(0, 0);
    line1.setEnd(920, 1);
    line1.setLineWidth(2);
    line1.setLineEndingStyle(touchgfx::Line::BUTT_CAP_ENDING);

    add(__background);
    add(box1);
    add(boxWithBorder1);
    add(btnBack);
    add(textArea1);
    add(sldrBrightnes);
    add(btnDisplayOff);
    add(textArea2_1);
    add(container1);
    add(line1);
    radioButtonGroup1.add(rdbtnSet0);
    radioButtonGroup1.add(rdbtnSet1);
    radioButtonGroup1.add(rdbtnSet5);
    radioButtonGroup1.add(rdbtnSet10);
    radioButtonGroup1.add(rdbtnSet30);
    radioButtonGroup1.add(rdbtnSet60);
    radioButtonGroup1.add(rdbtnSet120);
    radioButtonGroup1.setRadioButtonSelectedHandler(radioButtonSelectedCallback);
}

void DisplayScreenViewBase::setupScreen()
{

}

void DisplayScreenViewBase::flexButtonCallbackHandler(const touchgfx::AbstractButtonContainer& src)
{
    if (&src == &btnBack)
    {
        //ShowMain
        //When btnBack clicked change screen to Main
        //Go to Main with screen transition towards West
        application().gotoMainScreenSlideTransitionWest();
    }
    else if (&src == &btnDisplayOff)
    {
        //ShowScreenoff
        //When btnDisplayOff clicked change screen to OffScreen
        //Go to OffScreen with screen transition towards West
        application().gotoOffScreenScreenSlideTransitionWest();
    }
}

void DisplayScreenViewBase::sliderValueChangedCallbackHandler(const touchgfx::Slider& src, int value)
{
    if (&src == &sldrBrightnes)
    {
        //sldrBrightnesChanged
        //When sldrBrightnes value changed call virtual function
        //Call sldrBrightnesChanged
        sldrBrightnesChanged(value);
    }
}

void DisplayScreenViewBase::radioButtonSelectedCallbackHandler(const touchgfx::AbstractButton& src)
{
    if (&src == &rdbtnSet0)
    {
        //rbtnSelect0OffTmr
        //When rdbtnSet0 selected call virtual function
        //Call rbtnSelect0OffTmr
        rbtnSelect0OffTmr();
    }
    else if (&src == &rdbtnSet1)
    {
        //rbtnSelect1OffTmr
        //When rdbtnSet1 selected call virtual function
        //Call rbtnSelect1OffTmr
        rbtnSelect1OffTmr();
    }
    else if (&src == &rdbtnSet5)
    {
        //rbtnSelect5OffTmr
        //When rdbtnSet5 selected call virtual function
        //Call rbtnSelect5OffTmr
        rbtnSelect5OffTmr();
    }
    else if (&src == &rdbtnSet10)
    {
        //rbtnSelect10OffTmr
        //When rdbtnSet10 selected call virtual function
        //Call rbtnSelect10OffTmr
        rbtnSelect10OffTmr();
    }
    else if (&src == &rdbtnSet30)
    {
        //rbtnSelect30OffTmr
        //When rdbtnSet30 selected call virtual function
        //Call rbtnSelect30OffTmr
        rbtnSelect30OffTmr();
    }
    else if (&src == &rdbtnSet60)
    {
        //rbtnSelect60OffTmr
        //When rdbtnSet60 selected call virtual function
        //Call rbtnSelect60OffTmr
        rbtnSelect60OffTmr();
    }
    else if (&src == &rdbtnSet120)
    {
        //rbtnSelect120OffTmr
        //When rdbtnSet120 selected call virtual function
        //Call rbtnSelect120OffTmr
        rbtnSelect120OffTmr();
    }
}
