#include <gui/common/BackendCommunicator.hpp>


	BackendCommunicator::BackendCommunicator()
	{

	}
	 
#ifdef SIMULATOR 

	uint32_t mUptimeCounterSim;


	//GUI 
	uint8_t BackendCommunicator::GuiItfGetVersion(char* fw, char* uid, char* pcb) 
	{ 
		char fwGUI[25] = "220613_1242";
		char uidGUI[25] = "0123456789ABCDEF0000001"; 
		char pcbGUI[25] = "V01";

		fw = fwGUI;
		uid = uidGUI;
		pcb = pcbGUI;
		return GUIITF_OK;
	}


	//KARUNA
	uint8_t BackendCommunicator::GuiItfGetKarunaVersion(char* fw, char* uid, char* pcb)
	{
		//char fwDasClock[25]; char uidDasClock[25]; char pcbDasClock[25];

		fw = "220613_1243";
		uid = "0123456789ABCDEF0000002"; 
		pcb = "V02";
		return GUIITF_OK;
	}
	uint32_t BackendCommunicator::GuiItfGetKarunaUptimeCnt()
	{
		mUptimeCounterSim++;
		return mUptimeCounterSim;
	}

	uint8_t BackendCommunicator::GuiItfGetKarunaStatus()
	{
		return 0b00000001;
	}
	void BackendCommunicator::GuiItfKarunaControl(uint8_t p_Output)
	{
	}

	//DAS CLOCK	
	uint8_t BackendCommunicator::GuiItfGetDasClockVersion(char* fw, char* uid, char* pcb)
	{
		//char fwKaruna[25]; char uidKaruna[25]; char pcbKaruna[25];

		fw = "220613_1244";
		uid = "0123456789ABCDEF0000003";
		pcb = "V03";
		return GUIITF_OK;
	}
	uint32_t BackendCommunicator::GuiItfGetDasClockUptimeCnt()
	{
		mUptimeCounterSim++;
		return mUptimeCounterSim;
	}

	double BackendCommunicator::GuiItfGetDasClockMV341Temp()
	{
		return 50.0;
	}
	double BackendCommunicator::GuiItfGetDasClockMVOCX1Temp()
	{
		return 55.1;
	}
	double BackendCommunicator::GuiItfGetDasClockMVOCX2Temp()
	{
		return 60.2;
	}

	double BackendCommunicator::GuiItfGetDasClockMV341Current()
	{
		return 550.0;
	}
	double BackendCommunicator::GuiItfGetDasClockMVOCX1Current()
	{
		return 160.1;
	}
	double BackendCommunicator::GuiItfGetDasClockMVOCX2Current()
	{
		return 160.2;
	}

	double BackendCommunicator::GuiItfGetDasClockMainVoltage()
	{
		return 12.5;
	}
	double BackendCommunicator::GuiItfGetDasClockRefVoltage()
	{
		return 6.25;
	}

	bool BackendCommunicator::GuiItfGetDasClockStatusLock1()
	{
		return true;
	}
	bool BackendCommunicator::GuiItfGetDasClockStatusLock2()
	{
		return true;
	}
	bool BackendCommunicator::GuiItfGetDasClockIsExt()
	{
		return false;
	}


	//DISPLAY
	void BackendCommunicator::GuiItfBacklightEnable()
	{
	}
	void BackendCommunicator::GuiItfBacklightDisable()
	{
	}
	uint8_t BackendCommunicator::GuiItfSetBacklight(uint8_t percent)
	{
		return percent;
	}
	uint8_t BackendCommunicator::GuiItfGetBacklight(void)
	{
		return 42; //Ez egy sokkal szebb szám 
	}

#else
	extern "C"
	{

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


		//DISPLAY
		uint8_t GuiItfSetBacklight(uint8_t percent);
		uint8_t GuiItfGetBacklight(void);
		void GuiItfBacklightEnable();
		void GuiItfBacklightDisable();
	}
#endif