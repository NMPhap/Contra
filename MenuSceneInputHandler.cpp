#include "MenuSceneInputHandler.h"
extern int done;
void CMenuSceneInputHandler::onKeyClick(int keyCode)
{
}

void CMenuSceneInputHandler::onKeyPress(int keyCode)
{
	if (keyCode == DIK_UPARROW)
		scene->SetCusorPos(25.0f, 110.0f);
	if (keyCode == DIK_DOWNARROW)
		scene->SetCusorPos(25.0f, 95.0f);
	if (keyCode == DIK_RETURN)
	{
		D3DXVECTOR2 cursorPos;
		scene->GetCursorPos(cursorPos.x, cursorPos.y);
		if (cursorPos.y == 110.0f)
			CGame::GetInstance()->InitiateSwitchScene(1);
		else
			done = 1;
	}

}

void CMenuSceneInputHandler::onKeyRelease(int keyCode)
{
}

void CMenuSceneInputHandler::HandleInput(CInput* input)
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
