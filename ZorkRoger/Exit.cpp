#include "Exit.h"


Exit::Exit(string namep, string descriptionp, vector<Entity*> containsp, directionExit dirp, Room* sourcep, Room* destinationp, string description2p, bool key) :
	Entity(namep, descriptionp, containsp)
{
	//the container can be used as requirement to pass
	t = EXIT;
	dir = dirp;
	source = sourcep;
	destination = destinationp;
	description2 = description2p;
	requiresKey = key;
}


Exit::~Exit()
{
}
