#include <d3d10.h>
#include <D3DX10.h>
#include <Windows.h>
#include "Game.h"
#include <msxml.h>
#include <MsXml6.h>

#include <iostream>
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPreInstance, LPSTR lpCmdLine, int nCmdShow)
{
	CGame* game = CGame::GetInstance();
	game->CreateGameWindow(500,500);
	game->Init(hInstance);
}