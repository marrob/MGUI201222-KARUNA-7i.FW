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
protected:
};

#endif // LOGSCREENVIEW_HPP
