#pragma once
#include "AirCraft.h"
#include "SpreadGun.h"
class CSAirCraft : public CAirCraft
{
public:
	CSAirCraft(float x, float y) :CAirCraft(x, y)
	{
		LPSPRITE sprite = CSprites::GetInstance()->Get(ID_ANI_SAIRCRAFT);
		if (sprite == NULL)
			this->LoadAnimation();
	}
	void Render()
	{
		CAnimations::GetInstance()->Get(ID_ANI_SAIRCRAFT)->Render(x, y);
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
		sprites->Add(ID_ANI_SAIRCRAFT, 158, 0, 183, 15, texture);
		LPANIMATION ani = new CAnimation(100);
		ani->Add(ID_ANI_SAIRCRAFT);
		CAnimations::GetInstance()->Add(ID_ANI_SAIRCRAFT, ani);
	}
	void PowerUp(CBill* bill)
	{
		bill->SetGun(new CSpreadGun());
	}
};
