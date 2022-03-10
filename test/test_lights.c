#ifdef TEST

#include "unity.h"

#include "lights.h"

void setUp(void)
{
}

void tearDown(void)
{
}
/*
void test_lights_NeedToImplement(void)
{
    TEST_IGNORE_MESSAGE("Need to Implement lights");
}
*/
void test_WhenTheHeadlightSwitchIsOff_ThenTheHeadlightsAreOff(void)
{
    // turn headlight switch off
    lights_setHeadlightSwitchOff();
    //confirm the the state of the headlights
    TEST_ASSERT_EQUAL(false, lights_AreHeadlighsOn());
}
#endif // TEST
