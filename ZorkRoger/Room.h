#pragma once
#include "Entity.h"

class Room :
	public Entity
{
public:
	Room(string namep, string descriptionp, vector<Entity*> containsp);
	~Room();

	void addElement(Entity* e);
	void printAllElements();
	void printSpecificElement(string name);
};

