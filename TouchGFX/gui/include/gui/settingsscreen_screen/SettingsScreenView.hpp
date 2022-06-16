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

    virtual void scrollYearUpdateItem(textContainer& item, int16_t itemIndex);
    virtual void scrollYearUpdateCenterItem(TextContainerHigh& item, int16_t itemIndex);
    virtual void scrollMonthUpdateItem(textContainer& item, int16_t itemIndex);
    virtual void scrollMonthUpdateCenterItem(TextContainerHigh& item, int16_t itemIndex);
    virtual void scrollDayUpdateItem(textContainer& item, int16_t itemIndex);
    virtual void scrollDayUpdateCenterItem(TextContainerHigh& item, int16_t itemIndex);


    virtual void scrollHourUpdateItem(textContainer& item, int16_t itemIndex);
    virtual void scrollHourUpdateCenterItem(TextContainerHigh& item, int16_t itemIndex);
    virtual void scrollMinUpdateItem(textContainer& item, int16_t itemIndex);
    virtual void scrollMinUpdateCenterItem(TextContainerHigh& item, int16_t itemIndex);
    virtual void scrollSecUpdateItem(textContainer& item, int16_t itemIndex);
    virtual void scrollSecUpdateCenterItem(TextContainerHigh& item, int16_t itemIndex);

#ifdef SIMULATOR
    uint8_t GuiItfGetKarunaOutputsAllEnabledAfterStart(void);
    void GuiItfSetKarunaOutputsAllEnabledAfterStart(uint8_t onoff);
    void GuiItfSetKarunaMasterClkOnI2S(uint8_t onoff);
    uint8_t GuiItfGetKarunaMasterClkOnI2SIsEnabled(void);
#endif


protected:

};

#endif  //SETTINGSSCREENVIEW_HPP
