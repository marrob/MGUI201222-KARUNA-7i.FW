#ifndef SETTINGSSCREENVIEW_HPP
#define SETTINGSSCREENVIEW_HPP

#include <gui_generated/settingsscreen_screen/SettingsScreenViewBase.hpp>
#include <gui/settingsscreen_screen/SettingsScreenPresenter.hpp>
#include <gui/common/BackendCommunicator.hpp>

class SettingsScreenView : public SettingsScreenViewBase
{
public: 

    SettingsScreenView();
    virtual ~SettingsScreenView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
         
protected:
    BackendCommunicator mCommunicator;

};

#endif  //SETTINGSSCREENVIEW_HPP
