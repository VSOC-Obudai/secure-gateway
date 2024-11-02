#ifndef LED_H
#define LED_H

#include <IfxPort.h>
#include <stdint.h>

typedef enum
{
  LED_TYPE_ACTIVE_LOW = 0,
  LED_TYPE_ACTIVE_HIGH = 1,
} led_type_t;

typedef struct
{
  IfxPort_Pin* pin;
  int8_t type;
} led_t;

extern const led_t led_0;
extern const led_t led_1;
extern const led_t led_rgb_r;
extern const led_t led_rgb_g;
extern const led_t led_rgb_b;

extern void led_init(const led_t* const led);
extern void led_on(const led_t* const led);
extern void led_off(const led_t* const led);
extern void led_toggle(const led_t* const led);

#endif /* LED_H */
