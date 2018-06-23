#pragma once
#include "Creature.h"
class NPC :
	public Creature
{
public:
	NPC(string namep, string descriptionp, vector<Entity*> containsp, Room* locationp);
	~NPC();
};

