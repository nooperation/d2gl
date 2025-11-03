/*
	D2GL: Diablo 2 LoD Glide/DDraw to OpenGL Wrapper.
	Copyright (C) 2023  Bayaraa

	This program is free software: you can redistribute it and/or modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation, either version 3 of the License, or
	(at your option) any later version.

	This program is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU General Public License for more details.

	You should have received a copy of the GNU General Public License
	along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/

#pragma once

#include "structs.h"

namespace d2gl::d2 {

uint32_t mpqLoad(const char* mpqfile);
glm::ivec2 getCursorPos();
bool isPerspective();
bool isEscMenuOpen();
bool isLangCJK(uint32_t lang_id);

UnitAny* getPlayerUnit();
UnitAny* findUnit(uint32_t type_id);

DWORD getUnitID(UnitAny* unit);
DWORD getUnitFlag(UnitAny* unit);
Path* getUnitPath(UnitAny* unit);
StaticPath* getUnitStaticPath(UnitAny* unit);
uint32_t getUnitStat(UnitAny* unit, uint32_t stat);
UnitAny* getSelectedItem();

bool isUnitDead(UnitAny* unit);
char* getPlayerName(UnitAny* unit);
MonsterType getMonsterType(UnitAny* unit);
wchar_t* getMonsterName(UnitAny* unit);
bool isMercUnit(UnitAny* unit);

ItemQuality getItemQuality(UnitAny* unit);
BYTE getItemLocation(UnitAny* unit);

CellFile* getCellFile(CellContext* cell);
DWORD getCellNo(CellContext* cell);

void gameDrawBegin();
void automapDrawBegin();
void automapDrawEnd();
void uiDrawBegin();
void uiDrawCursorItem();
void uiDrawEnd();

void __stdcall drawImageHooked(CellContext* cell, int x, int y, uint32_t gamma, int draw_mode, uint8_t* palette);
void __stdcall drawPerspectiveImageHooked(CellContext* cell, int x, int y, uint32_t gamma, int draw_mode, int screen_mode, uint8_t* palette);
void __stdcall drawShiftedImageHooked(CellContext* cell, int x, int y, uint32_t gamma, int draw_mode, int global_palette_shift);
void __stdcall drawVerticalCropImageHooked(CellContext* cell, int x, int y, int skip_lines, int draw_lines, int draw_mode);
void __stdcall drawClippedImageHooked(CellContext* cell, int x, int y, void* crop_rect, int draw_mode);
void __stdcall drawImageFastHooked(CellContext* cell, int x, int y, uint8_t palette_index);
void __stdcall drawShadowHooked(CellContext* cell, int x, int y);
void __stdcall drawSolidRectExHooked(int left, int top, int right, int bottom, uint32_t color, int draw_mode);
void __stdcall drawLineHooked(int x_start, int y_start, int x_end, int y_end, uint8_t color, uint8_t alpha);
bool __stdcall drawGroundTileHooked(TileContext* tile, GFXLight* light, int x, int y, int world_x, int world_y, uint8_t alpha, int screen_panels, bool tile_data);
bool __stdcall drawWallTileHooked(TileContext* tile, int x, int y, GFXLight* light, int screen_panels);
bool __stdcall drawTransWallTileHooked(TileContext* tile, int x, int y, GFXLight* light, int screen_panels, uint8_t alpha);
bool __stdcall drawShadowTileHooked(TileContext* tile, int x, int y, int draw_mode, int screen_panels);

void __fastcall takeScreenShotHooked();
void __fastcall drawNormalTextHooked(const wchar_t* str, int x, int y, uint32_t color, uint32_t centered);
void __fastcall drawNormalTextExHooked(const wchar_t* str, int x, int y, uint32_t color, uint32_t centered, uint32_t trans_lvl);
void __fastcall drawFramedTextHooked(const wchar_t* str, int x, int y, uint32_t color, uint32_t centered);
void __fastcall drawRectangledTextHooked(const wchar_t* str, int x, int y, uint32_t rect_color, uint32_t rect_transparency, uint32_t color);
uint32_t __fastcall getNormalTextWidthHooked(const wchar_t* str);
uint32_t __fastcall getNormalTextNWidthHooked(const wchar_t* str, const int n_chars);
uint32_t __fastcall getFramedTextSizeHooked(const wchar_t* str, uint32_t* width, uint32_t* height);
uint16_t __fastcall getFontHeightHooked();
uint32_t __fastcall setTextSizeHooked(uint32_t dwSize);

void rectangledTextBegin();
void rectangledTextEnd();
void unitHoverText();
void altItemsText();
void drawRectFrame();
void drawUnitHealthBar();

void loadUIImage();
void drawSubTextA();
void drawSubTextB();
void drawSubTextC();
void levelEntryText();

}

#ifdef __cplusplus
extern "C" {
#endif

// Exported functions for external calling
__declspec(dllexport) void __cdecl d2glGameDrawBegin();
__declspec(dllexport) void __cdecl d2glAutomapDrawBegin();
__declspec(dllexport) void __cdecl d2glAutomapDrawEnd();
__declspec(dllexport) void __cdecl d2glUIDrawBegin();
__declspec(dllexport) void __cdecl d2glUIDrawCursorItem();
__declspec(dllexport) void __cdecl d2glUIDrawEnd();

__declspec(dllexport) void __cdecl d2glDrawImage(void* cell, int x, int y, uint32_t gamma, int draw_mode, uint8_t* palette);
__declspec(dllexport) void __cdecl d2glDrawPerspectiveImage(void* cell, int x, int y, uint32_t gamma, int draw_mode, int screen_mode, uint8_t* palette);
__declspec(dllexport) void __cdecl d2glDrawShiftedImage(void* cell, int x, int y, uint32_t gamma, int draw_mode, int global_palette_shift);
__declspec(dllexport) void __cdecl d2glDrawVerticalCropImage(void* cell, int x, int y, int skip_lines, int draw_lines, int draw_mode);
__declspec(dllexport) void __cdecl d2glDrawClippedImage(void* cell, int x, int y, void* crop_rect, int draw_mode);
__declspec(dllexport) void __cdecl d2glDrawImageFast(void* cell, int x, int y, uint8_t palette_index);
__declspec(dllexport) void __cdecl d2glDrawShadow(void* cell, int x, int y);
__declspec(dllexport) void __cdecl d2glDrawSolidRectEx(int left, int top, int right, int bottom, uint32_t color, int draw_mode);
__declspec(dllexport) void __cdecl d2glDrawLine(int x_start, int y_start, int x_end, int y_end, uint8_t color, uint8_t alpha);
__declspec(dllexport) int __cdecl d2glDrawGroundTile(void* tile, void* light, int x, int y, int world_x, int world_y, uint8_t alpha, int screen_panels, int tile_data);
__declspec(dllexport) int __cdecl d2glDrawWallTile(void* tile, int x, int y, void* light, int screen_panels);
__declspec(dllexport) int __cdecl d2glDrawTransWallTile(void* tile, int x, int y, void* light, int screen_panels, uint8_t alpha);
__declspec(dllexport) int __cdecl d2glDrawShadowTile(void* tile, int x, int y, int draw_mode, int screen_panels);

__declspec(dllexport) void __cdecl d2glTakeScreenShot();
__declspec(dllexport) void __cdecl d2glDrawNormalText(const wchar_t* str, int x, int y, uint32_t color, uint32_t centered);
__declspec(dllexport) void __cdecl d2glDrawNormalTextEx(const wchar_t* str, int x, int y, uint32_t color, uint32_t centered, uint32_t trans_lvl);
__declspec(dllexport) void __cdecl d2glDrawFramedText(const wchar_t* str, int x, int y, uint32_t color, uint32_t centered);
__declspec(dllexport) void __cdecl d2glDrawRectangledText(const wchar_t* str, int x, int y, uint32_t rect_color, uint32_t rect_transparency, uint32_t color);
__declspec(dllexport) uint32_t __cdecl d2glGetNormalTextWidth(const wchar_t* str);
__declspec(dllexport) uint32_t __cdecl d2glGetNormalTextNWidth(const wchar_t* str, const int n_chars);
__declspec(dllexport) uint32_t __cdecl d2glGetFramedTextSize(const wchar_t* str, uint32_t* width, uint32_t* height);
__declspec(dllexport) uint16_t __cdecl d2glGetFontHeight();
__declspec(dllexport) uint32_t __cdecl d2glSetTextSize(uint32_t dwSize);

__declspec(dllexport) void __cdecl d2glRectangledTextBegin();
__declspec(dllexport) void __cdecl d2glRectangledTextEnd();
__declspec(dllexport) void __cdecl d2glUnitHoverText();
__declspec(dllexport) void __cdecl d2glAltItemsText();
__declspec(dllexport) void __cdecl d2glDrawRectFrame();
__declspec(dllexport) void __cdecl d2glDrawUnitHealthBar();

__declspec(dllexport) void __cdecl d2glLoadUIImage();
__declspec(dllexport) void __cdecl d2glDrawSubTextA();
__declspec(dllexport) void __cdecl d2glDrawSubTextB();
__declspec(dllexport) void __cdecl d2glDrawSubTextC();
__declspec(dllexport) void __cdecl d2glLevelEntryText();

#ifdef __cplusplus
}
#endif