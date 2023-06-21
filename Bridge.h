#pragma once
#include "GameObject.h"
#include "AssetID.h"
#include "BridgePart.h"
#include <random>

class CBridge  : public CGameObject
{
public:
	LPGAMEOBJECT Tiles[2][8];
	int _matrixIndex[2][4 * 2] =
	{
		{ 3, 0, 3, 0, 3, 0, 3, 0 },
		{ 1, 4, 4, 4, 4, 4, 4, 5 },
	};
	int GenerateRandomID() {
		std::random_device rd;
		std::mt19937 gen(rd());
		std::uniform_int_distribution<int> dis(100, 999);
		return dis(gen);
	}
	CBridge(float x, float y) : CGameObject(x,y) {
		float height = 0;

			for (int i = 0; i < 2; i++) {
				float width = 0;
				for (int j = 0; j < 8; j++) {
					int k = _matrixIndex[i][j];
					int wave = -1;
					if (j <= 1)
						wave = 1;
					else if (j <= 3)
						wave = 2;
					else if (j <= 5)
						wave = 3;
					else
						wave = 4;

					switch (k)
					{
					case 0:
						Tiles[i][j] = new CBridgePart(x + width, y + height, TEXTURE_BRIDGE_ID_TOPRIGHT, wave, this);
						width += 16.0f;
						break;
					case 1:
						Tiles[i][j] = new CBridgePart(x + width, y + height, TEXTURE_BRIDGE_ID_BOTLEFT, wave, this);
						width += 16.0f;
						break;
					case 3:
						Tiles[i][j] = new CBridgePart(x + width, y + height, TEXTURE_BRIDGE_ID_TOPLEFT, wave, this);
						width += 16.0f;
						break;
					case 4:
						Tiles[i][j] = new CBridgePart(x + width, y + height, TEXTURE_BRIDGE_ID_BOTMID, wave, this);
						width += 16.0f;
						break;
					case 5:
						Tiles[i][j] = new CBridgePart(x + width, y + height, TEXTURE_BRIDGE_ID_BOTRIGHT, wave, this);
						width += 16.0f;
						break;
					default:
						break;
					}
				}
				height -= 16.0f;
			}
	}
	static void LoadAnimation();
	void Update(DWORD dt, vector<LPGAMEOBJECT>* gameObject);
	void Render();
	void OnCollisionWith(LPCOLLISIONEVENT e);
	void SetState(int state) {
		for (int i = 0; i < 2; i++)
			for (int j = 0; j < 8; j++) {
				Tiles[i][j]->SetDieStart(GetTickCount64());
				Tiles[i][j]->SetState(state);
			}
	}
	void GetBoundingBox(float& left, float& top, float& right, float& bottom)
	{
		left = x;
		bottom = y - 5 - 16;
		right = x + 16 * 8;
		top = y - 5;
	}
};

