#include "clock.h"
#include "util.h"

/* system core clock enabler
Author: Yuming Zhu
*/
void setupClock(void){
	uint32_t lock = 0;											
	RCC->CFGR = 0x07130002;				//Configure PLLx6, PREDIV1 as PLL input. 24MHz system clk, enable MCO fol PLL/2
	RCC->CR =  0x01010081;				//Enable PLL, HSE, HSI
	while(lock != 0x02000000){			//Wait for PLL lock
		lock = RCC->CR & 0x02000000;
	}
}
