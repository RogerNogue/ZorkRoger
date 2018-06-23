#pragma once
#include "Entity.h"
class Room :
	public Entity
{
public:
	Room(string namep, string descriptionp, vector<Entity*> containsp);
	~Room();
};

