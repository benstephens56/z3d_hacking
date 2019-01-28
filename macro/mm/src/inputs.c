#include "macro.h"

__attribute__((section(".rodata")))
__attribute__ ((aligned (4)))
const pad_t shadow_pad[8] = {
    {},
    {.curr.b = 1},      //B
    {.curr.y = 1},      //Y
    {.curr.x = 1},      //X
    {},
    {},
    {},
    {},
};
const uint32_t shadow_pad_size = sizeof(shadow_pad);

__attribute__((section(".rodata")))
__attribute__ ((aligned (4)))
const touch_t shadow_touch[8] = {
    {},
    {.touch.x = 0x005b, .touch.y = 0x00e0, .updated = 1},   //MT
    {.touch.x = 0x0119, .touch.y = 0x0094, .updated = 1},   //YT
    {.touch.x = 0x00ee, .touch.y = 0x007c, .updated = 1},   //DM
    {.touch.x = 0x00e8, .touch.y = 0x00ac, .updated = 1},   //GM
    {},
    {},
    {}
};
const uint32_t shadow_touch_size = sizeof(shadow_touch);

#define MACRO(p,t,r) {.pad_index=p, .touch_index=t, .repeat=r-1}
#define NEUT 0,0

#define B      1
#define Y      2
#define X      3

#define MT     1 //mask button at bottom
#define YT     2 //y touch button
#define DM     3 //deku mask
#define GM     4 //goron mask

//                        P     M   #
#define CMJ(mask)   MACRO(B,    0,  1), /* jumslash*/  \
                    MACRO(0,    0,  1), /* neutral */  \
                    MACRO(Y,    0,  1), /* mask */  \
                    MACRO(0,   MT,  1), /* mask menu*/  \
                    MACRO(0,    0, 20), /* mask menu opening*/  \
                    MACRO(0, mask,  1), /* mask to switch to (C macro arg)*/  \
                    MACRO(0,   YT,  1), /* y touch button*/  \
                    MACRO(0,    0, 12), /* switching animation*/  \
                    MACRO(B,    0,  1), /* close menu*/  \
                    MACRO(0,    0, 13), /* mask menu closing*/  \
                    MACRO(X,    0,  1), /* bottle */  \
                    MACRO(0,    0,  1)  /* neutral */ 



const struct macro_input_t macro[] = {
    CMJ(DM),
    CMJ(GM)
};

__attribute__((section(".rodata")))
const uint32_t macro_size = sizeof(macro) / sizeof(macro[0]);