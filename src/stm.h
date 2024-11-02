#ifndef STM_H
#define STM_H

#include <stdbool.h>
#include <stdint.h>

#define IFX_CFG_STM_TICKS_PER_MS (100000)
#define ISR_PRIORITY_STM_TICKS (100)

typedef struct
{
  volatile bool flag_1ms : 1;
  volatile bool flag_10ms : 1;
  volatile bool flag_100ms : 1;
  volatile bool flag_1000ms : 1;
} stm_info_t;

extern stm_info_t stm_info;

extern void stm_init(void);
extern void stm_update(void);
extern void stm_reset(void);
extern void stm_wait(uint32_t ms);

#endif /* STM_H */
