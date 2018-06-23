#include "Exit.h"


Exit::Exit(string namep, string descriptionp, vector<Entity*> containsp, directionExit dirp, Room* sourcep, Room* destinationp) :
	Entity(namep, descriptionp, containsp)
{
	t = EXIT;
	dir = dirp;
	source = sourcep;
	destination = destinationp;
}


Exit::~Exit()
{
}
