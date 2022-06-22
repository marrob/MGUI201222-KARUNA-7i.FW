#include <gui/servicescreen_screen/ServiceScreenView.hpp>
#include <string>

int mTickCountService;

ServiceScreenView::ServiceScreenView()
{
	//GetVersionInfo();
}

void ServiceScreenView::setupScreen()
{
	ServiceScreenViewBase::setupScreen();
}

void ServiceScreenView::tearDownScreen()
{
	ServiceScreenViewBase::tearDownScreen();
}

void ServiceScreenView::handleTickEvent()
{
	mTickCountService++;
	//Wait for 0.5sec
	if (mTickCountService % 30 == 0)
	{
		serviceControl.RefreshServiceInfo();
	}
}
