#ifndef LOGSCREENVIEW_HPP
#define LOGSCREENVIEW_HPP

#include <gui_generated/logscreen_screen/LogScreenViewBase.hpp>
#include <gui/logscreen_screen/LogScreenPresenter.hpp>



class LogScreenView : public LogScreenViewBase
{ 
public:

    LogScreenView();
    virtual ~LogScreenView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();

    virtual void OnClickNextPage();
    virtual void OnClickPrevPage();

    void IncLogPointer();
    void DecLogPointer();
 
#ifdef SIMULATOR
     
    /*** Log ***/
    uint32_t GuiItfLogGetLastAddress(void);
    void GuitItfLogGetLine(uint32_t address, char* line, uint32_t size); 

#endif

protected:
};

#endif // LOGSCREENVIEW_HPP
