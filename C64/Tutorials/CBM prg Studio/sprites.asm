*=$0801               ; memory address to store program at

; basic starter
  byte $0C, $08           ; address of the next basic line
  byte $0A, $00           ; line number
  byte $9E                ; Kernal SYS command
  byte $20                ; space
  byte $28                ; opening bracket
  byte $32, $30, $36, $34 ; start address in ascii (hex) [2064 = $0810]
  byte $29                ; closing bracket
  byte $00                ; end of line
  byte $00, $00           ; end of program

main
  jsr clear_screen

exit
  rts                 ; return from subroutine

incasm "constants.asm"
incasm "kernalfunctions.asm"
incasm "graphicslibrary.asm"