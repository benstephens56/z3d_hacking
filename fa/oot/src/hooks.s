.arm

.section .patch_main
.global main_patch

main_patch:
    b hook_into_main    