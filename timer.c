#include "timer.h"
//a.k.a servo controller

/****************************************************************
fucntion setTim1 
author: Zongyao Liu 
Enable timer 1 to control signal that will transfer to stepper driver
****************************************************************/
void setTim1 (void)
{		
		RCC->APB2ENR |= RCC_APB2ENR_TIM1EN;
		GPIOA->CRH &= ~GPIO_CRH_CNF10;
		GPIOA->CRH |= GPIO_CRH_CNF10_1;
		GPIOA->CRH |= GPIO_CRH_MODE10;
		GPIOA->CRH &= ~GPIO_CRH_CNF11;
		GPIOA->CRH |= GPIO_CRH_CNF11_1;
		GPIOA->CRH |= GPIO_CRH_MODE11;

		TIM1->CR1 |= TIM_CR1_ARPE | TIM_CR1_DIR;
		TIM1->CR2 |= TIM_CR2_OIS1;
		TIM1->EGR |= TIM_EGR_UG;
		TIM1->CCMR2 |= TIM_CCMR2_OC3M_2 | TIM_CCMR2_OC3M_1 | TIM_CCMR2_OC3PE | TIM_CCMR2_OC3FE;
		TIM1->CCER |= TIM_CCER_CC3E;
		TIM1->CCMR2 |= TIM_CCMR2_OC4M_2 | TIM_CCMR2_OC4M_1 | TIM_CCMR2_OC4PE | TIM_CCMR2_OC4FE;
		TIM1->CCER |= TIM_CCER_CC4E;

		TIM1->ARR = 900;
		TIM1->CCR3 = 800;
		TIM1->CCR4 = 800;
		TIM1->BDTR |= TIM_BDTR_MOE | TIM_BDTR_OSSI;
}

//SET PA0,3 AS TIM2 CH1, 4
//SINCE ADC_1 IS IN PA2, WE DONT USE PA1 AND PA2
//void setTim2(void){
//	RCC->APB1ENR |= RCC_APB1ENR_TIM2EN;			//Enable the TIM2 clock source
////	TIM2->CR1 = 0x0080;					//Set TIM2 as upcounter with preload	
////	TIM2->DIER = 0x0001;				//Enable the update interrupt
////	TIM2->PSC = 24000;						//Divide clock source by 24000 
////	TIM2->ARR = 100;					//Set TIM2 1HZ to generate an interrupt every 1s
////	NVIC->ISER[0] |= 0x10000000;		//Enable the interrupt
//	GPIOA->CRL &= ~GPIO_CRL_CNF0;
//	GPIOA->CRL |= GPIO_CRL_CNF0_1;
//	GPIOA->CRL |= GPIO_CRL_MODE0;
//	
//	GPIOA->CRL &= ~GPIO_CRL_CNF1;
//	GPIOA->CRL |= GPIO_CRL_CNF1_1;
//	GPIOA->CRL |= GPIO_CRL_MODE1;
//	
//	GPIOA->CRL &= ~GPIO_CRL_CNF3;
//	GPIOA->CRL |= GPIO_CRL_CNF3_1;
//	GPIOA->CRL |= GPIO_CRL_MODE3;
//	
//	GPIOA->CRL &= ~GPIO_CRL_CNF2;
//	GPIOA->CRL |= GPIO_CRL_CNF2_1;
//	GPIOA->CRL |= GPIO_CRL_MODE2;
//	
//	TIM2->CR1 	|= TIM_CR1_DIR| TIM_CR1_ARPE;
//	TIM2->CCER = 0;
//	TIM2->CCMR1 = 0;
//	TIM2->CCER	 |= TIM_CCER_CC2E;													//set CC2E ENABLE
//	TIM2->CCMR1  |= TIM_CCMR1_OC2PE | TIM_CCMR1_OC2M_1 | TIM_CCMR1_OC2M_2;

//	TIM2->CCER	 |= TIM_CCER_CC1E;													//set CC2E ENABLE
//	TIM2->CCMR1  |= TIM_CCMR1_OC1PE | TIM_CCMR1_OC1M_1 | TIM_CCMR1_OC1M_2;
//	
//	TIM2->CCER  |= TIM_CCER_CC3E;
//	TIM2->CCMR2 |= TIM_CCMR2_OC3PE | TIM_CCMR2_OC3M_1| TIM_CCMR2_OC3M_2;

//	
//	TIM2->CCER  |= TIM_CCER_CC4E;
//	TIM2->CCMR2 |= TIM_CCMR2_OC4PE | TIM_CCMR2_OC4M_1| TIM_CCMR2_OC4M_2;

//	TIM2->EGR |= TIM_EGR_UG;

//	

//	TIM2->PSC	= 240;
//	TIM2->ARR = 2000;//->50HZ

//	
//	TIM2->SR = 0x00000000;			//Clear Flag
//}

//SET PA6,7 PB 0,1 AS TIM3 CH 1,2,3,4
/**************************************************************
Timer 3 enabler
Author: Yuming Zhu
Enable timer 3 to enable arm rotation, all other availiable channel
can be used in extension
***************************************************************/
void setTim3(void){
	RCC->APB1ENR |= RCC_APB1ENR_TIM3EN;
	GPIOA->CRL &= ~GPIO_CRL_CNF6;
	GPIOA->CRL |= GPIO_CRL_CNF6_1;
	GPIOA->CRL |= GPIO_CRL_MODE6;
	
	GPIOA->CRL &= ~GPIO_CRL_CNF7;
	GPIOA->CRL |= GPIO_CRL_CNF7_1;
	GPIOA->CRL |= GPIO_CRL_MODE7;
	
	GPIOB->CRL &= ~GPIO_CRL_CNF0;
	GPIOB->CRL |= GPIO_CRL_CNF0_1;
	GPIOB->CRL |= GPIO_CRL_MODE0;
	
	GPIOB->CRL &= ~GPIO_CRL_CNF1;
	GPIOB->CRL |= GPIO_CRL_CNF1_1;
	GPIOB->CRL |= GPIO_CRL_MODE1;

	TIM3->CR1    |=TIM_CR1_DIR| TIM_CR1_ARPE;	//set CR1 ARPE DIR AND CEN
	
	TIM3->CCER	 |= TIM_CCER_CC1E;													//set CC1E ENABLE
	TIM3->CCMR1  |= TIM_CCMR1_OC1PE | TIM_CCMR1_OC1M_1 | TIM_CCMR1_OC1M_2;//0x6800;			//set OC1M AND OC1PE
	
	TIM3->CCER	 |= TIM_CCER_CC2E;													//set CC1E ENABLE
	TIM3->CCMR1  |= TIM_CCMR1_OC2PE | TIM_CCMR1_OC2M_1 | TIM_CCMR1_OC2M_2;//0x6800;			//set OC1M AND OC1PE
	
	TIM3->CCER	 |= TIM_CCER_CC3E;													//set CC1E ENABLE
	TIM3->CCMR2  |= TIM_CCMR2_OC3PE | TIM_CCMR2_OC3M_1 | TIM_CCMR2_OC3M_2;//0x6800;			//set OC1M AND OC1PE

	TIM3->CCER	 |= TIM_CCER_CC4E;													//set CC1E ENABLE
	TIM3->CCMR2  |= TIM_CCMR2_OC4PE | TIM_CCMR2_OC4M_1 | TIM_CCMR2_OC4M_2;//0x6800;			//set OC1M AND OC1PE
	

	TIM3->PSC     = 240;				//set PSC to 1000Hz
	TIM3->ARR     = 300;			 //set ARR TO 333Hz

	TIM3->SR = 0x00000000;			//Clear Flag
}

/**************************************************************
Timer 4 enabler
Author: Yuming Zhu
Enable timer 4 to enable mechanical arm actions
set period to 50Hz
***************************************************************/
void setTim4(void){
	RCC->APB1ENR |= RCC_APB1ENR_TIM4EN;
	GPIOB->CRL &= ~GPIO_CRL_CNF6;
	GPIOB->CRL |= GPIO_CRL_CNF6_1;
	GPIOB->CRL |= GPIO_CRL_MODE6;
	
	GPIOB->CRL &= ~GPIO_CRL_CNF7;
	GPIOB->CRL |= GPIO_CRL_CNF7_1;
	GPIOB->CRL |= GPIO_CRL_MODE7;
	
	GPIOB->CRH &= ~GPIO_CRH_CNF8;
	GPIOB->CRH |= GPIO_CRH_CNF8_1;
	GPIOB->CRH |= GPIO_CRH_MODE8;
	
	GPIOB->CRH &= ~GPIO_CRH_CNF9;
	GPIOB->CRH |= GPIO_CRH_CNF9_1;
	GPIOB->CRH |= GPIO_CRH_MODE9;	


	TIM4->CR1    |= TIM_CR1_DIR| TIM_CR1_ARPE;
	
	TIM4->CCER	 |= TIM_CCER_CC1E;													
	TIM4->CCMR1  |= TIM_CCMR1_OC1PE | TIM_CCMR1_OC1M_1 | TIM_CCMR1_OC1M_2;
	
	TIM4->CCER	 |= TIM_CCER_CC2E;													
	TIM4->CCMR1  |= TIM_CCMR1_OC2PE | TIM_CCMR1_OC2M_1 | TIM_CCMR1_OC2M_2;
	
	TIM4->CCER	 |= TIM_CCER_CC3E;													
	TIM4->CCMR2  |= TIM_CCMR2_OC3PE | TIM_CCMR2_OC3M_1 | TIM_CCMR2_OC3M_2;

	TIM4->CCER	 |= TIM_CCER_CC4E;													
	TIM4->CCMR2  |= TIM_CCMR2_OC4PE | TIM_CCMR2_OC4M_1 | TIM_CCMR2_OC4M_2;

	TIM4->PSC     = 240;				
	TIM4->ARR     = 2000;	
//	TIM4->CCR1 = 70;
//	TIM4->CCR2 = 40;
//	TIM4->CCR3 = 40;
//	TIM4->CCR4 = 160;


	TIM4->SR = 0x00000000;			
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
