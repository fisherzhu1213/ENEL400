#include "GPIOs.h"

void GPIOs_ini(void){
	RCC->APB2ENR |= RCC_APB2ENR_IOPAEN | RCC_APB2ENR_IOPBEN | RCC_APB2ENR_IOPCEN;
	GPIOC->CRH |= GPIO_CRH_MODE8|GPIO_CRH_MODE9;
	GPIOC->CRH &=~GPIO_CRH_CNF8 & ~GPIO_CRH_CNF9;
	RCC->APB2ENR |= RCC_APB2ENR_AFIOEN;

	GPIOA->CRH &= ~0x0000000f;//set PA8 AS AFIO for MCO
	GPIOA->CRH |= 0x0000000B;

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
