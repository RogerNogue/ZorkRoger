#pragma once
#include "Entity.h"
class Room :
	public Entity
{
public:
	Room(type tp, string namep, string descriptionp, vector<Entity*> containsp);
	~Room();
};

