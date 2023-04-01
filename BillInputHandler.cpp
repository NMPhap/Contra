#include "BillInputHandler.h"
#include "Bill.h"
#include "Bullet.h"
#include "NormalGun.h"
#include "CircularGun.h"
extern CBill* bill;
void CBillInputHandler::HandleInput(CInput* input)
{
	switch (input->GetType())
	{
	case KEY_CLICK:
		onKeyClick(input->GetInput());
		break;
	case KEY_DOWN:
		onKeyPress(input->GetInput());
		break;
	case KEY_UP:
		onKeyRelease(input->GetInput());
		break;
	default:
		break;
	}
}

void CBillInputHandler::onKeyClick(int keyCode)
{
	if (keyCode == DIK_RIGHTARROW)
	{
		bill->SetFaceDirection(1);
		bill->SetSpeedX(BILL_RUN_SPEED);
		if (bill->GetState() == BILL_STATE_JUMP)
			return;
		if(bill->GetState() != BILL_STATE_LAYDOWN)
			if (bill->GetState() == BILL_STATE_SWIM || bill->GetState() == BILL_STATE_SWIM_MOVE)
				bill->SetState(BILL_STATE_SWIM_MOVE);
			else
				bill->SetState(BILL_STATE_RUN);
		return;
	}
	if (keyCode == DIK_LEFTARROW)
	{
		bill->SetFaceDirection(-1);
		bill->SetSpeedX(-BILL_RUN_SPEED);
		if (bill->GetState() == BILL_STATE_JUMP)
			return;
		if (bill->GetState() != BILL_STATE_LAYDOWN)
			if (bill->GetState() == BILL_STATE_SWIM || bill->GetState() == BILL_STATE_SWIM_MOVE)
				bill->SetState(BILL_STATE_SWIM_MOVE);
			else
				bill->SetState(BILL_STATE_RUN);
		return;
	}
	if (keyCode == DIK_S && bill->GetState() != BILL_STATE_JUMP)
	{
		bill->SetState(BILL_STATE_JUMP);
		return;
	}
	if (keyCode == DIK_0)
	{
		bill->SetGun(new CNormalGun());
		return;
	}
	if (keyCode == DIK_1)
	{
		bill->SetGun(new CCircularGun());
		return;
	}
}

void CBillInputHandler::onKeyPress(int keyCode)
{
	if (keyCode == DIK_UPARROW)
		bill->shotDirection = 1;
	if (keyCode == DIK_DOWNARROW && bill->GetState() != BILL_STATE_IDLE)
		bill->shotDirection = -1;
	if (keyCode == DIK_X)
	{
		if(bill->faceDirection == 1)
			CAnimations::GetInstance()->Get(ID_ANI_BILL_SWIMMING_RIGHT)->SetStartAnimation(CAnimations::GetInstance()->Get(ID_ANI_BILL_SWIMMING_START));
		else
			CAnimations::GetInstance()->Get(ID_ANI_BILL_SWIMMING_LEFT)->SetStartAnimation(CAnimations::GetInstance()->Get(ID_ANI_BILL_SWIMMING_START));
		bill->SetState(BILL_STATE_SWIM);
		return;

	}
	if (keyCode == DIK_A)
		bill->isShotting = true;
	if (keyCode == DIK_Z)
		bill->SetState(BILL_STATE_LAYDOWN);
}

void CBillInputHandler::onKeyRelease(int keyCode)
{
	if (bill->GetState() != BILL_STATE_JUMP)
	{
		if (keyCode == DIK_RIGHTARROW || keyCode == DIK_LEFTARROW)
		{
			bill->SetSpeedX(0.0f);
			if (bill->GetState() == BILL_STATE_RUN)
				bill->SetState(BILL_STATE_IDLE);
		}
	}
	if (keyCode == DIK_A)
		bill->isShotting = false;
	if (keyCode == DIK_UPARROW)
		bill->shotDirection = 0;
	if (keyCode == DIK_DOWNARROW)
		bill->shotDirection = 0;
	if (keyCode == DIK_Z)
		bill->SetState(BILL_STATE_IDLE);
}