#include <gui/containers/TextContainerHigh.hpp>

TextContainerHigh::TextContainerHigh()
{

}

void TextContainerHigh::initialize()
{
    TextContainerHighBase::initialize();
}

void TextContainerHigh::updateText(int16_t value)
{
    Unicode::snprintf(textBuffer, TEXT_SIZE, "%02d", value);
    text.invalidate();
}
