/*
 * DCmotor.h
 *  Created on: Oct 29, 2026
 *      Author: YOUSEF
 */

#ifndef DCMOTOR_H_
#define DCMOTOR_H_

#include "std_types.h"
#include "gpio.h"


/* Motor input 1 pin */
#define DCMOTOR_IN1_PORT_ID     PORTB_ID
#define DCMOTOR_IN1_PIN_ID      PIN0_ID

/* Motor input 2 pin */
#define DCMOTOR_IN2_PORT_ID     PORTB_ID
#define DCMOTOR_IN2_PIN_ID      PIN1_ID

/* Max speed in percentage */
#define DCMOTOR_MAX_SPEED       100

typedef enum
{
    DCMOTOR_STOP,
    DCMOTOR_CW,
    DCMOTOR_ACW
}DcMotor_State;


void DcMotor_Init(void);

void DcMotor_Rotate(DcMotor_State state, uint8 speed);

#endif /* DC_MOTOR_H_ */
