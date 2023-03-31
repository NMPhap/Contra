#include "BillInputHandler.h"
#include "Bill.h"
#include "Bullet.h"
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
	if (bill->GetState() != BILL_STATE_JUMP)
	{
		if (keyCode == DIK_RIGHTARROW)
		{
			bill->faceDirection = 1;
			if (bill->GetState() == BILL_STATE_SWIM)
				bill->SetState(BILL_STATE_SWIM_MOVE);
			else
				bill->SetState(BILL_STATE_RUN);
		}
		if (keyCode == DIK_LEFTARROW)
		{
			bill->faceDirection = -1;
			if (bill->GetState() == BILL_STATE_SWIM || bill->GetState() == BILL_STATE_SWIM_MOVE)
				bill->SetState(BILL_STATE_SWIM_MOVE);
			else
				bill->SetState(BILL_STATE_RUN);
		}
		if (keyCode == DIK_S && bill->GetState() != BILL_STATE_JUMP)
			bill->SetState(BILL_STATE_JUMP);
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

	}
	if (keyCode == DIK_A)
		bill->isShotting = true;
}

void CBillInputHandler::onKeyRelease(int keyCode)
{
	if (bill->GetState() != BILL_STATE_JUMP)
	{
		if (keyCode == DIK_RIGHTARROW || keyCode == DIK_LEFTARROW)
			if (bill->GetState() != BILL_STATE_SWIM && bill->GetState() != BILL_STATE_SWIM_MOVE)
				bill->SetState(BILL_STATE_IDLE);
			else
				bill->SetState(BILL_STATE_SWIM);
	}
	if (keyCode == DIK_A)
		bill->isShotting = false;
	if (keyCode == DIK_UPARROW)
		bill->shotDirection = 0;
	if (keyCode == DIK_DOWNARROW)
		bill->shotDirection = 0;
}