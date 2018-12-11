@ display fullscreen (240 x 160 pixels) image (stored in external file 'image.bin')
@ code retrieved from https://patater.com/gbaguy/gba/ch4.htm

.arm			@ use the ARM mode instruction set
.text			@ put the following int he text (code) section (usually ROM for a GBA cartridge)
.global main	@ instruct assembler to allow global access to our main function
				@   so the linker can find this function
main:			@ label indicating the main function

mov r0, #0x4000000	@ store address of REG_DISPCNT (lcd controller) in register r0
mov r1, #0x400		@ store literal value in r1
add r1, r1, #3		@ add 3 to get #0x403
str r1, [r0]		@ write to the address stored in r0
					@ this setup enable graphics mode 3 using background 2

mov r0, #0x6000000 	@ address of VRAM
ldr r1, =pic		@ store address of label pic in r1
mov r2, #0x9600		@ 9600 16 bit writes to cover the entire screen

loop:
	ldmia r1!, { r3, r4, r5, r6, r7, r8, r9, r10 }	@ load multiple registers with data from the address stored in r1, incrementing the address by 4 after each read
													@ the final address used (+4) is written back to r1 
													@ (mark the lack of square brackets around r1 even though the address stored at r1 is used)

	stmia r0!, { r3, r4, r5, r6, r7, r8, r9, r10 }	@ write data from multiple registers into the address stored in r0, incrementing the address by 4 after each read
													@ the final address used (+4) is written back to r0
													@ (mark the lack of square brackets around r1 even though the address stored at r0 is used)

													@ ldmia and stmia are a fast(er) way to copy memory than using individual registers

	subs r2, r2, #1		@ subtract 1 from r2 (decrement counter) and set appropriate flags in CPSR
	bne loop			@ check for zero result; if not equal jump (branch) to loop

infin:					@ infinite loop
	b infin

.ltorg 					@ instructs the assembler to assemble the current literal pool immediately
pic:					@ label indicating the address of the included image data
.incbin "image.bin"		@ include binary file