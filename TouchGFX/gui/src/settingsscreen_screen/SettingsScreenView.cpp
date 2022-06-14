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
}

void SettingsScreenView::setupScreen()
{
    SettingsScreenViewBase::setupScreen(); 
}

void SettingsScreenView::tearDownScreen()
{
    SettingsScreenViewBase::tearDownScreen();
} 
