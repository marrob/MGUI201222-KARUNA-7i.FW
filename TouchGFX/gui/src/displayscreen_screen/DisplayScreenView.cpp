#include <gui/displayscreen_screen/DisplayScreenView.hpp>


#ifdef SIMULATOR
uint8_t DisplayScreenView::GuiItfSetBacklight(uint8_t percent)
{ 
	return percent;
}

uint8_t DisplayScreenView::GuiItfGetBacklight(void) 
{
	return 101;
}

#else
extern "C"
{
	uint8_t GuiItfSetBacklight(uint8_t percent);
	uint8_t GuiItfGetBacklight(void);
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
	sldrBrightnes.setValue(GuiItfGetBacklight());
}

void DisplayScreenView::sliderValueChangedCallbackHandler(const touchgfx::Slider& src, int value)
{
	if (&src == &sldrBrightnes)
	{
		//execute code whenever the value of the slider changes. 

		Unicode::snprintf(lblBrightnessBuffer, 8, "%d", value);
		lblBrightness.invalidate();
		GuiItfSetBacklight((uint8_t)value);
	}
}

void DisplayScreenView::tearDownScreen()
{
	DisplayScreenViewBase::tearDownScreen();
}
