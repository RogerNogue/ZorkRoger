#pragma once
#include "inclusions.h"
#include "Entity.h"
#include "Room.h"
class Exit :
	public Entity
{
public:
	Exit();
	~Exit();

	
	Room* source;
	Room* destination;
};

