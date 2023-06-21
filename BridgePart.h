#pragma once
#include "GameObject.h"
#include "AssetID.h"
#include "Textures.h"

class CBridgePart : public CGameObject
{
public:
	int Bridge_Tile_ID;
	int wave;
	CBridgePart(float x, float y, int t, int wave) :CGameObject(x, y)
	{
		this->wave = wave;
		state = BRIDGE_STATE_ALIVE;
		dieStart = 0;
		Bridge_Tile_ID = t;
	};
	void Render() {
		CAnimations::GetInstance()->Get(Bridge_Tile_ID)->Render(x, y);
	}
	//void Update(DWORD dt, vector<LPGAMEOBJECT>* gameObject);
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
		bottom = y - 16;
		right = x + 15;
		top = y;
	}
};
