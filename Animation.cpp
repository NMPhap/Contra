#include "Animation.h"

void CAnimation::Add(int spriteId, DWORD time)
{
	int t = time;
	if (time == 0) t = this->defaultTime;

	LPSPRITE sprite = CSprites::GetInstance()->Get(spriteId);
	LPANIMATION_FRAME frame = new CAnimationFrame(sprite, t);
	frames.push_back(frame);
}

void CAnimation::Render(float x, float y)
{
	ULONGLONG now = GetTickCount64();
	if (this == nullptr)
		return;
	else if (startAnimation != NULL)
	{
		startAnimation->Render(x, y);
		if (startAnimation->currentFrame == -1)
		{
			startAnimation = NULL;
		}
	}
	else
	{
		DWORD t = frames[currentFrame]->GetTime();
		if (currentFrame < 0)
		{
			this->currentFrame += 1;
			lastFrameTime = now;
		}
		else if (now - lastFrameTime > t)
		{
			currentFrame++;
			lastFrameTime = now;
			if (currentFrame == frames.size())
				if (oneTimeAnimation)
				{
					currentFrame = -1;
					return;
				}
				else
					currentFrame = 0;
			//DebugOut(L"now: %d, lastFrameTime: %d, t: %d\n", now, lastFrameTime, t);
		}
		frames[currentFrame]->GetSprite()->Draw(x, y);

	}

}

