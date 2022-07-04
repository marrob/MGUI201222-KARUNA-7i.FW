/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#include <gui_generated/debugscreen_screen/DebugScreenViewBase.hpp>
#include <touchgfx/Color.hpp>
#include <BitmapDatabase.hpp>
#include <texts/TextKeysAndLanguages.hpp>
#include <touchgfx/canvas_widget_renderer/CanvasWidgetRenderer.hpp>


DebugScreenViewBase::DebugScreenViewBase() :
    buttonCallback(this, &DebugScreenViewBase::buttonCallbackHandler),
    flexButtonCallback(this, &DebugScreenViewBase::flexButtonCallbackHandler)
{

    touchgfx::CanvasWidgetRenderer::setupBuffer(canvasBuffer, CANVAS_BUFFER_SIZE);

    __background.setPosition(0, 0, 1024, 600);
    __background.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));

    box1.setPosition(0, 0, 1024, 600);
    box1.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));

    btnBack.setBoxWithBorderPosition(0, 0, 500, 90);
    btnBack.setBorderSize(1);
    btnBack.setBoxWithBorderColors(touchgfx::Color::getColorFromRGB(0, 0, 0), touchgfx::Color::getColorFromRGB(32, 32, 32), touchgfx::Color::getColorFromRGB(100, 100, 100), touchgfx::Color::getColorFromRGB(100, 100, 100));
    btnBack.setBitmaps(Bitmap(BITMAP_GOBACK_ID), Bitmap(BITMAP_GOBACK_ID));
    btnBack.setBitmapXY(20, 5);
    btnBack.setText(TypedText(T___SINGLEUSE_830Q));
    btnBack.setTextPosition(-20, 20, 500, 90);
    btnBack.setTextColors(touchgfx::Color::getColorFromRGB(150, 118, 73), touchgfx::Color::getColorFromRGB(64, 64, 64));
    btnBack.setPosition(5, 505, 500, 90);
    btnBack.setAction(flexButtonCallback);

    boxWithBorder1.setPosition(5, 100, 1019, 400);
    boxWithBorder1.setColor(touchgfx::Color::getColorFromRGB(25, 25, 25));
    boxWithBorder1.setBorderColor(touchgfx::Color::getColorFromRGB(100, 100, 100));
    boxWithBorder1.setBorderSize(1);

    containerDO.setPosition(380, 113, 360, 380);

    lblDI_1.setXY(20, 7);
    lblDI_1.setColor(touchgfx::Color::getColorFromRGB(100, 100, 100));
    lblDI_1.setLinespacing(0);
    lblDI_1.setTypedText(touchgfx::TypedText(T___SINGLEUSE_SBEA));
    containerDO.add(lblDI_1);

    lblDI1.setXY(20, 54);
    lblDI1.setColor(touchgfx::Color::getColorFromRGB(100, 100, 100));
    lblDI1.setLinespacing(0);
    lblDI1.setTypedText(touchgfx::TypedText(T___SINGLEUSE_PW3D));
    containerDO.add(lblDI1);

    lblDO0_2_3.setXY(20, 100);
    lblDO0_2_3.setColor(touchgfx::Color::getColorFromRGB(100, 100, 100));
    lblDO0_2_3.setLinespacing(0);
    lblDO0_2_3.setTypedText(touchgfx::TypedText(T___SINGLEUSE_48NN));
    containerDO.add(lblDO0_2_3);

    lblDO0_1_1_3.setXY(20, 147);
    lblDO0_1_1_3.setColor(touchgfx::Color::getColorFromRGB(100, 100, 100));
    lblDO0_1_1_3.setLinespacing(0);
    lblDO0_1_1_3.setTypedText(touchgfx::TypedText(T___SINGLEUSE_QI35));
    containerDO.add(lblDO0_1_1_3);

    lblDO0_1_2_2.setXY(20, 240);
    lblDO0_1_2_2.setColor(touchgfx::Color::getColorFromRGB(100, 100, 100));
    lblDO0_1_2_2.setLinespacing(0);
    lblDO0_1_2_2.setTypedText(touchgfx::TypedText(T___SINGLEUSE_18PO));
    containerDO.add(lblDO0_1_2_2);

    lblDO0_2_1_2.setXY(20, 286);
    lblDO0_2_1_2.setColor(touchgfx::Color::getColorFromRGB(100, 100, 100));
    lblDO0_2_1_2.setLinespacing(0);
    lblDO0_2_1_2.setTypedText(touchgfx::TypedText(T___SINGLEUSE_IMDO));
    containerDO.add(lblDO0_2_1_2);

    lblDO0_1_1_1_2.setXY(20, 333);
    lblDO0_1_1_1_2.setColor(touchgfx::Color::getColorFromRGB(100, 100, 100));
    lblDO0_1_1_1_2.setLinespacing(0);
    lblDO0_1_1_1_2.setTypedText(touchgfx::TypedText(T___SINGLEUSE_GK7P));
    containerDO.add(lblDO0_1_1_1_2);

    lblDO0_3_2.setXY(20, 193);
    lblDO0_3_2.setColor(touchgfx::Color::getColorFromRGB(100, 100, 100));
    lblDO0_3_2.setLinespacing(0);
    lblDO0_3_2.setTypedText(touchgfx::TypedText(T___SINGLEUSE_TA5O));
    containerDO.add(lblDO0_3_2);

    tbOut0.setXY(146, 6);
    tbOut0.setBitmaps(touchgfx::Bitmap(BITMAP_DARK_TOGGLEBARS_TOGGLE_LARGE_BUTTON_OFF_ID), touchgfx::Bitmap(BITMAP_DARK_TOGGLEBARS_TOGGLE_LARGE_BUTTON_ON_ID));
    tbOut0.setAction(buttonCallback);
    containerDO.add(tbOut0);

    tbOut1.setXY(146, 52);
    tbOut1.setBitmaps(touchgfx::Bitmap(BITMAP_DARK_TOGGLEBARS_TOGGLE_LARGE_BUTTON_OFF_ID), touchgfx::Bitmap(BITMAP_DARK_TOGGLEBARS_TOGGLE_LARGE_BUTTON_ON_ID));
    tbOut1.setAction(buttonCallback);
    containerDO.add(tbOut1);

    tbOut2.setXY(146, 99);
    tbOut2.setBitmaps(touchgfx::Bitmap(BITMAP_DARK_TOGGLEBARS_TOGGLE_LARGE_BUTTON_OFF_ID), touchgfx::Bitmap(BITMAP_DARK_TOGGLEBARS_TOGGLE_LARGE_BUTTON_ON_ID));
    tbOut2.setAction(buttonCallback);
    containerDO.add(tbOut2);

    tbOut3.setXY(146, 148);
    tbOut3.setBitmaps(touchgfx::Bitmap(BITMAP_DARK_TOGGLEBARS_TOGGLE_LARGE_BUTTON_OFF_ID), touchgfx::Bitmap(BITMAP_DARK_TOGGLEBARS_TOGGLE_LARGE_BUTTON_ON_ID));
    tbOut3.setAction(buttonCallback);
    containerDO.add(tbOut3);

    tbOut4.setXY(146, 194);
    tbOut4.setBitmaps(touchgfx::Bitmap(BITMAP_DARK_TOGGLEBARS_TOGGLE_LARGE_BUTTON_OFF_ID), touchgfx::Bitmap(BITMAP_DARK_TOGGLEBARS_TOGGLE_LARGE_BUTTON_ON_ID));
    tbOut4.setAction(buttonCallback);
    containerDO.add(tbOut4);

    tbOut5.setXY(146, 241);
    tbOut5.setBitmaps(touchgfx::Bitmap(BITMAP_DARK_TOGGLEBARS_TOGGLE_LARGE_BUTTON_OFF_ID), touchgfx::Bitmap(BITMAP_DARK_TOGGLEBARS_TOGGLE_LARGE_BUTTON_ON_ID));
    tbOut5.setAction(buttonCallback);
    containerDO.add(tbOut5);

    tbOut6.setXY(146, 287);
    tbOut6.setBitmaps(touchgfx::Bitmap(BITMAP_DARK_TOGGLEBARS_TOGGLE_LARGE_BUTTON_OFF_ID), touchgfx::Bitmap(BITMAP_DARK_TOGGLEBARS_TOGGLE_LARGE_BUTTON_ON_ID));
    tbOut6.setAction(buttonCallback);
    containerDO.add(tbOut6);

    tbOut7.setXY(146, 334);
    tbOut7.setBitmaps(touchgfx::Bitmap(BITMAP_DARK_TOGGLEBARS_TOGGLE_LARGE_BUTTON_OFF_ID), touchgfx::Bitmap(BITMAP_DARK_TOGGLEBARS_TOGGLE_LARGE_BUTTON_ON_ID));
    tbOut7.setAction(buttonCallback);
    containerDO.add(tbOut7);

    containerAI.setPosition(732, 108, 263, 385);

    lblDI_1_1.setXY(8, 65);
    lblDI_1_1.setColor(touchgfx::Color::getColorFromRGB(100, 100, 100));
    lblDI_1_1.setLinespacing(0);
    lblDI_1_1.setTypedText(touchgfx::TypedText(T___SINGLEUSE_OB5W));
    containerAI.add(lblDI_1_1);

    lblDI_1_1_1.setXY(8, 138);
    lblDI_1_1_1.setColor(touchgfx::Color::getColorFromRGB(100, 100, 100));
    lblDI_1_1_1.setLinespacing(0);
    lblDI_1_1_1.setTypedText(touchgfx::TypedText(T___SINGLEUSE_RZ96));
    containerAI.add(lblDI_1_1_1);

    lblDI_1_1_2.setXY(8, 210);
    lblDI_1_1_2.setColor(touchgfx::Color::getColorFromRGB(100, 100, 100));
    lblDI_1_1_2.setLinespacing(0);
    lblDI_1_1_2.setTypedText(touchgfx::TypedText(T___SINGLEUSE_VZ2D));
    containerAI.add(lblDI_1_1_2);

    lblDI_1_1_3.setXY(8, 285);
    lblDI_1_1_3.setColor(touchgfx::Color::getColorFromRGB(100, 100, 100));
    lblDI_1_1_3.setLinespacing(0);
    lblDI_1_1_3.setTypedText(touchgfx::TypedText(T___SINGLEUSE_MGJ6));
    containerAI.add(lblDI_1_1_3);

    containerDI.setPosition(17, 113, 361, 371);

    lblDO0.setXY(5, 5);
    lblDO0.setColor(touchgfx::Color::getColorFromRGB(100, 100, 100));
    lblDO0.setLinespacing(0);
    lblDO0.setTypedText(touchgfx::TypedText(T___SINGLEUSE_MKUD));
    containerDI.add(lblDO0);

    circLED0.setPosition(114, 5, 40, 40);
    circLED0.setCenter(20, 20);
    circLED0.setRadius(17);
    circLED0.setLineWidth(0);
    circLED0.setArc(0, 360);
    circLED0Painter.setColor(touchgfx::Color::getColorFromRGB(150, 118, 73));
    circLED0.setPainter(circLED0Painter);
    containerDI.add(circLED0);

    lblDO0_1.setXY(5, 52);
    lblDO0_1.setColor(touchgfx::Color::getColorFromRGB(100, 100, 100));
    lblDO0_1.setLinespacing(0);
    lblDO0_1.setTypedText(touchgfx::TypedText(T___SINGLEUSE_WVNP));
    containerDI.add(lblDO0_1);

    circLED1.setPosition(114, 52, 40, 40);
    circLED1.setCenter(20, 20);
    circLED1.setRadius(17);
    circLED1.setLineWidth(0);
    circLED1.setArc(0, 360);
    circLED1Painter.setColor(touchgfx::Color::getColorFromRGB(150, 118, 73));
    circLED1.setPainter(circLED1Painter);
    containerDI.add(circLED1);

    lblDO0_2.setXY(5, 98);
    lblDO0_2.setColor(touchgfx::Color::getColorFromRGB(100, 100, 100));
    lblDO0_2.setLinespacing(0);
    lblDO0_2.setTypedText(touchgfx::TypedText(T___SINGLEUSE_X2HN));
    containerDI.add(lblDO0_2);

    circLED2.setPosition(114, 98, 40, 40);
    circLED2.setCenter(20, 20);
    circLED2.setRadius(17);
    circLED2.setLineWidth(0);
    circLED2.setArc(0, 360);
    circLED2Painter.setColor(touchgfx::Color::getColorFromRGB(150, 118, 73));
    circLED2.setPainter(circLED2Painter);
    containerDI.add(circLED2);

    lblDO0_1_1.setXY(5, 145);
    lblDO0_1_1.setColor(touchgfx::Color::getColorFromRGB(100, 100, 100));
    lblDO0_1_1.setLinespacing(0);
    lblDO0_1_1.setTypedText(touchgfx::TypedText(T___SINGLEUSE_MH5A));
    containerDI.add(lblDO0_1_1);

    circLED3.setPosition(114, 145, 40, 40);
    circLED3.setCenter(20, 20);
    circLED3.setRadius(17);
    circLED3.setLineWidth(0);
    circLED3.setArc(0, 360);
    circLED3Painter.setColor(touchgfx::Color::getColorFromRGB(150, 118, 73));
    circLED3.setPainter(circLED3Painter);
    containerDI.add(circLED3);

    lblDO0_3.setXY(5, 191);
    lblDO0_3.setColor(touchgfx::Color::getColorFromRGB(100, 100, 100));
    lblDO0_3.setLinespacing(0);
    lblDO0_3.setTypedText(touchgfx::TypedText(T___SINGLEUSE_ETIW));
    containerDI.add(lblDO0_3);

    circLED4.setPosition(114, 191, 40, 40);
    circLED4.setCenter(20, 20);
    circLED4.setRadius(17);
    circLED4.setLineWidth(0);
    circLED4.setArc(0, 360);
    circLED4Painter.setColor(touchgfx::Color::getColorFromRGB(150, 118, 73));
    circLED4.setPainter(circLED4Painter);
    containerDI.add(circLED4);

    lblDO0_1_2.setXY(5, 238);
    lblDO0_1_2.setColor(touchgfx::Color::getColorFromRGB(100, 100, 100));
    lblDO0_1_2.setLinespacing(0);
    lblDO0_1_2.setTypedText(touchgfx::TypedText(T___SINGLEUSE_9PXR));
    containerDI.add(lblDO0_1_2);

    circLED5.setPosition(114, 238, 40, 40);
    circLED5.setCenter(20, 20);
    circLED5.setRadius(17);
    circLED5.setLineWidth(0);
    circLED5.setArc(0, 360);
    circLED5Painter.setColor(touchgfx::Color::getColorFromRGB(150, 118, 73));
    circLED5.setPainter(circLED5Painter);
    containerDI.add(circLED5);

    lblDO0_2_1.setXY(5, 284);
    lblDO0_2_1.setColor(touchgfx::Color::getColorFromRGB(100, 100, 100));
    lblDO0_2_1.setLinespacing(0);
    lblDO0_2_1.setTypedText(touchgfx::TypedText(T___SINGLEUSE_VIJT));
    containerDI.add(lblDO0_2_1);

    circLED6.setPosition(114, 284, 40, 40);
    circLED6.setCenter(20, 20);
    circLED6.setRadius(17);
    circLED6.setLineWidth(0);
    circLED6.setArc(0, 360);
    circLED6Painter.setColor(touchgfx::Color::getColorFromRGB(150, 118, 73));
    circLED6.setPainter(circLED6Painter);
    containerDI.add(circLED6);

    lblDO0_1_1_1.setXY(5, 331);
    lblDO0_1_1_1.setColor(touchgfx::Color::getColorFromRGB(100, 100, 100));
    lblDO0_1_1_1.setLinespacing(0);
    lblDO0_1_1_1.setTypedText(touchgfx::TypedText(T___SINGLEUSE_IZJG));
    containerDI.add(lblDO0_1_1_1);

    circLED7.setPosition(114, 331, 40, 40);
    circLED7.setCenter(20, 20);
    circLED7.setRadius(17);
    circLED7.setLineWidth(0);
    circLED7.setArc(0, 360);
    circLED7Painter.setColor(touchgfx::Color::getColorFromRGB(150, 118, 73));
    circLED7.setPainter(circLED7Painter);
    containerDI.add(circLED7);

    lblDO0_4.setXY(168, 5);
    lblDO0_4.setColor(touchgfx::Color::getColorFromRGB(100, 100, 100));
    lblDO0_4.setLinespacing(0);
    lblDO0_4.setTypedText(touchgfx::TypedText(T___SINGLEUSE_JL2J));
    containerDI.add(lblDO0_4);

    circLED8.setPosition(281, 5, 40, 40);
    circLED8.setCenter(20, 20);
    circLED8.setRadius(17);
    circLED8.setLineWidth(0);
    circLED8.setArc(0, 360);
    circLED8Painter.setColor(touchgfx::Color::getColorFromRGB(150, 118, 73));
    circLED8.setPainter(circLED8Painter);
    containerDI.add(circLED8);

    lblDO0_1_3.setXY(168, 52);
    lblDO0_1_3.setColor(touchgfx::Color::getColorFromRGB(100, 100, 100));
    lblDO0_1_3.setLinespacing(0);
    lblDO0_1_3.setTypedText(touchgfx::TypedText(T___SINGLEUSE_HBYJ));
    containerDI.add(lblDO0_1_3);

    circLED9.setPosition(281, 52, 40, 40);
    circLED9.setCenter(20, 20);
    circLED9.setRadius(17);
    circLED9.setLineWidth(0);
    circLED9.setArc(0, 360);
    circLED9Painter.setColor(touchgfx::Color::getColorFromRGB(150, 118, 73));
    circLED9.setPainter(circLED9Painter);
    containerDI.add(circLED9);

    lblDO0_2_2.setXY(168, 98);
    lblDO0_2_2.setColor(touchgfx::Color::getColorFromRGB(100, 100, 100));
    lblDO0_2_2.setLinespacing(0);
    lblDO0_2_2.setTypedText(touchgfx::TypedText(T___SINGLEUSE_IV9O));
    containerDI.add(lblDO0_2_2);

    circLED10.setPosition(281, 98, 40, 40);
    circLED10.setCenter(20, 20);
    circLED10.setRadius(17);
    circLED10.setLineWidth(0);
    circLED10.setArc(0, 360);
    circLED10Painter.setColor(touchgfx::Color::getColorFromRGB(150, 118, 73));
    circLED10.setPainter(circLED10Painter);
    containerDI.add(circLED10);

    lblDO0_1_1_2.setXY(168, 145);
    lblDO0_1_1_2.setColor(touchgfx::Color::getColorFromRGB(100, 100, 100));
    lblDO0_1_1_2.setLinespacing(0);
    lblDO0_1_1_2.setTypedText(touchgfx::TypedText(T___SINGLEUSE_XZYJ));
    containerDI.add(lblDO0_1_1_2);

    circLED11.setPosition(281, 145, 40, 40);
    circLED11.setCenter(20, 20);
    circLED11.setRadius(17);
    circLED11.setLineWidth(0);
    circLED11.setArc(0, 360);
    circLED11Painter.setColor(touchgfx::Color::getColorFromRGB(150, 118, 73));
    circLED11.setPainter(circLED11Painter);
    containerDI.add(circLED11);

    lblDO0_3_1.setXY(168, 191);
    lblDO0_3_1.setColor(touchgfx::Color::getColorFromRGB(100, 100, 100));
    lblDO0_3_1.setLinespacing(0);
    lblDO0_3_1.setTypedText(touchgfx::TypedText(T___SINGLEUSE_Y37K));
    containerDI.add(lblDO0_3_1);

    circLED12.setPosition(281, 191, 40, 40);
    circLED12.setCenter(20, 20);
    circLED12.setRadius(17);
    circLED12.setLineWidth(0);
    circLED12.setArc(0, 360);
    circLED12Painter.setColor(touchgfx::Color::getColorFromRGB(150, 118, 73));
    circLED12.setPainter(circLED12Painter);
    containerDI.add(circLED12);

    lblDO0_1_2_1.setXY(168, 238);
    lblDO0_1_2_1.setColor(touchgfx::Color::getColorFromRGB(100, 100, 100));
    lblDO0_1_2_1.setLinespacing(0);
    lblDO0_1_2_1.setTypedText(touchgfx::TypedText(T___SINGLEUSE_05DQ));
    containerDI.add(lblDO0_1_2_1);

    circLED13.setPosition(281, 238, 40, 40);
    circLED13.setCenter(20, 20);
    circLED13.setRadius(17);
    circLED13.setLineWidth(0);
    circLED13.setArc(0, 360);
    circLED13Painter.setColor(touchgfx::Color::getColorFromRGB(150, 118, 73));
    circLED13.setPainter(circLED13Painter);
    containerDI.add(circLED13);

    lblDO0_2_1_1.setXY(168, 284);
    lblDO0_2_1_1.setColor(touchgfx::Color::getColorFromRGB(100, 100, 100));
    lblDO0_2_1_1.setLinespacing(0);
    lblDO0_2_1_1.setTypedText(touchgfx::TypedText(T___SINGLEUSE_F24O));
    containerDI.add(lblDO0_2_1_1);

    circLED14.setPosition(281, 284, 40, 40);
    circLED14.setCenter(20, 20);
    circLED14.setRadius(17);
    circLED14.setLineWidth(0);
    circLED14.setArc(0, 360);
    circLED14Painter.setColor(touchgfx::Color::getColorFromRGB(150, 118, 73));
    circLED14.setPainter(circLED14Painter);
    containerDI.add(circLED14);

    lblDO0_1_1_1_1.setXY(168, 331);
    lblDO0_1_1_1_1.setColor(touchgfx::Color::getColorFromRGB(100, 100, 100));
    lblDO0_1_1_1_1.setLinespacing(0);
    lblDO0_1_1_1_1.setTypedText(touchgfx::TypedText(T___SINGLEUSE_M3H7));
    containerDI.add(lblDO0_1_1_1_1);

    circLED15.setPosition(281, 331, 40, 40);
    circLED15.setCenter(20, 20);
    circLED15.setRadius(17);
    circLED15.setLineWidth(0);
    circLED15.setArc(0, 360);
    circLED15Painter.setColor(touchgfx::Color::getColorFromRGB(150, 118, 73));
    circLED15.setPainter(circLED15Painter);
    containerDI.add(circLED15);

    lblAI0.setPosition(887, 171, 117, 50);
    lblAI0.setColor(touchgfx::Color::getColorFromRGB(200, 200, 200));
    lblAI0.setLinespacing(0);
    Unicode::snprintf(lblAI0Buffer, LBLAI0_SIZE, "%s", touchgfx::TypedText(T___SINGLEUSE_94Q1).getText());
    lblAI0.setWildcard(lblAI0Buffer);
    lblAI0.setTypedText(touchgfx::TypedText(T___SINGLEUSE_VX4C));

    lblAI1.setPosition(887, 244, 117, 42);
    lblAI1.setColor(touchgfx::Color::getColorFromRGB(200, 200, 200));
    lblAI1.setLinespacing(0);
    Unicode::snprintf(lblAI1Buffer, LBLAI1_SIZE, "%s", touchgfx::TypedText(T___SINGLEUSE_82GT).getText());
    lblAI1.setWildcard(lblAI1Buffer);
    lblAI1.setTypedText(touchgfx::TypedText(T___SINGLEUSE_984M));

    lblAI2.setPosition(887, 316, 117, 42);
    lblAI2.setColor(touchgfx::Color::getColorFromRGB(200, 200, 200));
    lblAI2.setLinespacing(0);
    Unicode::snprintf(lblAI2Buffer, LBLAI2_SIZE, "%s", touchgfx::TypedText(T___SINGLEUSE_B78P).getText());
    lblAI2.setWildcard(lblAI2Buffer);
    lblAI2.setTypedText(touchgfx::TypedText(T___SINGLEUSE_SP6U));

    lblAI3.setPosition(887, 391, 117, 42);
    lblAI3.setColor(touchgfx::Color::getColorFromRGB(200, 200, 200));
    lblAI3.setLinespacing(0);
    Unicode::snprintf(lblAI3Buffer, LBLAI3_SIZE, "%s", touchgfx::TypedText(T___SINGLEUSE_SX6S).getText());
    lblAI3.setWildcard(lblAI3Buffer);
    lblAI3.setTypedText(touchgfx::TypedText(T___SINGLEUSE_G3O6));

    line1.setPosition(365, 121, 15, 364);
    line1Painter.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    line1.setPainter(line1Painter);
    line1.setStart(1, 5);
    line1.setEnd(1, 400);
    line1.setLineWidth(1);
    line1.setLineEndingStyle(touchgfx::Line::ROUND_CAP_ENDING);
    line1.setAlpha(177);

    line1_1.setPosition(699, 120, 15, 364);
    line1_1Painter.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    line1_1.setPainter(line1_1Painter);
    line1_1.setStart(1, 5);
    line1_1.setEnd(1, 400);
    line1_1.setLineWidth(1);
    line1_1.setLineEndingStyle(touchgfx::Line::ROUND_CAP_ENDING);
    line1_1.setAlpha(177);

    lblServiceTitle.setPosition(0, 10, 1024, 80);
    lblServiceTitle.setColor(touchgfx::Color::getColorFromRGB(128, 128, 128));
    lblServiceTitle.setLinespacing(0);
    lblServiceTitle.setTypedText(touchgfx::TypedText(T___SINGLEUSE_MHPH));

    add(__background);
    add(box1);
    add(btnBack);
    add(boxWithBorder1);
    add(containerDO);
    add(containerAI);
    add(containerDI);
    add(lblAI0);
    add(lblAI1);
    add(lblAI2);
    add(lblAI3);
    add(line1);
    add(line1_1);
    add(lblServiceTitle);
}

void DebugScreenViewBase::setupScreen()
{

}

void DebugScreenViewBase::buttonCallbackHandler(const touchgfx::AbstractButton& src)
{
    if (&src == &tbOut0)
    {
        //OnClickDO_0
        //When tbOut0 clicked call virtual function
        //Call OnClickDO_0
        OnClickDO_0();
    }
    else if (&src == &tbOut1)
    {
        //OnClickDO_1
        //When tbOut1 clicked call virtual function
        //Call OnClickDO_1
        OnClickDO_1();
    }
    else if (&src == &tbOut2)
    {
        //OnClickDO_2
        //When tbOut2 clicked call virtual function
        //Call OnClickDO_2
        OnClickDO_2();
    }
    else if (&src == &tbOut3)
    {
        //OnClickDO_3
        //When tbOut3 clicked call virtual function
        //Call OnClickDO_3
        OnClickDO_3();
    }
    else if (&src == &tbOut4)
    {
        //OnClickDO_4
        //When tbOut4 clicked call virtual function
        //Call OnClickDO_4
        OnClickDO_4();
    }
    else if (&src == &tbOut5)
    {
        //OnClickDO_5
        //When tbOut5 clicked call virtual function
        //Call OnClickDO_5
        OnClickDO_5();
    }
    else if (&src == &tbOut6)
    {
        //OnClickDO_6
        //When tbOut6 clicked call virtual function
        //Call OnClickDO_6
        OnClickDO_6();
    }
    else if (&src == &tbOut7)
    {
        //OnClickDO_7
        //When tbOut7 clicked call virtual function
        //Call OnClickDO_7
        OnClickDO_7();
    }
}

void DebugScreenViewBase::flexButtonCallbackHandler(const touchgfx::AbstractButtonContainer& src)
{
    if (&src == &btnBack)
    {
        //ShowService
        //When btnBack clicked change screen to ServiceScreen
        //Go to ServiceScreen with no screen transition
        application().gotoServiceScreenScreenNoTransition();
    }
}