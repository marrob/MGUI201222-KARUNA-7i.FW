/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#ifndef SCROLLELMENTBASE_HPP
#define SCROLLELMENTBASE_HPP

#include <gui/common/FrontendApplication.hpp>
#include <touchgfx/containers/Container.hpp>
#include <touchgfx/widgets/Box.hpp>
#include <touchgfx/widgets/TextAreaWithWildcard.hpp>
#include <touchgfx/widgets/canvas/Line.hpp>
#include <touchgfx/widgets/canvas/PainterRGB565.hpp>

class ScrollElmentBase : public touchgfx::Container
{
public:
    ScrollElmentBase();
    virtual ~ScrollElmentBase() {}
    virtual void initialize();

protected:
    FrontendApplication& application() {
        return *static_cast<FrontendApplication*>(touchgfx::Application::getInstance());
    }

    /*
     * Member Declarations
     */
    touchgfx::Box bacdround;
    touchgfx::TextAreaWithOneWildcard lblElement;
    touchgfx::Line line4;
    touchgfx::PainterRGB565 line4Painter;

    /*
     * Wildcard Buffers
     */
    static const uint16_t LBLELEMENT_SIZE = 260;
    touchgfx::Unicode::UnicodeChar lblElementBuffer[LBLELEMENT_SIZE];

private:

};

#endif // SCROLLELMENTBASE_HPP
