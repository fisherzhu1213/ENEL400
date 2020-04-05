#include "GPIOs.h"


/* system Basic GPIO enabler
Author: Yuming Zhu
*/
void GPIOs_ini(void){
	RCC->APB2ENR |= RCC_APB2ENR_IOPAEN | RCC_APB2ENR_IOPBEN | RCC_APB2ENR_IOPCEN;
	RCC->APB2ENR |= RCC_APB2ENR_AFIOEN;
	
	GPIOC->CRH |= GPIO_CRH_MODE8|GPIO_CRH_MODE9;
	GPIOC->CRH &=~GPIO_CRH_CNF8 & ~GPIO_CRH_CNF9;
	
	GPIOA->CRH |= GPIO_CRH_MODE12;
  GPIOA->CRH &= ~GPIO_CRH_CNF12;
	GPIOA->CRL |= GPIO_CRL_MODE3;
  GPIOA->CRL &= ~GPIO_CRL_CNF3;

}

void ir_sensor(void)
{
	GPIOC->CRL &=~GPIO_CRL_CNF5;
	GPIOC->CRL |= GPIO_CRL_CNF5_0;
	GPIOC->CRL &= ~GPIO_CRL_MODE5;
}

	void indicator_on(void){
	GPIOC->BSRR |= GPIO_BSRR_BS8;
	}


	//blue LED modifier
	void indicator_off(void){
	GPIOC->BSRR |= GPIO_BSRR_BR8;
	}

	void greenLed_on(void){
	GPIOC->BSRR |= GPIO_BSRR_BS9;
	}

	//blue LED modifier
	void greenLed_off(void){
	GPIOC->BSRR |= GPIO_BSRR_BR9;
	}
