#pragma once
#include "inclusions.h"
#include "Entity.h"
#include "Room.h"
class Creature :
	public Entity
{
public:
	Creature(type tp, string namep, string descriptionp, vector<Entity*> containsp, Room* locationp);
	~Creature();

	Room* location;
};

