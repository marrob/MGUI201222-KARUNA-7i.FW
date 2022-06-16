/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#ifndef TEXTCONTAINERHIGHBASE_HPP
#define TEXTCONTAINERHIGHBASE_HPP

#include <gui/common/FrontendApplication.hpp>
#include <touchgfx/containers/Container.hpp>
#include <touchgfx/widgets/canvas/Line.hpp>
#include <touchgfx/widgets/canvas/PainterRGB565.hpp>
#include <touchgfx/widgets/TextAreaWithWildcard.hpp>

class TextContainerHighBase : public touchgfx::Container
{
public:
    TextContainerHighBase();
    virtual ~TextContainerHighBase() {}
    virtual void initialize();

protected:
    FrontendApplication& application() {
        return *static_cast<FrontendApplication*>(touchgfx::Application::getInstance());
    }

    /*
     * Member Declarations
     */
    touchgfx::Line line0;
    touchgfx::PainterRGB565 line0Painter;
    touchgfx::TextAreaWithOneWildcard text;
    touchgfx::Line line1;
    touchgfx::PainterRGB565 line1Painter;

    /*
     * Wildcard Buffers
     */
    static const uint16_t TEXT_SIZE = 10;
    touchgfx::Unicode::UnicodeChar textBuffer[TEXT_SIZE];

private:

};

#endif // TEXTCONTAINERHIGHBASE_HPP
