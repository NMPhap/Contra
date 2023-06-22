#pragma once
#include "AirCraft.h"
#include "NormalGun.h"
class CMAirCraft : public CAirCraft
{
public:
	CMAirCraft(float x, float y) :CAirCraft(x, y)
	{
		LPSPRITE sprite = CSprites::GetInstance()->Get(ID_ANI_MAIRCRAFT);
		if (sprite == NULL)
			this->LoadAnimation();
	}
	void Render()
	{
		CAnimations::GetInstance()->Get(ID_ANI_MAIRCRAFT)->Render(x, y);
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
		sprites->Add(ID_ANI_MAIRCRAFT, 106, 0, 131, 15, texture);
		LPANIMATION ani = new CAnimation(100);
		ani->Add(ID_ANI_MAIRCRAFT);
		CAnimations::GetInstance()->Add(ID_ANI_MAIRCRAFT, ani);
	}
	void PowerUp(CBill* bill)
	{
		bill->SetGun(new CNormalGun());
	}
};
