#include "command.h"
/*
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
	*/
uint8_t command_fwd[]="fwd";//A
uint8_t command_bwd[]="bwd";//B
uint8_t command_turnLeft[]="turnLeft";//C
uint8_t command_turnRight[]="turnRight";//D
uint8_t command_parallelRight[]="parallelRight";//E
uint8_t command_parallelLeft[]="parallelLeft";//F
uint8_t command_armFwd[]="armFwd";//G
uint8_t command_armBwd[]="armBwd";//H
uint8_t command_armTurnRight[]="armTurnRight";//I
uint8_t command_armTurnLeft[]="armTurnLeft";//J
uint8_t command_cameraDown[]="cameraDown";//K
uint8_t command_cameraUp[]="cameraUp";//L

uint8_t command_rev(void){
	uint8_t code;
	code = getByte();//read data from USART2
	return code;
}

uint8_t checkCmmand(uint8_t command, int size){
	
}
Command checkOperation(void){
	
}
