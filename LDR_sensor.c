/*
 * LDR_sensor.c
 *
 *  Created on: Oct 29, 2026
 *      Author: YOUSEF
 */

#include "ldr_sensor.h"
#include "adc.h"   /* Provides: uint16 ADC_readChannel(uint8 channel_num) */

uint16 LDR_getLightIntensity(void)
{
    uint16 adc_value = 0;
    uint16 light_intensity = 0;

    /* Read the ADC digital value of the LDR channel */
    adc_value = ADC_readChannel(LDR_SENSOR_CHANNEL_ID);

    /* Convert digital value -> voltage -> light intensity percentage:
     * voltage   = adc_value * ADC_REF_VOLT / ADC_MAX_VALUE
     * intensity = voltage * MAX_LIGHT_INTENSITY / SENSOR_MAX_VOLT        */
    light_intensity = (uint16)(((float32)adc_value * LDR_ADC_REF_VOLT_VALUE *
                                LDR_SENSOR_MAX_LIGHT_INTENSITY) /
                               ((float32)LDR_ADC_MAXIMUM_VALUE * LDR_SENSOR_MAX_VOLT_VALUE));

    /* Saturate to the maximum allowed intensity */
    if (light_intensity > LDR_SENSOR_MAX_LIGHT_INTENSITY)
    {
        light_intensity = LDR_SENSOR_MAX_LIGHT_INTENSITY;
    }

#if (LDR_INVERT_READING == 1)
    light_intensity = LDR_SENSOR_MAX_LIGHT_INTENSITY - light_intensity;
#endif

    return light_intensity;
}
