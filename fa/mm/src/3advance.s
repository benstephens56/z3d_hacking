.arm
.text

.global hook_into_main
hook_into_main:
    push {r0-r12, lr}
    bl advance_main
    pop {r0-r12, lr}
    b 0x104d08

.global svcSleepThread
svcSleepThread:
    svc 0x0a
    bx lr