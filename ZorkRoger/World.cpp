#include "World.h"




World::World()
{
	string name, description;
	vector<Entity*> empty;
	//Items creation
	name = "key";
	description = "a dusty old key";
	Item* key = &Item(name, description, empty, false, false);

	vector<Entity*> stonePertenences;
	stonePertenences.push_back(key);
	name = "stone";
	description = "a suspicious wierd shaped stone";
	Item* stone = &Item(name, description, stonePertenences, false, false);

	name = "torch";
	description = "a torch that can help me see";
	Item* torch = &Item(name, description, empty, false, true);

	name = "paper";
	description = "a small paper that says \" legend says this person was rich\"";
	Item* paper = &Item(name, description, empty, false, false);
	
	vector<Entity*> boxPertenences;
	boxPertenences.push_back(paper);
	name = "box";
	description = "a little wooden box";
	Item* box = &Item(name, description, boxPertenences, false, false);

	name = "prize";
	description = "wow, a bitcoin cupon";
	Item* secretPrize = &Item(name, description, empty, true, false);

	vector<Entity*> tombPertenences;
	tombPertenences.push_back(secretPrize);
	name = "tomb";
	description = "looks like arelatively recent tomb";
	Item* tomb = &Item(name, description, tombPertenences, false, false);

	//Rooms creation
	vector<Entity*> graveyardOutsidePertenences;
	graveyardOutsidePertenences.push_back(stone);
	name = "graveyardOutside";
	description = "Looks like I'm right in front of the graveyard doors";
	Room* graveyardOutside = &Room(name, description, graveyardOutsidePertenences);

	name = "graveyardEntrance";
	description = "I'm right inside the graveyard, there is a path to get deep in the graveyard in the north";
	Room* graveyardEntrance = &Room(name, description, empty);

	name = "graveyard";
	description = "I'm deep inside of the graveyard, i can see a sanctum in the east";
	Room* graveyardCenter = &Room(name, description, empty);

	vector<Entity*> sanctumEntrancePertenences;
	sanctumEntrancePertenences.push_back(box);
	name = "sanctumEntrance";
	description = "I'm right in front of the sanctum, there's an inscription saying \"Hideo Kojima\" and a tunnel to the inside of the sanctum in the east";
	Room* sanctumEntrance = &Room(name, description, sanctumEntrancePertenences);

	vector<Entity*> sanctumPertenences;
	sanctumPertenences.push_back(tomb);
	name = "sanctum";
	description = "I'm inside the sanctum";
	Room* sanctum = &Room(name, description, sanctumPertenences);

	//exits creation
	name = "graveyardDoor";
	description = "Closed door to the graveyard";
	Exit* graveyardDoor = &Exit(name, description, empty, BOTH, graveyardOutside, graveyardEntrance, true);

	name = "graveyardPathway";
	description = "Pathway to the center of the graveyard";
	Exit* graveyardPathway = &Exit(name, description, empty, BOTH, graveyardEntrance, graveyardCenter, false);

	name = "sanctumPathway";
	description = "Pathway to the sanctum entrance";
	Exit* sanctumPathway = &Exit(name, description, empty, BOTH, graveyardCenter, sanctumEntrance, false);

	name = "sanctumTunnel";
	description = "Tunnel to the inside of the sanctum";
	Exit* sanctumTunnel = &Exit(name, description, empty, BOTH, sanctumEntrance, sanctum, false);

	//Player creation
	name = "player";
	description = "And this is you, a greedy person without principles.";
	Player* p = &Player(name, description, empty, graveyardOutside);

	vector<Entity*> vigilantePertenences;
	vigilantePertenences.push_back(torch);
	//NPCs creation
	name = "vigilante";
	description = "Looks like there is a bored vigilante here";
	NPC* vigilante = &NPC(name, description, vigilantePertenences, graveyardEntrance);

	//placing everything into the world array
}


World::~World()
{
}

void World::update(string inp) {
	Parser::Parse(inp, player);
}