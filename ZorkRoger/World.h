#pragma once

#include "Entity.h"
#include "inclusions.h"

using namespace std;
class World
{
public:
	World();
	~World();

	vector<Entity*> elements;
};

