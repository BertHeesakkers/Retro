incasm "constants.asm"

; simple vsync: https://www.lemon64.com/forum/viewtopic.php?t=14949&sid=141cff0fcc91243d9e6e245be002a800
vsync
  bit VIC_SCR_CNTRL_REGISTER1
  bpl vsync
vsync_wait
  bit VIC_SCR_CNTRL_REGISTER1
  bmi vsync_wait
  rts
