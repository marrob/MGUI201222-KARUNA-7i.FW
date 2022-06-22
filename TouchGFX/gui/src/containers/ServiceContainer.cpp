#include <gui/containers/ServiceContainer.hpp>


#ifdef SIMULATOR

uint32_t mUptimeCounterSim;

/*** GUI ***/
uint8_t ServiceContainer::GuiItfGetVersion(char** fw, char** uid, char** pcb)
{
    char _fw[25] = "220613_1241";
    char _uidI[25] = "0123456789ABCDEF0000001";
    char _pcb[25] = "V01";
    *fw = _fw;
    *uid = _uidI;
    *pcb = _pcb;
    return 0;
}

uint32_t ServiceContainer::GuiItfGetBootupCnt(void)
{
    return 10000;
}

uint32_t ServiceContainer::GuiItfGetBusUartErrorCnt(void)
{
    return 1;
}

void ServiceContainer::GuiItfFacotryReset(void)
{

}

void ServiceContainer::GuiItfSoftReset(void)
{

}

/*** Karuna ***/
uint8_t ServiceContainer::GuiItfGetKarunaVersion(char** fw, char** uid, char** pcb)
{
    char _fw[25] = "220613_1242";
    char _uidI[25] = "0123456789ABCDEF0000002";
    char _pcb[25] = "V02";
    *fw = _fw;
    *uid = _uidI;
    *pcb = _pcb;
    return 0;
}

uint32_t ServiceContainer::GuiItfGetKarunaUptimeCnt()
{
    mUptimeCounterSim++;
    return mUptimeCounterSim;
}

uint32_t ServiceContainer::GuiItfGetKarunaUartErrorCnt(void)
{
    return 2;
}

/*** DasClock ***/
uint8_t ServiceContainer::GuiItfGetDasClockVersion(char** fw, char** uid, char** pcb)
{
    char _fw[25] = "220613_1243";
    char _uidI[25] = "0123456789ABCDEF0000003";
    char _pcb[25] = "V03";
    *fw = _fw;
    *uid = _uidI;
    *pcb = _pcb;
    return 0;
}
uint32_t ServiceContainer::GuiItfGetDasClockUptimeCnt()
{
    mUptimeCounterSim++;
    return mUptimeCounterSim;
}
float ServiceContainer::GuiItfGetDasClockMV341Temp()
{
    return 50.0;
}
float ServiceContainer::GuiItfGetDasClockMVOCX1Temp()
{
    return 55.1f;
}
float ServiceContainer::GuiItfGetDasClockMVOCX2Temp()
{
    return 60.2f;
}
float ServiceContainer::GuiItfGetDasClockMV341Current()
{
    return 550.0f;
}
float ServiceContainer::GuiItfGetDasClockMVOCX1Current()
{
    return 160.1f;
}
float ServiceContainer::GuiItfGetDasClockMVOCX2Current()
{
    return 160.2f;
}
float ServiceContainer::GuiItfGetDasClockMainVoltage()
{
    return 12.5f;
}

uint32_t ServiceContainer::GuiItfGetDasClocUartErrorCnt(void)
{
    return 3;
}

#else
extern "C"
{
    /*** GUI ***/
    uint8_t GuiItfGetVersion(char** fw, char** uid, char** pcb);
    uint32_t GuiItfGetBootupCnt(void);
    uint32_t GuiItfGetBusUartErrorCnt(void);
    void GuiItfFacotryReset(void);
    void GuiItfSoftReset(void);

    /*** Karuna ***/
    uint8_t GuiItfGetKarunaVersion(char** fw, char** uid, char** pcb);
    uint32_t GuiItfGetKarunaUptimeCnt();
    uint32_t GuiItfGetKarunaUartErrorCnt(void);

    /*** DasClock ***/
    uint8_t GuiItfGetDasClockVersion(char** fw, char** uid, char** pcb);
    uint32_t GuiItfGetDasClockUptimeCnt();

    float GuiItfGetDasClockMV341Temp();
    float GuiItfGetDasClockMVOCX1Temp();
    float GuiItfGetDasClockMVOCX2Temp();
    float GuiItfGetDasClockMV341Current();
    float GuiItfGetDasClockMVOCX1Current();
    float GuiItfGetDasClockMVOCX2Current();
    float GuiItfGetDasClockMainVoltage();

    uint32_t GuiItfGetDasClocUartErrorCnt(void);
}
#endif

//int mTickCountService;


ServiceContainer::ServiceContainer()
{

}

void ServiceContainer::initialize()
{
    ServiceContainerBase::initialize();
    GetVersionInfo();
}

//
//void ServiceContainer::handleTickEvent()
//{
//    mTickCountService++;
//    //Wait for 0.5sec
//    if (mTickCountService % 30 == 0)
//    {
//        RefreshServiceInfo();
//    }
//}

void ServiceContainer::RefreshServiceInfo()
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
     

    uint32_t BusUartError = GuiItfGetBusUartErrorCnt();
    uint32_t DasClocUartError = GuiItfGetDasClocUartErrorCnt();
    uint32_t KarunaUartError = GuiItfGetKarunaUartErrorCnt();
    uint32_t BootUp = GuiItfGetBootupCnt();

    
    Unicode::snprintf(DasClockErrorCntBuffer, 11, "%d", DasClocUartError);
    Unicode::snprintf(lblBusUartErrorCntBuffer, 11, "%d", BusUartError );
    Unicode::snprintf(lblKarunaUartErrorCntBuffer, 11, "%d", KarunaUartError);
    Unicode::snprintf(lblBootupCntBuffer, 11, "%d", BootUp);

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

void ServiceContainer::GetVersionInfo()
{ 
    char* fw = nullptr;
    char* uid = nullptr;
    char* pcb = nullptr;
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

void ServiceContainer::OnClickFactoryReset()
{
    GuiItfFacotryReset();
}

void ServiceContainer::OnClickSoftReset()
{
    GuiItfSoftReset();
}