#include <gui/displayscreen_screen/DisplayScreenView.hpp>
 
DisplayScreenView::DisplayScreenView() :
	sliderValueChangedCallback(this, &DisplayScreenView::sliderValueChangedCallbackHandler)
{

}

void DisplayScreenView::setupScreen()
{
	DisplayScreenViewBase::setupScreen();
	sldrBrightnes.setNewValueCallback(sliderValueChangedCallback);
	sldrBrightnes.setValue(mCommunicator.GuiItfGetBacklight());
}

void DisplayScreenView::sliderValueChangedCallbackHandler(const touchgfx::Slider& src, int value)
{
	if (&src == &sldrBrightnes)
	{
		//execute code whenever the value of the slider changes. 

		Unicode::snprintf(lblBrightnessBuffer, 8, "%d", value);
		lblBrightness.invalidate();
		mCommunicator.GuiItfSetBacklight((uint8_t)value);
	}
}

void DisplayScreenView::tearDownScreen()
{
	DisplayScreenViewBase::tearDownScreen();
}
