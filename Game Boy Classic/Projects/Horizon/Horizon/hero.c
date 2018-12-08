#include "hero.h"
#include "math.h"

void SetHeroSpeed(Hero *a_Hero, UINT8 a_Speed)
{
	a_Hero->m_Speed = a_Speed;
}

void SetHeroSpriteID(Hero *a_Hero, UINT8 a_SpriteID)
{
	a_Hero->m_SpriteID = a_SpriteID;
}

void SetHeroSpriteTile(Hero *a_Hero, UINT8 a_Tile)
{
	a_Hero->m_Tile = a_Tile;
	set_sprite_tile(a_Hero->m_SpriteID, a_Hero->m_Tile);
}

void MoveHeroUp(Hero *a_Hero)
{
	UpdatePosition(&a_Hero->m_Position, 0, -1 * a_Hero->m_Speed);
}

void MoveHeroDown(Hero *a_Hero)
{
	UpdatePosition(&a_Hero->m_Position, 0, a_Hero->m_Speed);
}

void MoveHeroLeft(Hero *a_Hero)
{
	UpdatePosition(&a_Hero->m_Position, -1 * a_Hero->m_Speed, 0);
}

void MoveHeroRight(Hero *a_Hero)
{
	UpdatePosition(&a_Hero->m_Position, a_Hero->m_Speed, 0);
}

void RenderHero(Hero *a_Hero)
{
	move_sprite(a_Hero->m_SpriteID, a_Hero->m_Position.m_X, a_Hero->m_Position.m_Y);
}
