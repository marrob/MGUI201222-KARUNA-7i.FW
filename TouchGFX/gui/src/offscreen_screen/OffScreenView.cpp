#include <gui/offscreen_screen/OffScreenView.hpp>

#ifdef SIMULATOR
void OffScreenView::BacklightEnable()
{
}
void OffScreenView::BacklightDisable()
{
}
#else
extern "C"
{
    void BacklightEnable();
    void BacklightDisable();
}
#endif

OffScreenView::OffScreenView()
{

}

void OffScreenView::setupScreen()
{
    OffScreenViewBase::setupScreen();    
    BacklightDisable();
}

void OffScreenView::tearDownScreen()
{
    OffScreenViewBase::tearDownScreen();
}

void OffScreenView::btnScreenOnClick() 
{
  BacklightEnable();
}
