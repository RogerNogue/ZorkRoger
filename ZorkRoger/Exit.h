#pragma once
#include "inclusions.h"
#include "Entity.h"
#include "Room.h"

class Exit :
	public Entity
{
public:
	Exit(string namep, string descriptionp, vector<Entity*> containsp, directionExit dirp, Room* sourcep,
		Room* destinationp, direction sourceDirp, direction destinationDirp, string description2p, bool key);
	~Exit();
	directionExit dir;
	Room* source;
	Room* destination;
	direction sourceDir;
	direction destinationDir;
	string description2;
	bool requiresKey;
};

