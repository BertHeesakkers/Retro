*=$2000
!binary "sprite2.spr"

*=$0801               ; memory address to store program at

; basic starter
!byte $0C,$08         ; [?] program start
!byte $0A,$00         ; line number
!byte $9E             ; Kernal SYS command
!byte $20             ; space
!byte $32,$30,$36,$34 ; start address in ascii (hex) [2064 = $0810]
!byte $00             ; end of line
!byte $00,$00         ; end of program
!byte $00,$00         ; padding to make sure actual code starts at correct adress

initialization:
  jsr $e544           ; call Kernal (no typo) subroutine to clear the screen

main:
  lda #$80                    ; sprite in data file is located at $2000 (40 * 80 (hex))
  sta SPRITE_POINTER_0        ; store memory offset in sprite pointer
  
  lda #%0000001               ; set indices for sprites that need to be enabled
  sta VIC_BASE_ADDRESS + $15  ; set enabled sprites
  
  lda #$80                    ; load the value 128 into the accumulator
  sta SPRITE_0_COORD_X        ; load sprite 0 x coordinate with the value in the accumulator
  sta SPRITE_0_COORD_Y        ; load sprite 0 y coordinate with the value in the accumulator
  
  rts                         ; return from subroutine
  
; address of the screen buffer
VIC_BASE_ADDRESS        = $D000
SPRITE_POINTER_0        = $07F8
SPRITE_0_COORD_X        = $d000
SPRITE_0_COORD_Y        = $d001
