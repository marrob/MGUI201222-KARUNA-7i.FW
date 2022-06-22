#include <gui/displayscreen_screen/DisplayScreenView.hpp>

int mDisplayTickCount;

#ifdef SIMULATOR

uint32_t simTimetoOff;
static uint32_t simOffTimmer;
static uint8_t simEnableScreenSaver;

uint8_t DisplayScreenView::GuiItfSetBacklight(uint8_t percent)
{
	return percent;
}
uint8_t DisplayScreenView::GuiItfGetBacklight(void)
{
	return 42; //Ez egy sokkal szebb sz�m
}

void DisplayScreenView::GuiItfSetBackLightAutoOff(uint32_t sec)
{
	simOffTimmer = sec;
	simTimetoOff = sec;
}
uint32_t DisplayScreenView::GuiItfGetBacklightAutoOff(void)
{
	return simOffTimmer;
}
uint32_t DisplayScreenView::GuiItfGetRemainingTimeToOff(void)
{
	if (simTimetoOff > 0)
	{
		simTimetoOff--;
	}
	return simTimetoOff;
}

void DisplayScreenView::GuiItfSetScreenSaverEnable(uint8_t isSet)
{
	simEnableScreenSaver = isSet;
}
uint8_t DisplayScreenView::GuiItfGetScreenSaverEnable( )
{
	return simEnableScreenSaver ;
}

#else
extern "C"
{

	//Backlight
	uint8_t GuiItfSetBacklight(uint8_t percent);
	uint8_t GuiItfGetBacklight(void);

	//Backlight off timer
	void GuiItfSetBackLightAutoOff(uint32_t sec);
	uint32_t GuiItfGetBacklightAutoOff(void);
	uint32_t GuiItfGetRemainingTimeToOff(void); 

	//ScreenSaver
	GuiItfSetScreenSaverEnable(uint8_t isSet);
	uint8_t GuiItfGetScreenSaverEnable();
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
	GetOfTimerValue();

	chbxEnableScreenSaver.forceState(GuiItfGetScreenSaverEnable());
}

void DisplayScreenView::tearDownScreen()
{
	DisplayScreenViewBase::tearDownScreen();
}

//Baclight 
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

//Auto Off Timer
void DisplayScreenView::rbtnSelect0OffTmr()
{
	GuiItfSetBackLightAutoOff(0);
}

void DisplayScreenView::rbtnSelect1OffTmr()
{
	GuiItfSetBackLightAutoOff(1 * 60);
}

void DisplayScreenView::rbtnSelect5OffTmr()
{
	GuiItfSetBackLightAutoOff(5 * 60);
}

void DisplayScreenView::rbtnSelect10OffTmr()
{
	GuiItfSetBackLightAutoOff(10 * 60);
}

void DisplayScreenView::rbtnSelect30OffTmr()
{
	GuiItfSetBackLightAutoOff(30 * 60);
}

void DisplayScreenView::rbtnSelect60OffTmr()
{
	GuiItfSetBackLightAutoOff(60 * 60);
}

void DisplayScreenView::rbtnSelect120OffTmr()
{
	GuiItfSetBackLightAutoOff(120 * 60);
}

void DisplayScreenView::chbxChangeEnableScreen()
{
	GuiItfSetScreenSaverEnable(chbxEnableScreenSaver.getState());
}

void DisplayScreenView::GetOfTimerValue()
{
	uint32_t offtimer = GuiItfGetBacklightAutoOff();
	switch (offtimer)
	{
	case 0 * 60:
	{
		rdbtnSet0.setSelected(true);
	}break;
	case 1 * 60:
	{
		rdbtnSet1.setSelected(true);
	}break;
	case 5 * 60:
	{
		rdbtnSet5.setSelected(true);
	}break;
	case 10 * 60:
	{
		rdbtnSet10.setSelected(true);
	}break;
	case 30 * 60:
	{
		rdbtnSet30.setSelected(true);
	}break;
	case 60 * 60:
	{
		rdbtnSet60.setSelected(true);
	}break;
	case 120 * 60:
	{
		rdbtnSet120.setSelected(true);
	}break;

	default:
		break;
	}
}

//Polling TimeToOff
void DisplayScreenView::handleTickEvent()
{
	mDisplayTickCount++;

	//Wait for 
	if (mDisplayTickCount % 30 == 0)
	{
		int remainSec = GuiItfGetRemainingTimeToOff();
		//if (remainSec > 0)
		{	 
			int RemainMinute = remainSec / 60;
			int RemainSecond = remainSec % 60;

			Unicode::snprintf(lblTimeToOffBuffer, sizeof(lblTimeToOffBuffer), "%02d:%02d", RemainMinute, RemainSecond);
			lblTimeToOff.invalidate();
		}
		
	}
}

