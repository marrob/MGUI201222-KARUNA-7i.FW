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
     
protected:

};

#endif // SERVICESCREENVIEW_HPP
