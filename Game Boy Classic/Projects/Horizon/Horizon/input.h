#ifndef INPUT_H
#define INPUT_H

typedef enum EJoyPadButton
{
	JoyPad_Start = 0,
	JoyPad_Select,
	JoyPad_A,
	JoyPad_B,
	JoyPad_Up,
	JoyPad_Down,
	JoyPad_Left,
	JoyPad_Right,
	JoyPad_Count
} EJoyPadButton;

typedef void(*InputCallback)(void);

void SetInputCallback(EJoyPadButton a_Button, InputCallback a_Callback);
void HandleInput();

#endif // INPUT_H
