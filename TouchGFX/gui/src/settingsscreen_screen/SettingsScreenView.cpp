#include <gui/settingsscreen_screen/SettingsScreenView.hpp>

int mTickGUICount;
bool mSetupLoaded;

#ifdef SIMULATOR

static uint8_t simOutputState;
static uint8_t simMCLKState;

uint8_t SettingsScreenView::GuiItfGetKarunaOutputsAllEnabledAfterStart(void)
{
	return simOutputState;
}
void SettingsScreenView::GuiItfSetKarunaOutputsAllEnabledAfterStart(uint8_t onoff)
{
	simOutputState = onoff;
}
void SettingsScreenView::GuiItfSetKarunaMasterClkOnI2S(uint8_t onoff)
{
	simMCLKState = onoff;
}
uint8_t SettingsScreenView::GuiItfGetKarunaMasterClkOnI2SIsEnabled(void)
{
	return simMCLKState;
}
#else
extern "C"
{
	uint8_t GuiItfGetKarunaOutputsAllEnabledAfterStart();
	void GuiItfSetKarunaOutputsAllEnabledAfterStart(uint8_t onoff);
	void GuiItfSetKarunaMasterClkOnI2S(uint8_t onoff);
	uint8_t GuiItfGetKarunaMasterClkOnI2SIsEnabled(void);
}
#endif


SettingsScreenView::SettingsScreenView()
{
	mSetupLoaded = false;
	if (GuiItfGetKarunaOutputsAllEnabledAfterStart())
		radioButtonGroup1.setSelected(rdbtnEnableAll);
	else
		radioButtonGroup1.setSelected(rdbtnLastState);

	if (GuiItfGetKarunaMasterClkOnI2SIsEnabled())
		chbxMCLKON.forceState(true);
	else
		chbxMCLKON.forceState(false);

	mSetupLoaded = true;

}

void SettingsScreenView::setupScreen()
{
	SettingsScreenViewBase::setupScreen(); 
}

void SettingsScreenView::tearDownScreen()
{
	SettingsScreenViewBase::tearDownScreen();
}

//OUTPUT SETTINGS

void SettingsScreenView::RdbBtnSelectEnableAllOutputAtStartUp()
{
	if (mSetupLoaded)
	{
		GuiItfSetKarunaOutputsAllEnabledAfterStart(1);
	}
}

void SettingsScreenView::RdbBtnSelectLastOutputStatAtStartUp()
{
	if (mSetupLoaded)
	{
		GuiItfSetKarunaOutputsAllEnabledAfterStart(0);
	}
}

void SettingsScreenView::ClickMasterClkOnI2S()
{
	if (chbxMCLKON.getState())
		GuiItfSetKarunaMasterClkOnI2S(1);
	else
		GuiItfSetKarunaMasterClkOnI2S(0);
}
