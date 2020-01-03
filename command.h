#include "GPIOs.h"
#include "timer.h"
#include "adc.h"
#include "USART.h"

typedef enum{
	//movement part
	fwd,
	bwd,
	turnLeft,
	turnRight,
	parallelRight,
	parallelLeft,
	//arm part
	armFwd,
	armBwd,
	armTurnRight,
	armTurnLeft,
	//camera mechanical part
	cameraUp,
	camaraDown
}Command;

uint8_t command_rev(void);
uint8_t checkCmmand(uint8_t command, int size);
Command checkOperation(void);
void process(void);
void arm_control(void);
void movement_ctrl(void);
