#ifndef SERVICESCREENVIEW_HPP
#define SERVICESCREENVIEW_HPP

#include <gui_generated/servicescreen_screen/ServiceScreenViewBase.hpp>
#include <gui/servicescreen_screen/ServiceScreenPresenter.hpp>
#include <gui/common/BackendCommunicator.hpp>

class ServiceScreenView : public ServiceScreenViewBase
{
public:
    ServiceScreenView();
    virtual ~ServiceScreenView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();

    virtual void handleTickEvent();

    void RefreshServiceInfo();
    void GetVersionInfo();
     
protected:
    BackendCommunicator mCommunicator;

};

#endif // SERVICESCREENVIEW_HPP
