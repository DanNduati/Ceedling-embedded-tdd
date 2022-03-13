#include <stdint.h>
#include <stdio.h>
#include "tempSensor.h"
#include "i2c.h"
float tempSensor_getTemperature(void)
{
    uint16_t rawValue = i2c_readRegister(0x03);
    float currentTemperature = -100.0f + (0.2f * (float)rawValue);
    printf("rawvalue:%d temperature:%f", rawValue, currentTemperature);
    return currentTemperature;
}