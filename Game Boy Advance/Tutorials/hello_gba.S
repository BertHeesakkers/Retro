@ color screen in a red-ish color
@ code retrieved from https://patater.com/gbaguy/gba/ch2.htm

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

mov r0, #0x6000000	@ address of VRAM
mov r1, #0xFF		@ red color
mov r2, #0x9600		@ 9600 16 bit writes to cover the entire screen
loop:
	strh r1, [r0], #2	@ write value in r1 to r0 and add 2 bytes to r0
	subs r2, r2, #1		@ subtract 1 from r2 (decrement counter) and set appropriate flags in CPSR
	bne loop			@ check for zero result; if not equal jump (branch) to loop

infin:					@ infinite loop
	b infin