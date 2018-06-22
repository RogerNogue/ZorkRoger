#include "World.h"




World::World()
{
	//Rooms creation

	//exits creation

	//Player creation

	//NPCs creation

	//Items creation

	//placing everything into the world array
}


World::~World()
{
}

void World::update(string inp) {
	Parser::Parse(inp, player);
}