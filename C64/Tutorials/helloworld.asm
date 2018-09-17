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

  jsr $e544           ; call Kernal (no typo) subroutine to clear the screen
  ldx #$00            ; load literal value 0 into the X register

main
  lda message, x      ; load character at position X of the message in the accumulator register
  sta $0400, x        ; place contents of accumulator register at memory location $0400 + X 
                      ; (upper left corner of the screen + number of character to print)
  inx                 ; increase content of data in the X register by 1
  cpx #$0c            ; compare value at the X register with the length of the string
  bne main            ; jump back to loop if not finished
  rts                 ; return from subroutine
  
message
  !scr "hello world!"