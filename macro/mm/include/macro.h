#ifndef MACRO_H
#define MACRO_H

#include <stdint.h>
#include "hid.h"
#include "z3d.h"

typedef enum {
    IDLE = 0,
    INIT,
    ENABLED_LATCHED, //enabled, but button is still pressed down
    ENABLED,        //enabled and button is not still pressed down
} macro_state_t;

typedef struct {
    btn_t cur;
    btn_t up;
    btn_t pressed;
    btn_t old;
} live_inputs_t;

typedef struct{
    macro_state_t state;
    uint8_t enable_down;

    uint8_t macro_index;
    int32_t counter;
} macro_ctx_t;

struct macro_input_t {
    uint8_t pad_index;
    uint8_t touch_index;
    uint8_t repeat;
};

void toggle_macro_state();
void macro_update();

extern macro_ctx_t macro_ctx;
extern hid_mem_t shadow_hid;

extern const pad_t shadow_pad[8];
extern const uint32_t shadow_pad_size;
extern const touch_t shadow_touch[8];
extern const uint32_t shadow_touch_size;
extern const  struct macro_input_t macro[];
extern const uint32_t macro_size;

#endif //MACRO_H