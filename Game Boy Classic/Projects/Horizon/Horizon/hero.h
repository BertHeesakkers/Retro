#ifndef HERO_H
#define HERO_H

#include <gb/gb.h>

#include "math.h"

typedef
struct Hero
{
	Position m_Position;
	Size m_Size;
	UINT8 m_Speed;
	UINT8 m_SpriteID;
	UINT8 m_Tile;
} Hero;

void SetHeroSpeed(Hero *a_Hero, UINT8 a_Speed);
void SetHeroSpriteID(Hero *a_Hero, UINT8 a_SpriteID);
void SetHeroSpriteTile(Hero *a_Hero, UINT8 a_Tile);

void MoveHeroUp(Hero *a_Hero);
void MoveHeroDown(Hero *a_Hero);
void MoveHeroLeft(Hero *a_Hero);
void MoveHeroRight(Hero *a_Hero);

void RenderHero(Hero *a_Hero);

#endif // HERO_H
