/*
 * smart_home.c
 *
 *  Created on: Oct 29, 2026
 *      Author: YOUSEF
 */

#include "pwm.h"

/*
 PWM MODE
 PRESCALER=F_CPU/256
 Set OC0 on compare match when up-counting. Clear OC0 on compare
 match when downcounting.
 */


void PWM_Timer0_start(uint8 duty_cycle)
{
	if(duty_cycle>=PWM_MIN_DUTY_CYCLE && duty_cycle<=PWM_MAX_DUTY_CYCLE)
	{
	TCCR0=(1<<WGM00)|(1<<CS02)|(1<<COM01);   //INTIALIZE  TIMER0 IN PWM MODE
	OCR0=(uint8)(((uint16)duty_cycle * 255) / 100);
	DDRB|=(1<<PB3);
	}

}
