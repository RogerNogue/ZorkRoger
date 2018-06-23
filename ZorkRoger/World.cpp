#include "World.h"




World::World()
{
	/*
	//Rooms creation
	string name = "Starting location";
	string desc = "Looks like I'm right in front of the graveyard doors";
	Room* graveyardOutside(name, desc, vector<Entity*>);

	Room* graveyardEntrance(roomType);

	Room* graveyardEntrance(roomType);

	Room* sanctumEntrance(roomType);

	Room* sanctum(roomType);
	*/

	//exits creation
	Exit* graveyardDoor();

	Exit* graveyardPathway();

	Exit* sanctumPathway();

	Exit* sanctumPathway();

	//Player creation

	Player* p();

	//NPCs creation
	NPC* vigilante();

	//Items creation

	Item* stone();

	Item* key();

	Item* torch();

	Item* box();

	Item* paper();

	Item* tomb();

	Item* secretPrize();

	//placing everything into the world array
}


World::~World()
{
}

void World::update(string inp) {
	Parser::Parse(inp, player);
}