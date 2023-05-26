#pragma once
#include "Game.h"
#include "AssetID.h"
class CBullet : public CGameObject
{
protected:
	LPANIMATION bulletAnimation;
public:
	CBullet(float x, float y, float vx = 0.5f, float vy = 0.0f) :CGameObject(x,y){

			this->vy = vy;
			this->vx = vx;
			bulletAnimation = NULL;
	}
	void Update(DWORD dt, vector<LPGAMEOBJECT> *gameObject = NULL) 
	{
		CCollision::GetInstance()->Process(this, dt, gameObject);
	}
	void Render() { 
		if (bulletAnimation != NULL)
			bulletAnimation->Render(x, y);
	}
	void DeleteBullet()
	{
		vector<CBullet*>* ammo = ((LPPLAYSCENE)CGame::GetInstance()->GetCurrentScene())->GetAmmo();
		vector<CBullet*>::iterator i = std::find(ammo->begin(), ammo->end(), this);
		ammo->erase(i);
	}
	static void LoadAnimation()
	{
		CTextures* tex = CTextures::GetInstance();
		tex->Add(ID_BULLET_TEXTURE, TEXTURE_BULET_PATH);
	}


	// When no collision has been detected (triggered by CCollision::Process)
	void OnNoCollision(DWORD dt)
	{
		x += vx * dt;
		y += vy * dt;
		CGame* game = CGame::GetInstance();
		float camX, camY;
		CGame::GetInstance()->GetCamPos(camX, camY);
		float camWidth, camHeight;
		camWidth = CGame::GetInstance()->GetScreenWidth();
		camHeight = CGame::GetInstance()->GetScreenHeight();
		if (x < camX || x > camX + camWidth + 50 || y < camY || y > camY + camHeight + 50)
			DeleteBullet();
	}
	int IsCollidable() { return 1; };
	// When collision with an object has been detected (triggered by CCollision::Process)
	void OnCollisionWith(LPCOLLISIONEVENT e, DWORD dt = 0);
	virtual void GetBoundingBox(float& left, float& top, float& right, float& bottom) = 0;
};