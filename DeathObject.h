#pragma once
#include "BlockObject.h"
class CDeathObject :
    public CBlockObject
{
	int tile_length;
public:
	CDeathObject(float x, float y, float l) : CBlockObject(x, y, l) { tile_length = l; };
	void GetBoundingBox(float& left, float& top, float& right, float& bottom) { left = x, top = y; right = x + 16 * tile_length, bottom = y - 0.5f; }
	int IsCollidable() { return 1; };
	virtual int IsBlocking() { return 1; };
	void Render() {} //CAnimations::GetInstance()->Get(ID_GRASS)->Render(x, y); }

};

