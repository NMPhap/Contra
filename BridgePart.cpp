#include "BridgePart.h"
#include "Bill.h"
#include "ObjectExplosion.h"
//extern CBill* bill;
#define DIETIMEOUT 10

void CBridgePart::Update(DWORD dt, vector<LPGAMEOBJECT>* gameObject)
{
	//if (bill->GetX() >= bridge->GetX()) {
	//	for (int i = 0; i < 2; i++)
	//		for (int j = 0; j < 8; j++) {
	//			bridge->Tiles[i][j]->SetState(BRIDGE_STATE_EXPLOSIVE);
	//		}
	//}
	if (state == BRIDGE_STATE_EXPLOSIVE)
	{
		if (GetTickCount64() - dieStart >= dietimeout) {
			Deleted = 1;
			((LPPLAYSCENE)CGame::GetInstance()->GetCurrentScene())->AddObjectToQuadTree(new CObjectExplosion(x, y));
		}
	}
	//else
	//	CCollision::GetInstance()->Process(this, dt, gameObject);
}

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
