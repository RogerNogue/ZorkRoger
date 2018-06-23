#include "Exit.h"


Exit::Exit(type tp, string namep, string descriptionp, vector<Entity*> containsp, directionExit dirp, Room* sourcep, Room* destinationp) :
	Entity(tp, namep, descriptionp, containsp)
{
	dir = dirp;
	source = sourcep;
	destination = destinationp;
}


Exit::~Exit()
{
}
