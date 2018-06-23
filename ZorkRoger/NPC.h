#pragma once
#include "Creature.h"
class NPC :
	public Creature
{
public:
	NPC(type tp, string namep, string descriptionp, vector<Entity*> containsp, Room* locationp);
	~NPC();
};

