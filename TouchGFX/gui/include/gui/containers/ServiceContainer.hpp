#ifndef SERVICECONTAINER_HPP
#define SERVICECONTAINER_HPP

#include <gui_generated/containers/ServiceContainerBase.hpp>

class ServiceContainer : public ServiceContainerBase
{
public:
    ServiceContainer();
    virtual ~ServiceContainer() {}

    virtual void initialize();
     
    virtual void OnClickFactoryReset();
    virtual void OnClickSoftReset();
    void RefreshServiceInfo();
    void GetVersionInfo(); 


#ifdef SIMULATOR

    /*** GUI ***/
    uint8_t GuiItfGetVersion(char** fw, char** uid, char** pcb);
    uint32_t GuiItfGetBootupCnt(void);
    uint32_t GuiItfGetBusUartErrorCnt(void);
    void GuiItfFacotryReset(void);
    void GuiItfSoftReset(void);

    /*** Karuna ***/
    uint8_t GuiItfGetKarunaVersion(char** fw, char** uid, char** pcb);
    uint32_t GuiItfGetKarunaUptimeCnt();
    uint32_t GuiItfGetKarunaUartErrorCnt();

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
    uint32_t GuiItfGetClockHeatedTemperature();
    void GuiItfSetClockHeatedTemperature(uint32_t temp);

#endif


protected:

private:
    /*
     * Callback Declarations
     */
    touchgfx::Callback<ServiceContainer,uint32_t> ValueChangedTriggerCallback;
    /*
     * Callback Handler Declarations
     */
    void OffsetValueChangedCallbackHandler(uint32_t Value);
    void RefresTempRanges(uint32_t heatedTemp);
};

#endif // SERVICECONTAINER_HPP
