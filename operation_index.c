#include "timer.h"

uint16_t main_arm_mvm_signal = 120;//main arm
uint16_t sub_arm_mvm_signal=65;//sub arm
uint16_t clamp_mvm_signal=65;
uint16_t arm_rotate_signal = 140;
uint16_t clamp_rotate_signal = 200;
//uint16_t main_arm_mvm_signal = 65;//main arm
//uint16_t sub_arm_mvm_signal=35;//sub arm
//uint16_t clamp_mvm_signal=40;
//uint16_t arm_rotate_signal = 120;
//uint16_t clamp_rotate_signal = 220;

//uint16_t main_arm_mvm_signal,sub_arm_mvm_signal,arm_rotate_signal,clamp_rotate_signal,clamp_mvm_signal;

/**********************************************************************************
initialization
Author: Yuming Zhu
Function: initialize the postion for clamp rotation, catch, main arm, sub arm
					Reset all servos' position
**********************************************************************************/
void initialization(void)
{

	TIM4->CR1 |= TIM_CR1_CEN;
	while(main_arm_mvm_signal!=70||sub_arm_mvm_signal!=30||clamp_mvm_signal!=40||clamp_rotate_signal!=220||arm_rotate_signal!=120){
	//sub arm
		if(main_arm_mvm_signal>70){
			main_arm_mvm_signal -=5;
		TIM4->CCR1 = main_arm_mvm_signal;
			delay_ms(35);
		}
		if(main_arm_mvm_signal<70){
			main_arm_mvm_signal += 5;
			TIM4->CCR1 = main_arm_mvm_signal;
			delay_ms(35);
		}
		
	//main arm
		if(sub_arm_mvm_signal>30){
			sub_arm_mvm_signal -=5;
			TIM4->CCR2 = sub_arm_mvm_signal;
			delay_ms(35);
		}
		if(sub_arm_mvm_signal<30){
			sub_arm_mvm_signal += 5;
			TIM4->CCR2 = sub_arm_mvm_signal;
			delay_ms(35);
		}
	//clamp rotate
		if(clamp_rotate_signal>220){
			clamp_rotate_signal -= 5;
			TIM4->CCR4 = clamp_rotate_signal;
			delay_ms(35);
		}
		if(clamp_rotate_signal<220){
			clamp_rotate_signal += 5;
			TIM4->CCR4 = clamp_rotate_signal;
			delay_ms(35);
		}
	//clamp catch
		if(clamp_mvm_signal>40){
			clamp_mvm_signal -= 5;
			TIM4->CCR3 = clamp_mvm_signal;
			delay_ms(35);
		}
		if(clamp_mvm_signal<40){
			clamp_mvm_signal += 5;
			TIM4->CCR3 = clamp_mvm_signal;
			delay_ms(35);
		}
		if(arm_rotate_signal>120){
			arm_rotate_signal -= 5;
			TIM3->CCR2 = arm_rotate_signal;
			delay_ms(35);
		}
		
		if(arm_rotate_signal<120){
			arm_rotate_signal += 5;
			TIM3->CCR2 = arm_rotate_signal;
			delay_ms(35);
		}
		
	}
}


/**********************************************************************************
Name: Motor Movement 
Author: Zongyao Liu
Modifier: Yuming Zhu
Function: Control all movement of the steppers
Including: Forward, backward, Acceleration, turnning
**********************************************************************************/
void motor1_on(void){
		GPIOA->CRH &= ~GPIO_CRH_CNF10;
		GPIOA->CRH |= GPIO_CRH_CNF10_1;
		GPIOA->CRH |= GPIO_CRH_MODE10;
}

void motor2_on(void){
		GPIOA->CRH &= ~GPIO_CRH_CNF11;
		GPIOA->CRH |= GPIO_CRH_CNF11_1;
		GPIOA->CRH |= GPIO_CRH_MODE11;
}

 void motor_on (void)
 {
	 	  TIM1->PSC = 240; //240,180,120
	  TIM1->CR1 |= TIM_CR1_CEN;

 }
 
  void stop_motor1(void)
 {
		GPIOA->CRH &= ~GPIO_CRH_CNF10;
		GPIOA->CRH |= GPIO_CRH_CNF10_0;
		GPIOA->CRH &= ~GPIO_CRH_MODE10;
 }
 
  void stop_motor2(void)
 {
		GPIOA->CRH &= ~GPIO_CRH_CNF11;
		GPIOA->CRH |= GPIO_CRH_CNF11_0;
		GPIOA->CRH &= ~GPIO_CRH_MODE11;
 }

void operation_fwd (void)
{
	motor1_on();
	motor2_on();
	GPIOA->ODR |= GPIO_ODR_ODR12;
	GPIOA->ODR &= ~GPIO_ODR_ODR3;						
	motor_on();
}

void operation_bwd (void)
{
	motor1_on();
	motor2_on();
	GPIOA->ODR |= GPIO_ODR_ODR3; //PA3 pos, direction back
	GPIOA->ODR &= ~GPIO_ODR_ODR12;//PA12 neg, direction back
	motor_on();
}

void operation_turnLeft (void)
{
//	stop_motor1();
	motor2_on();
	motor1_on();
	GPIOA->BSRR |= GPIO_BSRR_BR3;//PA 3 RIGHT MOTOR
	GPIOA->BSRR |= GPIO_BSRR_BR12;
	
	motor_on();
}

void operation_turnRight (void)
{
//	stop_motor2();
	motor1_on();
	motor2_on();
	GPIOA->BSRR |= GPIO_BSRR_BS12;
	GPIOA->BSRR |= GPIO_BSRR_BS3;
	motor_on();
}

void opreation_second_acceleration(void)
	{
		TIM1->PSC = 180;
	}
	
void operation_third_acceleration(void)
	{
		TIM1->PSC = 120;
	}
	
void opreation_wheel_stop(void){
	TIM1->CR1 &=~ TIM_CR1_CEN;
}	

/************************ end of motor part ******************************/



/**********************************************************************************
 Name: arm move forward
Author: Yuming Zhu
Function: Move arm forward for 20deg
**********************************************************************************/ 
void operation_armFwd(void){
	int i;
	TIM4->CR1 |= TIM_CR1_CEN;
	if(main_arm_mvm_signal<=180){
		for(i=0;i<4;i++){
		main_arm_mvm_signal = main_arm_mvm_signal + 5;
		TIM4->CCR2 = main_arm_mvm_signal;//those two servos goes 180~0
		delay_ms(35);
		}
}
}

/**********************************************************************************
 Name: arm move backward
Author: Yuming Zhu
Function: Move arm backward for 20deg, 5 deg each time, loops for 4 times
**********************************************************************************/ 

void operation_armBwd(void){
	int j;
	TIM4->CR1 |= TIM_CR1_CEN;
	if(main_arm_mvm_signal>=70){
		for(j=0;j<4;j++){
		main_arm_mvm_signal = main_arm_mvm_signal - 5;
		delay_ms(35);
		TIM4->CCR2 = main_arm_mvm_signal;//those two servos goes 0~180
		}
	}
}

/**********************************************************************************
 Name: arm move forward for 5 deg
Author: Yuming Zhu
Function: Move arm forward for 5 deg
**********************************************************************************/ 
void operation_arm_mvfwd_5_deg(void){
		TIM4->CR1 |= TIM_CR1_CEN;
		
	if(main_arm_mvm_signal<=180){
		main_arm_mvm_signal = main_arm_mvm_signal + 5;
		delay_ms(50);
		TIM4->CCR2 = main_arm_mvm_signal;	//this servo goes 0~180
	}
	else{
		main_arm_mvm_signal=main_arm_mvm_signal;
	}
}

/**********************************************************************************
 Name: arm move backward for 5 deg
Author: Yuming Zhu
Function: Move arm forward for 5 deg
*********************************************************************************/ 
void operation_arm_mvbwd_5_deg(void){
		TIM4->CR1 |= TIM_CR1_CEN;
		delay_ms(50);
	if(main_arm_mvm_signal>=70){
		main_arm_mvm_signal = main_arm_mvm_signal - 5;
		delay_ms(50);
		TIM4->CCR2 = main_arm_mvm_signal;	//this servo goes 0~180
	}
	else{
		main_arm_mvm_signal=main_arm_mvm_signal;
	}
		
}

/**********************************************************************************
 Name: sub-arm move forward for 20 deg
Author: Yuming Zhu
Function: Move sub-arm forward for 20 deg
**********************************************************************************/ 
void operation_subarmFwd(void){
	int i;
	TIM4->CR1 |= TIM_CR1_CEN;
	if(sub_arm_mvm_signal>=40){
		for(i=0;i<4;i++){
			if(sub_arm_mvm_signal>40){
		sub_arm_mvm_signal = sub_arm_mvm_signal - 5;
			}
			else{
				sub_arm_mvm_signal=sub_arm_mvm_signal;
			}
		TIM4->CCR1 = sub_arm_mvm_signal;//those two servos goes 180~0
		delay_ms(35);
		}
}
}

/**********************************************************************************
 Name: sub-arm move backward for 20 deg
Author: Yuming Zhu
Function: Move sub-arm backward for 20 deg
**********************************************************************************/ 
void operation_subarmBwd(void){
	int j;
	TIM4->CR1 |= TIM_CR1_CEN;
	if(sub_arm_mvm_signal<=180){
		for(j=0;j<4;j++){
			if(sub_arm_mvm_signal<180){
		sub_arm_mvm_signal = sub_arm_mvm_signal + 5;
			}
			else{
				sub_arm_mvm_signal=sub_arm_mvm_signal;
			}	
		TIM4->CCR1 = sub_arm_mvm_signal;//those two servos goes 0~180
			delay_ms(35);
		}
	}
}

/**********************************************************************************
 Name: close arms' servos
Author: Yuming Zhu
Function: disable TIM4 stop close all servos of the arms
Note: This will unlock the arm, be careful when use
**********************************************************************************/ 
void operation_armStop(void){
	TIM4->CR1 &= ~TIM_CR1_CEN;	//stop the timer for stopping pwm signal
}

/**********************************************************************************
 Name: sub-arm move forward for 5 deg
Author: Yuming Zhu
Function: Move sub-arm forward for 5 deg
**********************************************************************************/ 
void operation_subarm_mvfwd_5_deg(void){
	TIM4->CR1 |= TIM_CR1_CEN;
	delay_ms(35);
	if(sub_arm_mvm_signal>=40){
		sub_arm_mvm_signal = sub_arm_mvm_signal - 5;
	}
		TIM4->CCR1 = sub_arm_mvm_signal;	//this servo goes 0~180
}

/**********************************************************************************
 Name: sub-arm move backward for 5 deg
Author: Yuming Zhu
Function: Move sub-arm backward for 5 deg
**********************************************************************************/ 
void operation_subarm_mvbwd_5_deg(void){
	TIM4->CR1 |= TIM_CR1_CEN;
	delay_ms(35);
	if(sub_arm_mvm_signal<=180){
		sub_arm_mvm_signal = sub_arm_mvm_signal + 5;
	}
		TIM4->CCR1 = sub_arm_mvm_signal;	//this servo goes 0~180
}

/**********************************************************************************
 Name: Clamp-catch
Author: Yuming Zhu
Function: change CCR value to let servo rotation clockwise
					Let clamp reduce the angle to catch something
**********************************************************************************/ 
void operation_clampGet(void){
	TIM4->CR1|=TIM_CR1_CEN;
	while(clamp_mvm_signal<=235){
		TIM4->CCR3 = clamp_mvm_signal;	//this servo goes 0~180		
		delay_ms(50);
		clamp_mvm_signal = clamp_mvm_signal + 5;
	}
}

/**********************************************************************************
 Name: Clamp-Lease
Author: Yuming Zhu
Function: change CCR value to let servo rotation counter clockwise
					Let clamp reduce the angle to lease something
**********************************************************************************/ 
void operation_clampLease(void){
	TIM4->CR1|=TIM_CR1_CEN;
	while(clamp_mvm_signal>=40){
		TIM4->CCR3 = clamp_mvm_signal;	//this servo goes 0~180
		delay_ms(50);
		clamp_mvm_signal = clamp_mvm_signal - 5;
	}
}

/**********************************************************************************
 Name: Clamp-stop
Author: Yuming Zhu
Function: change CCR value to stop clamp's servo
Note: This will stop the whole arm, be careful
**********************************************************************************/ 
void operation_clampStop(void){
	TIM4->CR1 &= ~TIM_CR1_CEN;
}

//void operation_clamp_get_10_deg(void){
//		TIM2->CR1|=TIM_CR1_CEN;
//		clamp_mvm_signal = clamp_mvm_signal + 5;
//		clamp_mvm_signal_2 = clamp_mvm_signal_2 - 5;
//		delay_ms(100);
//		TIM2->CCR3 = clamp_mvm_signal;	//this servo goes 0~180
//		TIM2->CCR4 = clamp_mvm_signal_2;//those two servos goes 180~0	

//}

//void operation_clamp_lease_10_deg(void){
//		TIM2->CR1|=TIM_CR1_CEN;
//		clamp_mvm_signal = clamp_mvm_signal - 5;
//		clamp_mvm_signal_2 = clamp_mvm_signal_2 + 5;
//		delay_ms(100);
//		TIM2->CCR3 = clamp_mvm_signal;	//this servo goes 0~180
//		TIM2->CCR4 = clamp_mvm_signal_2;//those two servos goes 180~0	
//}

	
/**********************************************************************************
 Name: Arm rotates right
Author: Yuming Zhu
Function: Change CCR value to make the base of the arm rotate right
**********************************************************************************/ 
void operation_rotate_arm_right(void){
	TIM3->CR1 |= TIM_CR1_CEN;
		while(arm_rotate_signal>=70){
		TIM3->CCR2 = arm_rotate_signal;	//this servo goes 0~180
		delay_ms(100);
		arm_rotate_signal = arm_rotate_signal - 5;
	}

}

/**********************************************************************************
 Name: Arm rotates left
Author: Yuming Zhu
Function: Change CCR value to make the base of the arm rotate left
**********************************************************************************/ 
void operation_rotate_arm_left(void){
	TIM3->CR1 |= TIM_CR1_CEN;
		while(arm_rotate_signal<=250){
		TIM3->CCR2 = arm_rotate_signal;	//this servo goes 0~180
		delay_ms(100);
		arm_rotate_signal = arm_rotate_signal +5;
	}

}

/**********************************************************************************
 Name: Arm rotates right for 10 deg
Author: Yuming Zhu
Function: Change CCR value to make the base of the arm rotate right for 10 deg
**********************************************************************************/ 
void operation_rotate_arm_right_10deg(void){
	TIM3->CR1 |= TIM_CR1_CEN;
		if(arm_rotate_signal>=70){
		arm_rotate_signal = arm_rotate_signal - 5;
		TIM3->CCR2 = arm_rotate_signal;	//this servo goes 0~180
		delay_ms(35);		
	}

}

/**********************************************************************************
 Name: Arm rotates left for 10 deg
Author: Yuming Zhu
Function: Change CCR value to make the base of the arm rotate left for 10 deg
**********************************************************************************/
void operation_rotate_arm_left_10deg(void){
	TIM3->CR1 |= TIM_CR1_CEN;
		if(arm_rotate_signal<=250){		
		arm_rotate_signal = arm_rotate_signal +5;
		TIM3->CCR2 = arm_rotate_signal;	//this servo goes 0~180
		delay_ms(35);
	}

}

/**********************************************************************************
 Name: clamp rotates right for 10 deg
Author: Yuming Zhu
Function: Change CCR value to make the clamp rotate right for 10 deg
**********************************************************************************/
void operation_rotate_clamp_right(void){
		TIM4->CR1 |= TIM_CR1_CEN;
		if(clamp_rotate_signal<=250){
		clamp_rotate_signal = clamp_rotate_signal - 10;
		TIM4->CCR4 = clamp_rotate_signal;	//this servo goes 0~180
		delay_ms(35);
		}
		else{
			clamp_mvm_signal=clamp_mvm_signal;
	
}
}

/**********************************************************************************
 Name: clamp rotates left for 10 deg
Author: Yuming Zhu
Function: Change CCR value to make the clamp rotate left for 10 deg
**********************************************************************************/
void operation_rotate_clamp_left(void){
		TIM4->CR1 |= TIM_CR1_CEN;
		if(clamp_rotate_signal>=60){
		clamp_rotate_signal = clamp_rotate_signal + 10;
		TIM4->CCR4 = clamp_rotate_signal;	//this servo goes 0~180
		delay_ms(35);
	}
		else{
			clamp_mvm_signal=clamp_mvm_signal;
	
}
}


/**********************************************************************************
tester functions
author: Yuming Zhu
Function: multiple functions for testing different parts
So that I can read the maximum and minimum position that the arm and clamp, etc
can reach
Enable if need further adjustment
**********************************************************************************/
//clamp catch signal
//void timer3_1_tester(void){
//	TIM3->CR1 |= TIM_CR1_CEN;
//	if(tmp2==40){
//	while(tmp2<=235){
////		TIM2->CCR3 = counter;
//		TIM3->CCR1 = tmp2;
//		delay_ms(60);
//		tmp2 = tmp2 + 5;
//		}
//	}
//	tmp2 =235;
//	if(tmp2 == 235){
//		while(tmp2>=40){
//			tmp2 = tmp2 - 5;	
////		TIM2->CCR3 = counter;
//		TIM3->CCR1 = tmp2;
//		delay_ms(60);
//		}
//	}
//	tmp2=40;
//}

////arm rotate part, middle is 110, right is 70, left to back is 245
//void timer3_2_tester(void){
//	TIM3->CR1 |= TIM_CR1_CEN;
//	if(arm_rotate_signal==110){
//	while(arm_rotate_signal<=245){
////		TIM2->CCR3 = counter;
//		TIM3->CCR2 = arm_rotate_signal;
//		delay_ms(500);
//		arm_rotate_signal = arm_rotate_signal+5;	
//		}
//	}
//	arm_rotate_signal =245;
//	if(arm_rotate_signal==245){
//		while(arm_rotate_signal>=110){
////		TIM2->CCR3 = counter;
//		TIM3->CCR2 = arm_rotate_signal;
//		delay_ms(500);
//		arm_rotate_signal = arm_rotate_signal-5;	
//		}
//	}
//	arm_rotate_signal=110;
//}

////arm sub arm part:fwd signal-, bwd signal+
//void timer4_1_tester(void){
//	TIM4->CR1 |= TIM_CR1_CEN;
//		TIM3->CR1 |= TIM_CR1_CEN;
//	if(tmp==270){
//	while(tmp>=90){ 
////		TIM2->CCR3 = counter;
//		TIM3->CCR1 = tmp;
//		delay_ms(500);
//		tmp = tmp - 10;
//			
//		}
//	}
//	tmp =90;
//	if(tmp==90){
//		while(tmp<=270){
////		TIM2->CCR3 = counter;
//		tmp = tmp + 10;	
//		TIM3->CCR1 = tmp;
//		delay_ms(500);
//		
//		
//		}
//	}
//	tmp = 270;
//}

////arm main arm part, fwd signal +, bwd signal-
//void timer4_2_tester(void){
//	TIM4->CR1 |= TIM_CR1_CEN;
//	if(arm_mvm_signal==70){
//	while(arm_mvm_signal<=180){
////		TIM2->CCR3 = counter;
//		TIM4->CCR2 = arm_mvm_signal;

//		delay_ms(35);
//		arm_mvm_signal = arm_mvm_signal + 5;	

//		}
//	}
//	arm_mvm_signal =180;

//	if(arm_mvm_signal==180){
//		while(arm_mvm_signal>=70){
////		TIM2->CCR3 = counter;
//		TIM4->CCR2 = arm_mvm_signal;

//		delay_ms(35);
//		arm_mvm_signal = arm_mvm_signal - 5;	

//		}
//	}
//	arm_mvm_signal = 70;

//}

////clamp finger 1 part
//void timer4_3_tester(void){
//	TIM4->CR1 |= TIM_CR1_CEN;
//	if(clamp_rotate_signal==30||clamp_rotate_signal==35){
//	while(clamp_rotate_signal<=250){
////		TIM2->CCR3 = counter;
//		TIM4->CCR3 = clamp_rotate_signal;
//		delay_ms(100);
//		clamp_rotate_signal = clamp_rotate_signal + 5;	
//		}
//	}
//	clamp_rotate_signal =250;
//	if(clamp_rotate_signal==245 || clamp_rotate_signal==250){
//		while(clamp_rotate_signal>=30){
////		TIM2->CCR3 = counter;
//		TIM4->CCR3 = clamp_rotate_signal;
//		delay_ms(100);
//		clamp_rotate_signal = clamp_rotate_signal - 5;	
//		}
//	}
//	clamp_rotate_signal = 30;
//}

////clamp rotate part
//void timer4_4_tester(void){
//	TIM4->CR1 |= TIM_CR1_CEN;
//	if(clamp_rotate_signal==60){
//	while(clamp_rotate_signal<=250){
////		TIM2->CCR3 = counter;
//		TIM4->CCR4 = clamp_rotate_signal;
//		delay_ms(100);
//		clamp_rotate_signal = clamp_rotate_signal + 5;	
//		}
//	}
//	clamp_rotate_signal =250;
//	if(clamp_rotate_signal==250){
//		while(clamp_rotate_signal>=60){
////		TIM2->CCR3 = counter;
//		TIM4->CCR4 = clamp_rotate_signal;
//		delay_ms(100);
//		clamp_rotate_signal = clamp_rotate_signal - 5;	
//		}
//	}
//	clamp_rotate_signal = 60;
//}
