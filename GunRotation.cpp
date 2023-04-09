#include "GunRotation.h"
#include "Bill.h"
extern CBill* bill;
float Radius(float ax, float ay, float bx, float by)
{
	return sqrt((ax - bx) * (ax - bx) * (ay - by) * (ay - by));
}
void CGunRotation::Update(DWORD dt, vector<LPGAMEOBJECT> *gameObject)
{
	if (abs(bill->GetX() - x) <= 100 && state == GUNROTATION_STATE_HIDDEN)
		this->SetState(GUNROTATION_STATE_NORMAL);
	if (abs(bill->GetX() - x) > 100 && state == GUNROTATION_STATE_NORMAL)
		this->SetState(GUNROTATION_STATE_HIDDEN);
}

void CGunRotation::Render()
{
	int aniID = -1;
	if (state == GUNROTATION_STATE_HIDDEN)
		aniID = ID_ANI_GUNROTATION_HIDDEN;
	else
		aniID = ID_ANI_GUNROTATION_SHOT_0;
	CAnimations::GetInstance()->Get(aniID)->Render(x, y);
}

void CGunRotation::LoadAnimation()
{
	CTextures* texture = CTextures::GetInstance();
	texture->Add(TEXTURE_GUNROTATION_ID, L"./Resources/Images/wall_turret_all.png");
	CSprites* sprites = CSprites::GetInstance();
	CAnimations* animations = CAnimations::GetInstance();
	LPANIMATION ani;
	sprites->Add(ID_ANI_GUNROTATION_HIDDEN, 96, 64, 128, 96, texture->Get(TEXTURE_GUNROTATION_ID));

	ani = new CAnimation(100);
	ani->Add(ID_ANI_GUNROTATION_HIDDEN);

	animations->Add(ID_ANI_GUNROTATION_HIDDEN, ani);

	sprites->Add(ID_ANI_GUNROTATION_SHOW, 96, 32, 128, 64, texture->Get(TEXTURE_GUNROTATION_ID));

	ani = new CAnimation(200);
	ani->Add(ID_ANI_GUNROTATION_SHOW);
	ani->oneTimeAnimation = true;
	animations->Add(ID_ANI_GUNROTATION_SHOW, ani);
	sprites->Add(ID_ANI_GUNROTATION_SHOT_0, 0, 0, 32, 32, texture->Get(TEXTURE_GUNROTATION_ID));

	ani = new CAnimation(100);

	ani->Add(ID_ANI_GUNROTATION_SHOT_0);

	animations->Add(ID_ANI_GUNROTATION_SHOT_0, ani);
}

void CGunRotation::SetState(int state)
{
	switch (state)
	{
		case GUNROTATION_STATE_HIDDEN:
		{
			CAnimations::GetInstance()->Get(ID_ANI_GUNROTATION_HIDDEN)->SetStartAnimation(CAnimations::GetInstance()->Get(ID_ANI_GUNROTATION_SHOW));
			break;
		}
		case GUNROTATION_STATE_NORMAL:
		{
			CAnimations::GetInstance()->Get(ID_ANI_GUNROTATION_SHOT_0)->SetStartAnimation(CAnimations::GetInstance()->Get(ID_ANI_GUNROTATION_SHOW));
			break;
		}
	}
	CGameObject::SetState(state);
}
