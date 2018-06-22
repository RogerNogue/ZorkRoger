#pragma once

#include "Entity.h"
#include <vector>

using namespace std;
class World
{
public:
	World();
	~World();

	vector<Entity*> elements;
};

