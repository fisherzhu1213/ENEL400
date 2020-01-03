#include "clock.h"
#include "util.h"


void USART2_ini(void);
void USART3_ini(void);
void sendByte(uint8_t data);
uint8_t getByte(void);
void sendByte_U3(uint8_t data);
uint8_t getByte_U3(void);
