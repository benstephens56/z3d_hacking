#include "advance.h"
#include "z3d.h"

advance_ctx_t advance_ctx = {};
advance_input_t inputs = {};
uint8_t advance_init;

void toggle_advance();

void advance_main() {
    if(advance_init == 0) {
        advance_init = 1;
    }


    //down to enable, left to advance
    toggle_advance();
    scan_inputs();
    

    if(advance_ctx.advance_state == STEP) {
        if(inputs.cur.d_left) {
            advance_ctx.advance_state = LATCHED;
        } else {
            advance_ctx.advance_state = PAUSED;
        }
    }


    while(advance_ctx.advance_state == PAUSED || advance_ctx.advance_state == LATCHED) {
        toggle_advance();
        if(advance_ctx.advance_state == LATCHED && !inputs.cur.d_left) {
            advance_ctx.advance_state = PAUSED;
        }
        if(advance_ctx.advance_state == PAUSED && inputs.cur.d_left) {
            advance_ctx.advance_state = STEP;
        }
        svcSleepThread(16e6);
    }
}

void toggle_advance() {
    scan_inputs();
    if(inputs.pressed.d_down && advance_ctx.advance_state == NORMAL && !advance_ctx.d_down_latched){
        advance_ctx.advance_state = PAUSED;
        advance_ctx.d_down_latched = 1;
    } else if(inputs.pressed.d_down && advance_ctx.advance_state != NORMAL && !advance_ctx.d_down_latched) {
        advance_ctx.advance_state = NORMAL;
        advance_ctx.d_down_latched = 1;
    } else if (advance_ctx.advance_state == NORMAL &&inputs.pressed.d_left){
        advance_ctx.advance_state = LATCHED;
    } else if(!inputs.pressed.d_down) {
        advance_ctx.d_down_latched = 0;
    }
}

void scan_inputs() {
    inputs.cur.val = real_hid.pad.pads[real_hid.pad.index].curr.val;
    inputs.pressed.val = (inputs.cur.val) & (~inputs.old.val);
    inputs.up.val = (~inputs.cur.val) & (inputs.old.val);
    inputs.old.val = inputs.cur.val;
}