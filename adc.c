#include "adc.h"


/********************************
Equipment: Sharp GP2Y0D805Z0F
Output : digital
Range	 : minimum range : 50mm
Consumption : 5mA
Supply volt : 2.7 ~ 6.2V
*Sunlight tolerance
*************************************/

//gpioa has enabled
//PA2 AS ADC1 Channel 2
void ADC_1_ini(void)
{	
	RCC->APB2ENR |= RCC_APB2ENR_ADC1EN;
	GPIOA->CRL &=~GPIO_CRL_MODE2;
	GPIOA->CRL &=~GPIO_CRL_CNF2;
  ADC1->CR2 |= ADC_CR2_ADON;
	
	//calibration
	
	ADC1->CR2 |= ADC_CR2_RSTCAL;
	while(ADC1->CR2 & ADC_CR2_RSTCAL);
	ADC1->CR2 |= ADC_CR2_CAL;
	while(ADC1->CR2 & ADC_CR2_CAL);
	ADC1->CR2 |= ADC_CR2_EXTSEL;
	ADC1->CR2 |= ADC_CR2_CONT;
	
	//trigger by swstart
	ADC1->CR2 |= ADC_CR2_EXTSEL;
	ADC1->SMPR2 |= ADC_SMPR2_SMP2_2|ADC_SMPR2_SMP2_0;
	
	ADC1->SQR1 &= ~ADC_SQR1_L;
	ADC1->SQR3 = 0x3fffffe0;
	ADC1->SQR3 |=2;
	ADC1->CR2 |= ADC_CR2_SWSTART;
//		
////		GPIOC->CRL &= ~0XF;
//		GPIOC->CRL &= ~GPIO_CRL_CNF0;
//		GPIOC->CRL &= ~GPIO_CRL_MODE0;
////		GPIOC->CRL |= 0X4;
//		ADC1->SQR3 |= 0X0000000A;
//		ADC1->SMPR1 |= 0X5;
//		ADC1->CR1 |=0X120;
//		ADC1->CR2 |= 0XE0001;
//		ADC1->CR2 |= 0X4;
//		while(ADC1->CR2 &0X2);
//		ADC1->CR2 |= 0X2;
//	GPIOA->CRL &=~GPIO_CRL_CNF1;//analog input mode for PA1
//	GPIOA->CRL &= ~GPIO_CRL_MODE1;//CNF|MODE = 00(ANALOG)00(INPUT)
//	ADC1->CR2 |= ADC_CR2_ADON;
//	
//	
//	ADC1->CR2 |= ADC_CR2_RSTCAL;
//	while(ADC1->CR2 & ADC_CR2_RSTCAL);
//	ADC1->CR2 |= ADC_CR2_CAL;
//	while(ADC1->CR2 & ADC_CR2_CAL);
//	
//	
//	//set external event select for SW START
//	ADC1->CR2 |= ADC_CR2_EXTSEL;
//	ADC1->CR2 |= ADC_CR2_CONT;
//	ADC1->CR2 |= ADC_CR2_EXTSEL;
//	ADC1->SQR3 |= 0X1;
//	
//	// 55.5 cycles
//	ADC1->SMPR2 |= ADC_SMPR2_SMP1;
//	
	//enable ADC interrupt
//	ADC1->CR1 |= ADC_CR1_EOCIE;
	NVIC->ISER[0] |= 0X40000;
	
}


