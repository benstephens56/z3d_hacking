#include "macro.h"

macro_ctx_t macro_ctx = {};
live_inputs_t inputs = {};
uint8_t macro_init;

__attribute__ ((aligned (4)))
hid_mem_t shadow_hid = {};

struct pad_t {
    
};
void macro_main() {
    if(macro_init == 0) {
        memcpy(&shadow_hid.pad.pads, &shadow_pad, shadow_pad_size);
        memcpy(&shadow_hid.touch.touches, &shadow_touch, shadow_touch_size);
        macro_init = 1;
    }
    toggle_macro_state();
    if(macro_ctx.state != IDLE)
        macro_update();
}

void scan_inputs() {
    inputs.cur.val = real_hid.pad.pads[real_hid.pad.index].curr.val;
    inputs.pressed.val = (inputs.cur.val) & (~inputs.old.val);
    inputs.up.val = (~inputs.cur.val) & (inputs.old.val);
    inputs.old.val = inputs.cur.val;
}

void toggle_macro_state() {
    macro_state_t current;

    scan_inputs();

    current = macro_ctx.state;

    //update macro state
    if(inputs.pressed.d_left){
        if(macro_ctx.state == IDLE) {
            macro_ctx.state = INIT;
        } else if(macro_ctx.state == ENABLED) {
            macro_ctx.state = IDLE;\
        }
    } else if (macro_ctx.state == ENABLED_LATCHED) {
        macro_ctx.state = ENABLED;
    }

    //if macro state update, update how inputs are read
    //also transition from INIT -> ENABLED_LATCHED
    if(current != macro_ctx.state) {
        if(macro_ctx.state == IDLE) {
            hid_ctx.hid_pad   = &real_hid.pad;
            hid_ctx.hid_touch = &real_hid.touch;
        }else {
            if(macro_ctx.state == INIT) {
                macro_ctx.macro_index = -1;
                macro_ctx.counter = 0;
                macro_ctx.state = ENABLED_LATCHED;
            }
            hid_ctx.hid_pad   = &shadow_hid.pad;
            hid_ctx.hid_touch = &shadow_hid.touch;
        } 
    }

}

void macro_update() {
    if(macro_ctx.counter <= 0) {
        const struct macro_input_t *input = &macro[macro_ctx.macro_index];
        macro_ctx.counter = input->repeat;
        shadow_hid.pad.index   = input->pad_index;
        shadow_hid.touch.index = input->touch_index;
        macro_ctx.counter = input->repeat;
        macro_ctx.macro_index++;
        if(macro_ctx.macro_index > macro_size)
            macro_ctx.macro_index = 0;
    }
    macro_ctx.counter--;
    
}