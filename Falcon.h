#pragma once
#include "GameObject.h"
#include "AssetID.h"
class CFalcon: public CGameObject
{
	int showStart;
public:
	int powerup;
	CFalcon(float x, float y, int pow) : CGameObject(x, y) {
		state = ID_FALCON_CLOSE;
		hp = 99999999;
		powerup = pow;
	}
	void Update(DWORD dt, vector<LPGAMEOBJECT>* gameObject);
	static void LoadAnimation();
	void Render();
	void GetBoundingBox(float& left, float& top, float& right, float& bottom);
	void OnNoCollision();
	void GetHit(int damage = 0);
	int IsCollidable() { return 1; }
	int IsBLocking() { return 1; }
};

