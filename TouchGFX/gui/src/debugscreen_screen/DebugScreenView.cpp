#include <gui/debugscreen_screen/DebugScreenView.hpp>
#include <touchgfx/Color.hpp>

int mTickCountDebug;

#ifdef SIMULATOR

float DebugScreenView::GuiItfGetTempCh0(void)
{
	return 50.42;
}
float DebugScreenView::GuiItfGetTempCh1(void)
{
	return 51.42;
}
float DebugScreenView::GuiItfGetTempCh2(void)
{
	return 52.42;
}
float DebugScreenView::GuiItfGetTempCh3(void)
{
	return 53.42;
}
void DebugScreenView::GuiItfSetDo0(uint8_t onoff) {}
void DebugScreenView::GuiItfSetDo1(uint8_t onoff) {}
void DebugScreenView::GuiItfSetDo2(uint8_t onoff) {}
void DebugScreenView::GuiItfSetDo3(uint8_t onoff) {}
void DebugScreenView::GuiItfSetDo4(uint8_t onoff) {}
void DebugScreenView::GuiItfSetDo5(uint8_t onoff) {}
void DebugScreenView::GuiItfSetDo6(uint8_t onoff) {}
void DebugScreenView::GuiItfSetDo7(uint8_t onoff) {}

uint8_t DebugScreenView::GuiItfGetDo0(void) {
	return 1;
}
uint8_t DebugScreenView::GuiItfGetDo1(void) {
	return 0;
}
uint8_t DebugScreenView::GuiItfGetDo2(void) {
	return 0;
}
uint8_t DebugScreenView::GuiItfGetDo3(void) {
	return 0;
}
uint8_t DebugScreenView::GuiItfGetDo4(void) {
	return 1;
}
uint8_t DebugScreenView::GuiItfGetDo5(void) {
	return 0;
}
uint8_t DebugScreenView::GuiItfGetDo6(void) {
	return 0;
}
uint8_t DebugScreenView::GuiItfGetDo7(void) {
	return 0;
}
uint8_t DebugScreenView::GuiItfGetDi0(void) {
	return 1;
}
uint8_t DebugScreenView::GuiItfGetDi1(void) {
	return 0;
}
uint8_t DebugScreenView::GuiItfGetDi2(void) {
	return 0;
}
uint8_t DebugScreenView::GuiItfGetDi3(void) {
	return 0;
}
uint8_t DebugScreenView::GuiItfGetDi4(void) {
	return 1;
}
uint8_t DebugScreenView::GuiItfGetDi5(void) {
	return 0;
}
uint8_t DebugScreenView::GuiItfGetDi6(void) {
	return 0;
}
uint8_t DebugScreenView::GuiItfGetDi7(void) {
	return 0;
}
uint8_t DebugScreenView::GuiItfGetDi8(void) {
	return 1;
}
uint8_t DebugScreenView::GuiItfGetDi9(void) {
	return 0;
}
uint8_t DebugScreenView::GuiItfGetDi10(void) {
	return 0;
}
uint8_t DebugScreenView::GuiItfGetDi11(void) {
	return 0;
}
uint8_t DebugScreenView::GuiItfGetDi12(void) {
	return 1;
}
uint8_t DebugScreenView::GuiItfGetDi13(void) {
	return 0;
}
uint8_t DebugScreenView::GuiItfGetDi14(void) {
	return 0;
}
uint8_t DebugScreenView::GuiItfGetDi15(void) {
	return 0;
}


#else
extern "C"
{


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


}
#endif
 

DebugScreenView::DebugScreenView()
{
 
}

void DebugScreenView::setupScreen()
{
	DebugScreenViewBase::setupScreen();
}

void DebugScreenView::tearDownScreen()
{
	DebugScreenViewBase::tearDownScreen();
}

void DebugScreenView::OnClickDO_0()
{
	GuiItfSetDo0(tbOut0.getState());
}

void DebugScreenView::OnClickDO_1()
{
	GuiItfSetDo0(tbOut1.getState());
}

void DebugScreenView::OnClickDO_2()
{
	GuiItfSetDo0(tbOut2.getState());
}

void DebugScreenView::OnClickDO_3()
{
	GuiItfSetDo0(tbOut3.getState());
}

void DebugScreenView::OnClickDO_4()
{
	GuiItfSetDo0(tbOut4.getState());
}

void DebugScreenView::OnClickDO_5()
{
	GuiItfSetDo0(tbOut5.getState());
}

void DebugScreenView::OnClickDO_6()
{
	GuiItfSetDo0(tbOut6.getState());
}

void DebugScreenView::OnClickDO_7()
{
	GuiItfSetDo0(tbOut7.getState());
}

void DebugScreenView::RefreshInterface()
{
	//circLED0.set GuiItfGetDo0(void) > 


	circLED0Painter.setColor(GetOutputColor(GuiItfGetDi0()));
	circLED0.invalidate();
	circLED1Painter.setColor(GetOutputColor(GuiItfGetDi1()));
	circLED1.invalidate();
	circLED2Painter.setColor(GetOutputColor(GuiItfGetDi2()));
	circLED2.invalidate();
	circLED3Painter.setColor(GetOutputColor(GuiItfGetDi3()));
	circLED3.invalidate();
	circLED4Painter.setColor(GetOutputColor(GuiItfGetDi4()));
	circLED4.invalidate();
	circLED5Painter.setColor(GetOutputColor(GuiItfGetDi5()));
	circLED5.invalidate();
	circLED6Painter.setColor(GetOutputColor(GuiItfGetDi6()));
	circLED6.invalidate();
	circLED7Painter.setColor(GetOutputColor(GuiItfGetDi7()));
	circLED7.invalidate();
	circLED8Painter.setColor(GetOutputColor(GuiItfGetDi8()));
	circLED8.invalidate();
	circLED9Painter.setColor(GetOutputColor(GuiItfGetDi9()));
	circLED9.invalidate();
	circLED10Painter.setColor(GetOutputColor(GuiItfGetDi10()));
	circLED10.invalidate();
	circLED11Painter.setColor(GetOutputColor(GuiItfGetDi11()));
	circLED11.invalidate();
	circLED12Painter.setColor(GetOutputColor(GuiItfGetDi12()));
	circLED12.invalidate();
	circLED13Painter.setColor(GetOutputColor(GuiItfGetDi13()));
	circLED13.invalidate();
	circLED14Painter.setColor(GetOutputColor(GuiItfGetDi14()));
	circLED14.invalidate();
	circLED15Painter.setColor(GetOutputColor(GuiItfGetDi15()));
	circLED15.invalidate();

	float ai_0 = GuiItfGetTempCh0();
	Unicode::snprintfFloat(lblAI0Buffer, 11, "%0.2f", ai_0);
	lblAI0.invalidate();

	float ai_1 = GuiItfGetTempCh1();
	Unicode::snprintfFloat(lblAI1Buffer, 11, "%0.2f", ai_1);
	lblAI1.invalidate();

	float ai_2 = GuiItfGetTempCh2();
	Unicode::snprintfFloat(lblAI2Buffer, 11, "%0.2f", ai_2);
	lblAI2.invalidate();

	float ai_3 = GuiItfGetTempCh3();
	Unicode::snprintfFloat(lblAI3Buffer, 11, "%0.2f", ai_3);
	lblAI3.invalidate();

	//lblAI0
/*
*	Meghívja a click eseményt a rohadék
* 
	tbOut0.forceState(GuiItfGetDo0());
	tbOut1.forceState(GuiItfGetDo1());
	tbOut2.forceState(GuiItfGetDo2());
	tbOut3.forceState(GuiItfGetDo3());
	tbOut4.forceState(GuiItfGetDo4());
	tbOut5.forceState(GuiItfGetDo5());
	tbOut6.forceState(GuiItfGetDo6());
	tbOut7.forceState(GuiItfGetDo7());*/ 
	 
}

colortype DebugScreenView::GetOutputColor(uint8_t p_State)
{ 
	if (p_State)
	{
		return touchgfx::Color::getColorFrom24BitRGB(150, 118, 73);
	}
	else
	{
		return touchgfx::Color::getColorFrom24BitRGB(128, 128, 128);
	}
}

void DebugScreenView::handleTickEvent() 
{
	mTickCountDebug++;
	//Wait for 0.5sec
	if (mTickCountDebug % 30 == 0)
	{
		RefreshInterface(); 
	}
}