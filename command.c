#include "command.h"
#include "operation_index.h"
//uint8_t command_fwd[]="A";//fwd
//uint8_t command_bwd[]="B";//bwd
//uint8_t command_turnLeft[]="C";//turn left
//uint8_t command_turnRight[]="D";//turn right
//uint8_t command_parallelRight[]="E";//parallel right
//uint8_t command_parallelLeft[]="F";//parallel left
//uint8_t command_armFwd[]="G";//arm fwd
//uint8_t command_armBwd[]="H";//arm bwd
//uint8_t command_armTurnRight[]="I";//arm right
//uint8_t command_armTurnLeft[]="J";//arm left
//uint8_t command_cameraDown[]="K";//camera down
//uint8_t command_cameraUp[]="L";//camera up

/**********************************************************
Complex command reader
Author: Yuming Zhu
Usage: For farther extension for the system
			 When there are too many functions need to be called
			 The following code will help to read command in string
			 
			 Note: Not applied in the project
************************************************************
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

/**********************************************************
Single Character comand Reader
Author: Yuming Zhu
Usage: For a single character command, this function will be better
				to reduce memory usage. 
Read the command that receives from USART3, and goes to specific 
functions. 
Empty case can be used by further system extension
************************************************************/
void process(uint8_t receiver){
	//Command command = receiver;
	uint8_t ch;
	ch=receiver;
	switch(ch){
		case 'A':
			operation_fwd();
		break;
	
		case 'B':
			operation_bwd();
		break;
	
		case 'C':
			operation_turnLeft();
		break;
	
		case 'D':
			operation_turnRight();
		break;
	
		case 'E':
			opreation_second_acceleration();
		break;
	
		case 'F':
			operation_third_acceleration();
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
			operation_subarmFwd();
		break;
	
		case 'K':
			operation_subarmBwd();
		break;
	
		case 'L':
			operation_rotate_arm_right_10deg();
		break;
	
		case 'M':
			operation_rotate_arm_left_10deg();
		break;
		
		case 'N':
			//operation_camerastop();
		break;
		
		case 'O':
			opreation_wheel_stop();
		break;
		
		case 'P':

		break;
		
		case 'Q':

		break;
		
		case 'a':
			operation_clampGet();
		break;
		
		case 'b':
			operation_clampLease();
		break;
		
		case 'c':
			operation_clampStop();
		break;
		
		case'd':
			operation_rotate_arm_left();
		break;
		
		case 'e':
			operation_rotate_arm_right();
		break;
		
		case 'f':
			operation_rotate_clamp_left();
		break;
		
		case 'g':
			operation_rotate_clamp_right();
		break;
		
		case'h':

		break;
		
		case 'i':
			operation_arm_mvfwd_5_deg();
		break;
		
		case 'j':
			operation_arm_mvbwd_5_deg();
		break;
		
		case 'k':

		break;
		
		case'l':

		break;
		
		case'm':
			operation_rotate_clamp_right();
		break;
		
		case'n':
			operation_rotate_clamp_left();
		break;
		
		case'o':
			operation_subarm_mvfwd_5_deg();
		break;
		
		case'p':
			operation_subarm_mvbwd_5_deg();
		break;
		
		case'q':
			initialization();
		break;
		
		
		default:
			//operation_ready();
		break;
	}

}



