#pragma once
#include "Creature.h"
class Player :
	public Creature
{
public:
	Player(type tp, string namep, string descriptionp, vector<Entity*> containsp, Room* locationp);
	~Player();
};

