#include "util.h"


void initialization(void);
//void timer3_1_tester(void);
//void timer3_2_tester(void);
//void timer4_1_tester(void);
//void timer4_2_tester(void);
//void timer4_4_tester(void);

void motor1_on(void);
void motor2_on(void);
void motor_on(void);
void stop_motor1(void);
void stop_motor2(void);	
void stop_mvm(void);
void operation_fwd(void);
void operation_bwd (void);
void operation_turnLeft (void);
void operation_turnRight (void);
void opreation_second_acceleration(void);
void operation_third_acceleration(void);
void opreation_wheel_stop(void);

void operation_armFwd(void);
void operation_armBwd(void);
void operation_subarmFwd(void);//new
void operation_subarmBwd(void);//new
void operation_armStop(void);
void operation_clampGet(void);
void operation_clampLease(void);
void operation_clampStop(void);
void operation_rotate_arm_right(void);
void operation_rotate_arm_left(void);
void operation_rotate_arm_right_10deg(void);//new
void operation_rotate_arm_left_10deg(void);//new
void operation_rotate_clamp_right(void);
void operation_rotate_clamp_left(void);
void operation_arm_mvfwd_5_deg(void);
void operation_arm_mvbwd_5_deg(void);
void operation_subarm_mvfwd_5_deg(void);
void operation_subarm_mvbwd_5_deg(void);

void operation_clamp_get_5_deg(void);
void operation_clamp_lease_5_deg(void);

void movement_ctrl(void);
