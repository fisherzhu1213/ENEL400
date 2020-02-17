#include "GPIOs.h"
#include "timer.h"
#include "adc.h"
#include "util.h"
#include "USART.h"
/*
for farther extension
extern uint8_t inBuffer[BUFFER_SIZE];
extern uint8_t outBuffer[BUFFER_SIZE];

extern int inBufferCounter;
extern int outBufferCounter;
extern uint32_t adc_val;
*/

typedef enum{
	//movement part
	A,//FWD
	B,//BWD
	C,//TURN LEFT
	D,//TURN RIGHT
	E,//PARALLEL RIGHT
	F,//PARALLEL LEFT
	//arm part
	G,//ARM FWD
	H,//ARM BWD
	I,//ARM RIGHT
	J,//ARM LEFT
	//camera mechanical part
	K,//CAMERA UP
	L,//CAMERA DOWN
	M,//ARM STOP
	N,//CAMERA STOP
	O,//SECOND ACCELERATION
	P,//THIRD ACCELERATION
	Q,//WHEEL STOP
	R,//FINGER_1_INWARD
	S,//FINGER_1_OUTWARD
	T,//FINGER_2_INWARD
	U,//FINGER_2_OUTWARD
	V,//FINGER_3_INWARD
	W,//FINGER_3_OUTWARD
	X,
	Y,
	Z,
	a,
	b,
	c,
	d
}Command;

uint8_t command_rev(void);
void process(uint8_t );
//uint8_t checkCommand(uint8_t [], int size);
//Command getFirstArgu(void);
//Command getSecondArgu(void);
//Command checkOperation(void);


