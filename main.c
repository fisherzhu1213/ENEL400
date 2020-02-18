#include "GPIOs.h"
#include "timer.h"
#include "adc.h"
#include "util.h"
#include "USART.h"
#include "command.h"
#include "operation_index.h"
uint16_t data,data_U3;
int main(){

	setupClock();
	GPIOs_ini();
	setTim2();
	setTim3();
	setTim4();

//	TIM2->CR1 |= 0x0001;				//Enable the timer	
//	USART2_ini();
	USART3_ini();
//	ADC_1_ini();
	while(1){
//		tim2_tester();
			timer2_1_tester();
//			timer2_4_tester();
//			timer4_1_tester();
//			timer4_2_tester();
//		delay_ms(1000);
//		TIM2->CCR2 = 15;
//		delay_ms(1000);
//		TIM2->CCR2 = 10;
//		delay_ms(1000);
//		TIM2->CCR2 = 20;
//		delay_ms(1000);

//		uint8_t irdata;
//		irdata	=	(GPIOC->IDR|GPIO_IDR_IDR5);
//		data = getByte_U3();
//		if(data == 0x84){indicator_on();}
//		if(data == 0x76) {greenLed_on();}
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

//void ADC1_IRQHandler(void)
//{
//	uint16_t adc_val;
//	uint16_t recorder = ADC1->SR;
//	if(recorder & 0x2){
//		adc_val = ADC1->DR;
//		
//	}
//}

//void USART3_IRQHandler(void){
//	uint8_t receiver;
//	receiver = getByte_U3();
//	process(receiver);
//}


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
