#include <d3dx9.h>

#include "debug.h"
#include "Game.h"
#include "GameObject.h"
CGameObject::CGameObject()
{
	x = y = 0;
	vx = vy = 0;
	nx = 1;	
	state = -1;
}

void CGameObject::DeleteFromGameObjects()
{
	CGame* game = CGame::GetInstance();
	vector<LPGAMEOBJECT> gameObjects = CGame::GetInstance()->gameObjects;
	vector<LPGAMEOBJECT>::iterator i = std::find(gameObjects.begin(), gameObjects.end(), this);
	gameObjects.erase(i);
}

CGameObject::~CGameObject()
{
}
