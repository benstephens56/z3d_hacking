OUTPUT_FORMAT("elf32-littlearm", "elf32-littlearm", "elf32-littlearm")
OUTPUT_ARCH(arm)
ENTRY(main_patch)
SECTIONS{
	. = 0x105164;
	. = ALIGN(4);
	.patch_main : {
		*(.patch_main*)
	}

	. = 0x61cd8c;
	. = ALIGN(4);
	.text : {
		*(.text*)
	}

	. = 0x64a5d0;
	. = ALIGN(4);
	.rodata : {
		*(.rodata*)
	}

	. = 0x7ce49c;
	. = ALIGN(4);
	.data : {
		*(.data*)
	}
	.bss : {
		*(.bss*)
	}
}
