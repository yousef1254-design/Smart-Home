/*
 * DCmotor.c
 *
 *  Created on: Oct 29, 2026
 *      Author: YOUSEF
 */


#include "DCmotor.h"
#include "pwm.h"

void DcMotor_Init(void)
{
    /* Setup the direction of the motor pins as output */
    GPIO_setupPinDirection(DCMOTOR_IN1_PORT_ID, DCMOTOR_IN1_PIN_ID, PIN_OUTPUT);
    GPIO_setupPinDirection(DCMOTOR_IN2_PORT_ID, DCMOTOR_IN2_PIN_ID, PIN_OUTPUT);

    /* Stop the motor at the beginning */
    GPIO_writePin(DCMOTOR_IN1_PORT_ID, DCMOTOR_IN1_PIN_ID, LOGIC_LOW);
    GPIO_writePin(DCMOTOR_IN2_PORT_ID, DCMOTOR_IN2_PIN_ID, LOGIC_LOW);

}

void DcMotor_Rotate(DcMotor_State state, uint8 speed)
{

    if (speed > DCMOTOR_MAX_SPEED)
    {
        speed = DCMOTOR_MAX_SPEED;
    }

    switch (state)
    {
    case DCMOTOR_CW:
        GPIO_writePin(DCMOTOR_IN1_PORT_ID, DCMOTOR_IN1_PIN_ID, LOGIC_LOW);
        GPIO_writePin(DCMOTOR_IN2_PORT_ID, DCMOTOR_IN2_PIN_ID, LOGIC_HIGH);
        break;
    case DCMOTOR_ACW:
        GPIO_writePin(DCMOTOR_IN1_PORT_ID, DCMOTOR_IN1_PIN_ID, LOGIC_HIGH);
        GPIO_writePin(DCMOTOR_IN2_PORT_ID, DCMOTOR_IN2_PIN_ID, LOGIC_LOW);
        break;
    case DCMOTOR_STOP:
    default:
        GPIO_writePin(DCMOTOR_IN1_PORT_ID, DCMOTOR_IN1_PIN_ID, LOGIC_LOW);
        GPIO_writePin(DCMOTOR_IN2_PORT_ID, DCMOTOR_IN2_PIN_ID, LOGIC_LOW);
        speed = 0;
        break;
    }

    PWM_Timer0_start(speed);
}
