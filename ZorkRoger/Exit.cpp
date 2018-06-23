#include "Exit.h"


Exit::Exit(string namep, string descriptionp, vector<Entity*> containsp, directionExit dirp, Room* sourcep, Room* destinationp, bool key) :
	Entity(namep, descriptionp, containsp)
{
	//the container can be used as requirement to pass
	t = EXIT;
	dir = dirp;
	source = sourcep;
	destination = destinationp;
	requiresKey = key;
}


Exit::~Exit()
{
}
