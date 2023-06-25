#include "Falcon.h"
#include "Bill.h"
#include "ObjectExplosion.h"
#include "BAirCraft.h"
#include "LAirCraft.h"
#include "FAirCraft.h"
#include "MAirCraft.h"
#include "SAirCraft.h"

extern CBill* bill;
#define SHOW_DURATION 100
void CFalcon::Update(DWORD dt, vector<LPGAMEOBJECT>* gameObject)
{
	//if (state == ID_FAL)
	if (state == ID_FALCON_SHOW && GetTickCount64() - showStart >= SHOW_DURATION)
	{
		SetState(ID_FALCON_OPEN);
		hp = 2;
	}
	if (abs(x - bill->GetX()) < 100)
		if (state == ID_FALCON_CLOSE)
		{
			SetState(ID_FALCON_SHOW);
			showStart = GetTickCount64();
		}
		else {}
	else
	{
		SetState(ID_FALCON_CLOSE);
	}
}
void CFalcon::LoadAnimation()
{
	if (CTextures::GetInstance()->Get(TEXTURE_FALCON_ID) != NULL)
		return;
	CTextures* tex = CTextures::GetInstance();
	CAnimations* animations = CAnimations::GetInstance();
	CSprites* sprites = CSprites::GetInstance();

	tex->Add(TEXTURE_FALCON_ID, TEXTURE_FALCON_PATH);
	sprites->Add(ID_ANI_FALCON_CLOSE, 0, 0, 31, 31, tex->Get(TEXTURE_FALCON_ID));

	CAnimation* ani = new CAnimation();
	ani->Add(ID_ANI_FALCON_CLOSE);
	animations->Add(ID_ANI_FALCON_CLOSE, ani);

	sprites->Add(ID_ANI_FALCON_SHOW, 34, 0, 65, 31, tex->Get(TEXTURE_FALCON_ID));
	sprites->Add(ID_ANI_FALCON_SHOW + 1, 68, 0, 99, 31, tex->Get(TEXTURE_FALCON_ID));
	sprites->Add(ID_ANI_FALCON_SHOW + 2, 102, 0, 133, 31, tex->Get(TEXTURE_FALCON_ID));

	ani = new CAnimation();
	ani->Add(ID_ANI_FALCON_SHOW);
	ani->Add(ID_ANI_FALCON_SHOW + 1);
	ani->Add(ID_ANI_FALCON_SHOW + 2);

	animations->Add(ID_ANI_FALCON_SHOW, ani);

	sprites->Add(ID_ANI_FALCON_OPEN, 136, 0, 167, 31, tex->Get(TEXTURE_FALCON_ID));
	sprites->Add(ID_ANI_FALCON_OPEN + 1, 136, 0, 167, 31, tex->Get(TEXTURE_FALCON_ID));
	sprites->Add(ID_ANI_FALCON_OPEN + 2, 136, 0, 167, 31, tex->Get(TEXTURE_FALCON_ID));

	ani = new CAnimation();
	ani->Add(ID_ANI_FALCON_OPEN);
	ani->Add(ID_ANI_FALCON_OPEN + 1);
	ani->Add(ID_ANI_FALCON_OPEN + 2);

	animations->Add(ID_ANI_FALCON_OPEN, ani);
}

void CFalcon::Render()
{
	CAnimations::GetInstance()->Get(state)->Render(x, y);
}

void CFalcon::GetBoundingBox(float& left, float& top, float& right, float& bottom)
{
	left = x;
	top = y;
	right = x + 31;
	bottom = y - 31;
}

void CFalcon::OnNoCollision()
{

	if (state == ID_FALCON_SHOW && GetTickCount64() - showStart >= SHOW_DURATION)
	{
		SetState(ID_FALCON_OPEN);
		hp = 2;
	}
	if(abs(x - bill->GetX()) < 100)
		if (state == ID_FALCON_CLOSE)
		{
			SetState(ID_FALCON_SHOW);
			showStart = GetTickCount64();
		}
		else{}
	else 
	{
		SetState(ID_FALCON_CLOSE);
	}
}

void CFalcon::GetHit(int damage)
{
	hp -= damage;
	if (hp <= 0)
	{
		switch (powerup)
		{
		case 1:
			((LPPLAYSCENE)CGame::GetInstance()->GetCurrentScene())->AddObject(new CMAirCraft(x, y));
			//((LPPLAYSCENE)CGame::GetInstance()->GetCurrentScene())->AddObjectToQuadTree(new CMAirCraft(x, y));
			break;
		case 2:
			((LPPLAYSCENE)CGame::GetInstance()->GetCurrentScene())->AddObject(new CBAirCraft(x, y));
			//((LPPLAYSCENE)CGame::GetInstance()->GetCurrentScene())->AddObjectToQuadTree(new CBAirCraft(x, y));
			break;

		case 3:
			((LPPLAYSCENE)CGame::GetInstance()->GetCurrentScene())->AddObject(new CLAirCraft(x, y));
			//((LPPLAYSCENE)CGame::GetInstance()->GetCurrentScene())->AddObjectToQuadTree(new CLAirCraft(x, y));

			break;

		case 4:
			((LPPLAYSCENE)CGame::GetInstance()->GetCurrentScene())->AddObject(new CFAirCraft(x, y));
			//((LPPLAYSCENE)CGame::GetInstance()->GetCurrentScene())->AddObjectToQuadTree(new CFAirCraft(x, y));
			break;

		case 5:
			((LPPLAYSCENE)CGame::GetInstance()->GetCurrentScene())->AddObject(new CSAirCraft(x, y));
			//((LPPLAYSCENE)CGame::GetInstance()->GetCurrentScene())->AddObjectToQuadTree(new CSAirCraft(x, y));

			break;

		default:
			break;
		}
		((LPPLAYSCENE)CGame::GetInstance()->GetCurrentScene())->AddObjectToQuadTree(new CObjectExplosion(x, y));

		Deleted = 1;
	}
}
