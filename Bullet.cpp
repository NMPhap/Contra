#include "Bullet.h"
#include "Soldier.h"
#include "PlayScreen.h"
#include "Sniper.h"
void CBullet::OnCollisionWith(LPCOLLISIONEVENT e, DWORD dt)
{
	if (dynamic_cast<CSoldier*>(e->obj))
		e->obj->SetDeleted(1);
	if (dynamic_cast<CSniper*>(e->obj))
		e->obj->SetDeleted(1);
	this->Deleted = 1;
}
