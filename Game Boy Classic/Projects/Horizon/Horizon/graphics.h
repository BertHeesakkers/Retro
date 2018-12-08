#ifndef GRAPHICS_H
#define GRAPHICS_H

#define LOAD_BACKGROUND_DATA(a_StartIndex, a_EndIndex, a_Data) \
	set_bkg_data(a_StartIndex, a_EndIndex, a_Data)

#define SET_BACKGROUND_TILES(a_X, a_Y, a_Width, a_Height, a_TileData) \
	set_bkg_tiles(a_X, a_Y, a_Width, a_Height, a_TileData);

#define LOAD_SPRITE_DATA(a_Start, a_NumTiles, a_TileData) \
	set_sprite_data(a_Start, a_NumTiles, a_TileData);

#endif // GRAPHICS_H
