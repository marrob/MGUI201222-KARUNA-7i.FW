/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#include <gui_generated/logscreen_screen/LogScreenViewBase.hpp>
#include <touchgfx/Color.hpp>
#include <texts/TextKeysAndLanguages.hpp>
#include <BitmapDatabase.hpp>
#include <touchgfx/canvas_widget_renderer/CanvasWidgetRenderer.hpp>


LogScreenViewBase::LogScreenViewBase() :
    buttonCallback(this, &LogScreenViewBase::buttonCallbackHandler),
    flexButtonCallback(this, &LogScreenViewBase::flexButtonCallbackHandler),
    updateItemCallback(this, &LogScreenViewBase::updateItemCallbackHandler)
{

    touchgfx::CanvasWidgetRenderer::setupBuffer(canvasBuffer, CANVAS_BUFFER_SIZE);

    __background.setPosition(0, 0, 1024, 600);
    __background.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));

    box1.setPosition(0, 0, 1024, 600);
    box1.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));

    btnPrevPage.setBoxWithBorderPosition(0, 0, 247, 90);
    btnPrevPage.setBorderSize(1);
    btnPrevPage.setBoxWithBorderColors(touchgfx::Color::getColorFromRGB(0, 0, 0), touchgfx::Color::getColorFromRGB(32, 32, 32), touchgfx::Color::getColorFromRGB(100, 100, 100), touchgfx::Color::getColorFromRGB(100, 100, 100));
    btnPrevPage.setText(TypedText(T___SINGLEUSE_BPY3));
    btnPrevPage.setTextPosition(0, 20, 247, 90);
    btnPrevPage.setTextColors(touchgfx::Color::getColorFromRGB(150, 118, 73), touchgfx::Color::getColorFromRGB(64, 64, 64));
    btnPrevPage.setPosition(519, 505, 247, 90);
    btnPrevPage.setAction(flexButtonCallback);

    btnBack.setBoxWithBorderPosition(0, 0, 500, 90);
    btnBack.setBorderSize(1);
    btnBack.setBoxWithBorderColors(touchgfx::Color::getColorFromRGB(0, 0, 0), touchgfx::Color::getColorFromRGB(32, 32, 32), touchgfx::Color::getColorFromRGB(100, 100, 100), touchgfx::Color::getColorFromRGB(100, 100, 100));
    btnBack.setBitmaps(Bitmap(BITMAP_GOBACK_ID), Bitmap(BITMAP_GOBACK_ID));
    btnBack.setBitmapXY(20, 5);
    btnBack.setText(TypedText(T___SINGLEUSE_FDYF));
    btnBack.setTextPosition(-20, 20, 500, 90);
    btnBack.setTextColors(touchgfx::Color::getColorFromRGB(150, 118, 73), touchgfx::Color::getColorFromRGB(64, 64, 64));
    btnBack.setPosition(5, 505, 500, 90);
    btnBack.setAction(flexButtonCallback);

    lblTitle.setPosition(0, 10, 1024, 80);
    lblTitle.setColor(touchgfx::Color::getColorFromRGB(128, 128, 128));
    lblTitle.setLinespacing(0);
    lblTitle.setTypedText(touchgfx::TypedText(T___SINGLEUSE_QJTD));

    boxWithBorder1.setPosition(5, 100, 1014, 400);
    boxWithBorder1.setColor(touchgfx::Color::getColorFromRGB(25, 25, 25));
    boxWithBorder1.setBorderColor(touchgfx::Color::getColorFromRGB(100, 100, 100));
    boxWithBorder1.setBorderSize(1);

    btnNextPage.setBoxWithBorderPosition(0, 0, 247, 90);
    btnNextPage.setBorderSize(1);
    btnNextPage.setBoxWithBorderColors(touchgfx::Color::getColorFromRGB(0, 0, 0), touchgfx::Color::getColorFromRGB(32, 32, 32), touchgfx::Color::getColorFromRGB(100, 100, 100), touchgfx::Color::getColorFromRGB(100, 100, 100));
    btnNextPage.setText(TypedText(T___SINGLEUSE_C0B1));
    btnNextPage.setTextPosition(0, 20, 247, 90);
    btnNextPage.setTextColors(touchgfx::Color::getColorFromRGB(150, 118, 73), touchgfx::Color::getColorFromRGB(64, 64, 64));
    btnNextPage.setPosition(772, 505, 247, 90);
    btnNextPage.setAction(flexButtonCallback);

    scrollLog.setPosition(0, 109, 1024, 325);
    scrollLog.setHorizontal(false);
    scrollLog.setCircular(false);
    scrollLog.setEasingEquation(touchgfx::EasingEquations::backEaseOut);
    scrollLog.setSwipeAcceleration(10);
    scrollLog.setDragAcceleration(10);
    scrollLog.setNumberOfItems(10);
    scrollLog.setPadding(0, 0);
    scrollLog.setSnapping(false);
    scrollLog.setDrawableSize(101, 0);
    scrollLog.setDrawables(scrollLogListItems, updateItemCallback);

    lblElement_1.setPosition(16, 453, 489, 30);
    lblElement_1.setColor(touchgfx::Color::getColorFromRGB(170, 170, 170));
    lblElement_1.setLinespacing(0);
    Unicode::snprintf(lblElement_1Buffer, LBLELEMENT_1_SIZE, "%s", touchgfx::TypedText(T___SINGLEUSE_HXDW).getText());
    lblElement_1.setWildcard(lblElement_1Buffer);
    lblElement_1.setTypedText(touchgfx::TypedText(T___SINGLEUSE_ZK75));

    container1.setPosition(552, 435, 467, 66);

    chbxINFO.setXY(0, 11);
    chbxINFO.setBitmaps(touchgfx::Bitmap(BITMAP_ON_44X44_ID), touchgfx::Bitmap(BITMAP_OFF_44X44_ID));
    chbxINFO.forceState(true);
    container1.add(chbxINFO);

    lblInfo.setXY(54, 15);
    lblInfo.setColor(touchgfx::Color::getColorFromRGB(200, 200, 200));
    lblInfo.setLinespacing(0);
    lblInfo.setTypedText(touchgfx::TypedText(T___SINGLEUSE_LTA0));
    container1.add(lblInfo);

    chbxWarn.setXY(158, 11);
    chbxWarn.setBitmaps(touchgfx::Bitmap(BITMAP_ON_44X44_ID), touchgfx::Bitmap(BITMAP_OFF_44X44_ID));
    chbxWarn.forceState(true);
    container1.add(chbxWarn);

    lblWARN.setXY(212, 15);
    lblWARN.setColor(touchgfx::Color::getColorFromRGB(200, 200, 200));
    lblWARN.setLinespacing(0);
    lblWARN.setTypedText(touchgfx::TypedText(T___SINGLEUSE_G4CD));
    container1.add(lblWARN);

    chbxError.setXY(315, 11);
    chbxError.setBitmaps(touchgfx::Bitmap(BITMAP_ON_44X44_ID), touchgfx::Bitmap(BITMAP_OFF_44X44_ID));
    chbxError.forceState(true);
    container1.add(chbxError);

    lblERROR.setXY(369, 15);
    lblERROR.setColor(touchgfx::Color::getColorFromRGB(200, 200, 200));
    lblERROR.setLinespacing(0);
    lblERROR.setTypedText(touchgfx::TypedText(T___SINGLEUSE_Y806));
    container1.add(lblERROR);

    add(__background);
    add(box1);
    add(btnPrevPage);
    add(btnBack);
    add(lblTitle);
    add(boxWithBorder1);
    add(btnNextPage);
    add(scrollLog);
    add(lblElement_1);
    add(container1);
}

void LogScreenViewBase::setupScreen()
{
    scrollLog.initialize();
    for (int i = 0; i < scrollLogListItems.getNumberOfDrawables(); i++)
    {
        scrollLogListItems[i].initialize();
    }
}

void LogScreenViewBase::buttonCallbackHandler(const touchgfx::AbstractButton& src)
{
}

void LogScreenViewBase::flexButtonCallbackHandler(const touchgfx::AbstractButtonContainer& src)
{
    if (&src == &btnPrevPage)
    {
        //PrevPage
        //When btnPrevPage clicked call virtual function
        //Call OnClickPrevPage
        OnClickPrevPage();
    }
    else if (&src == &btnBack)
    {
        //ShowService
        //When btnBack clicked change screen to ServiceScreen
        //Go to ServiceScreen with no screen transition
        application().gotoServiceScreenScreenNoTransition();
    }
    else if (&src == &btnNextPage)
    {
        //NextPage
        //When btnNextPage clicked call virtual function
        //Call OnClickNextPage
        OnClickNextPage();
    }
}

void LogScreenViewBase::updateItemCallbackHandler(touchgfx::DrawableListItemsInterface* items, int16_t containerIndex, int16_t itemIndex)
{
    if (items == &scrollLogListItems)
    {
        touchgfx::Drawable* d = items->getDrawable(containerIndex);
        ScrollElment* cc = (ScrollElment*)d;
        scrollLogUpdateItem(*cc, itemIndex);
    }
}
