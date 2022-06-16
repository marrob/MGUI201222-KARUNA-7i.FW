#include <gui/offscreen_screen/OffScreenView.hpp>
 

#ifdef SIMULATOR
void OffScreenView::GuiItfSetBacklightEn(uint8_t onoff)
{
}
#else
extern "C"
{
  void GuiItfSetBacklightEn(uint8_t onoff);
}
#endif

OffScreenView::OffScreenView()
{

}

void OffScreenView::setupScreen()
{
  OffScreenViewBase::setupScreen();
  GuiItfSetBacklightEn(0);
}

void OffScreenView::tearDownScreen()
{
    OffScreenViewBase::tearDownScreen();
}

void OffScreenView::btnScreenOnClick() 
{
  GuiItfSetBacklightEn(1);
}
