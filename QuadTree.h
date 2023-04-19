#pragma once
#include "GameObject.h"
#include <map>
class TreeNode;
typedef TreeNode* LPTREENODE;

class TreeNode
{
private:
	int id;
	float x;
	float y;
	float width;
	float height;
	static int NodeCount;
	LPTREENODE parentNode;
	vector<LPTREENODE>* child;
	vector<LPGAMEOBJECT>* gameObjects;
public:
	TreeNode(float x, float y, float width, float height, LPTREENODE parent = NULL) {
		id = NodeCount;
		this->x = x;
		this->y = y;
		this->width = width;
		this->height = height;
		NodeCount++;
		child = NULL;
		gameObjects = NULL;
		parentNode = parent;
	}
	void Split();

	void AddObjectToNode(LPGAMEOBJECT object);
	
	vector<LPTREENODE>* IsObjectInside(LPGAMEOBJECT object);
	void GetBoundingBox(float& left, float& top, float& right, float& down)
	{
		left = x;
		top = y;
		right = x + width;
		down = y + height;
	}
};