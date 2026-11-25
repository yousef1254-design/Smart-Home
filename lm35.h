/*
 * lm35.h
 *
 *  Created on: Oct 29, 2026
 *      Author: YOUSEF
 */

#ifndef LM35_H_
#define LM35_H_

#include "std_types.h"

#define SENSOR_CHANNEL_ID         1
#define SENSOR_MAX_VOLT_VALUE     1.5
#define SENSOR_MAX_TEMPERATURE    150

/*
 * Description :
 * Function responsible for calculate the temperature from the ADC digital value.
 */
uint8 LM35_getTemperature(void);

#endif /* LM35_SENSOR_H_ */
