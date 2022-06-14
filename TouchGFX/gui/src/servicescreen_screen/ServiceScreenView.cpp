#include <gui/servicescreen_screen/ServiceScreenView.hpp>
#include <string>

#ifdef SIMULATOR

  uint32_t mUptimeCounterSim;


  //GUI
  uint8_t ServiceScreenView::GuiItfGetVersion(char* fw, char* uid, char* pcb)
  {
    char fwGUI[25] = "220613_1242";
    char uidGUI[25] = "0123456789ABCDEF0000001";
    char pcbGUI[25] = "V01";

    fw = fwGUI;
    uid = uidGUI;
    pcb = pcbGUI;
    return GUIITF_OK;
  }


  //KARUNA
  uint8_t ServiceScreenView::GuiItfGetKarunaVersion(char* fw, char* uid, char* pcb)
  {
    //char fwDasClock[25]; char uidDasClock[25]; char pcbDasClock[25];

    fw = "220613_1243";
    uid = "0123456789ABCDEF0000002";
    pcb = "V02";
    return GUIITF_OK;
  }
  uint32_t ServiceScreenView::GuiItfGetKarunaUptimeCnt()
  {
    mUptimeCounterSim++;
    return mUptimeCounterSim;
  }

  uint8_t ServiceScreenView::GuiItfGetKarunaStatus()
  {
    return 0b00000001;
  }
  void ServiceScreenView::GuiItfKarunaControl(uint8_t p_Output)
  {
  }

  //DAS CLOCK
  uint8_t ServiceScreenView::GuiItfGetDasClockVersion(char* fw, char* uid, char* pcb)
  {
    //char fwKaruna[25]; char uidKaruna[25]; char pcbKaruna[25];

    fw = "220613_1244";
    uid = "0123456789ABCDEF0000003";
    pcb = "V03";
    return GUIITF_OK;
  }
  uint32_t ServiceScreenView::GuiItfGetDasClockUptimeCnt()
  {
    mUptimeCounterSim++;
    return mUptimeCounterSim;
  }

  double ServiceScreenView::GuiItfGetDasClockMV341Temp()
  {
    return 50.0;
  }
  double ServiceScreenView::GuiItfGetDasClockMVOCX1Temp()
  {
    return 55.1;
  }
  double ServiceScreenView::GuiItfGetDasClockMVOCX2Temp()
  {
    return 60.2;
  }

  double ServiceScreenView::GuiItfGetDasClockMV341Current()
  {
    return 550.0;
  }
  double ServiceScreenView::GuiItfGetDasClockMVOCX1Current()
  {
    return 160.1;
  }
  double ServiceScreenView::GuiItfGetDasClockMVOCX2Current()
  {
    return 160.2;
  }

  double ServiceScreenView::GuiItfGetDasClockMainVoltage()
  {
    return 12.5;
  }
  double ServiceScreenView::GuiItfGetDasClockRefVoltage()
  {
    return 6.25;
  }

  bool ServiceScreenView::GuiItfGetDasClockStatusLock1()
  {
    return true;
  }
  bool ServiceScreenView::GuiItfGetDasClockStatusLock2()
  {
    return true;
  }
  bool ServiceScreenView::GuiItfGetDasClockIsExt()
  {
    return false;
  }


#else
  extern "C"
  {
    /*** GUI ***/
    uint8_t GuiItfGetVersion(char* fw, char* uid, char* pcb);

    //KARUNA
    uint8_t GuiItfGetKarunaVersion(char* fw, char* uid, char* pcb);
    uint32_t GuiItfGetKarunaUptimeCnt();

    uint8_t GuiItfGetKarunaStatus();
    void GuiItfKarunaControl(uint8_t p_Output);

    /*** DasClock ***/
    uint8_t GuiItfGetDasClockVersion(char* fw, char* uid, char* pcb);
    uint32_t GuiItfGetDasClockUptimeCnt();

    float GuiItfGetDasClockMV341Temp();
    float GuiItfGetDasClockMVOCX1Temp();
    float GuiItfGetDasClockMVOCX2Temp();

    float GuiItfGetDasClockMV341Current();
    float GuiItfGetDasClockMVOCX1Current();
    float GuiItfGetDasClockMVOCX2Current();

    float GuiItfGetDasClockMainVoltage();

    bool GuiItfGetDasClockStatusLock1();
    bool GuiItfGetDasClockStatusLock2();
    bool GuiItfGetDasClockIsExt();


  }
#endif

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
	uint32_t uptimeKaruna = GuiItfGetKarunaUptimeCnt();
	uint32_t uptimeDasClock = GuiItfGetDasClockUptimeCnt();

	Unicode::snprintf(lblKarunaUptimeBuffer, 11, "%d", uptimeKaruna);
	Unicode::snprintf(lblClockUptimeBuffer, 11, "%d", uptimeDasClock);

	//Clock temperature
	float MV341_temp = GuiItfGetDasClockMV341Temp();
	float OCXO_1_temp = GuiItfGetDasClockMVOCX1Temp();
	float OCXO_2_temp = GuiItfGetDasClockMVOCX2Temp();

	Unicode::snprintfFloat(lblClocktemp_0Buffer, 11, "%0.2f", MV341_temp);
	Unicode::snprintfFloat(lblClocktemp_1Buffer, 11, "%0.2f", OCXO_1_temp);
	Unicode::snprintfFloat(lblClocktemp_2Buffer, 11, "%0.2f", OCXO_2_temp);

	//Clock Current
	float MV341_Current = GuiItfGetDasClockMV341Current();
	float OCXO_1_Current = GuiItfGetDasClockMVOCX1Current();
	float OCXO_2_Current = GuiItfGetDasClockMVOCX2Current();

	Unicode::snprintfFloat(lblClockCurrent_0Buffer, 11, "%0.2f", MV341_Current);
	Unicode::snprintfFloat(lblClockCurrent_1Buffer, 11, "%0.2f", OCXO_1_Current);
	Unicode::snprintfFloat(lblClockCurrent_2Buffer, 11, "%0.2f", OCXO_2_Current);

	//Clock Voltage
	float MainVoltage = GuiItfGetDasClockMainVoltage();

	Unicode::snprintfFloat(lblDASClockSupplyVoltageBuffer, 11, "%0.2f", MainVoltage);

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

	GuiItfGetVersion(fwGUI, uidGUI, pcbGUI);
	GuiItfGetKarunaVersion(fwKaruna, uidKaruna, pcbKaruna);
	GuiItfGetDasClockVersion(fwDasClock, uidDasClock, pcbDasClock);

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
