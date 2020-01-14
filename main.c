#include "GPIOs.h"
#include "timer.h"
#include "adc.h"
#include "util.h"
#include "USART.h"
#include "command.h"

int main(){

	setupClock();
	GPIOs_ini();
	setTim2();
	setTim3();
	setTim4();

//	TIM2->CR1 |= 0x0001;				//Enable the timer	
	USART2_ini();
	USART3_ini();
	ADC_1_ini();
	while(1){
//		uint8_t irdata;
//		irdata	=	(GPIOC->IDR|GPIO_IDR_IDR5);
//		uint16_t data,data_U3;
//		sendByte_U3(0x76);
//		sendByte(0x84);
//		data = getByte_U3();
//		data_U3=getByte();
//		if((data == (0x84))|(data==(0x76))){greenLed_on();}
//		if((data_U3 == (0x84))|(data_U3==(0x76))){indicator_on();}
//		//else{greenLed_on();}
//		delay_ms(500);
//		greenLed_off();
//		indicator_off();
//		delay_ms(500);
//		indicator_on();
//		delay(12000000);
//		indicator_off();
//		delay(12000000);
	}
	return 0;
}

void ADC1_IRQHandler(void)
{
	uint16_t adc_val;
	uint16_t recorder = ADC1->SR;
	if(recorder & 0x2){
		adc_val = ADC1->DR;
		
	}
}

void USART3_IRQHandler(void){
	uint8_t receiver;
	receiver = getByte_U3();
	process(receiver);
	delay_ms(500);
	closeAllTimer();
}


//void USART2_IRQHandler(void){
//	uint8_t receiver;
//	receiver = getByte();
//	if(receiver == 0x76){
//		indicator_on();
//	}
//	else{
//		greenLed_on();
//	}
//		
//	process();
//}
