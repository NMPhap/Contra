#include "ContraGame.h"

#include "Bill.h"

#define ID_TEX_BILL 10
#define TEXTURE_PATH_BILL L"/Resources/Images/bill_animation.png"
#define BACKGROUND_COLOR D3DXCOLOR(200.0f/255, 200.0f/255, 255.0f/255, 0.0f)

extern CBill* bill;

void CContraGame::LoadResources()
{
	CTextures* textures = CTextures::GetInstance();

	textures->Add(ID_TEX_BILL, TEXTURE_PATH_BILL);

	CSprites* sprites = CSprites::GetInstance();
	CAnimations* animations = CAnimations::GetInstance();

	LPTEXTURE texBill = textures->Get(ID_TEX_BILL);
	// NORMAL RIGHT & LEFT
	sprites->Add(10001, 1, 30, 25, 65, texBill);
	sprites->Add(10002, 26, 30, 50, 65, texBill);

	sprites->Add(10003, 480, 30, 504, 65, texBill);
	sprites->Add(10004, 455, 30, 479, 65, texBill);


	// RUNNING RIGHT 
	sprites->Add(10011, 2, 66, 23, 102, texBill);
	sprites->Add(10012, 24, 66, 41, 102, texBill);
	sprites->Add(10013, 42, 66, 61, 102, texBill);
	sprites->Add(10014, 62, 66, 83, 102, texBill);
	sprites->Add(10015, 84, 66, 101, 102, texBill);
	sprites->Add(10016, 102, 66, 122, 102, texBill);


	// RUNNING LEFT
	sprites->Add(10021, 482, 66, 503, 102, texBill);
	sprites->Add(10022, 464, 66, 481, 102, texBill);
	sprites->Add(10023, 444, 66, 463, 102, texBill);
	sprites->Add(10024, 422, 66, 443, 102, texBill);
	sprites->Add(10025, 404, 66, 421, 102, texBill);
	sprites->Add(10026, 383, 66, 403, 102, texBill);

	// JUMP WALK RIGHT & LEFT 
	sprites->Add(10031, 117, 44, 134, 65, texBill);
	sprites->Add(10032, 135, 44, 155, 65, texBill);
	sprites->Add(10033, 156, 44, 173, 65, texBill);
	sprites->Add(10034, 174, 44, 194, 65, texBill);

	sprites->Add(10035, 371, 44, 388, 65, texBill);
	sprites->Add(10036, 350, 44, 370, 65, texBill);
	sprites->Add(10037, 332, 44, 349, 65, texBill);
	sprites->Add(10038, 311, 44, 331, 65, texBill);

	// LAY RIGHT/LEFT
	sprites->Add(10041, 83, 48, 116, 65, texBill);
	sprites->Add(10042, 389, 48, 422, 65, texBill);

	LPANIMATION ani;

	ani = new CAnimation(100);
	ani->Add(10001);
	ani->Add(10002);
	animations->Add(ID_ANI_BILL_IDLE_RIGHT, ani);

	ani = new CAnimation(100);
	ani->Add(10003);
	ani->Add(10004);
	animations->Add(ID_ANI_BILL_IDLE_LEFT, ani);

	ani = new CAnimation(100);
	ani->Add(10011);
	ani->Add(10012);
	ani->Add(10013);
	ani->Add(10014);
	ani->Add(10015);
	ani->Add(10016);
	animations->Add(ID_ANI_BILL_WALKING_RIGHT, ani);

	ani = new CAnimation(100);
	ani->Add(10021);
	ani->Add(10022);
	ani->Add(10023);
	ani->Add(10024);
	ani->Add(10025);
	ani->Add(10026);
	animations->Add(ID_ANI_BILL_WALKING_LEFT, ani);

	ani = new CAnimation(100);
	ani->Add(10031);
	ani->Add(10032);
	ani->Add(10033);
	ani->Add(10034);
	animations->Add(ID_ANI_BILL_JUMP_WALK_RIGHT, ani);

	ani = new CAnimation(100);
	ani->Add(10035);
	ani->Add(10036);
	ani->Add(10037);
	ani->Add(10038);
	animations->Add(ID_ANI_BILL_JUMP_WALK_LEFT, ani);

	ani = new CAnimation(100);
	ani->Add(10041);
	animations->Add(ID_ANI_BILL_LAY_RIGHT, ani);

	ani = new CAnimation(100);
	ani->Add(10042);
	animations->Add(ID_ANI_BILL_LAY_LEFT, ani);

	bill = new CBill(200.0f, 10.0f);
	objects.push_back(bill);
}

void CContraGame::Update(DWORD dt)
{
	for (int i = 0; i < (int)objects.size(); i++)
	{
		objects[i]->Update(dt);
	}
}

void CContraGame::Render()
{
	pD3DDevice->ClearRenderTargetView(pRenderTargetView, BACKGROUND_COLOR);

	ID3DX10Sprite* spriteHandler = this->GetSpriteHandler();
	spriteHandler->Begin(D3DX10_SPRITE_SORT_TEXTURE);

	for (int i = 0; i < (int)objects.size(); i++)
	{
		objects[i]->Render();
	}

	spriteHandler->End();
	pSwapChain->Present(0, 0);

}

void CContraGame::Run()
{
	MSG msg;
	int done = 0;
	ULONGLONG frameStart = GetTickCount64();
	ULONGLONG tickPerFrame = 1000 / MAX_FRAME_RATE;

	while (!done)
	{
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			if (msg.message == WM_QUIT) done = 1;

			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}

		ULONGLONG now = GetTickCount64();

		// dt: the time between (beginning of last frame) and now
		// this frame: the frame we are about to render
		ULONGLONG dt = now - frameStart;

		if (dt >= tickPerFrame)
		{
			frameStart = now;
			Update((DWORD)dt);
			GetInstance()->ProcessKeyboard();
			Render();
		}
		else
			Sleep((DWORD)(tickPerFrame - dt));
	}
}