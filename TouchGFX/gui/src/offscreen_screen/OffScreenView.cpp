#include <gui/offscreen_screen/OffScreenView.hpp>

#ifdef SIMULATOR
void OffScreenView::DisplayEnable()
{
}
void OffScreenView::DisplayDisable()
{
}
#else
extern "C"
{
    void DisplayEnable();
    void DisplayDisable();
}
#endif

OffScreenView::OffScreenView()
{

}

void OffScreenView::setupScreen()
{
    OffScreenViewBase::setupScreen();    
    DisplayDisable();
}

void OffScreenView::tearDownScreen()
{
    OffScreenViewBase::tearDownScreen();
}

void OffScreenView::btnScreenOnClick() 
{
    DisplayEnable();
}