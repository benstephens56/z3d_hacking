.arm
.text
.global hook_into_main

hook_into_main:
    push {r0-r12, lr}
    bl macro_main
    pop {r0-r12, lr}
    b 0x104d08