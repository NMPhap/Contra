#pragma once
#include "Bullet.h"
class CBillBullet : public CBullet
{
public:
	static ULONG lastBulletTime;
	CBillBullet(float x, float y, float vx = 0.5f, float vy = 0.5f): CBullet(x,y,vx,vy) {
		lastBulletTime = GetTickCount64();
		bulletAnimation = CAnimations::GetInstance()->Get(ID_ANI_BULLET_NORMAL);
	}

	void Update(DWORD dt)
	{
		CBullet::Update(dt);
	}
	
	static void LoadAnimation()
	{
		CTextures* tex = CTextures::GetInstance();
		tex->Add(ID_BULLET_TEXTURE, TEXTURE_BULET_PATH);
		LPTEXTURE textures = CTextures::GetInstance()->Get(ID_BULLET_TEXTURE);
		CSprites* sprites = CSprites::GetInstance();
		sprites->Add(ID_ANI_BULLET_NORMAL, 52, 42, 54, 44, textures);
		LPANIMATION ani = new  CAnimation(100);
		ani->Add(ID_ANI_BULLET_NORMAL);
		CAnimations::GetInstance()->Add(ID_ANI_BULLET_NORMAL, ani);
	}
};

