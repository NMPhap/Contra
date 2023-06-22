#include "MenuScene.h"
#include "Game.h"
#include "Utils.h"
#include "MenuSceneInputHandler.h"
#define MENUDURATION 2000

CMenuScene::CMenuScene(int id, LPCWSTR filePath):CScene(id, filePath)
{
	background = NULL;
	cursor = NULL;
	key_handler = new CMenuSceneInputHandler(this);
	CText* text1 = new CText(40.0f, 110.0f, "Player 1", 0);
	CText* text2 = new CText(40.0f, 950.0f, "Player 2", 0);
	AddText(text1);
	AddText(text2);
}

void CMenuScene::Load()
{
	background = CGame::GetInstance()->LoadTexture(L".\\Resources\\Images\\intro.png");
	LPTEXTURE cursor_tex = CGame::GetInstance()->LoadTexture(L".\\Resources\\Images\\yellowfalcon.png");
	cursor = new CSprite(1712, 0, 0, cursor_tex->getWidth(), cursor_tex->getHeight(), cursor_tex);
	cursorPos.x = 25.0f;
	cursorPos.y = 110.0f;

}

void CMenuScene::Unload()
{
}

void CMenuScene::Update(DWORD dt)
{
}

void CMenuScene::Render()
{
	CGame::GetInstance()->Draw(135.0f, 113.0f, background);
	cursor->Draw(cursorPos.x, cursorPos.y);
	//for (int i = 0; i < texts.size(); i++)
	//	texts.at(i)->Render();
}

void CMenuScene::AddText(CText* text)
{
	
	texts.push_back(text);

}
