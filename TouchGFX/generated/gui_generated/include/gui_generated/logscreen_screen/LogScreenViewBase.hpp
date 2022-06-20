/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#ifndef LOGSCREENVIEWBASE_HPP
#define LOGSCREENVIEWBASE_HPP

#include <gui/common/FrontendApplication.hpp>
#include <mvp/View.hpp>
#include <gui/logscreen_screen/LogScreenPresenter.hpp>
#include <touchgfx/widgets/Box.hpp>
#include <touchgfx/containers/buttons/Buttons.hpp>
#include <touchgfx/widgets/TextArea.hpp>
#include <touchgfx/widgets/BoxWithBorder.hpp>
#include <touchgfx/containers/scrollers/ScrollList.hpp>
#include <gui/containers/ScrollElment.hpp>
#include <touchgfx/widgets/TextAreaWithWildcard.hpp>
#include <touchgfx/containers/Container.hpp>
#include <touchgfx/widgets/ToggleButton.hpp>

class LogScreenViewBase : public touchgfx::View<LogScreenPresenter>
{
public:
    LogScreenViewBase();
    virtual ~LogScreenViewBase() {}
    virtual void setupScreen();

    virtual void scrollLogUpdateItem(ScrollElment& item, int16_t itemIndex)
    {
        // Override and implement this function in LogScreen
    }

    /*
     * Virtual Action Handlers
     */
    virtual void OnClickNextPage()
    {
        // Override and implement this function in LogScreen
    }

    virtual void OnClickPrevPage()
    {
        // Override and implement this function in LogScreen
    }

protected:
    FrontendApplication& application() {
        return *static_cast<FrontendApplication*>(touchgfx::Application::getInstance());
    }

    /*
     * Member Declarations
     */
    touchgfx::Box __background;
    touchgfx::Box box1;
    touchgfx::TextButtonStyle< touchgfx::BoxWithBorderButtonStyle< touchgfx::ClickButtonTrigger >  >  btnPrevPage;
    touchgfx::TextButtonStyle< touchgfx::ImageButtonStyle< touchgfx::BoxWithBorderButtonStyle< touchgfx::ClickButtonTrigger >  >  >  btnBack;
    touchgfx::TextArea lblTitle;
    touchgfx::BoxWithBorder boxWithBorder1;
    touchgfx::TextButtonStyle< touchgfx::BoxWithBorderButtonStyle< touchgfx::ClickButtonTrigger >  >  btnNextPage;
    touchgfx::ScrollList scrollLog;
    touchgfx::DrawableListItems<ScrollElment, 5> scrollLogListItems;
    touchgfx::TextAreaWithOneWildcard lblElement_1;
    touchgfx::Container container1;
    touchgfx::ToggleButton chbxINFO;
    touchgfx::TextArea lblInfo;
    touchgfx::ToggleButton chbxWarn;
    touchgfx::TextArea lblWARN;
    touchgfx::ToggleButton chbxError;
    touchgfx::TextArea lblERROR;

    /*
     * Wildcard Buffers
     */
    static const uint16_t LBLELEMENT_1_SIZE = 70;
    touchgfx::Unicode::UnicodeChar lblElement_1Buffer[LBLELEMENT_1_SIZE];

private:

    /*
     * Callback Declarations
     */
    touchgfx::Callback<LogScreenViewBase, const touchgfx::AbstractButton&> buttonCallback;
    touchgfx::Callback<LogScreenViewBase, const touchgfx::AbstractButtonContainer&> flexButtonCallback;
    touchgfx::Callback<LogScreenViewBase, touchgfx::DrawableListItemsInterface*, int16_t, int16_t> updateItemCallback;

    /*
     * Callback Handler Declarations
     */
    void buttonCallbackHandler(const touchgfx::AbstractButton& src);
    void flexButtonCallbackHandler(const touchgfx::AbstractButtonContainer& src);
    void updateItemCallbackHandler(touchgfx::DrawableListItemsInterface* items, int16_t containerIndex, int16_t itemIndex);

    /*
     * Canvas Buffer Size
     */
    static const uint16_t CANVAS_BUFFER_SIZE = 15360;
    uint8_t canvasBuffer[CANVAS_BUFFER_SIZE];
};

#endif // LOGSCREENVIEWBASE_HPP