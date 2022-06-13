#ifndef BACKENDCOMMUNICATOR_HPP
#define BACKENDCOMMUNICATOR_HPP
#define GUIITF_OK             0x00
#define GUIITF_FAIL           0x01
#define GUIITF_OUT_OF_RANGE   0x02


#include <cstdint>
class BackendCommunicator
{

public: 
	BackendCommunicator(); 

#ifdef SIMULATOR

	//GUI
	uint8_t GuiItfGetVersion(char* fw, char* uid, char* pcb); 

	//KARUNA
	uint8_t GuiItfGetKarunaVersion(char* fw, char* uid, char* pcb);
	uint32_t GuiItfGetKarunaUptimeCnt();

	uint8_t GuiItfGetKarunaStatus();
	void GuiItfKarunaControl(uint8_t p_Output);

	//DAS CLOCK	
	uint8_t GuiItfGetDasClockVersion(char* fw, char* uid, char* pcb);
	uint32_t GuiItfGetDasClockUptimeCnt();

	double GuiItfGetDasClockMV341Temp();
	double GuiItfGetDasClockMVOCX1Temp();
	double GuiItfGetDasClockMVOCX2Temp();

	double GuiItfGetDasClockMV341Current();
	double GuiItfGetDasClockMVOCX1Current();
	double GuiItfGetDasClockMVOCX2Current();

	double GuiItfGetDasClockMainVoltage();
	double GuiItfGetDasClockRefVoltage();
	 
	bool GuiItfGetDasClockStatusLock1();
	bool GuiItfGetDasClockStatusLock2();
	bool GuiItfGetDasClockIsExt();

	//BACKLIGHT
	uint8_t GuiItfSetBacklight(uint8_t percent);
	uint8_t GuiItfGetBacklight(void);
	void GuiItfBacklightEnable();
	void GuiItfBacklightDisable();

	//REALTIME CLOCK


#endif
	
private:

};

#endif //BACKENDCOMMUNICATOR_HPP