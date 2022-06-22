#ifndef SAVERSCREENVIEW_HPP
#define SAVERSCREENVIEW_HPP

#include <gui_generated/saverscreen_screen/SaverScreenViewBase.hpp>
#include <gui/saverscreen_screen/SaverScreenPresenter.hpp>

class SaverScreenView : public SaverScreenViewBase
{
public:
    SaverScreenView();
    virtual ~SaverScreenView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();

    virtual void handleTickEvent();

    void RequestCurrentTime();
    void RefreshCurrentAudio();

    bool  ToBinary(int number, int position);

    char* SetDSDPCM(uint8_t);
    char* SetBitDepth(uint8_t);
    char* SetFreq(uint8_t);

#ifdef SIMULATOR

    /*** RTC ***/ 
    void GuiItfGetRtc(time_t* dt);  
    /*** Karuna ****/
    uint8_t GuiItfGetKarunaStatus();

#endif

protected:
};

#endif // SAVERSCREENVIEW_HPP
