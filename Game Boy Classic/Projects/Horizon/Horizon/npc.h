#ifndef NPC_H
#define NPC_H

#include <gb/gb.h>

#include "math.h"

typedef
struct NPC
{
	Position m_Position;
	Size m_Size;
	UINT8 m_SpriteID;
	UINT8 m_Tile;
} NPC;

void SetNPCSpriteID(NPC *a_NPC, UINT8 a_SpriteID);
void SetNPCSpriteTile(NPC *a_NPC, UINT8 a_Tile);

void RenderNPC(NPC *a_NPC);

#endif // NPC_H
