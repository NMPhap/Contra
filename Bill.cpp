#include "Bill.h"
#include "Game.h"

void CBill::Update(DWORD dt)
{
	x += vx * dt;
	y += vy * dt;

	// simple fall down
	vy += BILL_GRAVITY * dt;

	DebugOutTitle(L"vx = %0.5f", this->vx);


	// BAD & sinful platform collision handling, see next sample for correct collision handling
	if (y > GROUND_Y)
	{
		vy = 0; y = GROUND_Y;
	}

	// simple screen edge collision!!!
	if (vx > 0 && x > 290) x = 290;
	if (vx < 0 && x < 0) x = 0;
}

void CBill::Render()
{
	CAnimations* animations = CAnimations::GetInstance();
	int aniId = -1;

	if (y < GROUND_Y) {
		if (nx >= 0)
			aniId = ID_ANI_BILL_JUMP_WALK_RIGHT;
		else
		{
			aniId = ID_ANI_BILL_JUMP_WALK_LEFT;
		}
	}
	else if (isLaying) {
		if (nx > 0)
			aniId = ID_ANI_BILL_LAY_RIGHT;
		else
			aniId = ID_ANI_BILL_LAY_LEFT;
	}
	else if (vx == 0) {
		if (nx > 0)
			aniId = ID_ANI_BILL_IDLE_RIGHT;
		else
			aniId = ID_ANI_BILL_IDLE_LEFT;
	}
	else if (vx > 0) {
		aniId = ID_ANI_BILL_WALKING_RIGHT;
	}
	else {
		aniId = ID_ANI_BILL_WALKING_LEFT;
	}

	if (aniId == -1) aniId = ID_ANI_BILL_IDLE_RIGHT;
	float d = 0;
	if (isLaying) d = BILL_LAY_HEIGHT_ADJUST;

	animations->Get(aniId)->Render(x, y + d);

}

void CBill::SetState(int state)
{
	switch (state)
	{
	case BILL_STATE_WALKING_RIGHT:
		vx = BILL_WALKING_SPEED;
		nx = 1;
		break;
	case BILL_STATE_WALKING_LEFT:
		vx = -BILL_WALKING_SPEED;
		nx = -1;
		break;
	case BILL_STATE_JUMP:
		if (y == GROUND_Y)
		{
			vy = -BILL_JUMP_SPEED_Y;
		}
		break;
	case BILL_STATE_RELEASE_JUMP:
		if (vy < 0) vy += BILL_JUMP_SPEED_Y / 2;
		break;
	case BILL_STATE_LAY:
		if (y == GROUND_Y)
		{
			state = BILL_STATE_IDLE;
			isLaying = true;
			vx = 0; vy = 0;
		}
		break;

	case BILL_STATE_LAY_RELEASE:
		isLaying = false;
		state = BILL_STATE_IDLE;
		break;

	case BILL_STATE_IDLE:
		vx = 0.0f;
		break;
	}

	CGameObject::SetState(state);
}
