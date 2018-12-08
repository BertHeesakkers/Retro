#ifndef MATH_H
#define MATH_H

#include <gb/gb.h>
#include "util.h"

typedef
struct Position
{
	UINT8 m_X;
	UINT8 m_Y;
} Position;

typedef
struct Size
{
	UINT8 m_Width;
	UINT8 m_Height;
} Size;

void SetPosition(Position *a_Position, UINT8 a_X, UINT8 a_Y);
void UpdatePosition(Position *a_Position, INT8 a_DeltaX, INT8 a_DeltaY);

void SetSize(Size *a_Size, UINT8 a_X, UINT8 a_Y);

BOOL CheckOverlap(Position *a_PosLhs, Size *a_SizeLhs, Position *a_PosRhs, Size *a_SizeRhs);

#endif // MATH_H