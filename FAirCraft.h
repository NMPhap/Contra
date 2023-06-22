#pragma once
#include "AirCraft.h"
#include "CircularGun.h"
class CFAirCraft : public CAirCraft
{
public:
	CFAirCraft(float x, float y) :CAirCraft(x, y)
	{
		LPSPRITE sprite = CSprites::GetInstance()->Get(ID_ANI_FAIRCRAFT);
		if (sprite == NULL)
			this->LoadAnimation();
	}
	void Render()
	{
		CAnimations::GetInstance()->Get(ID_ANI_FAIRCRAFT)->Render(x, y);
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
		sprites->Add(ID_ANI_FAIRCRAFT, 55, 0, 79, 15, texture);
		LPANIMATION ani = new CAnimation(100);
		ani->Add(ID_ANI_FAIRCRAFT);
		CAnimations::GetInstance()->Add(ID_ANI_FAIRCRAFT, ani);
	}
	void PowerUp(CBill* bill)
	{
		bill->SetGun(new CCircularGun());
	}
};
