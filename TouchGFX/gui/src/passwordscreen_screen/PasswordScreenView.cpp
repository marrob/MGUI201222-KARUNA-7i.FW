#include <gui/passwordscreen_screen/PasswordScreenView.hpp>
#include <string>

Unicode::UnicodeChar mPinCode[10];

PasswordScreenView::PasswordScreenView()
{
	lblPinIsNotCorrect.setVisible(false);
	lblPinIsNotCorrect.invalidate();

  memset(mPinCode, 0, sizeof(mPinCode));
  memset(lblPinCodeBuffer, 0, sizeof(lblPinCodeBuffer));
}

void PasswordScreenView::setupScreen()
{
	PasswordScreenViewBase::setupScreen();
}

void PasswordScreenView::tearDownScreen()
{
	PasswordScreenViewBase::tearDownScreen();
}


void PasswordScreenView::SetIncoreectHide()
{
	if (lblPinIsNotCorrect.isVisible())
	{
		lblPinIsNotCorrect.setVisible(false);
		lblPinIsNotCorrect.invalidate();
	}
}


void PasswordScreenView::AppendPinCode(Unicode::UnicodeChar pinChar)
{
  uint32_t length = Unicode::strlen(mPinCode);

  if(length < 5)
  {
    mPinCode[length] = pinChar;
    mPinCode[length + 1] = 0;
    Unicode::strncpy(lblPinCodeBuffer, mPinCode, length + 1);
  }
  lblPinCode.invalidate();
  SetIncoreectHide();
}

void PasswordScreenView::ClickBtn0()
{
	AppendPinCode('0');
}

void PasswordScreenView::ClickBtn1()
{
	AppendPinCode('1');
}

void PasswordScreenView::ClickBtn2()
{
	AppendPinCode('2');
}

void PasswordScreenView::ClickBtn3()
{
	AppendPinCode('3');
}

void PasswordScreenView::ClickBtn4()
{
	AppendPinCode('4');
}

void PasswordScreenView::ClickBtn5()
{
	AppendPinCode('5');
}

void PasswordScreenView::ClickBtn6()
{
	AppendPinCode('6');
}

void PasswordScreenView::ClickBtn7()
{
	AppendPinCode('7');
}

void PasswordScreenView::ClickBtn8()
{
	AppendPinCode('8');
}

void PasswordScreenView::ClickBtn9()
{
	AppendPinCode('9');
}

void PasswordScreenView::ClickBtnOK()
{
  if (mPinCode[0] == '0')
  {
    application().gotoServiceScreenScreenSlideTransitionEast();
  }
  else
  {
    memset(mPinCode, 0, sizeof(mPinCode));
    memset(lblPinCodeBuffer, 0, sizeof(lblPinCodeBuffer));

    lblPinIsNotCorrect.setVisible(true);
    lblPinIsNotCorrect.invalidate();
  }
}
