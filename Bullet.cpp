#include "Bullet.h"
#include "Bill.h"
#include "BlockObject.h"
#include "JumpObject.h"

void CBullet::OnCollisionWith(LPCOLLISIONEVENT e, DWORD dt)
{
	if (!dynamic_cast<CBlockObject*>(e->obj) && !dynamic_cast<CJumpObject*>(e->obj))
	{
		if (e->src_obj->IsEnemy() ^ e->obj->IsEnemy())
			e->obj->GetHit(GetDamage());
		this->Deleted = 1;
	}
	else
		OnNoCollision(dt);

}
