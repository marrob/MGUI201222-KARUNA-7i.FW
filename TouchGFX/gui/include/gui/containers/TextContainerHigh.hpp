#ifndef TEXTCONTAINERHIGH_HPP
#define TEXTCONTAINERHIGH_HPP

#include <gui_generated/containers/TextContainerHighBase.hpp>

class TextContainerHigh : public TextContainerHighBase
{
public:
    TextContainerHigh();
    virtual ~TextContainerHigh() {}

    virtual void initialize();
    void updateText(int16_t value);
protected:
};

#endif // TEXTCONTAINERHIGH_HPP
