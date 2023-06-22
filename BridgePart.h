#pragma once
#include "GameObject.h"
#include "AssetID.h"
#include "Textures.h"

class CBridge;

class CBridgePart : public CGameObject
{
public:
	CBridge* bridge;
	int Bridge_Tile_ID;
	int wave;
	int dietimeout;
	CBridgePart(float x, float y, int t, int wave, CBridge* b) :CGameObject(x, y)
	{
		bridge = b;
		this->wave = wave;
		if (wave == 1)
			dietimeout = 500;
		else if (wave == 2)
			dietimeout = 1000;
		else if (wave == 3)
			dietimeout = 1500;
		else
			dietimeout = 2000;

		state = BRIDGE_STATE_ALIVE;
		dieStart = 0;
		Bridge_Tile_ID = t;
	};
	//CBridgePart(float x, float y, int t, int wave, int id) :CGameObject(x, y)
	//{
	//	bridge_id = id;
	//	this->wave = wave;
	//	if (wave <= 1)
	//		dietimeout = 300;
	//	else if (wave <= 3)
	//		dietimeout = 900;
	//	else if (wave <= 5)
	//		dietimeout = 1500;
	//	else
	//		dietimeout = 1800;

	//	state = BRIDGE_STATE_ALIVE;
	//	dieStart = 0;
	//	Bridge_Tile_ID = t;
	//};
	void SetDieStart(int value) {
		dieStart = value;
	}

	int GetDieStart() {
		return dieStart;
	}
	void Render() {
		CAnimations::GetInstance()->Get(Bridge_Tile_ID)->Render(x, y);
	}
	void Update(DWORD dt, vector<LPGAMEOBJECT>* gameObject);
	void SetState(int state) {
		if (state == BRIDGE_STATE_EXPLOSIVE)
		{
			dieStart = GetTickCount64();
		}
		CGameObject::SetState(state);
	}
	void OnCollisionWith(LPCOLLISIONEVENT e);
	void OnNoCollision(DWORD dt);

	int IsCollidable() { return 1; };
	int IsBlocking() { return 1; }
	void GetBoundingBox(float& left, float& top, float& right, float& bottom)
	{
		left = x;
		bottom = y - 5 - 16;
		right = x + 16;
		top = y - 5;
	}
};
