#include "adc.h"
/*
Equipment: Sharp GP2Y0D805Z0F
Output : digital
Range	 : minimum range : 50mm
Consumption : 5mA
Supply volt : 2.7 ~ 6.2V
*Sunlight tolerance
*/

//gpioa has enabled
//PA1 AS ADC1 Channel 1
void ADC_1_ini(void)
{
	RCC->APB2ENR |= RCC_APB2ENR_ADC1EN;
	GPIOA->CRL &=~GPIO_CRL_CNF1;//analog input mode for PA1
	ADC1->CR2 |= ADC_CR2_ADON;
	
	
	ADC1->CR2 |= ADC_CR2_RSTCAL;
	while(ADC1->CR2 & ADC_CR2_RSTCAL);
	ADC1->CR2 |= ADC_CR2_CAL;
	while(ADC1->CR2 & ADC_CR2_CAL);
	
	
	//set external event select for SW START
	ADC1->CR2 |= ADC_CR2_EXTSEL;
	ADC1->CR2 |= ADC_CR2_CONT;
	ADC1->CR2 |= ADC_CR2_EXTSEL;
	ADC1->SQR3 |= 0X1;
	
	// 55.5 cycles
	ADC1->SMPR2 |= ADC_SMPR2_SMP1;
	
	//enable ADC interrupt
//	ADC1->CR1 |= ADC_CR1_EOCIE;
//	NVIC->ISER[0] |= 0X40000;
	
}

void ADC1_IRQHandler(void)
{
	uint16_t adcval;
	adcval=ADC1->DR;
}
