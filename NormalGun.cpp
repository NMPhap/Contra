#include "NormalGun.h"
#include "Bill.h"
#include "BillBullet.h"
#include "FireBullet.h"
extern CBill* bill;
void CNormalGun::Shoot()
{
	float x = bill->GetX();
	float y = bill->GetY();
	if (GetTickCount64() - lastShotTime < NORMAL_GUN_RECOIL_TIME)
		return;
	lastShotTime = GetTickCount64();
	if (bill->faceDirection == 1)
		if (bill->GetState() == BILL_STATE_LAYDOWN)
			CGame::GetInstance()->gameObjects.push_back(new CBillBullet(x + 15.0f, y + 0.0f, 0.5f, 0.0f));
		else 
			if (bill->GetState() == BILL_STATE_RUN)//Run shot
			{
				if (bill->shotDirection == 1)//Run shot up
					CGame::GetInstance()->gameObjects.push_back(new CBillBullet(x + 5.0f, y - 10.0f, 0.5f, -0.5f));
				if (bill->shotDirection == -1)
					CGame::GetInstance()->gameObjects.push_back(new CBillBullet(x + 8.0f, y + 6.0f, 0.5f, 0.5f));
				if (bill->shotDirection == 0)
					CGame::GetInstance()->gameObjects.push_back(new CBillBullet(x + 8.0f, y - 6.0f, 0.5f, 0.0f));
			}
			else
				if (bill->shotDirection == 1)
					CGame::GetInstance()->gameObjects.push_back(new CBillBullet(x + 5.0f, y - 15.0f, 0, -0.5f));
				else
					CGame::GetInstance()->gameObjects.push_back(new CBillBullet(x + 8.0f, y - 6.0f, 0.5f, 0.0f));
	else
		if(bill->GetState() == BILL_STATE_LAYDOWN)
			CGame::GetInstance()->gameObjects.push_back(new CBillBullet(x - 15.0f, y + 0.0f, -0.5f, 0.0f));
		else
			if (bill->GetState() == BILL_STATE_RUN)
			{
				if (bill->shotDirection == 1)//run shot up
					CGame::GetInstance()->gameObjects.push_back(new CBillBullet(x - 3.0f, y - 10.0f, -0.5f, -0.5f));
				if (bill->shotDirection == -1) // run shot down
					CGame::GetInstance()->gameObjects.push_back(new CBillBullet(x - 10.0f, y + 6.0f, -0.5f, 0.5f));
				if (bill->shotDirection == 0)
					CGame::GetInstance()->gameObjects.push_back(new CBillBullet(x - 8.0f, y - 6.0f, -0.5f, 0.0f));
			}
			else
				if (bill->shotDirection == 1)
					CGame::GetInstance()->gameObjects.push_back(new CBillBullet(x - 5.0f, y - 15.0f, 0, -0.5f));
				else
					CGame::GetInstance()->gameObjects.push_back(new CBillBullet(x - 8.0f, y - 6.0f, -0.5f, 0.0f));
}	