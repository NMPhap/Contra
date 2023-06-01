#pragma once
#include "GameObject.h"
#include "Textures.h"
#include "AssetID.h"
class CAirCraft: public CGameObject
{
private:
public:
	CAirCraft(float x, float y) : CGameObject(x, y){}
	virtual void Update(DWORD dt, vector<LPGAMEOBJECT> *gameObject = NULL)
	{
		CCollision::GetInstance()->Process(this, dt, gameObject);
	}
	static void LoadAnimation()
	{
		CTextures* textures = CTextures::GetInstance();
		textures->Add(AIRCRAFT_TEXTURE_ID, L"./Resources/Images/aircraft.png");
	}
	void GetBoundingBox(float& left, float& top, float& right, float& bottom);
	virtual int IsCollision() { return 1; }
	virtual int IsBlocking() { return 1; }
	void OnNoCollision(DWORD dt) {
		x += vx * dt;
		y += vy * dt;
		vy += Bill_GRAVITY;
	}

	void OnCollisionWith(LPCOLLISIONEVENT e, DWORD dt)
	{
		if (e->ny != 0 && e->obj->IsBlocking())
			vy = 0;
	}
};

