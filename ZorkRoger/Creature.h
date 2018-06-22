#pragma once
#include "inclusions.h"
#include "Entity.h"
#include "Room.h"
class Creature :
	public Entity
{
public:
	Creature();
	~Creature();

	Room* location;
};

