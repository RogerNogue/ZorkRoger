#pragma once
#include "Entity.h"
#include "item.h"

class Room :
	public Entity
{
public:
	Room(string namep, string descriptionp, vector<Entity*> containsp);
	~Room();

	void addElement(Entity* e);
	void printAllElements(bool light);
	Entity* printSpecificElement(string name, bool light);
	Entity* grabItem(string n);
	Entity* talkTo(string n);
	Room* move(direction dir, bool key);
	bool put(Entity* a, string b);
};

