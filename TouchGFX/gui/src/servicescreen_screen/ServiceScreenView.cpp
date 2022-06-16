#include <gui/servicescreen_screen/ServiceScreenView.hpp>
#include <string>

#ifdef SIMULATOR

  uint32_t mUptimeCounterSim;

  /*** GUI ***/
  uint8_t ServiceScreenView::GuiItfGetVersion(char **fw, char **uid, char **pcb)
  {
    char _fw[25] = "220613_1241";
    char _uidI[25] = "0123456789ABCDEF0000001";
    char _pcb[25] =  "V01" ;
    *fw = _fw;
    *uid = _uidI;
    *pcb = _pcb;
    return 0;
  }

  /*** Karuna ***/
  uint8_t ServiceScreenView::GuiItfGetKarunaVersion(char **fw, char **uid, char **pcb)
  {
    char _fw[25] = "220613_1242";
    char _uidI[25] = "0123456789ABCDEF0000002";
    char _pcb[25] =  "V02" ;
    *fw = _fw;
    *uid = _uidI;
    *pcb = _pcb;
    return 0;
  }
  uint32_t ServiceScreenView::GuiItfGetKarunaUptimeCnt()
  {
    mUptimeCounterSim++;
    return mUptimeCounterSim;
  }

  /*** DasClock ***/
  uint8_t ServiceScreenView::GuiItfGetDasClockVersion(char **fw, char **uid, char **pcb)
  {
    char _fw[25] = "220613_1243";
    char _uidI[25] = "0123456789ABCDEF0000003";
    char _pcb[25] =  "V03" ;
    *fw = _fw;
    *uid = _uidI;
    *pcb = _pcb;
    return 0;
  }
  uint32_t ServiceScreenView::GuiItfGetDasClockUptimeCnt()
  {
    mUptimeCounterSim++;
    return mUptimeCounterSim;
  }
  float ServiceScreenView::GuiItfGetDasClockMV341Temp()
  {
    return 50.0;
  }
  float ServiceScreenView::GuiItfGetDasClockMVOCX1Temp()
  {
    return 55.1f;
  }
  float ServiceScreenView::GuiItfGetDasClockMVOCX2Temp()
  {
    return 60.2f;
  }
  float ServiceScreenView::GuiItfGetDasClockMV341Current()
  {
    return 550.0f;
  }
  float ServiceScreenView::GuiItfGetDasClockMVOCX1Current()
  {
    return 160.1f;
  }
  float ServiceScreenView::GuiItfGetDasClockMVOCX2Current()
  {
    return 160.2f;
  }
  float ServiceScreenView::GuiItfGetDasClockMainVoltage()
  {
    return 12.5f;
  }
#else
  extern "C"
  {
    /*** GUI ***/
    uint8_t GuiItfGetVersion(char **fw, char **uid, char **pcb);

    /*** Karuna ***/
    uint8_t GuiItfGetKarunaVersion(char **fw, char **uid, char **pcb);
    uint32_t GuiItfGetKarunaUptimeCnt();

    /*** DasClock ***/
    uint8_t GuiItfGetDasClockVersion(char **fw, char **uid, char **pcb);
    uint32_t GuiItfGetDasClockUptimeCnt();

    float GuiItfGetDasClockMV341Temp();
    float GuiItfGetDasClockMVOCX1Temp();
    float GuiItfGetDasClockMVOCX2Temp();

    float GuiItfGetDasClockMV341Current();
    float GuiItfGetDasClockMVOCX1Current();
    float GuiItfGetDasClockMVOCX2Current();

    float GuiItfGetDasClockMainVoltage();
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
}

void ServiceScreenView::GetVersionInfo()
{
  std::string sep = " - ";
  char *fw = nullptr;
  char *uid = nullptr;
  char *pcb = nullptr;
  Unicode::UnicodeChar uni_fw[25];
  Unicode::UnicodeChar uni_uid[25];
  Unicode::UnicodeChar uni_pcb[25];

  GuiItfGetVersion(&fw, &uid, &pcb);
  Unicode::fromUTF8((const uint8_t*)fw, uni_fw, sizeof(uni_fw));
  Unicode::fromUTF8((const uint8_t*)uid, uni_uid, sizeof(uni_uid));
  Unicode::fromUTF8((const uint8_t*)pcb, uni_pcb, sizeof(uni_pcb));
  Unicode::snprintf(lblGUIFwVersionBuffer, sizeof(lblGUIFwVersionBuffer), "%s-%s-%s", uni_fw, uni_uid, uni_pcb);

  GuiItfGetKarunaVersion(&fw, &uid, &pcb);
  Unicode::fromUTF8((const uint8_t*)fw, uni_fw, sizeof(uni_fw));
  Unicode::fromUTF8((const uint8_t*)uid, uni_uid, sizeof(uni_uid));
  Unicode::fromUTF8((const uint8_t*)pcb, uni_pcb, sizeof(uni_pcb));
  Unicode::snprintf(lblKarunaFwVersionBuffer, sizeof(lblKarunaFwVersionBuffer), "%s-%s-%s", uni_fw, uni_uid, uni_pcb);

  GuiItfGetDasClockVersion(&fw, &uid, &pcb);
  Unicode::fromUTF8((const uint8_t*)fw, uni_fw, sizeof(uni_fw));
  Unicode::fromUTF8((const uint8_t*)uid, uni_uid, sizeof(uni_uid));
  Unicode::fromUTF8((const uint8_t*)pcb, uni_pcb, sizeof(uni_pcb));
  Unicode::snprintf(lblDASClockFwVersionBuffer, sizeof(lblDASClockFwVersionBuffer), "%s-%s-%s", uni_fw, uni_uid, uni_pcb);

  lblGUIFwVersion.invalidate();
  lblKarunaFwVersion.invalidate();
  lblDASClockFwVersion.invalidate();
}
