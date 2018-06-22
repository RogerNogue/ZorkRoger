#pragma once
#include "Entity.h"
#include "Room.h"
class Exit :
	public Entity
{
public:
	Exit();
	~Exit();

	enum direction {
		N, S, E, W
	};
	Room* source;
	Room* destination;
};

