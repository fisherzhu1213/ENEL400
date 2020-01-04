#include "clock.h"
#include "util.h"
/*
uint8_t inBuffer[BUFFER_SIZE];
uint8_t outBuffer[BUFFER_SIZE];
int inBufferCounter;
int outBufferCounter;
*/

void USART2_ini(void);
void USART3_ini(void);
void sendByte(uint8_t data);
uint8_t getByte(void);
void sendByte_U3(uint8_t data);
uint8_t getByte_U3(void);
