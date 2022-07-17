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
	if (mTickCountService % 30 == 0)
	{
		serviceControl.RefreshServiceInfo();
	}
}
