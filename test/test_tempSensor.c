#ifdef TEST

#include "unity.h"

#include "tempSensor.h"
#include "mock_i2c.h"
void setUp(void)
{
}

void tearDown(void)
{
}

void test_whenTempRegisterReadsMaxValue_thenTheTempIsTheMaxValue(void)
{

    uint8_t tempRegisterAddress = 0x03;
    float expectedTemperature = 104.6f;
    float tolerance = 0.1f;
    // When you read a temperature register value of 0x3FF the temperature calculated should be 104.6
    i2c_readRegister_ExpectAndReturn(tempRegisterAddress, 0x3ff); // mock function -> simulates/mocks the i2c module returning a value of 0x3ff on read of the temperature address
    // Then
    float actualTemperature = tempSensor_getTemperature();
    TEST_ASSERT_FLOAT_WITHIN(tolerance, expectedTemperature,
                             actualTemperature);
}

void test_whenTempRegisteReadsMinValue_thenTheTempIsTheMinValue(void)
{
    uint8_t tempRegisterAddress = 0x03;
    float expectedTemperature = -100.0f;
    float tolerance = 0.1f;
    i2c_readRegister_ExpectAndReturn(tempRegisterAddress, 0x000);

    float actualTemperature = tempSensor_getTemperature();
    TEST_ASSERT_FLOAT_WITHIN(tolerance, expectedTemperature,
                             actualTemperature);
}

#endif // TEST
