#include "BridgePart.h"
#include "Bill.h"
#include "ObjectExplosion.h"

#define DIETIMEOUT 10

//void CBridgePart::Update(DWORD dt, vector<LPGAMEOBJECT>* gameObject)
//{
//	if (state == BRIDGE_STATE_EXPLOSIVE)
//	{
//		if (GetTickCount64() - dieStart >= DIETIMEOUT) {
//			Deleted = 1;
//			((LPPLAYSCENE)CGame::GetInstance()->GetCurrentScene())->AddObjectToQuadTree(new CObjectExplosion(x, y));
//		}
//	}
//	else
//		CCollision::GetInstance()->Process(this, dt, gameObject);
//}

void CBridgePart::OnCollisionWith(LPCOLLISIONEVENT e)
{
	x = x;
	y = y;
	vy = 0;
	vx = 0;
}

void CBridgePart::OnNoCollision(DWORD dt)
{

}
