#include "timer.h"

//general TIM2 interrupt enabler
void setTim2(void){
	RCC->APB1ENR |= RCC_APB1ENR_TIM2EN;			//Enable the TIM2 clock source
//	TIM2->CR1 = 0x0080;					//Set TIM2 as upcounter with preload	
//	TIM2->DIER = 0x0001;				//Enable the update interrupt
//	TIM2->PSC = 24000;						//Divide clock source by 24000 
//	TIM2->ARR = 100;					//Set TIM2 1HZ to generate an interrupt every 1s
//	NVIC->ISER[0] |= 0x10000000;		//Enable the interrupt
	GPIOA->CRL &= ~GPIO_CRL_CNF1;
	GPIOA->CRL |= GPIO_CRL_CNF1_1;//SET CNF TO AFIO
	GPIOA->CRL |= GPIO_CRL_MODE1;//SET MODE TO OUTPUT 50MHZ
	GPIOA->CRL &= ~GPIO_CRL_CNF3;
	GPIOA->CRL |= GPIO_CRL_CNF3_1;//SET CNF TO AFIO
	GPIOA->CRL |= GPIO_CRL_MODE3;//SET MODE TO OUTPUT 50MHZ
	
	TIM2->CR1 |=TIM_CR1_DIR| TIM_CR1_ARPE;

	TIM2->CCER  |= TIM_CCER_CC2E;//ONE OUTPUT CAPTURE
	TIM2->CCMR1 |= TIM_CCMR1_OC2M_1|TIM_CCMR1_OC2M_2 | TIM_CCMR1_OC2PE;
	TIM2->CCER  |= TIM_CCER_CC4E;
	TIM2->CCMR2 |= TIM_CCMR2_OC4M_1| TIM_CCMR2_OC4M_2| TIM_CCMR2_OC4PE;
	TIM2->PSC	= 24000;
	TIM2->ARR = 100;

	TIM2->SR = 0x00000000;			//Clear Flag
}

///pwm for PA6, for small servo, 50hz, 1~2ms duty cycle
void setTim3(void){
	//RCC->APB1ENR |= RCC_APB1ENR_TIM3EN;//Enable timer 3 for pwm
	RCC->APB1ENR |= RCC_APB1ENR_TIM3EN;
	GPIOA->CRL &= ~GPIO_CRL_CNF6;
	GPIOA->CRL |= GPIO_CRL_CNF6_1;//SET CNF TO AFIO
	GPIOA->CRL |= GPIO_CRL_MODE6;//SET MODE TO OUTPUT 50MHZ
	GPIOA->CRL &= ~GPIO_CRL_CNF7;
	GPIOA->CRL |= GPIO_CRL_CNF7_1;//SET CNF TO AFIO
	GPIOA->CRL |= GPIO_CRL_MODE7;//SET MODE TO OUTPUT 50MHZ	

	TIM3->CR1    |=TIM_CR1_DIR| TIM_CR1_ARPE;	//set CR1 ARPE DIR AND CEN
	TIM3->CCER	 |= TIM_CCER_CC1E;													//set CC1E ENABLE
	TIM3->CCMR1  |= TIM_CCMR1_OC1PE | TIM_CCMR1_OC1M_1 | TIM_CCMR1_OC1M_2;//0x6800;			//set OC1M AND OC1PE
	TIM3->CCER	 |= TIM_CCER_CC2E;													//set CC1E ENABLE

	TIM3->CCMR1  |= TIM_CCMR1_OC2PE | TIM_CCMR1_OC2M_1 | TIM_CCMR1_OC2M_2;//0x6800;			//set OC1M AND OC1PE
	TIM3->PSC     = 24000;				//set PSC to 1000Hz
	TIM3->ARR     = 100;			 //set ARR TO 50Hz

	TIM3->SR = 0x00000000;			//Clear Flag
}

//set PB6 AS AFIO for TIM4 CH1 as PWM
void setTim4(void){
	RCC->APB1ENR |= RCC_APB1ENR_TIM4EN;//Enable timer 3 for pwm
	GPIOB->CRL &= ~GPIO_CRL_CNF6;
	GPIOB->CRL |= GPIO_CRL_CNF6_1;//SET CNF TO AFIO
	GPIOB->CRL |= GPIO_CRL_MODE6;//SET MODE TO OUTPUT 50MHZ


	TIM4->CR1    |= TIM_CR1_DIR| TIM_CR1_ARPE;	//set CR1 ARPE DIR AND CEN
	TIM4->CCER	 |= TIM_CCER_CC1E;													//set CC1E ENABLE
	TIM4->CCMR1  |= TIM_CCMR1_OC1PE | TIM_CCMR1_OC1M_1 | TIM_CCMR1_OC1M_2;//0x6800;			//set OC1M AND OC1PE
	TIM4->PSC     = 24000;				//set PSC to 5000Hz
	TIM4->ARR     = 100;			 //set ARR TO 50Hz

	TIM4->SR = 0x00000000;			//Clear Flag
}

void closeAllTimer(void){
	TIM2->CR1 &= ~TIM_CR1_CEN;
	TIM3->CR1 &= ~TIM_CR1_CEN;
	TIM4->CR1 &= ~TIM_CR1_CEN;
}
//void TIM2_IRQHandler(void){
//		greenLed_off();
//		indicator_on();
//		delay_ms(1200);
//		indicator_off();
//		greenLed_on();
//		TIM2->SR = 0x00000000;			//Clear Flag
//}
