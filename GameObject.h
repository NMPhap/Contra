#pragma once

#include <Windows.h>
#include <d3dx10.h>
#include <vector>
#include "Animations.h"
using namespace std;

class CGame;
class CGameObject
{
protected:
	float x; 
	float y;

	float vx;
	float vy;

	int nx;	 
	int state;									
public: 
	void SetPosition(float x, float y) { this->x = x, this->y = y; }
	void SetSpeedX(float vx) { this->vx = vx; }
	void SetSpeedY(float vy) { this->vy = vy; }
	void SetState(int state) { this->state = state; }
	int GetState() { return this->state; }

	CGameObject();
	CGameObject(float x, float y) :CGameObject() { this->x = x; this->y = y; this->vx = 0; this->vy = 0; }

	virtual void Update(DWORD dt) = 0;
	virtual void HandleInput() {};
	virtual void Render() = 0;
	virtual void DeleteFromGameObjects();
	float GetX() { return x; }
	float GetY() { return y; }
	~CGameObject();
};

typedef CGameObject* LPGAMEOBJECT;