#ifndef MAIN_VIEW_HPP
#define MAIN_VIEW_HPP

#include <gui_generated/main_screen/MainViewBase.hpp>
#include <gui/main_screen/MainPresenter.hpp>

class MainView : public MainViewBase
{
public:
	MainView();
	void SetOnAllOutput();
	virtual ~MainView() {}
	virtual void setupScreen();
	virtual void ToggleHDMI();
	virtual  void ToggleRCA();
	virtual  void ToggleBNC();
	virtual  void ToggleXLR();

	virtual void handleTickEvent();

	void RefreshKarunaAndClockInfo();

	void RefreshBNCOutput();
	void RefreshRCAOutput();
	void RefreshHDMIOutput();
	void RefreshXLROutput();

	void Refresh24Lock();
	void Refresh245Lock();
	void Refresh22Lock();
	void RefreshIntExt();

	void SetDSDPCM(int p_AudiFormat);
	void SetBitDepth(int p_AudiFormat);
	void SetFreq(int p_AudiFormat);

	void SetTemp(int p_Temp);
	void PaintDot(colortype p_Dot1, colortype p_Dot2, colortype p_Dot3);

	colortype GetOutputColor(bool p_State);
	colortype GetLockColor(bool p_State);
	bool ToBinary(int number, int p_Position);
	void CopyBit(int input, int* output, int CopyFrom, int CopyTo);
	void SetBit(uint8_t* input, bool bit, int SetTo);


#ifdef SIMULATOR

  //Karuna
  uint8_t GuiItfGetKarunaStatus();
  void GuiItfKarunaControl(uint8_t p_Output);

  //DAS Clock
  double GuiItfGetDasMV341Temp();
  bool GuiItfGetDasStatusLock1();
  bool GuiItfGetDasStatusLock2();
  bool GuiItfGetDasIntExt();
#endif


protected:


private:
	uint8_t count;
};

#endif // MAIN_VIEW_HPP
