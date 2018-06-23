#include "Creature.h"



Creature::Creature(string namep, string descriptionp, vector<Entity*> containsp, Room* locationp) :
	Entity(namep, descriptionp, containsp)
{
	location = locationp;
}


Creature::~Creature()
{
}
