#include "HIddenAirCraft.h"
#include "ObjectExplosion.h"
#include "BAirCraft.h"
#include "LAirCraft.h"
#include "FAirCraft.h"
#include "MAirCraft.h"
#include "SAirCraft.h"
#include "Bill.h"
extern CBill* bill;


void CHiddenAirCraft::GetHit(int damage)
{
	Deleted = 1;
	((LPPLAYSCENE)CGame::GetInstance()->GetCurrentScene())->AddObjectToQuadTree(new CObjectExplosion(x, y));
	switch (powerup)
	{
	case 1:
		((LPPLAYSCENE)CGame::GetInstance()->GetCurrentScene())->AddObject(new CMAirCraft(x, y));
		((LPPLAYSCENE)CGame::GetInstance()->GetCurrentScene())->AddObjectToQuadTree(new CMAirCraft(x, y));
		break;
	case 2:
		((LPPLAYSCENE)CGame::GetInstance()->GetCurrentScene())->AddObject(new CBAirCraft(x, y));
		((LPPLAYSCENE)CGame::GetInstance()->GetCurrentScene())->AddObjectToQuadTree(new CBAirCraft(x, y));
		break;

	case 3:
		((LPPLAYSCENE)CGame::GetInstance()->GetCurrentScene())->AddObject(new CLAirCraft(x, y));
		((LPPLAYSCENE)CGame::GetInstance()->GetCurrentScene())->AddObjectToQuadTree(new CLAirCraft(x, y));

		break;

	case 4:
		((LPPLAYSCENE)CGame::GetInstance()->GetCurrentScene())->AddObject(new CFAirCraft(x, y));
		((LPPLAYSCENE)CGame::GetInstance()->GetCurrentScene())->AddObjectToQuadTree(new CFAirCraft(x, y));
		break;

	case 5:
		((LPPLAYSCENE)CGame::GetInstance()->GetCurrentScene())->AddObject(new CSAirCraft(x, y));
		((LPPLAYSCENE)CGame::GetInstance()->GetCurrentScene())->AddObjectToQuadTree(new CSAirCraft(x, y));

		break;

	default:
		break;
	}
}
