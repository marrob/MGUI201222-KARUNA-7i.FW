#include <gui/offscreen_screen/OffScreenView.hpp>
 

#ifdef SIMULATOR
void OffScreenView::GuiItfBacklightEnable()
{
}
void OffScreenView::GuiItfBacklightDisable()
{
}
#else
extern "C"
{
    void GuiItfBacklightEnable();
    void GuiItfBacklightDisable();
}
#endif

OffScreenView::OffScreenView()
{

}

void OffScreenView::setupScreen()
{
  OffScreenViewBase::setupScreen();
  GuiItfBacklightDisable();
}

void OffScreenView::tearDownScreen()
{
    OffScreenViewBase::tearDownScreen();
}

void OffScreenView::btnScreenOnClick() 
{
  GuiItfBacklightEnable();
}
