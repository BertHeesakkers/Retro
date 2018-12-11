#include "math.h"

void SetPosition(Position *a_Position, UINT8 a_X, UINT8 a_Y)
{
	if (a_Position != NULL)
	{
		a_Position->m_X = a_X;
		a_Position->m_Y = a_Y;
	}
}

void UpdatePosition(Position *a_Position, INT8 a_DeltaX, INT8 a_DeltaY)
{
	// screen wrap enabled
	if (a_Position != NULL)
	{
		a_Position->m_X += a_DeltaX;
		a_Position->m_Y += a_DeltaY;
	}

	//	// screen wrap disabled
// 	if (a_DeltaX >= 0 || (a_DeltaX < 0 && (a_Position->m_X + a_DeltaX < a_Position->m_X)))
// 	{
// 		a_Position->m_X += a_DeltaX;
// 	}
// 	if (a_DeltaY >= 0 || (a_DeltaY < 0 && (a_Position->m_Y + a_DeltaY < a_Position->m_Y)))
// 	{
// 		a_Position->m_Y += a_DeltaY;
// 	}
}

void SetSize(Size *a_Size, UINT8 a_X, UINT8 a_Y)
{
	if (a_Size != NULL)
	{
		a_Size->m_Width = a_X;
		a_Size->m_Height = a_Y;
	}
}

BOOL CheckOverlap(Position *a_PosLhs, Size *a_SizeLhs, Position *a_PosRhs, Size *a_SizeRhs)
{
	BOOL result = FALSE;
	if ((a_PosLhs->m_X < (a_PosRhs->m_X + a_SizeRhs->m_Width)) && 
		((a_PosLhs->m_X + a_SizeLhs->m_Width) > a_PosRhs->m_X) &&
		(a_PosLhs->m_Y < (a_SizeRhs->m_Height + a_PosRhs->m_Y)) && 
		((a_PosLhs->m_Y + a_SizeLhs->m_Height) > a_PosRhs->m_Y))
	{
		result = TRUE;
	}
	return result;
}