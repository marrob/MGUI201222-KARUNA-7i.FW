#include <gui/offscreen_screen/OffScreenView.hpp>
 

OffScreenView::OffScreenView()
{

}

void OffScreenView::setupScreen()
{
  OffScreenViewBase::setupScreen();
  mCommunicator.GuiItfBacklightDisable();
}

void OffScreenView::tearDownScreen()
{
    OffScreenViewBase::tearDownScreen();
}

void OffScreenView::btnScreenOnClick() 
{
    mCommunicator.GuiItfBacklightEnable();
}
