#include "Bullet.h"
#include "Soldier.h"
#include "PlayScreen.h"
#include "Sniper.h"
#include "NormalExplosion.h"
void CBullet::OnCollisionWith(LPCOLLISIONEVENT e, DWORD dt)
{
	if (dynamic_cast<CSoldier*>(e->obj))
	{
		((CSoldier*)e->obj)->SetState(SODIER_STATE_DEATH);
		//((CSoldier*)e->obj)->Update(dt);
	}
	if (dynamic_cast<CSniper*>(e->obj))
		e->obj->SetDeleted(1);
	this->Deleted = 1;
}
