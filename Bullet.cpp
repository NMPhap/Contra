#include "Bullet.h"
#include "Bill.h"
#include "BlockObject.h"
#include "JumpObject.h"
#include "Bridge.h"
#include "AirCraft.h"
#include "HIddenAirCraft.h"

void CBullet::OnCollisionWith(LPCOLLISIONEVENT e, DWORD dt)
{
	if (dynamic_cast<CAirCraft*>(e->obj)) {
		if (dynamic_cast<CHiddenAirCraft*>(e->obj))
		{
			if (e->src_obj->IsEnemy() ^ e->obj->IsEnemy())
				e->obj->GetHit(GetDamage());
			this->Deleted = 1;
		}
	}
	if ((!dynamic_cast<CAirCraft*>(e->obj)) &&!dynamic_cast<CBlockObject*>(e->obj) && !dynamic_cast<CJumpObject*>(e->obj) && !dynamic_cast<CBridgePart*>(e->obj))
	{
		if (e->src_obj->IsEnemy() ^ e->obj->IsEnemy())
			e->obj->GetHit(GetDamage());
		this->Deleted = 1;
	}
	else
		OnNoCollision(dt);

}
