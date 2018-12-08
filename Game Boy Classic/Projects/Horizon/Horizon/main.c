#include <gb/gb.h>

#include "hero.h"
#include "npc.h"
#include "input.h"
#include "graphics.h"

#include "data/tiles.h"
#include "data/dungeon.h"
#include "data/sprites.h"

void Initialize();
void Render();
void Update();

Hero g_Player;
NPC enemy;

void main()
{
	Initialize();	
	while (TRUE)
	{
		HandleInput();
		Update();
		Render();
	}
}

void JoyPadUpPRessed(void)
{
	MoveHeroUp(&g_Player);
}

void JoyPadDownPRessed(void)
{
	MoveHeroDown(&g_Player);
}

void JoyPadLeftPRessed(void)
{
	MoveHeroLeft(&g_Player);
}

void JoyPadRightPRessed(void)
{
	MoveHeroRight(&g_Player);
}

void Initialize() {

	DISPLAY_ON;

	LOAD_BACKGROUND_DATA(0, 23, tiles);
	LOAD_SPRITE_DATA(0, 2, sprites);

	SET_BACKGROUND_TILES(0, 0, 20, 18, dungeon);

	// setup input handlers
	SetInputCallback(JoyPad_Up, JoyPadUpPRessed);
	SetInputCallback(JoyPad_Down, JoyPadDownPRessed);
	SetInputCallback(JoyPad_Left, JoyPadLeftPRessed);
	SetInputCallback(JoyPad_Right, JoyPadRightPRessed);

	// setup player
	SetPosition(&g_Player.m_Position, 64, 64);
	SetSize(&g_Player.m_Size, 8, 8);
	SetHeroSpeed(&g_Player, 1);
	SetHeroSpriteID(&g_Player, 0);
	SetHeroSpriteTile(&g_Player, 0);

	// setup enemy
	SetPosition(&enemy.m_Position, 128, 128);
	SetSize(&enemy.m_Size, 8, 8);
	SetNPCSpriteID(&enemy, 1);
	SetNPCSpriteTile(&enemy, 1);
}

void Update()
{
	if (CheckOverlap(&g_Player.m_Position, &g_Player.m_Size, &enemy.m_Position, &enemy.m_Size))
	{
		SetHeroSpriteTile(&g_Player, 1);
	}
	else
	{
		SetHeroSpriteTile(&g_Player, 0);
	}
}

void Render()
{
	RenderHero(&g_Player);
	RenderNPC(&enemy);

	HIDE_WIN;
	SHOW_SPRITES;
	SHOW_BKG;

	wait_vbl_done();
}
