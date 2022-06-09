#include <gui/settingsscreen_screen/SettingsScreenView.hpp>

uint32_t mUptimeCounter;
int mTickGUICount;

#ifdef SIMULATOR

uint32_t SettingsScreenView::GuiItfGetKarunaUptimeCnt()
{
  mUptimeCounter++;
  return mUptimeCounter;
}

uint32_t SettingsScreenView::GuiItfGetDASCLOCKUptimeCnt()
{
	mUptimeCounter++;
	return mUptimeCounter;
}

#else
extern "C"
{ 
	uint32_t GuiItfGetKarunaUptimeCnt();
	uint32_t GuiItfGetDASCLOCKUptimeCnt();
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

void SettingsScreenView::handleTickEvent()
{
	mTickGUICount++;
	//Wait for 0.5sec
	if (mTickGUICount % 30 == 0)
	{
		uint32_t uptime = GuiItfGetKarunaUptimeCnt();
		Unicode::snprintf(lblKarunaUptimeBuffer , 11, "%d", uptime);

		uint32_t uptimeClock = GuiItfGetDASCLOCKUptimeCnt();
		Unicode::snprintf(lblClockUptimeBuffer, 11, "%d", uptimeClock);

		lblKarunaUptime.invalidate();
		lblClockUptime.invalidate();
	}
}
