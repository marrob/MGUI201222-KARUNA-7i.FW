/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#include <gui_generated/containers/ScrollElmentBase.hpp>
#include <touchgfx/Color.hpp>
#include <texts/TextKeysAndLanguages.hpp>

ScrollElmentBase::ScrollElmentBase()
{
    setWidth(1024);
    setHeight(101);
    bacdround.setPosition(12, 0, 1000, 101);
    bacdround.setColor(touchgfx::Color::getColorFromRGB(16, 16, 16));

    lblElement.setPosition(16, 0, 996, 101);
    lblElement.setColor(touchgfx::Color::getColorFromRGB(170, 170, 170));
    lblElement.setLinespacing(0);
    Unicode::snprintf(lblElementBuffer, LBLELEMENT_SIZE, "%s", touchgfx::TypedText(T___SINGLEUSE_9NVL).getText());
    lblElement.setWildcard(lblElementBuffer);
    lblElement.setTypedText(touchgfx::TypedText(T___SINGLEUSE_GCT7));

    line4.setPosition(45, 95, 920, 18);
    line4Painter.setColor(touchgfx::Color::getColorFromRGB(32, 32, 32));
    line4.setPainter(line4Painter);
    line4.setStart(0, 0);
    line4.setEnd(920, 1);
    line4.setLineWidth(2);
    line4.setLineEndingStyle(touchgfx::Line::BUTT_CAP_ENDING);

    add(bacdround);
    add(lblElement);
    add(line4);
}

void ScrollElmentBase::initialize()
{

}

