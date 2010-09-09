#include "HardwareProfile.h"
#include <FatFs\diskio.h>
#include <FatFs\ff.h>
/*********************************************************************
 * Function:  		DWORD get_fattime(void)
 *
 * PreCondition:    
 *
 * Input:           None
 *
 * Output:          Time
 *
 * Side Effects:    
 *
 * Overview:        when writing fatfs requires a time stamp
 *					in this exmaple we are going to use a counter
 *					If the starter kit has the 32kHz crystal
 *					installed then the RTCC could be used instead
 *
 * Note:           
 ********************************************************************/
DWORD get_fattime(void)
{
	DWORD tmr = 0;

//	INTDisableInterrupts();
//	tmr =	  (((DWORD)rtcYear - 80) << 25)
//			| ((DWORD)rtcMon << 21)
//			| ((DWORD)rtcMday << 16)
//			| (WORD)(rtcHour << 11)
//			| (WORD)(rtcMin << 5)
//			| (WORD)(rtcSec >> 1);
//	INTEnableInterrupts();

	return tmr;
}
