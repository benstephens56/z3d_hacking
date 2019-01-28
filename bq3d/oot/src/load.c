#include "hid.h"
#include "z3d.h"
#include "loc.h"


struct load_t{
    int init;
};


struct load_t load = {};

void area_load_main() {
    int i;

    if(load.init == 0) {
        init();
        load.init = 1;
    }


    /*if(0x0211 == z3d_file.entrance_index){
            found();
    }*/
    for(i = 0; i < loc_len; i++){
        if(loc[i].index == z3d_file.entrance_index)
            z3d_file.entrance_index = ref[i].index;
    }
    
    return;
}