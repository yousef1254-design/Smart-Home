/*
 * buzzer.h
 *
 *  Created on: Oct 29, 2026
 *      Author: YOUSEF
 */

#ifndef BUZZER_H_
#define BUZZER_H_

#include "std_types.h"
#include "gpio.h"

#define BUZZER_PORT_ID          PORTD_ID
#define BUZZER_PIN_ID           PIN3_ID


#define BUZZER_POSITIVE_LOGIC   1   /* ON when pin = HIGH */
#define BUZZER_NEGATIVE_LOGIC   0   /* ON when pin = LOW  */
#define BUZZER_LOGIC_TYPE       BUZZER_POSITIVE_LOGIC

void Buzzer_init(void);

void Buzzer_on(void);

void Buzzer_off(void);

#endif /* BUZZER_H_ */
