#pragma once

#include "Entity.h"
#include "inclusions.h"
#include "Room.h"
#include "Player.h"
#include "NPC.h"
#include "Item.h"
#include "Exit.h"
#include "Parser.h"

using namespace std;
class World
{
public:
	World();
	~World();
	void update(string inp);
	void interpret(action a);

	int totalCommands;
	vector<Entity*> elements;
	Player* player;
};

