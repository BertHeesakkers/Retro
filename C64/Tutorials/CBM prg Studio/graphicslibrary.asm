incasm "constants.asm"

; clear screen function
; https://dustlayer.com/c64-coding-tutorials/2013/4/8/episode-2-2-writing-to-the-c64-screen
clear_screen
  ldx #$00                      ; load 0 into X register
  stx VIC_SCR_BORDER_COLOR      ; set X register value at border color
  stx VIC_SCR_BACKGROUND_COLOR  ; set X register value at background color

clear
  lda #$20
  sta $0400,X                 ; store X register value in screen RAM
  sta $0500,X                 ; store X register value in screen RAM 
  sta $0600,X                 ; store X register value in  screen RAM
  sta $0700,X                 ; store X register value in  screen RAM
  lda #$00                    ; load 0 in accumulator register
  sta $D800,x                 ; store accumulator value in color RAM
  sta $D900,x                 ; store accumulator value in color RAM
  sta $DA00,x                 ; store accumulator value in color RAM
  sta $DAE8,x                 ; store accumulator value in color RAM
  inx                         ; increment counter
  bne clear                   ; branch if zero flag is clear
  rts                         ; return from subroutine

; vsync
; https://www.lemon64.com/forum/viewtopic.php?t=14949&sid=141cff0fcc91243d9e6e245be002a800
vsync
  bit VIC_SCR_CNTRL_REGISTER1 ; http://www.obelisk.me.uk/6502/reference.html#BIT
  bpl vsync                   ; branch if negative flag is clear
vsync_wait                    ; 
  bit VIC_SCR_CNTRL_REGISTER1 ;
  bmi vsync_wait              ; branch if negative flag is set
  rts                         ; return from subroutine

; copy the complete Character Generator ROM in Bank 0 from ROM ($D000) to RAM underneath at the same address
; source: https://dustlayer.com/vic-ii/2013/4/23/vic-ii-for-beginners-part-2-to-have-or-to-not-have-character
copy_char_generator
        sei         ; set interrupt disable flag to one
        ldx #$08    ; set loop count variable (8 x 255 = 2Kb)
        lda #$33    ; ?make the CPU see the Character Generator ROM...
        sta $01     ; ?...at $D000 by storing %00110011 into location $01
        lda #$d0    ; ?load high byte of $D000
        sta $fc     ; ?store it in a free location we use as vector
        ldy #$00    ; initialize inner loop counter to 0
        sty $fb     ; ?store it as low byte in the $FB/$FC vector

loop    lda ($fb),y ; ?read byte from vector stored in $fb/$fc
        sta ($fb),y ; ?write to the RAM under ROM at same position
        iny         ; increase inner loop counter
        bne loop    ; branch if zero flag is clear
        inc $fc     ; ?when we passed $FF increase high byte...
        dex         ; decrease outer loop counter
        bne loop    ; branch if zero flag is clear
        lda #$37    ; ?switch in I/O mapped registers again...
        sta $01     ; ?... with %00110111 so CPU can see them
        cli         ; clear interrupt disable flag
        rts         ; return from subroutine

;
; source: