#pragma once
#include "Bullet.h"
class CGun
{
protected:
	CBullet* bullet;
	int recoil_time;
public:
	virtual void Shoot() { return; };

};

