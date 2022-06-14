#ifndef SERVICESCREENVIEW_HPP
#define SERVICESCREENVIEW_HPP

#include <gui_generated/servicescreen_screen/ServiceScreenViewBase.hpp>
#include <gui/servicescreen_screen/ServiceScreenPresenter.hpp>


class ServiceScreenView : public ServiceScreenViewBase
{
public:
    ServiceScreenView();
    virtual ~ServiceScreenView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
    virtual void handleTickEvent();
    void RefreshServiceInfo();
    void GetVersionInfo();

#ifdef SIMULATOR

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

#endif
     
protected:

};

#endif // SERVICESCREENVIEW_HPP
