#pragma once
#include "InputHandler.h"
class CBillInputHandler: public CInputHandler
{
protected:
	void onKeyClick(int keyCode);
	void onKeyPress(int keyCode);
	void onKeyRelease(int keyCode);
public:
	CBillInputHandler() : CInputHandler() { KeyToListen.push_back(DIK_LEFTARROW); KeyToListen.push_back(DIK_RIGHTARROW); KeyToListen.push_back(DIK_S); KeyToListen.push_back(DIK_0); KeyToListen.push_back(DIK_1); }
	void HandleInput(CInput* input);
};

