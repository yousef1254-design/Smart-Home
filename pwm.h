/*
 * smart_home.c
 *
 *  Created on: Oct 29, 2026
 *      Author: YOUSEF
 */

#ifndef PWM_H_
#define PWM_H_

#include <avr/io.h>
#include "std_types.h"

/* Duty cycle limits (in percent) */
#define PWM_MAX_DUTY_CYCLE          100
#define PWM_MIN_DUTY_CYCLE          0

void PWM_Timer0_Start(uint8 duty_cycle);

#endif /* PWM_H_ */
