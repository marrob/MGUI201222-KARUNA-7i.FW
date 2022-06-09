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

    virtual void handleTickEvent();
     
#ifdef SIMULATOR
    uint32_t GuiItfGetKarunaUptimeCnt();
    uint32_t  GuiItfGetDASCLOCKUptimeCnt();
#endif

protected:

};

#endif  SETTINGSSCREENVIEW_HPP
