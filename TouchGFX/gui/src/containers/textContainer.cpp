#include <gui/containers/textContainer.hpp>

textContainer::textContainer()
{

}

void textContainer::initialize()
{
    textContainerBase::initialize();
}

void textContainer::updateText(int16_t value)
{
    Unicode::snprintf(textBuffer, TEXT_SIZE, "%02d", value);
    text.invalidate();
}
