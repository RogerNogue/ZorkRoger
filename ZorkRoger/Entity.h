#pragma once
#include "inclusions.h"
using namespace std;
class Entity
{
public:
	Entity(type tp, string namep, string descriptionp, vector<Entity*> containsp);
	~Entity();
	virtual void Update();
	
	type t;
	string name;
	string description;
	vector<Entity*> contains;
	
};

