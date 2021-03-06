/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#ifndef UPDOWNCONTAINERBASE_HPP
#define UPDOWNCONTAINERBASE_HPP

#include <gui/common/FrontendApplication.hpp>
#include <touchgfx/containers/Container.hpp>
#include <touchgfx/widgets/Box.hpp>
#include <touchgfx/widgets/BoxWithBorder.hpp>
#include <touchgfx/containers/buttons/Buttons.hpp>
#include <touchgfx/widgets/TextAreaWithWildcard.hpp>

class UpDownContainerBase : public touchgfx::Container
{
public:
    UpDownContainerBase();
    virtual ~UpDownContainerBase() {}
    virtual void initialize();

    /*
     * Custom Trigger Callback Setters
     */
    void setValueChangedTriggerCallback(touchgfx::GenericCallback<uint32_t>& callback)
    {
        this->ValueChangedTriggerCallback = &callback;
    }

    /*
     * Virtual Action Handlers
     */
    virtual void OnBtnUpClick()
    {
        // Override and implement this function in UpDownContainer
    }

    virtual void OnBtnDownClick()
    {
        // Override and implement this function in UpDownContainer
    }

protected:
    FrontendApplication& application() {
        return *static_cast<FrontendApplication*>(touchgfx::Application::getInstance());
    }

    /*
     * Custom Trigger Emitters
     */
    virtual void emitValueChangedTriggerCallback(uint32_t value)
    {
        if (ValueChangedTriggerCallback && ValueChangedTriggerCallback->isValid())
        {
            this->ValueChangedTriggerCallback->execute(value);
        }
    }

    /*
     * Member Declarations
     */
    touchgfx::Box bacdround;
    touchgfx::BoxWithBorder boxWithBorder1;
    touchgfx::TextButtonStyle< touchgfx::BoxWithBorderButtonStyle< touchgfx::ClickButtonTrigger >  >  btnDown;
    touchgfx::TextButtonStyle< touchgfx::BoxWithBorderButtonStyle< touchgfx::ClickButtonTrigger >  >  btnUp;
    touchgfx::TextAreaWithOneWildcard lblValue;

    /*
     * Wildcard Buffers
     */
    static const uint16_t LBLVALUE_SIZE = 10;
    touchgfx::Unicode::UnicodeChar lblValueBuffer[LBLVALUE_SIZE];

private:

    /*
     * Callback Declarations
     */
    touchgfx::Callback<UpDownContainerBase, const touchgfx::AbstractButtonContainer&> flexButtonCallback;

    /*
     * Custom Trigger Callback Declarations
     */
    touchgfx::GenericCallback<uint32_t>* ValueChangedTriggerCallback;

    /*
     * Callback Handler Declarations
     */
    void flexButtonCallbackHandler(const touchgfx::AbstractButtonContainer& src);

};

#endif // UPDOWNCONTAINERBASE_HPP
