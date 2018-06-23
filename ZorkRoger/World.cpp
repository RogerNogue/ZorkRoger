#include "World.h"




World::World()
{
	//Rooms creation
	Room* graveyardOutside();

	Room* graveyardEntrance();

	Room* graveyardEntrance();

	Room* sanctumEntrance();

	Room* sanctum();

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