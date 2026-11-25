/*
 * buzzer.c
 *
 *  Created on: Oct 29, 2026
 *      Author: YOUSEF
 */


#include "buzzer.h"

#if (BUZZER_LOGIC_TYPE == BUZZER_POSITIVE_LOGIC)
    #define BUZZER_ON_LEVEL     LOGIC_HIGH
    #define BUZZER_OFF_LEVEL    LOGIC_LOW
#elif (BUZZER_LOGIC_TYPE == BUZZER_NEGATIVE_LOGIC)
    #define BUZZER_ON_LEVEL     LOGIC_LOW
    #define BUZZER_OFF_LEVEL    LOGIC_HIGH
#else
    #error "Invalid BUZZER_LOGIC_TYPE"
#endif

void Buzzer_init(void)
{
    GPIO_setupPinDirection(BUZZER_PORT_ID, BUZZER_PIN_ID, PIN_OUTPUT);
    Buzzer_off();
}

void Buzzer_on(void)
{
    GPIO_writePin(BUZZER_PORT_ID, BUZZER_PIN_ID, BUZZER_ON_LEVEL);
}

void Buzzer_off(void)
{
    GPIO_writePin(BUZZER_PORT_ID, BUZZER_PIN_ID, BUZZER_OFF_LEVEL);
}
