#pragma once
#include "Creature.h"
class Player :
	public Creature
{
public:
	Player(string namep, string descriptionp, vector<Entity*> containsp, Room* locationp);
	~Player();

	void look(action a);
	void inventory();
	void go(action a);
	void grab(action a);
	void drop(action a);
	void use(action a);
	void talk(action a);
	void put(action a);
};

