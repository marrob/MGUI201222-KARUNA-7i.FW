#ifndef DEBUGSCREENVIEW_HPP
#define DEBUGSCREENVIEW_HPP

#include <gui_generated/debugscreen_screen/DebugScreenViewBase.hpp>
#include <gui/debugscreen_screen/DebugScreenPresenter.hpp>

class DebugScreenView : public DebugScreenViewBase
{
public:
    DebugScreenView();
    virtual ~DebugScreenView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();

    virtual void OnClickDO_0();
    virtual void OnClickDO_1();
    virtual void OnClickDO_2();
    virtual void OnClickDO_3();
    virtual void OnClickDO_4();
    virtual void OnClickDO_5();
    virtual void OnClickDO_6();
    virtual void OnClickDO_7();

    virtual void handleTickEvent();

    void RefreshInterface();
    colortype GetOutputColor(uint8_t p_State);


#ifdef SIMULATOR
 
    float GuiItfGetTempCh0(void);
    float GuiItfGetTempCh1(void);
    float GuiItfGetTempCh2(void);
    float GuiItfGetTempCh3(void);
    void GuiItfSetDo0(uint8_t onoff);
    void GuiItfSetDo1(uint8_t onoff);
    void GuiItfSetDo2(uint8_t onoff);
    void GuiItfSetDo3(uint8_t onoff);
    void GuiItfSetDo4(uint8_t onoff);
    void GuiItfSetDo5(uint8_t onoff);
    void GuiItfSetDo6(uint8_t onoff);
    void GuiItfSetDo7(uint8_t onoff);
    uint8_t GuiItfGetDo0(void);
    uint8_t GuiItfGetDo1(void);
    uint8_t GuiItfGetDo2(void);
    uint8_t GuiItfGetDo3(void);
    uint8_t GuiItfGetDo4(void);
    uint8_t GuiItfGetDo5(void);
    uint8_t GuiItfGetDo6(void);
    uint8_t GuiItfGetDo7(void);
    uint8_t GuiItfGetDi0(void);
    uint8_t GuiItfGetDi1(void);
    uint8_t GuiItfGetDi2(void);
    uint8_t GuiItfGetDi3(void);
    uint8_t GuiItfGetDi4(void);
    uint8_t GuiItfGetDi5(void);
    uint8_t GuiItfGetDi6(void);
    uint8_t GuiItfGetDi7(void);
    uint8_t GuiItfGetDi8(void);
    uint8_t GuiItfGetDi9(void);
    uint8_t GuiItfGetDi10(void);
    uint8_t GuiItfGetDi11(void);
    uint8_t GuiItfGetDi12(void);
    uint8_t GuiItfGetDi13(void);
    uint8_t GuiItfGetDi14(void);
    uint8_t GuiItfGetDi15(void);

#endif
     

protected:
};

#endif // DEBUGSCREENVIEW_HPP
