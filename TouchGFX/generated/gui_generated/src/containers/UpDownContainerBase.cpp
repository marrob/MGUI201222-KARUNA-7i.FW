/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#include <gui_generated/containers/UpDownContainerBase.hpp>
#include <touchgfx/Color.hpp>
#include <texts/TextKeysAndLanguages.hpp>

UpDownContainerBase::UpDownContainerBase() :
    flexButtonCallback(this, &UpDownContainerBase::flexButtonCallbackHandler),
    ValueChangedTriggerCallback(0)
{
    setWidth(250);
    setHeight(50);
    bacdround.setPosition(0, 0, 250, 50);
    bacdround.setColor(touchgfx::Color::getColorFromRGB(16, 16, 16));

    boxWithBorder1.setPosition(0, 0, 250, 50);
    boxWithBorder1.setColor(touchgfx::Color::getColorFromRGB(32, 32, 32));
    boxWithBorder1.setBorderColor(touchgfx::Color::getColorFromRGB(100, 100, 100));
    boxWithBorder1.setBorderSize(2);

    btnDown.setBoxWithBorderPosition(0, 0, 60, 40);
    btnDown.setBorderSize(1);
    btnDown.setBoxWithBorderColors(touchgfx::Color::getColorFromRGB(0, 0, 0), touchgfx::Color::getColorFromRGB(32, 32, 32), touchgfx::Color::getColorFromRGB(100, 100, 100), touchgfx::Color::getColorFromRGB(100, 100, 100));
    btnDown.setText(TypedText(T___SINGLEUSE_BWV6));
    btnDown.setTextPosition(0, -6, 60, 40);
    btnDown.setTextColors(touchgfx::Color::getColorFromRGB(150, 118, 73), touchgfx::Color::getColorFromRGB(64, 64, 64));
    btnDown.setPosition(6, 5, 60, 40);
    btnDown.setAction(flexButtonCallback);

    btnUp.setBoxWithBorderPosition(0, 0, 60, 40);
    btnUp.setBorderSize(1);
    btnUp.setBoxWithBorderColors(touchgfx::Color::getColorFromRGB(0, 0, 0), touchgfx::Color::getColorFromRGB(32, 32, 32), touchgfx::Color::getColorFromRGB(100, 100, 100), touchgfx::Color::getColorFromRGB(100, 100, 100));
    btnUp.setText(TypedText(T___SINGLEUSE_IX9B));
    btnUp.setTextPosition(0, -4, 60, 40);
    btnUp.setTextColors(touchgfx::Color::getColorFromRGB(150, 118, 73), touchgfx::Color::getColorFromRGB(64, 64, 64));
    btnUp.setPosition(185, 5, 60, 40);
    btnUp.setAction(flexButtonCallback);

    lblValue.setPosition(57, 5, 136, 48);
    lblValue.setColor(touchgfx::Color::getColorFromRGB(128, 128, 128));
    lblValue.setLinespacing(0);
    Unicode::snprintf(lblValueBuffer, LBLVALUE_SIZE, "%s", touchgfx::TypedText(T___SINGLEUSE_MVNG).getText());
    lblValue.setWildcard(lblValueBuffer);
    lblValue.setTypedText(touchgfx::TypedText(T___SINGLEUSE_KMGP));

    add(bacdround);
    add(boxWithBorder1);
    add(btnDown);
    add(btnUp);
    add(lblValue);
}

void UpDownContainerBase::initialize()
{

}

void UpDownContainerBase::flexButtonCallbackHandler(const touchgfx::AbstractButtonContainer& src)
{
    if (&src == &btnDown)
    {
        //BtnDownClick
        //When btnDown clicked call virtual function
        //Call OnBtnDownClick
        OnBtnDownClick();
    }
    else if (&src == &btnUp)
    {
        //BtnUpClick
        //When btnUp clicked call virtual function
        //Call OnBtnUpClick
        OnBtnUpClick();
    }
}

