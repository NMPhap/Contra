#pragma once
#include "Bill.h"
#include "AirCraft.h"
extern CBill* bill;
class CHiddenAirCraft: public CAirCraft
{
private:
	int canMove;
	float A;
	float time;
	float omega;
	float cycle;
	float startX;
public:
	int powerup;
	CHiddenAirCraft(float x, float y, int pow, float vx = 0.1f, float vy = 0.0f, float omega = 0.005f, float A = 5.0f) :CAirCraft(x, y)
	{
		canMove = 0;
		LPSPRITE sprite = CSprites::GetInstance()->Get(ID_ANI_HIDDENAIRCRAFT);
		if (sprite == NULL)
			this->LoadAnimation();
		startX = y;
		powerup = pow;
		this->vx = vx;
		this->vy = vy;
		this->omega = omega;
		cycle = 2 * PI / omega;
		time = 0;
		this->A = A;
		state = ID_HIDDENAIRCRAFT + 1;
	}
	void SetState(int state) {
		this->state = state;
		if (state == ID_HIDDENAIRCRAFT)
		{
			hp = 1;
		}
		else
			hp = 999999;
	}
	int IsEnemy() { return 1; }
	void Render()
	{
		if (state == ID_HIDDENAIRCRAFT)
			CAnimations::GetInstance()->Get(ID_ANI_HIDDENAIRCRAFT)->Render(x, y);
		else
			CAnimations::GetInstance()->Get(ID_ANI_HIDDENAIRCRAFT + 1)->Render(x, y);
	}
	static void LoadAnimation()
	{
		LPTEXTURE texture = CTextures::GetInstance()->Get(AIRCRAFT_TEXTURE_ID);
		if (texture == NULL)
		{
			CAirCraft::LoadAnimation();
			texture = CTextures::GetInstance()->Get(AIRCRAFT_TEXTURE_ID);
		}
		CSprites* sprites = CSprites::GetInstance();
		sprites->Add(ID_ANI_HIDDENAIRCRAFT, 2, 0, 27, 15, texture);
		LPANIMATION ani = new CAnimation(100);
		ani->Add(ID_ANI_HIDDENAIRCRAFT);
		CAnimations::GetInstance()->Add(ID_ANI_HIDDENAIRCRAFT, ani);
		sprites->Add(ID_ANI_HIDDENAIRCRAFT + 1, 0, 0, 0, 0, texture);
		ani = new CAnimation(100);
		ani->Add(ID_ANI_HIDDENAIRCRAFT + 1);
		CAnimations::GetInstance()->Add(ID_ANI_HIDDENAIRCRAFT + 1, ani);

	}
	int IsCollidable() { return 1; }
	void OnNoCollision(DWORD dt)
	{
		time += dt;
		time = (float)((int)time % (int)cycle);
		if ((bill->GetX() - CGame::GetInstance()->GetScreenWidth() / 2 >= this->x) && canMove == 0) {
			SetState(ID_HIDDENAIRCRAFT);
			canMove = 1;
		}
		if (canMove == 1) {
			x += vx * dt;
			y += A * cos(omega * time);
		}
	}
	void OnCollisionWith(LPCOLLISIONEVENT e, DWORD dt)
	{
		if (e->obj->IsBlocking() && e->nx != 0)
			vx = -vx;
	}
	void GetHit(int damage);
};

