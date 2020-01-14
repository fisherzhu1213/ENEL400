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
uint8_t command_fwd[]="A";//fwd
uint8_t command_bwd[]="B";//bwd
uint8_t command_turnLeft[]="C";//turn left
uint8_t command_turnRight[]="D";//turn right
uint8_t command_parallelRight[]="E";//parallel right
uint8_t command_parallelLeft[]="F";//parallel left
uint8_t command_armFwd[]="G";//arm fwd
uint8_t command_armBwd[]="H";//arm bwd
uint8_t command_armTurnRight[]="I";//arm right
uint8_t command_armTurnLeft[]="J";//arm left
uint8_t command_cameraDown[]="K";//camera down
uint8_t command_cameraUp[]="L";//camera up

/*
For farther extension for the system
uint8_t tempBuffer[BUFFER_SIZE];
int tempBufferCounter;
int arguCounter;

Command getFirstArgu(void){
	for(tempBufferCounter =0;tempBufferCounter<inBufferCounter;tempBufferCounter++){
		if(inBuffer[tempBufferCounter] != ' ' && inBuffer[tempBufferCounter] != 0x00){
			tempBuffer[tempBufferCounter] = inBuffer[tempBufferCounter];
		}
		else{
			break;
		}
	}
	//send the buffer result the next function
	return checkOperation();
}

//if start with led, then go to this function, it will read the number of led, and the operation of led
Command getSecondArgu(void){
	arguCounter=0;
	for(;tempBufferCounter<inBufferCounter;tempBufferCounter++){
		if(inBuffer[tempBufferCounter] != ' '){
			break;
		}
	}
	for(;tempBufferCounter<inBufferCounter;tempBufferCounter++,arguCounter++){
		if(inBuffer[tempBufferCounter] != ' ' && inBuffer[tempBufferCounter] != 0x00){
			tempBuffer[arguCounter] = inBuffer[tempBufferCounter];
		}
		else{
			break;
		}
	}
	return checkOperation();
}


//compare the command size, then compare each character inside the buffer, and return true of false to the corresponding function in checkOperation()
uint8_t checkCommand(uint8_t command[],int size){
	if((tempBufferCounter != size) && (arguCounter != size)){
		return 0;
	}
	for(int i = 0;i<size;i++){
		if(tempBuffer[i] != command[i]){
			return 0;
		}
	}
	return 1;
}

//compare the size first, and then the character inside the buffer, if any command is totally matched, it return correspoding enum(command)
Command checkOperation(void){
	if(checkCommand(command_led,3)){
		return led;
	}
	else if(checkCommand(command_help,4)){
		return help;
	}
}
*/

uint8_t command_rev(void){
	uint8_t code;
	code = getByte_U3();//read data from USART2
	return code;
}

void process(uint8_t receiver){
	//Command command = receiver;
	uint8_t ch;
	ch=receiver;
	switch(ch){
		case 'A':
			//operation_fwd();
		break;
	
		case 'B':
			//operation_bwd();
		break;
	
		case 'C':
			//operation_turnLeft();
		break;
	
		case 'D':
			//operation_turnRight();
		break;
	
		case 'E':
			//operation_parallelRight();
		break;
	
		case 'F':
			//operation_parallelLeft();
		break;
	
		case 'G':
			operation_armFwd();
			//operation_armFwd();
		break;
	
		case 'H':
			operation_armBwd();
			//operation_armBwd();
		break;
	
		case 'I':
			operation_armStop();
			//operation_armTurnRight();
		break;
	
		case 'J':
			//operation_armTurnLeft();
		break;
	
		case 'K':
			//operation_cameraUp();
		break;
	
		case 'L':
			//operation_cameraDown();
		break;
	
		case 'M':
			//opreation_armStop();
		break;
		
		case 'N':
			//operation_camerastop();
		break;
		
		default:
			//operation_ready();
		break;
	}

}

void operation_armFwd(void){

	TIM2->CR1 |= TIM_CR1_CEN;
	TIM2->CCR1		= 10;//2ms duty cycle to make servo turn right
	TIM2->EGR		 |=	TIM_EGR_UG;				//set TO UG
}

void operation_armBwd(void){
	TIM3->CR1 |= TIM_CR1_CEN;
	TIM3->CCR1		= 30;//1ms duty cycle to make servo turn left
	TIM3->EGR		 |=	TIM_EGR_UG;				//set TO UG
}

void operation_armStop(void){
	TIM4->CR1 |= TIM_CR1_CEN;
	TIM4->CCR1		= 50;//2ms duty cycle to make servo turn right
	TIM4->EGR		 |=	TIM_EGR_UG;				//set TO UG
//	TIM3->CCR1		= 7;
//	TIM3->EGR		 |=	TIM_EGR_UG;
//	delay_ms(100);
//	TIM3->CR1 &= ~TIM_CR1_CEN;	//stop the timer for stopping pwm signal
}