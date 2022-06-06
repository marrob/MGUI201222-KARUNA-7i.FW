#include <gui/displayscreen_screen/DisplayScreenView.hpp>


#ifdef SIMULATOR
uint8_t DisplayScreenView::BacklightSet(uint8_t percent)
{ 
	return percent;
}
#else
extern "C"
{
	uint8_t BacklightSet(uint8_t percent);
}
#endif


DisplayScreenView::DisplayScreenView() :
	sliderValueChangedCallback(this, &DisplayScreenView::sliderValueChangedCallbackHandler)
{

}

void DisplayScreenView::setupScreen()
{
	DisplayScreenViewBase::setupScreen();
	sldrBrightnes.setNewValueCallback(sliderValueChangedCallback);
}

void DisplayScreenView::sliderValueChangedCallbackHandler(const touchgfx::Slider& src, int value)
{
	if (&src == &sldrBrightnes)
	{
		//execute code whenever the value of the slider changes. 

		Unicode::snprintf(lblBrightnessBuffer, 8, "%d", value);
		lblBrightness.invalidate();
		BacklightSet((uint8_t)value);
	}
}

void DisplayScreenView::tearDownScreen()
{
	DisplayScreenViewBase::tearDownScreen();
}
