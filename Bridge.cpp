#include "Bridge.h"
#include "Bill.h"
extern CBill* bill;
#define WAVE 4
int _matrixIndex[2][WAVE * 2] =
{
	{ 3, 0, 3, 0, 3, 0, 3, 0 },
	{ 1, 4, 4, 4, 4, 4, 4, 5 },
};


void CBridge::Update(DWORD dt, vector<LPGAMEOBJECT>* gameObject)
{
	if (bill->GetX() == this->x) {
		for (int i = 0; i < 2; i++)
			for (int j = 0; j < 8; j++) {
				Tiles[i][j]->SetState(BRIDGE_STATE_EXPLOSIVE);
			}
	}
	for (int i = 0;i<2;i++)
		for (int j = 0; j < 8; j++) {
			Tiles[i][j]->Update(dt,gameObject);
		}
}

void CBridge::LoadAnimation()
{
	CTextures* texture = CTextures::GetInstance();
	texture->Add(TEXTURE_BRIDGE_ID, L"./Resources/Images/bridge.png");
	LPANIMATION ani = new CAnimation(20);

	//Under left
	CSprites::GetInstance()->Add(TEXTURE_BRIDGE_ID_BOTLEFT, 16, 0, 31, 15, texture->Get(TEXTURE_BRIDGE_ID));
	ani->Add(TEXTURE_BRIDGE_ID_BOTLEFT);
	CAnimations::GetInstance()->Add(TEXTURE_BRIDGE_ID_BOTLEFT, ani);

	//Under right
	CSprites::GetInstance()->Add(TEXTURE_BRIDGE_ID_BOTRIGHT, 32, 16, 47, 31, texture->Get(TEXTURE_BRIDGE_ID));
	ani = new CAnimation(20);
	ani->Add(TEXTURE_BRIDGE_ID_BOTRIGHT);
	CAnimations::GetInstance()->Add(TEXTURE_BRIDGE_ID_BOTRIGHT, ani);

	//Under middle
	CSprites::GetInstance()->Add(TEXTURE_BRIDGE_ID_BOTMID, 16, 16, 31, 31, texture->Get(TEXTURE_BRIDGE_ID));
	ani = new CAnimation(20);
	ani->Add(TEXTURE_BRIDGE_ID_BOTMID);
	CAnimations::GetInstance()->Add(TEXTURE_BRIDGE_ID_BOTMID, ani);

	//Top left
	CSprites::GetInstance()->Add(TEXTURE_BRIDGE_ID_TOPLEFT, 0, 0, 15, 15, texture->Get(TEXTURE_BRIDGE_ID));
	ani = new CAnimation(20);
	ani->Add(TEXTURE_BRIDGE_ID_TOPLEFT);
	CAnimations::GetInstance()->Add(TEXTURE_BRIDGE_ID_TOPLEFT, ani);

	//Top right
	CSprites::GetInstance()->Add(TEXTURE_BRIDGE_ID_TOPRIGHT, 0, 16, 15, 31, texture->Get(TEXTURE_BRIDGE_ID));
	ani = new CAnimation(20);
	ani->Add(TEXTURE_BRIDGE_ID_TOPRIGHT);
	CAnimations::GetInstance()->Add(TEXTURE_BRIDGE_ID_TOPRIGHT, ani);

}

void CBridge::Render()
{
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 8; j++) {
			Tiles[i][j]->Render();
		}
}

void CBridge::OnCollisionWith(LPCOLLISIONEVENT e)
{
}
