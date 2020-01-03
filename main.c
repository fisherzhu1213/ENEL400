#include "clock.h"
#include "GPIOs.h"
#include "timer.h"
#include "USART.h"
#include "adc.h"
#include "util.h"

int main(){

	setupClock();
	GPIOs_ini();
//	setupTIM2();
//	TIM2->CR1 |= 0x0001;				//Enable the timer	
	USART2_ini();
	USART3_ini();
//	ADC_1_ini();
	while(1){
		uint16_t data,data_U3;
		sendByte_U3(0x76);
		sendByte(0x84);
		data = getByte_U3();
		data_U3=getByte();
		if((data == (0x84))|(data==(0x76))){greenLed_on();}
		if((data_U3 == (0x84))|(data_U3==(0x76))){indicator_on();}
		//else{greenLed_on();}
		delay_ms(500);
		greenLed_off();
		indicator_off();
		delay_ms(500);
//		indicator_on();
//		delay(12000000);
//		indicator_off();
//		delay(12000000);
	}
	return 0;
}

void TIM2_IRQHandler(void){
		greenLed_off();
		indicator_on();
		delay_ms(1200);
		indicator_off();
		greenLed_on();
		TIM2->SR = 0x00000000;			//Clear Flag
}
