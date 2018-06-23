#include "Creature.h"



Creature::Creature(type tp, string namep, string descriptionp, vector<Entity*> containsp, Room* locationp) :
	Entity(tp, namep, descriptionp, containsp)
{
	location = locationp;
}


Creature::~Creature()
{
}
