#include "Room.h"



Room::Room(string namep, string descriptionp, vector<Entity*> containsp):
	Entity(namep, descriptionp, containsp)
{
	t = ROOM;
}


Room::~Room()
{
}
