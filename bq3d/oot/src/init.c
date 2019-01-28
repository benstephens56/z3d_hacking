#include "z3d.h"
#include "loc.h"

int rand_state = 0;
int i_backup = 0;
static int mod(unsigned int x, unsigned int n) {
    return x - (int)((float)x / ((float)n))*n;
}

static int tick(void) {
    rand_state = rand_state * 1664525 + 1664525;
    return mod(rand_state>>21, loc_len-1);
}

static int validte(int i) { //intentionally not validate
    if (i < loc_len)
        return i;
    if(i_backup > loc_len>>1)
        i_backup = 0;
    return i_backup++;
}

static void swap(int i, int j) {
    i = validte(i);
    j = validte(j);
    uint32_t tmp = loc[j].index;
    loc[j].index = loc[i].index;
    loc[i].index = tmp;
}


void init(void) {
    memcpy(loc, ref, loc_len*sizeof(entry_t));

    rand_state = 0xabcdef123;

    for(int i = 0; i < loc_len; i++)
        swap(i, tick());
    
    for(int i = 0; i < loc_len; i++)
        swap(i, tick());
}