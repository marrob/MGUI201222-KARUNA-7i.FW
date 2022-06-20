#include <gui/containers/ScrollElment.hpp>

ScrollElment::ScrollElment()
{

}

void ScrollElment::initialize()
{
    ScrollElmentBase::initialize();
}

void ScrollElment::SetText(char* logText) 
{     
    Unicode::UnicodeChar uni_logText[260];
    Unicode::fromUTF8((const uint8_t*)logText, uni_logText, sizeof(uni_logText));
    Unicode::snprintf(lblElementBuffer, sizeof(lblElementBuffer), "%s", uni_logText); 
    lblElement.setWideTextAction(touchgfx::WIDE_TEXT_WORDWRAP);
    lblElement.resizeHeightToCurrentText();
    lblElement.invalidate();
}
