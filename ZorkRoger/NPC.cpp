#include "NPC.h"



NPC::NPC(type tp, string namep, string descriptionp, vector<Entity*> containsp, Room* locationp) :
	Creature(tp, namep, descriptionp, containsp, locationp)
{
}


NPC::~NPC()
{
}
