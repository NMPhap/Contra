#pragma once
#include "GameObject.h"
class CBlockObject: public CGameObject
{
public:
	CBlockObject(float x, float y):CGameObject(x, y) {}
	void GetBoundingBox(float& left, float& top, float& right, float& bottom) { left = x, top = y; right = x + 16, bottom = y + 20; }
	int IsCollidable() { return 1; }
	int IsBlocking() { return 1; };
};

