#pragma once
#include "GameObject.h"
#include "BillInputHandler.h"
#include "NormalGun.h"
#define GROUND_Y 160.0f
#define Bill_GRAVITY 0.002f
#define BILL_RUN_SPEED  0.1f
#define BILL_JUMP_SPEED_Y 0.5f

#define BILL_STATE_IDLE 100
#define BILL_STATE_SWIM 200
#define BILL_STATE_RUN 300
#define BILL_STATE_JUMP 400
#define BILL_STATE_LAYDOWN 500
#define BILL_STATE_DEAD 600
#define BILL_STATE_SWIM_MOVE 700


#pragma once ANIMATION_ID
#define ID_ANI_BILL_IDLE_RIGHT 100
#define ID_ANI_BILL_IDLE_SHOT_UP_RIGHT 101
#define ID_ANI_BILL_IDLE_LEFT 150
#define ID_ANI_BILL_IDLE_SHOT_UP_LEFT 151
#define ID_ANI_BILL_SWIMMING_RIGHT 200
#define ID_ANI_BILL_SWIMMING_SHOT_RIGHT 201
#define ID_ANI_BILL_SWIMMING_SHOT_UP_RIGHT 202
#define ID_ANI_BILL_SWIMMING_SHOT_UP_STAND_RIGHT 203
#define ID_ANI_BILL_SWIMMING_LEFT 250
#define ID_ANI_BILL_SWIMMING_SHOT_LEFT 251
#define ID_ANI_BILL_SWIMMING_SHOT_UP_LEFT 252
#define ID_ANI_BILL_SWIMMING_SHOT_UP_STAND_LEFT 253
#define ID_ANI_BILL_SWIMMING_START 299
#define ID_ANI_BILL_RUN_RIGHT 300
#define ID_ANI_BILL_RUN_SHOT_RIGHT 301
#define ID_ANI_BILL_RUN_SHOT_UP_RIGHT 302
#define ID_ANI_BILL_RUN_SHOT_DOWN_RIGHT 303
#define ID_ANI_BILL_RUN_LEFT 350
#define ID_ANI_BILL_RUN_SHOT_LEFT 351
#define ID_ANI_BILL_RUN_SHOT_UP_LEFT 352
#define ID_ANI_BILL_RUN_SHOT_DOWN_LEFT 353
#define ID_ANI_BILL_JUMP_RIGHT 400
#define ID_ANI_BILL_JUMP_LEFT 450
#define ID_ANI_BILL_LAYDOWN_RIGHT 500
#define ID_ANI_BILL_LAYDOWN_LEFT 550
#define ID_ANI_BILL_DEAD 600

#define TEXTURE_RIGHT_PATH L"./Resources/Images/bill_animation.png"
#define TEXTURE_RIGHT_ID 0
#define TEXTURE_LEFT_ID 1
#pragma once ANIMATION_DURATION
#define DURATION_ANI_BILL_IDLE 20
#define DURATION_ANI_BILL_SWIMMING 100
#define DURATION_ANI_BILL_RUN 100
#define DURATION_ANI_BILL_JUMP 100


class CBill : public CGameObject
{
private:
	CGun* gun;
public:
	BOOLEAN isSitting;
	BOOLEAN isShotting;
	int shotDirection;
	int faceDirection;
	CBillInputHandler* handler;
	CBill(float x, float y): CGameObject(x,y)
	{
		isSitting = false;
		isShotting = false;
		shotDirection = 0;
		faceDirection = 1;
		state = BILL_STATE_IDLE;
		this->handler = new CBillInputHandler();
		gun = new CNormalGun();
	}
	void Update(DWORD dt);
	void Render();
	void SetState(int state);
	void SetFaceDirection(int faceD) { faceDirection = faceD; if (vx > 0) vx = faceDirection * vx; else vx = -faceDirection * vx; }
	void SetHandler(CBillInputHandler* inputHandler) { handler = inputHandler; }
	static void LoadAnimation();
	void SetGun(CGun* newGun) { gun = newGun; }
};