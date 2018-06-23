#pragma once
#include "Entity.h"
class Item :
	public Entity
{
public:
	Item(type tp, string namep, string descriptionp, vector<Entity*> containsp, bool hard);
	~Item();

	bool hardToSee;
};

