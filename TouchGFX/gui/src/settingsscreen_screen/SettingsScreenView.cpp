#include <gui/settingsscreen_screen/SettingsScreenView.hpp>

int mTickGUICount;

#ifdef SIMULATOR
uint8_t SettingsScreenView::GuiItfGetKarunaOutputsAllEnabledAfterStart()
{
}
void SettingsScreenView::GuiItfBacklightDisable()
{
}
#else
extern "C"
{
  uint8_t GuiItfGetKarunaOutputsAllEnabledAfterStart();
  void GuiItfSetKarunaOutputsIsAllEnabledAfterStart(uint8_t onoff);
}
#endif


SettingsScreenView::SettingsScreenView()
{
  if(GuiItfGetKarunaOutputsAllEnabledAfterStart())
    radioButtonGroup1.setSelected(rdbtnEnableAll);
  else
    radioButtonGroup1.setSelected(rdbtnLastState);
}

void SettingsScreenView::setupScreen()
{
    SettingsScreenViewBase::setupScreen(); 
}

void SettingsScreenView::tearDownScreen()
{
    SettingsScreenViewBase::tearDownScreen();
} 

void SettingsScreenView::RdbBtnSelectEnableAllOutputAtStartUp()
{
  GuiItfSetKarunaOutputsIsAllEnabledAfterStart(1);
}

void SettingsScreenView::RdbBtnSelectLastOutputStatAtStartUp()
{
  GuiItfSetKarunaOutputsIsAllEnabledAfterStart(0);
}
