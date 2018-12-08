#include "npc.h"

void SetNPCSpriteID(NPC *a_NPC, UINT8 a_SpriteID)
{
	a_NPC->m_SpriteID = a_SpriteID;
}

void SetNPCSpriteTile(NPC *a_NPC, UINT8 a_Tile)
{
	a_NPC->m_Tile = a_Tile;
	set_sprite_tile(a_NPC->m_SpriteID, a_NPC->m_Tile);
}

void RenderNPC(NPC *a_NPC)
{
	move_sprite(a_NPC->m_SpriteID, a_NPC->m_Position.m_X, a_NPC->m_Position.m_Y);
}
