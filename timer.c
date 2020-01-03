#include "timer.h"

//general TIM2 interrupt enabler
void setupTIM2(void){
	RCC->APB1ENR |= 0x00000001;			//Enable the TIM2 clock source
	TIM2->CR1 = 0x0080;					//Set TIM2 as upcounter with preload	
	TIM2->DIER = 0x0001;				//Enable the update interrupt
	TIM2->PSC = 24000;						//Divide clock source by 24 
	TIM2->ARR = 1000;					//Set TIM2 to generate an interrupt every 1s
	NVIC->ISER[0] |= 0x10000000;		//Enable the interrupt
	
}

///pwm for PA6
void steupTIM4(void){
	
	RCC->APB1ENR |= RCC_APB1ENR_TIM3EN;//Enable timer 3 for pwm
	
	GPIOA->CRL &= ~0x0f000000;//set PA6 AS AFIO for TIM3 CH1 as PWM
	GPIOA->CRL |= 0x0B000000;
	
	TIM3->PSC     = 143;				//set PSC to 500KHz
	TIM3->ARR     = 10000;			 //set ARR TO 
	TIM3->CR1    |= TIM_CR1_CEN| TIM_CR1_DIR| TIM_CR1_ARPE;	//set CR1 ARPE DIR AND CEN
	TIM3->CCER	 |= TIM_CCER_CC1E;													//set CC1E ENABLE
	TIM3->CCMR1  |= TIM_CCMR1_OC1PE | TIM_CCMR1_OC1M_1 | TIM_CCMR1_OC1M_2;//0x6800;			//set OC2M AND OC2PE
	TIM3->CCR1		= 5000;				//% of pwm
	//* regTIM4_DIER	 |= 0x01;
	TIM3->EGR		 |=	TIM_EGR_UG;				//set TO UG
}
