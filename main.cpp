#include <d3d10.h>
#include <D3DX10.h>
#include <Windows.h>
#include "Game.h"
#include <msxml.h>
#include <MsXml6.h>
#include <iostream>
#include "Textures.h"
#include "Sprites.h"
#include "Animations.h"
#include "Bill.h"
#include "BillBullet.h"
#include <vector>
#define TEXTURE_PATH L"./Resources/Images/bill_animation.png"
#define BACKGROUND_COLOR D3DXCOLOR(0.0f, 0.0f, 0.0f, 0.0f)
#define SCREEN_WIDTH 500
#define SCREEN_HEIGHT 500

CTextures* tex;
CAnimations* animation;
CSprites* sprite;
CBill* bill = NULL;
CBullet* bullet;
void Render()
{
	CGame* g = CGame::GetInstance();

	ID3D10Device* pD3DDevice = g->GetDirect3DDevice();
	IDXGISwapChain* pSwapChain = g->GetSwapChain();
	ID3D10RenderTargetView* pRenderTargetView = g->GetRenderTargetView();
	ID3DX10Sprite* spriteHandler = g->GetSpriteHandler();

	if (pD3DDevice != NULL)
	{
		// clear the background 
		pD3DDevice->ClearRenderTargetView(pRenderTargetView, BACKGROUND_COLOR);

		spriteHandler->Begin(D3DX10_SPRITE_SORT_TEXTURE);

		// Use Alpha blending for transparent sprites
		FLOAT NewBlendFactor[4] = { 0,0,0,0 };
		pD3DDevice->OMSetBlendState(g->GetAlphaBlending(), NewBlendFactor, 0xffffffff);


		// Uncomment this line to see how to draw a porttion of a texture  
		//g->Draw(10, 10, texMisc, 300, 117, 316, 133);
		for (int i = 0; i < g->gameObjects.size(); i++)
			g->gameObjects[i]->Render();
		spriteHandler->End();
		pSwapChain->Present(0, 0);
	}
}
void Run()
{
	int done = 0;
	while (!done)
	{
		CGame::GetInstance()->ProcessKeyboard();
		CGame* game = CGame::GetInstance();
		for (int i = 0; i < game->gameObjects.size(); i++)
			game->gameObjects[i]->Update(10);
		Render();
		Sleep(10);
	}
}
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPreInstance, LPSTR lpCmdLine, int nCmdShow)
{
	CGame* game = CGame::GetInstance();
	game->CreateGameWindow(SCREEN_WIDTH,SCREEN_HEIGHT);
	game->Init(hInstance);
	game->InitKeyboard();
	sprite = CSprites::GetInstance();
	animation = CAnimations::GetInstance();
	tex = CTextures::GetInstance();
	CBillBullet::LoadAnimation();
	bill = new CBill(200.0f, 200.0f);
	CBill::LoadAnimation();
	game->gameObjects.push_back(bill);
	//SetWindowPos(game->GetHWnd(), 0, 0, 0, SCREEN_WIDTH * 2, SCREEN_HEIGHT * 2, SWP_NOMOVE | SWP_NOOWNERZORDER | SWP_NOZORDER);
	Run(); 
}
