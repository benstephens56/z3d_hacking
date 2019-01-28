#ifndef Z3D_H
#define Z3D_H

#include "hid.h"

typedef void* (*memcpy_proc) (void* dst, void* src, uint32_t size);

#define real_hid_addr   0x10002000
#define hid_ctx_addr    0x007b2d30
#define z3d_rupee_addr  0x00775318
#define memcpy_addr     0x001f28e8

#define real_hid    (*(hid_mem_t *) real_hid_addr)
#define hid_ctx     (*(hid_ctx_t *) hid_ctx_addr)
#define memcpy      ((memcpy_proc)  memcpy_addr)
#define z3d_rupee   (*(uint16_t *)z3d_rupee_addr)

#endif //Z3D_H