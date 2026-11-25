/*
 * smart_home.c
 *
 *  Created on: Oct 29, 2026
 *      Author: YOUSEF
 */
#include "std_types.h"
#include "adc.h"
#include "lcd.h"
#include "LED.h"
#include "buzzer.h"
#include "DCmotor.h"
#include "flame_sensor.h"
#include "lm35.h"
#include "LDR_sensor.h"


/* Level on the flame sensor pin when fire is detected (change if inverted) */
#define FLAME_DETECTED_LEVEL        LOGIC_HIGH

/* LCD positions */
#define LCD_FAN_ROW                 0
#define LCD_INFO_ROW                1

static void controlLeds(uint16 light)
{
    if (light <= 15)
    {
        LED_on(LED_RED);
        LED_on(LED_GREEN);
        LED_on(LED_BLUE);
    }
    else if (light <= 50)
    {
        LED_on(LED_RED);
        LED_on(LED_GREEN);
       LED_off(LED_BLUE);
    }
    else if (light <= 70)
    {
        LED_on(LED_RED);
        LED_off(LED_GREEN);
        LED_off(LED_BLUE);
    }
    else
    {
        LED_off(LED_RED);
        LED_off(LED_GREEN);
       LED_off(LED_BLUE);
    }
}


static uint8 getFanSpeed(uint8 temp)
{
    if (temp >= 40)      return 100;
    else if (temp >= 35) return 75;
    else if (temp >= 30) return 50;
    else if (temp >= 25) return 25;
    else                 return 0;
}


static void updateLcd(uint8 fan_speed, uint8 temp, uint16 light)
{

    if (fan_speed != 0)
    {
        LCD_displayStringRowColumn(LCD_FAN_ROW, 0, "FAN is ON ");
    }
    else
    {
    	LCD_displayStringRowColumn(LCD_FAN_ROW, 0, "FAN is OFF");
    }


    LCD_displayStringRowColumn(LCD_INFO_ROW, 0, "Temp=");
    LCD_moveCursor(LCD_INFO_ROW, 5);
    LCD_intgerToString(temp);
    if (temp < 10)
    {
        LCD_displayString(" ");
    }
    LCD_displayStringRowColumn(LCD_INFO_ROW, 7, "C");

    LCD_displayStringRowColumn(LCD_INFO_ROW, 8, "LDR=");
    LCD_moveCursor(LCD_INFO_ROW, 12);
    LCD_intgerToString(light);
    if (light < 100)
    {
        LCD_displayString(" ");
    }
    if (light < 10)
    {
        LCD_displayString(" ");
    }
    LCD_displayStringRowColumn(LCD_INFO_ROW, 15, "%");
}


static void fireAlert(void)
{
    DcMotor_Rotate(DCMOTOR_STOP, 0);
    Buzzer_on();
    LCD_clearScreen();
    LCD_displayStringRowColumn(0, 0, "Critical alert!");

    while (FlameSensor_getValue() == FLAME_DETECTED_LEVEL)
    {
        /* Stay in alert mode */
    }

    Buzzer_off();
    LCD_clearScreen();
}

int main(void)
{
    uint8  temp          = 0;
    uint16 light         = 0;
    uint8  fan_speed     = 0;
    uint8  last_fan_speed = 0xFF;
    uint8  last_temp     =0;

    ADC_init();
    LCD_init();
    LEDS_init();
    Buzzer_init();
    DcMotor_Init();
    FlameSensor_init();

    while (1)
    {


        if (FlameSensor_getValue() == FLAME_DETECTED_LEVEL)
        {
            fireAlert();
            last_fan_speed = 0xFF;
        }

        temp  = LM35_getTemperature();
        light = LDR_getLightIntensity();

        controlLeds(light);

        fan_speed = getFanSpeed(temp);
        if (fan_speed != last_fan_speed)
        {
            if (fan_speed == 0)
            {
                DcMotor_Rotate(DCMOTOR_STOP, 0);
            }
            else
            {
                DcMotor_Rotate(DCMOTOR_CW, fan_speed);
            }
            last_fan_speed = fan_speed;
        }

        if (temp != last_temp)
        {
           updateLcd(fan_speed, temp, light);
            last_temp = temp;
        }

        updateLcd(fan_speed, temp, light);

    }
}

