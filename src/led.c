#include "led.h"
#include "assert.h"

#include <IfxPort_PinMap.h>

const led_t led_0 = {
  .pin = &IfxPort_P33_14,
  .type = LED_TYPE_ACTIVE_LOW
};

const led_t led_1 = {
  .pin = &IfxPort_P34_4,
  .type = LED_TYPE_ACTIVE_LOW
};

const led_t led_rgb_r = {
  .pin = &IfxPort_P34_5,
  .type = LED_TYPE_ACTIVE_LOW
};

const led_t led_rgb_g = {
  .pin = &IfxPort_P33_15,
  .type = LED_TYPE_ACTIVE_LOW
};

const led_t led_rgb_b = {
  .pin = &IfxPort_P34_3,
  .type = LED_TYPE_ACTIVE_LOW
};


void led_init(const led_t* const led)
{
  OE_ASSERT(led != NULL);

  if (led->type != LED_TYPE_ACTIVE_LOW)
  {
    IfxPort_setPinHigh(led->pin->port, led->pin->pinIndex);
  }
  else
  {
    IfxPort_setPinLow(led->pin->port, led->pin->pinIndex);
  }

  IfxPort_setPinMode(led->pin->port, led->pin->pinIndex, IfxPort_Mode_outputPushPullGeneral);
}

void led_on(const led_t* const led)
{
  OE_ASSERT(led != NULL);

  if (led->type == LED_TYPE_ACTIVE_LOW)
  {
    IfxPort_setPinLow(led->pin->port, led->pin->pinIndex);
  }
  else
  {
    IfxPort_setPinHigh(led->pin->port, led->pin->pinIndex);
  }
}

void led_off(const led_t* const led)
{
  OE_ASSERT(led != NULL);

  if (led->type == LED_TYPE_ACTIVE_LOW)
  {
    IfxPort_setPinHigh(led->pin->port, led->pin->pinIndex);
  }
  else
  {
    IfxPort_setPinLow(led->pin->port, led->pin->pinIndex);
  }
}

void led_toggle(const led_t* const led)
{
  OE_ASSERT(led != NULL);
  IfxPort_togglePin(led->pin->port, led->pin->pinIndex);
}
