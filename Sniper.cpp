#include "Sniper.h"
#include "Bill.h"

extern CBill* bill;
void CSniper::Update(DWORD dt, vector<LPGAMEOBJECT>* gameObject)
{
	if (abs(bill->GetX() - x) <= 100)
		SetState(SNIPER_STATE_SHOT);
	else
		SetState(SNIPER_STATE_NORMAl);
}

void CSniper::Render()
{
	int aniID = -1;
	if (state == SNIPER_STATE_NORMAl)
		aniID = ID_ANI_SNIPER_NORMAL;
	else if (state = SNIPER_STATE_SHOT)
		if (bill->GetY() - y <= -50)
			aniID = ID_ANI_SNIPER_SHOT_UP;
		else if (bill->GetY() - y >= 50)
			aniID = ID_ANI_SNIPER_SHOT_DOWN;
		else aniID = ID_ANI_SNIPER_SHOT;
	if(aniID  == -1)
		aniID = ID_ANI_SNIPER_NORMAL;
	CAnimations::GetInstance()->Get(aniID)->Render(x, y);
}

void CSniper::LoadAnimation()
{
	CTextures* texture = CTextures::GetInstance();
	texture->Add(TEXTURE_SNIPER_ID, L"./Resources/Images/rifleman.png");
	CSprites* sprites = CSprites::GetInstance();
	CAnimations* animations = CAnimations::GetInstance();
	sprites->Add(ID_ANI_SNIPER_NORMAL, 0, 0, 23, 38,texture->Get(TEXTURE_SNIPER_ID));

	LPANIMATION ani = new CAnimation(100);
	ani->Add(ID_ANI_SNIPER_NORMAL);

	animations->Add(ID_ANI_SNIPER_NORMAL, ani);

	sprites->Add(ID_ANI_SNIPER_SHOT, 26, 0, 49, 38, texture->Get(TEXTURE_SNIPER_ID));

	ani = new CAnimation(100);
	ani->Add(ID_ANI_SNIPER_NORMAL);
	ani->Add(ID_ANI_SNIPER_SHOT);

	animations->Add(ID_ANI_SNIPER_SHOT, ani);

	sprites->Add(ID_ANI_SNIPER_SHOT_UP, 72, 0, 89, 38, texture->Get(TEXTURE_SNIPER_ID));
	ani = new CAnimation(100);

	ani->Add(ID_ANI_SNIPER_SHOT_UP);

	animations->Add(ID_ANI_SNIPER_SHOT_UP, ani);

	sprites->Add(ID_ANI_SNIPER_SHOT_DOWN, 92, 0, 115, 38, texture->Get(TEXTURE_SNIPER_ID));
	ani = new CAnimation(100);
	ani->Add(ID_ANI_SNIPER_SHOT_DOWN);
	animations->Add(ID_ANI_SNIPER_SHOT_DOWN, ani);

	sprites->Add(ID_ANI_SNIPER_SHOW, 128, 0, 150, 38, texture->Get(TEXTURE_SNIPER_ID));

	ani = new CAnimation(50);
	ani->Add(ID_ANI_SNIPER_SHOW);
	ani->oneTimeAnimation = true;
	animations->Add(ID_ANI_SNIPER_SHOW, ani);

	sprites->Add(ID_ANI_SNIPER_HIDDEN, 118, 0, 125, 38, texture->Get(TEXTURE_SNIPER_ID));
	ani = new CAnimation(100);
	ani->Add(ID_ANI_SNIPER_HIDDEN);

	ani->SetStartAnimation(animations->Get(ID_ANI_SNIPER_SHOW));
	animations->Add(ID_ANI_SNIPER_HIDDEN, ani);

	sprites->Add(ID_ANI_SNIPER_HIDDEN_SHOT, 153, 0, 176, 38, texture->Get(TEXTURE_SNIPER_ID));
	ani = new CAnimation(100);
	ani->Add(ID_ANI_SNIPER_HIDDEN_SHOT);

	ani->SetStartAnimation(animations->Get(ID_ANI_SNIPER_SHOW));
	animations->Add(ID_ANI_SNIPER_HIDDEN_SHOT, ani);
}

void CSniper::GetBoundingBox(float& left, float& top, float& right, float& bottom)
{
	left = x;
	top = y;
	right = x + 23;
	bottom = y + 38;
}

void CSniper::OnNoCollision(DWORD dt)
{
}

void CSniper::OnCollisionWith(LPCOLLISIONEVENT e)
{
}
