#pragma once
#include "InputHandler.h"
#include "MenuScene.h"

class CMenuSceneInputHandler : public CInputHandler
{
protected:
	CMenuScene* scene;
	void onKeyClick(int keyCode);
	void onKeyPress(int keyCode);
	void onKeyRelease(int keyCode);
public:
	CMenuSceneInputHandler(CMenuScene* game)
	{
		scene = game;
	}
	void HandleInput(CInput* input);

};

