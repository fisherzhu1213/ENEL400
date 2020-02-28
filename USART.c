#include "USART.h"
#include "GPIOs.h"
#include "command.h"



void USART3_ini(void){
//PB10->TX, PB 11->RX
	RCC->APB1ENR |= RCC_APB1ENR_USART3EN;
	
	GPIOB->CRH &= ~GPIO_CRH_MODE10 & ~GPIO_CRH_CNF10;
	GPIOB->CRH |= GPIO_CRH_MODE10;
	GPIOB->CRH |= GPIO_CRH_CNF10_1;
	
	GPIOB->CRH &= ~GPIO_CRH_MODE11;
	GPIOB->CRH |= GPIO_CRH_CNF11_0;
	
	USART3->CR1 |= USART_CR1_RXNEIE | USART_CR1_UE | USART_CR1_RE | USART_CR1_TE;
	USART3->BRR = 0x9c5;
	NVIC->ISER[1]= NVIC_ISER_SETENA_7;
	NVIC->IP[0];
	
}

void sendByte_U3(uint8_t data){

	while((USART3->SR & USART_SR_TXE) == 0);
	USART3->DR = data;
	while((USART3->SR & USART_SR_TC) == 0);
}

uint8_t getByte_U3(void){
		uint8_t receiver;
		while((USART3->SR & USART_SR_RXNE) == 0);
		receiver = USART3->DR;
		return receiver;
}



//void USART2_ini(void){
//	RCC->APB1ENR |= RCC_APB1ENR_USART2EN;
//	//GPIOA is enabled, AFIO enabled
//	//SET GPIOC PA2,PA4(ck),PA2 is  TX, PA3 is RX
//	GPIOA->CRL &= ~0x0000ff00;//reset all value from PA2,PA3
//	GPIOA->CRL |= 0x00004B00;  //set PA2 as AFIO
//	
//	USART2->CR1 |= USART_CR1_RXNEIE|   USART_CR1_UE | USART_CR1_RE | USART_CR1_TE; 

//	USART2->BRR = 0x1D4C;
//	NVIC->ISER[1]= NVIC_ISER_SETENA_7;//0X40;enalbe usart2 interrupt
//}

////every time it receive signal should stop, keep the corresponding function run
////until next commmand received
//void sendByte(uint8_t data){
//	while((USART2->SR & USART_SR_TXE) == 0 );
//	USART2->DR = data;
//	while((USART2->SR & USART_SR_TC) == 0);
//}

//uint8_t getByte(void){
//		uint8_t receiver;
////		while((USART2->SR & USART_SR_RXNE) == 0);
//		receiver = USART2->DR;

//		return receiver;
//}


