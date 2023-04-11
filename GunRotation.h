#pragma once
#include "GameObject.h"
#include "AssetID.h"
class CGunRotation : public CGameObject
{

public:
	CGunRotation(float x, float y) : CGameObject(x, y) { state = GUNROTATION_STATE_HIDDEN; }
	void Update(DWORD dt, vector<LPGAMEOBJECT>* gameObject = NULL);
	void Render();
	static void LoadAnimation();
	void SetState(int state);
	int IsCollidable() { return 1; }
	void GetBoundingBox(float& left, float& top, float& right, float& bottom);
	int IsBlocking() { return 1; }
};
