#pragma once
#include "GameObject.h"
class CBlockObject: public CGameObject
{
public:
	CBlockObject(float x, float y):CGameObject(x, y) {}
	void GetBoundingBox(float& left, float& top, float& right, float& bottom) { left = x, top = y; right = x + 31, bottom = y - 31; }

};

