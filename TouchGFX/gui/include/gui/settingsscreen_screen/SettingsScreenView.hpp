#ifndef SETTINGSSCREENVIEW_HPP
#define SETTINGSSCREENVIEW_HPP

#include <gui_generated/settingsscreen_screen/SettingsScreenViewBase.hpp>
#include <gui/settingsscreen_screen/SettingsScreenPresenter.hpp>

class SettingsScreenView : public SettingsScreenViewBase
{
public: 

    SettingsScreenView();
    virtual ~SettingsScreenView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();

    virtual void RdbBtnSelectEnableAllOutputAtStartUp();
    virtual void RdbBtnSelectLastOutputStatAtStartUp();
    virtual void ClickMasterClkOnI2S();


#ifdef SIMULATOR
    uint8_t GuiItfGetKarunaOutputsAllEnabledAfterStart(void);
    void GuiItfSetKarunaOutputsAllEnabledAfterStart(uint8_t onoff);
    void GuiItfSetKarunaMasterClkOnI2S(uint8_t onoff);
    uint8_t GuiItfGetKarunaMasterClkOnI2SIsEnabled(void);
#endif


protected:

};

#endif  //SETTINGSSCREENVIEW_HPP
