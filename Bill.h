#pragma once
#include "GameObject.h"

#include "Animation.h"
#include "Animations.h"

#include "debug.h"

#define BILL_WALKING_SPEED		0.07f

#define BILL_JUMP_SPEED_Y		0.5f
#define BILL_JUMP_RUN_SPEED_Y	0.6f

#define BILL_GRAVITY			0.002f

#define BILL_STATE_IDLE			0
#define BILL_STATE_WALKING_RIGHT	100
#define BILL_STATE_WALKING_LEFT	200

#define BILL_STATE_JUMP			300
#define BILL_STATE_RELEASE_JUMP    301

#define BILL_STATE_LAY				600
#define BILL_STATE_LAY_RELEASE		601


#pragma region ANIMATION_ID

#define ID_ANI_BILL_IDLE_RIGHT 400
#define ID_ANI_BILL_IDLE_LEFT 401

#define ID_ANI_BILL_WALKING_RIGHT 500
#define ID_ANI_BILL_WALKING_LEFT 501


#define ID_ANI_BILL_JUMP_WALK_RIGHT 600
#define ID_ANI_BILL_JUMP_WALK_LEFT 601


#define ID_ANI_BILL_LAY_RIGHT 700
#define ID_ANI_BILL_LAY_LEFT 701


#pragma endregion

#define GROUND_Y 160.0f

#define BILL_LAY_HEIGHT_ADJUST 2.0f

class CBill : public CGameObject
{
	BOOLEAN isLaying;
public:
	CBill(float x, float y) :CGameObject(x, y) {
		isLaying = false;
		vx = 0;
		vy = 0;
	}
	void Update(DWORD dt);
	void Render();
	void SetState(int state);
};

