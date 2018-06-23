#include "NPC.h"



NPC::NPC(string namep, string descriptionp, vector<Entity*> containsp, Room* locationp) :
	Creature(namep, descriptionp, containsp, locationp)
{
	t = NPCE;
}


NPC::~NPC()
{
}
