#include "Soldier.h"
#include "Bill.h"

extern CBill* bill;

void CSoldier::Update(DWORD dt, vector<LPGAMEOBJECT>* gameObject)
{
	if (bill->GetY() <= y + 10 && bill->GetY() >= y && abs(bill->GetX() - x) <= 150)
		SetState(SODIER_STATE_SHOT);
	else
		SetState(SODIER_STATE_RUNNING);
	CCollision::GetInstance()->Process(this, dt, gameObject);
}

void CSoldier::Render()
{
	CAnimations::GetInstance()->Get(state)->Render(x, y);
}

void CSoldier::LoadAnimation()
{
	CTextures* texture = CTextures::GetInstance();
	texture->Add(TEXTURE_SODIER_ID, L"./Resources/Images/Soldier.png");
	CSprites* sprites = CSprites::GetInstance();
	sprites->Add(ID_ANI_SODIER_RUNNING + 5, 0, 0, 16, 32, texture->Get(TEXTURE_SODIER_ID));
	sprites->Add(ID_ANI_SODIER_RUNNING + 4, 18, 0, 34, 32, texture->Get(TEXTURE_SODIER_ID));
	sprites->Add(ID_ANI_SODIER_RUNNING + 3, 36, 0, 52, 32, texture->Get(TEXTURE_SODIER_ID));
	sprites->Add(ID_ANI_SODIER_RUNNING + 2, 54, 0, 70, 32, texture->Get(TEXTURE_SODIER_ID));
	sprites->Add(ID_ANI_SODIER_RUNNING + 1, 72, 0, 88, 32, texture->Get(TEXTURE_SODIER_ID));
	sprites->Add(ID_ANI_SODIER_RUNNING, 90, 0, 106, 32, texture->Get(TEXTURE_SODIER_ID));

	LPANIMATION ani = new CAnimation(100);
	CAnimations* animations = CAnimations::GetInstance();
	ani->Add(ID_ANI_SODIER_RUNNING);
	ani->Add(ID_ANI_SODIER_RUNNING + 1);
	ani->Add(ID_ANI_SODIER_RUNNING + 2);
	ani->Add(ID_ANI_SODIER_RUNNING + 3);
	ani->Add(ID_ANI_SODIER_RUNNING + 4);
	ani->Add(ID_ANI_SODIER_RUNNING + 5);

	animations->Add(ID_ANI_SODIER_RUNNING, ani);

	sprites->Add(ID_ANI_SODIER_JUMPING, 108, 0, 124, 32, texture->Get(TEXTURE_SODIER_ID));

	ani = new CAnimation(100);
	ani->Add(ID_ANI_SODIER_JUMPING);
	animations->Add(ID_ANI_SODIER_JUMPING, ani);

	sprites->Add(ID_ANI_SODIER_SHOT, 126, 0, 150, 32, texture->Get(TEXTURE_SODIER_ID));
	sprites->Add(ID_ANI_SODIER_SHOT + 1, 152, 0, 176, 32, texture->Get(TEXTURE_SODIER_ID));

	ani = new CAnimation(100);
	ani->Add(ID_ANI_SODIER_SHOT);
	ani->Add(ID_ANI_SODIER_SHOT + 1);

	animations->Add(ID_ANI_SODIER_SHOT, ani);

	sprites->Add(ID_ANI_SODIER_SHOTED, 212, 0, 227, 32, texture->Get(TEXTURE_SODIER_ID));

	ani = new CAnimation(100);
	ani->Add(ID_ANI_SODIER_SHOTED);
	animations->Add(ID_ANI_SODIER_SHOTED, ani);

}

void CSoldier::GetBoundingBox(float& left, float& top, float& right, float& bottom)
{
	left = x;
	top = y;
	right = x + 16;
	bottom = y + 32;
}

void CSoldier::OnNoCollision(DWORD dt)
{
	x += dt * vx;
	y += vy * dt;
	vy += Bill_GRAVITY * dt;
	if (y > GROUND_Y)
	{
		vy = 0;
		y = GROUND_Y;
	}
}

void CSoldier::OnCollisionWith(LPCOLLISIONEVENT e)
{
	if (e->ny != 0 && e->obj->IsBlocking())
	{
		vy = 0;
	}
	if (e->nx != 0 && e->obj->IsBlocking())
		vx = 0;
}
