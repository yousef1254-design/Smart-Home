/*
 * LDR_sensor.h
 *
 *  Created on: Oct 29, 2026
 *      Author: YOUSEF
 */

#ifndef LDR_SENSOR_H_
#define LDR_SENSOR_H_

#include "std_types.h"

/* ADC channel the LDR is connected to (ADC0 -> PA0) */
#define LDR_SENSOR_CHANNEL_ID           0

/* Max voltage output of the LDR sensor (volts) */
#define LDR_SENSOR_MAX_VOLT_VALUE       2.56

/* Max light intensity the sensor can measure (0% -> 100%) */
#define LDR_SENSOR_MAX_LIGHT_INTENSITY  100

/* ADC settings used for the conversion (must match your ADC driver config) */
#define LDR_ADC_REF_VOLT_VALUE          2.56   /* Internal 2.56V reference */
#define LDR_ADC_MAXIMUM_VALUE           1023   /* 10-bit ADC               */

/* Reading direction:
 * 0 -> light intensity is directly proportional to the ADC voltage
 * 1 -> inverted (voltage is max in darkness, so intensity = MAX - reading) */
#define LDR_INVERT_READING              0

/*
 * Description :
 * Reads the LDR sensor value from the configured ADC channel and returns
 * the light intensity as a percentage (0 to LDR_SENSOR_MAX_LIGHT_INTENSITY).
 * Note: ADC_init() must be called before using this function.
 */
uint16 LDR_getLightIntensity(void);

#endif /* LDR_SENSOR_H_ */
