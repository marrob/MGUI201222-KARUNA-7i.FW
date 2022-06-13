#include <gui/servicescreen_screen/ServiceScreenView.hpp>
#include <string>

int mTickCountService;

ServiceScreenView::ServiceScreenView()
{
	GetVersionInfo();
}

void ServiceScreenView::setupScreen()
{
	ServiceScreenViewBase::setupScreen();
}

void ServiceScreenView::tearDownScreen()
{
	ServiceScreenViewBase::tearDownScreen();
}

void ServiceScreenView::handleTickEvent()
{
	mTickCountService++;
	//Wait for 0.5sec
	if (mTickCountService % 30 == 0)
	{
		RefreshServiceInfo();
	}
}

void ServiceScreenView::RefreshServiceInfo()
{
	//Upime counter
	uint32_t uptimeKaruna = mCommunicator.GuiItfGetKarunaUptimeCnt();
	uint32_t uptimeDasClock = mCommunicator.GuiItfGetDasClockUptimeCnt();

	Unicode::snprintf(lblKarunaUptimeBuffer, 11, "%d", uptimeKaruna);
	Unicode::snprintf(lblClockUptimeBuffer, 11, "%d", uptimeDasClock);

	//Clock temperature
	float MV341_temp = (float)mCommunicator.GuiItfGetDasClockMV341Temp();
	float OCXO_1_temp = (float)mCommunicator.GuiItfGetDasClockMVOCX1Temp();
	float OCXO_2_temp = (float)mCommunicator.GuiItfGetDasClockMVOCX2Temp();

	Unicode::snprintfFloat(lblClocktemp_0Buffer, 11, "%0.2f", MV341_temp);
	Unicode::snprintfFloat(lblClocktemp_1Buffer, 11, "%0.2f", OCXO_1_temp);
	Unicode::snprintfFloat(lblClocktemp_2Buffer, 11, "%0.2f", OCXO_2_temp);

	//Clock Current
	float MV341_Current = (float)mCommunicator.GuiItfGetDasClockMV341Current();
	float OCXO_1_Current = (float)mCommunicator.GuiItfGetDasClockMVOCX1Current();
	float OCXO_2_Current = (float)mCommunicator.GuiItfGetDasClockMVOCX2Current();

	Unicode::snprintfFloat(lblClockCurrent_0Buffer, 11, "%0.2f", MV341_Current);
	Unicode::snprintfFloat(lblClockCurrent_1Buffer, 11, "%0.2f", OCXO_1_Current);
	Unicode::snprintfFloat(lblClockCurrent_2Buffer, 11, "%0.2f", OCXO_2_Current);

	//Clock Voltage
	float MainVoltage = (float)mCommunicator.GuiItfGetDasClockMainVoltage();
	float RefVoltage = (float)mCommunicator.GuiItfGetDasClockRefVoltage();

	Unicode::snprintfFloat(lblDASClockSupplyVoltageBuffer, 11, "%0.2f", MainVoltage);
	Unicode::snprintfFloat(lblDASClockRefVoltageBuffer, 11, "%0.2f", RefVoltage);

	lblKarunaUptime.invalidate();
	lblClockUptime.invalidate();
	lblClocktemp_0.invalidate();
	lblClocktemp_1.invalidate();
	lblClocktemp_2.invalidate();
	lblClockCurrent_0.invalidate();
	lblClockCurrent_1.invalidate();
	lblClockCurrent_2.invalidate();
	lblDASClockSupplyVoltage.invalidate();
	lblDASClockRefVoltage.invalidate();
}

void ServiceScreenView::GetVersionInfo()
{
	std::string sep = " - ";
	char* fwGUI = nullptr; char* uidGUI = nullptr; char* pcbGUI = nullptr;
	char* fwKaruna = nullptr; char* uidKaruna = nullptr; char* pcbKaruna = nullptr;
	char* fwDasClock = nullptr; char* uidDasClock = nullptr; char* pcbDasClock = nullptr;

	mCommunicator.GuiItfGetVersion(fwGUI, uidGUI, pcbGUI);
	mCommunicator.GuiItfGetKarunaVersion(fwKaruna, uidKaruna, pcbKaruna);
	mCommunicator.GuiItfGetDasClockVersion(fwDasClock, uidDasClock, pcbDasClock);

	std::string FW = fwGUI + sep + uidGUI + sep + pcbGUI;
	int length = FW.length();
	Unicode::strncpy(lblGUIFwVersionBuffer, FW.c_str(), length + 1);

	FW = fwKaruna + sep + uidKaruna + sep + pcbKaruna;
	length = FW.length();
	Unicode::strncpy(lblKarunaFwVersionBuffer, FW.c_str(), length + 1);

	FW = fwDasClock + sep + uidDasClock + sep + pcbDasClock;
	length = FW.length();
	Unicode::strncpy(lblDASClockFwVersionBuffer, FW.c_str(), length + 1);

	lblGUIFwVersion.invalidate();
	lblKarunaFwVersion.invalidate();
	lblDASClockFwVersion.invalidate();
}
