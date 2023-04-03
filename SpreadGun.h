#pragma once
#include "Gun.h"
class CSpreadGun: CGun
{
	ULONG lastShotTime;
	static float Direction[5];
public:
	void Shoot();
};

