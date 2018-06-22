#pragma once
#include <string>
#include <vector>
using namespace std;
class Entity
{
public:
	Entity();
	~Entity();
	virtual void Update();
	
	enum type {
		PLAYER, NPC, EXIT, ROOM, ITEM
	};
	
	string name;
	string description;
	vector<Entity*> contains;
	
};

