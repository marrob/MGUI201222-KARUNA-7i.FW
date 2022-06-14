#ifndef PASSWORDSCREENVIEW_HPP
#define PASSWORDSCREENVIEW_HPP

#include <gui_generated/passwordscreen_screen/PasswordScreenViewBase.hpp>
#include <gui/passwordscreen_screen/PasswordScreenPresenter.hpp>

class PasswordScreenView : public PasswordScreenViewBase
{
public:
    


    PasswordScreenView();
    virtual ~PasswordScreenView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
    /*
    * Virtual Action Handlers
    */
    virtual void ClickBtn0();
    virtual void ClickBtn1();
    virtual void ClickBtn2();
    virtual void ClickBtn3();
    virtual void ClickBtn4();
    virtual void ClickBtn5();
    virtual void ClickBtn6();
    virtual void ClickBtn7();
    virtual void ClickBtn8();
    virtual void ClickBtn9();
    virtual void ClickBtnOK();

    void SetIncoreectHide();
    void AppendPinCode(Unicode::UnicodeChar PinCode);


protected:


};

#endif // PASSWORDSCREENVIEW_HPP

void SetIncoreectHide();
