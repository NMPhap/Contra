#pragma once
#include "InputHandler.h"
class CBillInputHandler: public CInputHandler
{
protected:
	void onKeyClick(int keyCode);
	void onKeyPress(int keyCode);
	void onKeyRelease(int keyCode);
public:
	CBillInputHandler() : CInputHandler();
	void HandleInput(CInput* input);
};

