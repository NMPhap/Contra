#include "QuadTree.h"
#include "Utils.h"

int TreeNode::NodeCount = 0;

void TreeNode::AddObjectToNode(LPGAMEOBJECT object)
{
	if (IsIntersac(object, this))
		return;
	if (child == NULL)
	{
		if (gameObjects == NULL)
			gameObjects = new vector<LPGAMEOBJECT>();
		gameObjects->push_back(object);
		return;
	}

}

void TreeNode::Split()
{
	if (child != NULL)
	{
		for (int i = 0; i < child->size(); i++)
			child->at(i)->Split();
	}
	else
	{

		LPTREENODE node1 = new TreeNode(x, y, width / 2, height / 2, this);
		LPTREENODE node2 = new TreeNode(x + width / 2, y, width / 2, height / 2, this);
		LPTREENODE node3 = new TreeNode(x, y + height / 2, width / 2, height / 2, this);
		LPTREENODE node4 = new TreeNode(x + width / 2, y + height / 2, width / 2, height / 2, this);
		child = new vector<LPTREENODE>();
		child->push_back(node1);
		child->push_back(node2);
		child->push_back(node3);
		child->push_back(node4);
		if (gameObjects == NULL)
			return;
		for (int i = 0; i < gameObjects->size(); i++)
		{
			float left, top, right, down;
			LPGAMEOBJECT temp = gameObjects->at(i);
			temp->GetBoundingBox(left, top, right, down);
			if ((left < x + width / 2 && right > x) || (top < y + height / 2 && down > y))
				node1->AddObjectToNode(temp);
			if ((left < x + width && right > x + width / 2) || (top < y + height / 2 && down > y))
				node2->AddObjectToNode(temp);
			if ((left < x + width / 2 && right > x) || (top < y + height && down > y + height / 2))
				node3->AddObjectToNode(temp);
			if ((left < x + width && right > x / 2) || (top < y + height && down > y + height / 2))
				node4->AddObjectToNode(temp);
		}
	}

}

vector<LPTREENODE>* TreeNode::IsObjectInside(LPGAMEOBJECT object)
{
	if (gameObjects != NULL)
	{
		for (int i = 0; i < gameObjects->size(); i++)
			if (gameObjects->at(i) == object)
			{
				vector<LPTREENODE>* a;
				a->push_back(this);
				return a;
			}
		return NULL;
	}
	if (child == NULL)
		return NULL;
	vector<LPTREENODE>* a;
	for (int i = 0; i < child->size(); i++)
	{
		vector<LPTREENODE>* node = child->at(i)->IsObjectInside(object);
		if (node != NULL)
			a->insert(a->end(), node->begin(), node->end());
	}
	if (a->size() > 0)
		return a;
	return NULL;
}