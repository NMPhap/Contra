#pragma once
#include "Game.h"
#include "GameObject.h"
class CContraGame : public CGame
{
private:
	vector<LPGAMEOBJECT> objects;
public:
	virtual void LoadResources();
	void Update(DWORD);
	void Render();
	virtual void Run();
};

