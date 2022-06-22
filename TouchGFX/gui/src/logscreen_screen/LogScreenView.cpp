#include <gui/logscreen_screen/LogScreenView.hpp>
#include <stdio.h>

enum LogDirection
{
	UnknownDir = 0,
	Next,
	Prev
};

int mActLogPointer;
ScrollElment* mScrollItems[10];
int guiLines = 10;


LogDirection mDir;


#ifdef SIMULATOR

/*** Log ***/
uint32_t LogScreenView::GuiItfLogGetLastAddress(void)
{
	return 7;
}
void LogScreenView::GuitItfLogGetLine(uint32_t address, char* line, uint32_t size)
{
	char logText[] = "The main difference is that t number of specified bytes ; strcpy() and other str methods, on the other hand, will copy until it reads a NULL () byte, and then stop after that. strcpy() is not intended to be used with zero-terminated C-strings.";
	char buf[256];
	snprintf(buf, 256, "%d.) %s", address, logText);
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
	mActLogPointer = GuiItfLogGetLastAddress();
}

void LogScreenView::setupScreen()
{
	LogScreenViewBase::setupScreen();
	mScrollItems[0] = &scrollElment_0;
	mScrollItems[1] = &scrollElment_1;
	mScrollItems[2] = &scrollElment_2;
	mScrollItems[3] = &scrollElment_3;
	mScrollItems[4] = &scrollElment_4;
	mScrollItems[5] = &scrollElment_5;
	mScrollItems[6] = &scrollElment_6;
	mScrollItems[7] = &scrollElment_7;
	mScrollItems[8] = &scrollElment_8;
	mScrollItems[9] = &scrollElment_9;

	OnClickPrevPage();
}

void LogScreenView::tearDownScreen()
{
	LogScreenViewBase::tearDownScreen();
}

void LogScreenView::OnClickNextPage()
{

	char buf[256];

	//Clear list
	buf[0] = 0;
	for (int i = 0; i < guiLines; i++)
	{
		mScrollItems[i]->SetText(buf);
	}

	if (mDir == LogDirection::Prev)
	{
		DecLogPointer();
	}

	int lineNumber = 0;
	while (mActLogPointer - lineNumber >= 0)
	{
		GuitItfLogGetLine(mActLogPointer - lineNumber, buf, sizeof(buf));
		mScrollItems[lineNumber]->SetText(buf);

		lineNumber++;
		if (lineNumber >= guiLines)
		{
			break;
		}
	}

	DecLogPointer();
	mDir = LogDirection::Next;
	scrollableCont.doScroll(0, 2000);
}

void LogScreenView::OnClickPrevPage()
{
	char buf[256];

	//Clear list
	buf[0] = 0;
	for (int i = 0; i < guiLines; i++)
	{
		mScrollItems[i]->SetText(buf);
	}

	if (mDir == LogDirection::Next)
	{
		IncLogPointer();
	}

	int lineNumber = 0;
	while (mActLogPointer - lineNumber >= 0)
	{
		GuitItfLogGetLine(mActLogPointer - lineNumber, buf, sizeof(buf));
		mScrollItems[lineNumber]->SetText(buf);

		//mActLogPointer--;
		lineNumber++;
		if (lineNumber >= guiLines)
		{
			break;
		}
	}
	IncLogPointer();
	mDir = LogDirection::Prev;
	scrollableCont.doScroll(0, 2000);
}


void LogScreenView::IncLogPointer()
{
	int maxLogPointer = GuiItfLogGetLastAddress();

	mActLogPointer += guiLines;
	if (mActLogPointer > maxLogPointer)
	{
		mActLogPointer = maxLogPointer;
	}
}


void LogScreenView::DecLogPointer()
{
	int maxLogPointer = GuiItfLogGetLastAddress();

	mActLogPointer -= guiLines;
	if (mActLogPointer < 0)
	{
		mActLogPointer = guiLines - 1;
	}

	if (mActLogPointer > maxLogPointer)
	{
		mActLogPointer = maxLogPointer;
	}

}
