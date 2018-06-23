#pragma once
#include "Entity.h"
class Item :
	public Entity
{
public:
	Item(string namep, string descriptionp, vector<Entity*> containsp, bool hard, bool lights);
	~Item();

	bool hardToSee;
	bool lights;
	bool used;
};

