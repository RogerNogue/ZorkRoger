#pragma once
#include "inclusions.h"
using namespace std;
class Entity
{
public:
	Entity();
	~Entity();
	virtual void Update();
	
	string name;
	string description;
	vector<Entity*> contains;
	
};

