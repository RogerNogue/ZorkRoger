#include "Exit.h"

Exit::Exit(string namep, string descriptionp, vector<Entity*> containsp, directionExit dirp, Room* sourcep, Room* destinationp, direction sourceDirp, direction destinationDirp, string description2p, bool key) :
	Entity(namep, descriptionp, containsp)
{
	t = EXIT;
	dir = dirp;
	source = sourcep;
	destination = destinationp;
	description2 = description2p;
	requiresKey = key;
	sourceDir = sourceDirp;
	destinationDir = destinationDirp;
}


Exit::~Exit()
{
}
