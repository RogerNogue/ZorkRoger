#pragma once
#include "Entity.h"
class Item :
	public Entity
{
public:
	Item(string namep, string descriptionp, vector<Entity*> containsp, bool hard, bool lights, bool canBeUsedp, string descriptionUsedp, bool canBeGrabbedp);
	~Item();

	string descriptionUsed;
	bool hardToSee;
	bool lights;
	bool used;
	bool canBeGrabbed;
	bool canBeUsed;
};

