/*
 * LED.c
 *
 *  Created on: Oct 29, 2026
 *      Author: YOUSEF
 */

#include "led.h"

/* Pin levels according to the selected logic */
#if (LED_LOGIC_TYPE == LED_POSITIVE_LOGIC)
    #define LED_ON_LEVEL        LOGIC_HIGH
    #define LED_OFF_LEVEL       LOGIC_LOW
#elif (LED_LOGIC_TYPE == LED_NEGATIVE_LOGIC)
    #define LED_ON_LEVEL        LOGIC_LOW
    #define LED_OFF_LEVEL       LOGIC_HIGH
#else
    #error "Invalid LED_LOGIC_TYPE"
#endif

void LEDS_init(void)
{
    /* Setup the direction of all LEDs pins as output */
    GPIO_setupPinDirection(LED_RED_PORT_ID,   LED_RED_PIN_ID,   PIN_OUTPUT);
    GPIO_setupPinDirection(LED_GREEN_PORT_ID, LED_GREEN_PIN_ID, PIN_OUTPUT);
    GPIO_setupPinDirection(LED_BLUE_PORT_ID,  LED_BLUE_PIN_ID,  PIN_OUTPUT);

    /* Turn off all LEDs */
    LED_off(LED_RED);
    LED_off(LED_GREEN);
    LED_off(LED_BLUE);
}

void LED_on(LED_ID id)
{
    switch (id)
    {
    case LED_RED:
        GPIO_writePin(LED_RED_PORT_ID, LED_RED_PIN_ID, LED_ON_LEVEL);
        break;
    case LED_GREEN:
        GPIO_writePin(LED_GREEN_PORT_ID, LED_GREEN_PIN_ID, LED_ON_LEVEL);
        break;
    case LED_BLUE:
        GPIO_writePin(LED_BLUE_PORT_ID, LED_BLUE_PIN_ID, LED_ON_LEVEL);
        break;
    default:
        /* Invalid LED id: do nothing */
        break;
    }
}

void LED_off(LED_ID id)
{
    switch (id)
    {
    case LED_RED:
        GPIO_writePin(LED_RED_PORT_ID, LED_RED_PIN_ID, LED_OFF_LEVEL);
        break;
    case LED_GREEN:
        GPIO_writePin(LED_GREEN_PORT_ID, LED_GREEN_PIN_ID, LED_OFF_LEVEL);
        break;
    case LED_BLUE:
        GPIO_writePin(LED_BLUE_PORT_ID, LED_BLUE_PIN_ID, LED_OFF_LEVEL);
        break;
    default:
        /* Invalid LED id: do nothing */
        break;
    }
}
