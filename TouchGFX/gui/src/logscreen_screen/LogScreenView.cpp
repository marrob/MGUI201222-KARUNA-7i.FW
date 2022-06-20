#include <gui/logscreen_screen/LogScreenView.hpp>
#include <stdio.h>

#ifdef SIMULATOR

uint32_t simLogPointer;
/*** Log ***/
uint32_t LogScreenView::GuiItfLogGetLastAddress(void)
{
	if (simLogPointer >= 10)
	{
		simLogPointer = 0;
	}
	return simLogPointer++;
}
void LogScreenView::GuitItfLogGetLine(uint32_t address, char* line, uint32_t size)
{
	char buf[256] = "The main difference is that t number of specified bytes ; strcpy() and other str methods, on the other hand, will copy until it reads a NULL () byte, and then stop after that. strcpy() is not intended to be used with zero-terminated C-strings.";
	strcpy(line, buf); 
}

#else
extern "C"
{
	/*** Log ***/
	uint32_t GuiItfLogGetLastAddress(void);
	void GuitItfLogGetLine(uint32_t address, char* line, uint32_t size);
}
#endif

LogScreenView::LogScreenView()
{
	 
}

void LogScreenView::setupScreen()
{
	LogScreenViewBase::setupScreen();
}

void LogScreenView::tearDownScreen()
{
	LogScreenViewBase::tearDownScreen();
}

void LogScreenView::OnClickNextPage()
{
	for (int i = 0; i < scrollLogListItems.getNumberOfDrawables(); i++)
	{ 
		char buf[256];
		//for (uint32_t i = 0; i < 1/*GuiItfLogGetLastAddress()*/; i++)
		{
			GuitItfLogGetLine(i, buf, sizeof(buf)); 
		}

		 scrollLogListItems[i].SetText(buf); 
	}
}

void LogScreenView::OnClickPrevPage()
{
	for (int i = 0; i < scrollLogListItems.getNumberOfDrawables(); i++)
	{
		char buf[256];
		//for (uint32_t i = 0; i < 1/*GuiItfLogGetLastAddress()*/; i++)
		{
			GuitItfLogGetLine(i, buf, sizeof(buf));
		}

		scrollLogListItems[i].SetText(buf);
	}
}