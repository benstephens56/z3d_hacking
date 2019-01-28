#ifndef Z3D_H
#define Z3D_H

#include "hid.h"

typedef void* (*memcpy_proc) (void* dst, void* src, uint32_t size);

#if Z3D == MM3D

#define real_hid_addr   0x10002000
#define hid_ctx_addr    0x007b2d30
#define z3d_rupee_addr  0x00775318
#define memcpy_addr     0x001f28e8

#elif Z3D == OOT3D

#define real_hid_addr   0x10002000
#define hid_ctx_addr    0x005AEC58
#define z3d_rupee_addr  0x005879A0
#define memcpy_addr     0x00371738
#define z3d_file_addr   0x00587958

#endif

struct z3d_save_ctx
{
    int32_t entrance_index;
    int32_t link_age;
    uint16_t ukn_1;
    uint16_t cutscene_index;
    int16_t ToD;
    uint8_t mq_flag;
    uint8_t ukn_2[13];
    uint16_t file_name[8];
    uint8_t len_file_name;
    uint8_t target_mode;
    uint16_t ukn_3;
    char ZELDAZ[6];
    uint16_t save_counter;
    uint16_t ukn_4[5];
    int16_t health_capacity;
    int16_t health;
    uint8_t magic_capacity_set;
    uint8_t magic;
    uint16_t rupees;
    uint8_t ukn_5[10];
};

#define real_hid    (*(hid_mem_t *) real_hid_addr)
#define hid_ctx     (*(hid_ctx_t *) hid_ctx_addr)
#define memcpy      ((memcpy_proc)  memcpy_addr)
#define z3d_rupee   (*(uint16_t *)z3d_rupee_addr)
#define z3d_file    (*(struct z3d_save_ctx*) z3d_file_addr)

#endif //Z3D_H