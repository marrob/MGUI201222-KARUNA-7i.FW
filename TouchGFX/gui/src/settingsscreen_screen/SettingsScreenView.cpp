#include <gui/settingsscreen_screen/SettingsScreenView.hpp>

int mTickGUICount;

#ifdef SIMULATOR
uint8_t SettingsScreenView::GuiItfGetKarunaOutputsAllEnabledAfterStart(void)
{
	return 0;
}
void SettingsScreenView::GuiItfSetKarunaOutputsAllEnabledAfterStart(uint8_t onoff)
{
}
void SettingsScreenView::GuiItfSetKarunaMasterClkOnI2S(uint8_t onoff)
{
}
uint8_t SettingsScreenView::GuiItfGetKarunaMasterClkOnI2SIsEnabled(void)
{
	return 1;
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
	if (GuiItfGetKarunaOutputsAllEnabledAfterStart())
		radioButtonGroup1.setSelected(rdbtnEnableAll);
	else
		radioButtonGroup1.setSelected(rdbtnLastState);

	if (GuiItfGetKarunaMasterClkOnI2SIsEnabled())
		chbxMCLKON.forceState(true);
	else
		chbxMCLKON.forceState(false);
}

void SettingsScreenView::setupScreen()
{
	SettingsScreenViewBase::setupScreen();
	scrollYear.animateToItem(2022);
	scrollMonth.animateToItem(1);
	scrollDay.animateToItem(1);
}

void SettingsScreenView::tearDownScreen()
{
	SettingsScreenViewBase::tearDownScreen();
}

void SettingsScreenView::RdbBtnSelectEnableAllOutputAtStartUp()
{
	GuiItfSetKarunaOutputsAllEnabledAfterStart(1);
}

void SettingsScreenView::RdbBtnSelectLastOutputStatAtStartUp()
{
	GuiItfSetKarunaOutputsAllEnabledAfterStart(0);
}

void SettingsScreenView::ClickMasterClkOnI2S()
{
	if (chbxMCLKON.getState())
		GuiItfSetKarunaMasterClkOnI2S(1);
	else
		GuiItfSetKarunaMasterClkOnI2S(0);
}

void SettingsScreenView::scrollYearUpdateItem(textContainer& item, int16_t itemIndex)
{
	item.updateText(itemIndex);
}

void SettingsScreenView::scrollYearUpdateCenterItem(TextContainerHigh& item, int16_t itemIndex)
{
	item.updateText(itemIndex);
}

void SettingsScreenView::scrollMonthUpdateItem(textContainer& item, int16_t itemIndex)
{
	item.updateText(itemIndex + 1);
}

void SettingsScreenView::scrollMonthUpdateCenterItem(TextContainerHigh& item, int16_t itemIndex)
{
	item.updateText(itemIndex + 1);
}

void SettingsScreenView::scrollDayUpdateItem(textContainer& item, int16_t itemIndex)
{
	item.updateText(itemIndex + 1);
}

void SettingsScreenView::scrollDayUpdateCenterItem(TextContainerHigh& item, int16_t itemIndex)
{
	item.updateText(itemIndex + 1);
}


void SettingsScreenView::scrollHourUpdateItem(textContainer& item, int16_t itemIndex)
{
	item.updateText(itemIndex);
}

void SettingsScreenView::scrollHourUpdateCenterItem(TextContainerHigh& item, int16_t itemIndex)
{
	item.updateText(itemIndex);
}

void SettingsScreenView::scrollMinUpdateItem(textContainer& item, int16_t itemIndex)
{
	item.updateText(itemIndex);
}

void SettingsScreenView::scrollMinUpdateCenterItem(TextContainerHigh& item, int16_t itemIndex)
{
	item.updateText(itemIndex);
}

void SettingsScreenView::scrollSecUpdateItem(textContainer& item, int16_t itemIndex)
{
	item.updateText(itemIndex);
}

void SettingsScreenView::scrollSecUpdateCenterItem(TextContainerHigh& item, int16_t itemIndex)
{
	item.updateText(itemIndex);
}