#include "AirCraft.h"

void CAirCraft::GetBoundingBox(float& left, float& top, float& right, float& bottom)
{
	left = x;
	top = y;
	right = left + 25;
	bottom = top - 15;
}

void CAirCraft::OnCollisionWith(LPCOLLISIONEVENT e, DWORD dt)
{
	if (e->ny != 0 && e->obj->IsBlocking())
	{
		vy = 0;
		A = 0;
		omega = 0;
	}
}
