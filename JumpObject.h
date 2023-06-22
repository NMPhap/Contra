#pragma once
#include "AssetID.h"
#include "GameObject.h"
class CJumpObject :
    public CGameObject
{
public:
	CJumpObject(float x, float y) :CGameObject(x, y) { }
	void GetBoundingBox(float& left, float& top, float& right, float& bottom) { left = x, top = y; right = x + 1.0f , bottom = y - 20.0f; }
	int IsCollidable() { return 1; };
	virtual int IsBlocking() { return 0; };
	void Render() { }
};

