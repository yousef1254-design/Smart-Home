/*
 * LED.h
 *
 *  Created on: Oct 29, 2026
 *      Author: YOUSEF
 */

#ifndef LED_H_
#define LED_H_

#include "std_types.h"
#include "gpio.h"

/* LED connection logic */
#define LED_POSITIVE_LOGIC      1   /* LED ON  when pin = HIGH */
#define LED_NEGATIVE_LOGIC      0   /* LED ON  when pin = LOW  */
#define LED_LOGIC_TYPE          LED_POSITIVE_LOGIC

/* Red LED pin */
#define LED_RED_PORT_ID         PORTB_ID
#define LED_RED_PIN_ID          PIN5_ID

/* Green LED pin */
#define LED_GREEN_PORT_ID       PORTB_ID
#define LED_GREEN_PIN_ID        PIN6_ID

/* Blue LED pin */
#define LED_BLUE_PORT_ID        PORTB_ID
#define LED_BLUE_PIN_ID         PIN7_ID

typedef enum
{
    LED_RED,
    LED_GREEN,
    LED_BLUE
}LED_ID;

/* Initializes all LEDs pins direction as output and turns all LEDs off. */
void LEDS_init(void);

/* Turns on the specified LED. */
void LED_on(LED_ID id);

/* Turns off the specified LED. */
void LED_off(LED_ID id);

#endif /* LED_H_ */
