#pragma once
#include "Creature.h"
class Player :
	public Creature
{
public:
	Player(string namep, string descriptionp, vector<Entity*> containsp, Room* locationp);
	~Player();
};

