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

#ifdef SIMULATOR
    uint8_t GuiItfGetKarunaOutputsAllEnabledAfterStart(void);
    void GuiItfSetKarunaOutputsIsAllEnabledAfterStart(uint8_t onoff);
#endif


protected:

};

#endif  //SETTINGSSCREENVIEW_HPP
