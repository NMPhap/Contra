#include "GameObject.h"
#include "Sprite.h"
#include "sprites.h"
#include "Animation.h"
#include "Animations.h"
#include "Texture.h"
#include "Textures.h"
#include "Game.h"
#define ID_BULLET_TEXTURE 2
#define TEXTURE_BULET_PATH  L"./Resources/Images/Bullets.png"
#define ID_ANI_BULLET_NORMAL 1000
#define ID_ANI_BULLET_L 1001
#define ID_ANI_BULLET_F 1002
#define ID_ANI_BULLET_S 1003
#define ID_ANI_BULLET_M 1004

#define RECOID_TIME 100

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
	void Update(DWORD dt) {
		x += vx * dt;
		y += vy * dt;

		//Delete object if 
		if (x < 0 || y < 0)
			return;
		CGame* game = CGame::GetInstance();
		if (x > game->GetBackBufferWidth())
		{
			vector<LPGAMEOBJECT> gameObjects = CGame::GetInstance()->gameObjects;
			vector<LPGAMEOBJECT>::iterator i = std::find(gameObjects.begin(), gameObjects.end(), this);
			gameObjects.erase(i);
		}
	}
	void Render() { 
		if (bulletAnimation != NULL)
			bulletAnimation->Render(x, y);
	}
	static void LoadAnimation()
	{
		return;
	}
};