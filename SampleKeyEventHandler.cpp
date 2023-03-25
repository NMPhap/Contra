#include "SampleKeyEventHandler.h"

#include "debug.h"
#include "Game.h"

#include "Bill.h"

extern CBill* bill;

void CSampleKeyHandler::KeyState(BYTE* state)
{
	CGame* game = CGame::GetInstance();

	if (game->IsKeyDown(DIK_RIGHT))
	{
		bill->SetState(BILL_STATE_WALKING_RIGHT);
	}
	else if (game->IsKeyDown(DIK_LEFT))
	{
		bill->SetState(BILL_STATE_WALKING_LEFT);
	}
	else
		bill->SetState(BILL_STATE_IDLE);

	// Sitting state has higher priority 
	if (game->IsKeyDown(DIK_DOWN))
	{
		bill->SetState(BILL_STATE_LAY);
	}

}

void CSampleKeyHandler::OnKeyDown(int KeyCode)
{
	DebugOut(L"[INFO] KeyDown: %d\n", KeyCode);
	switch (KeyCode)
	{
	case DIK_S:
		bill->SetState(BILL_STATE_JUMP);
		break;
	}
}

void CSampleKeyHandler::OnKeyUp(int KeyCode)
{
	DebugOut(L"[INFO] KeyUp: %d\n", KeyCode);
	switch (KeyCode)
	{
	case DIK_S:
		bill->SetState(BILL_STATE_RELEASE_JUMP);
		break;
	case DIK_DOWN:
		bill->SetState(BILL_STATE_LAY_RELEASE);
		break;
	}
}


