*=$0801               ; memory address to store program at

; basic starter
  byte $0C, $08           ; [?] program start
  byte $0A, $00           ; line number
  byte $9E                ; Kernal SYS command
  byte $20                ; space
  byte $28                ; opening bracket
  byte $32, $30, $36, $34 ; start address in ascii (hex) [2064 = $0810]
  byte $29                ; closing bracket
  byte $00                ; end of line
  byte $00, $00           ; end of program

  jsr $e544           ; call Kernal (no typo) subroutine to clear the screen
  ldx #$00            ; load literal value 0 into the X register

main
  lda message,X       ; load character at position X of the message in the accumulator register
  cmp #0
  beq exit
  sta $0400,X         ; place contents of accumulator register at memory location $0400 + X 
                      ; (upper left corner of the screen + number of character to print)
  inx                 ; increase content of data in the X register by 1
  jmp main            ; jump back to loop if not finished

exit
  rts                 ; return from subroutine

message
  text 'hello world!'
  byte 0
