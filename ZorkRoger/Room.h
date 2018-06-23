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
	void printAllElements();
	Entity* printSpecificElement(string name);
	Entity* grabItem(string n);
};

