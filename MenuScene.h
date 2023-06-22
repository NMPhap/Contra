#pragma once
#include "Scene.h"
#include "Text.h"
#include "Game.h"

class CMenuScene : public CScene
{
private:
	CTexture* background;
	CSprite* cursor;
	D3DXVECTOR2 cursorPos;
	vector<CText*> texts;
public:
	CMenuScene(int id, LPCWSTR filePath);
	void Load();
	void Unload();
	void Update(DWORD dt);
	void Render();
	void AddText(CText* text);
	void SetCusorPos(float x, float y) { cursorPos.x = x, cursorPos.y = y; }
	void GetCursorPos(float& x, float& y) { x = cursorPos.x; y = cursorPos.y; }

};

