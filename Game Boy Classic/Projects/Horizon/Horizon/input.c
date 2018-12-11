#include "input.h"
#include <gb/gb.h>

static InputCallback g_Callbacks[JoyPad_Count] = { NULL };

void SetInputCallback(EJoyPadButton a_Button, InputCallback a_Callback)
{
	g_Callbacks[a_Button] = a_Callback;
}

void HandleInput()
{
	const UINT8 joypadValue = joypad();
	if (joypadValue & J_START && g_Callbacks[JoyPad_Start] != NULL) { g_Callbacks[JoyPad_Start](); }
	if (joypadValue & J_SELECT && g_Callbacks[JoyPad_Select] != NULL) { g_Callbacks[JoyPad_Select](); }
	if (joypadValue & J_A && g_Callbacks[JoyPad_A] != NULL) { g_Callbacks[JoyPad_A](); }
	if (joypadValue & J_B && g_Callbacks[JoyPad_B] != NULL) { g_Callbacks[JoyPad_B](); }
	if (joypadValue & J_UP && g_Callbacks[JoyPad_Up] != NULL) { g_Callbacks[JoyPad_Up](); }
	if (joypadValue & J_DOWN && g_Callbacks[JoyPad_Down] != NULL) { g_Callbacks[JoyPad_Down](); }
	if (joypadValue & J_LEFT && g_Callbacks[JoyPad_Left] != NULL) { g_Callbacks[JoyPad_Left](); }
	if (joypadValue & J_RIGHT && g_Callbacks[JoyPad_Right] != NULL) { g_Callbacks[JoyPad_Right](); }
}
