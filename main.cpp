#include <d3d10.h>
#include <D3DX10.h>
#include <Windows.h>
#include "Game.h"
#include <msxml.h>
#include <MsXml6.h>
#include "Bill.h"
#include "Game.h"
#include "SampleKeyEventHandler.h"

CBill* bill = NULL;

#include <iostream>
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPreInstance, LPSTR lpCmdLine, int nCmdShow)
{
	CGame* game = CGame::GetInstance();
	game->CreateGameWindow(400,400);
	game->Init(hInstance);

	CSampleKeyHandler* kkeyHandler = new CSampleKeyHandler();
	game->InitKeyboard(kkeyHandler);


	game->LoadResources();
	game->Run();
}