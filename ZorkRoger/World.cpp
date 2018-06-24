#include "World.h"




World::World()
{
	string name, description;
	vector<Entity*> empty;
	//Items creation
	name = "key";
	description = "a rusty old key";
	Item* key = new Item(name, description, empty, false, false, false, "", true);
	elements.push_back(key);

	vector<Entity*> stonePertenences;
	stonePertenences.push_back(key);
	name = "stone";
	description = "a stone which is suspicious and wierd shaped";
	Item* stone = new Item(name, description, stonePertenences, false, false, false, "", false);
	elements.push_back(stone);

	name = "stick";
	description = "a useless stick";
	Item* stick = new Item(name, description, empty, false, false, false, "", true);
	elements.push_back(stick);

	name = "torch";
	description = "a torch that can help me see";
	Item* torch = new Item(name, description, empty, false, true, true, "a torch lighting the way", true);
	elements.push_back(torch);

	name = "paper";
	description = "a small paper that says \" legend says this person was rich\"";
	Item* paper = new Item(name, description, empty, false, false, false, "", true);
	elements.push_back(paper);
	
	vector<Entity*> boxPertenences;
	boxPertenences.push_back(paper);
	name = "box";
	description = "a little wooden box";
	Item* box = new Item(name, description, boxPertenences, false, false, false, "", false);
	elements.push_back(box);

	name = "prize";
	description = "a bitcoin cupon!";
	Item* secretPrize = new Item(name, description, empty, true, false, false, "", true);
	elements.push_back(secretPrize);

	vector<Entity*> tombPertenences;
	tombPertenences.push_back(secretPrize);
	name = "tomb";
	description = "a relatively recent tomb";
	Item* tomb = new Item(name, description, tombPertenences, false, false, false, "", false);
	elements.push_back(tomb);

	//Rooms creation
	vector<Entity*> graveyardOutsidePertenences;
	graveyardOutsidePertenences.push_back(stone);
	graveyardOutsidePertenences.push_back(stick);
	name = "graveyardOutside";
	description = "I'm right in front of a graveyard";
	Room* graveyardOutside = new Room(name, description, graveyardOutsidePertenences);
	elements.push_back(graveyardOutside);

	name = "graveyardEntrance";
	description = "I'm right inside the graveyard";
	Room* graveyardEntrance = new Room(name, description, empty);
	elements.push_back(graveyardEntrance);

	name = "graveyard";
	description = "I'm deep inside of the graveyard";
	Room* graveyardCenter = new Room(name, description, empty);
	elements.push_back(graveyardCenter);

	vector<Entity*> sanctumEntrancePertenences;
	sanctumEntrancePertenences.push_back(box);
	name = "sanctumEntrance";
	description = "I'm right in front of the sanctum, there's an inscription saying \"Hideo Kojima\"";
	Room* sanctumEntrance = new Room(name, description, sanctumEntrancePertenences);
	elements.push_back(sanctumEntrance);

	vector<Entity*> sanctumPertenences;
	sanctumPertenences.push_back(tomb);
	name = "sanctum";
	description = "I'm inside the sanctum";
	Room* sanctum = new Room(name, description, sanctumPertenences);
	elements.push_back(sanctum);

	//exits creation
	string description2;
	name = "graveyardDoor";
	description = " a door to the graveyard at the north";
	description2 = " a door to the ouside at the south";
	Exit* graveyardDoor = new Exit(name, description, empty, BOTH, graveyardOutside, graveyardEntrance, S, N, description2, true);
	elements.push_back(graveyardDoor);

	name = "graveyardPathway";
	description = "a pathway to the center of the graveyard at the north";
	description2 = "a pathway to the entrance of the graveyard at the south";
	Exit* graveyardPathway = new Exit(name, description, empty, BOTH, graveyardEntrance, graveyardCenter, S, N, description2, false);
	elements.push_back(graveyardPathway);

	name = "sanctumPathway";
	description = "a pathway to the sanctum entrance at the east";
	description2 = "a pathway to the center of the graveyard at the west";
	Exit* sanctumPathway = new Exit(name, description, empty, BOTH, graveyardCenter, sanctumEntrance, W, E, description2, false);
	elements.push_back(sanctumPathway);

	name = "sanctumTunnel";
	description = "a tunnel to the inside of the sanctum at the east";
	description2 = "a tunnel to the entrance of the sanctum at the west";
	Exit* sanctumTunnel = new Exit(name, description, empty, BOTH, sanctumEntrance, sanctum, W, E, description2, false);
	elements.push_back(sanctumTunnel);

	//Player creation
	name = "player";
	description = "And this is you, a greedy person without principles.";
	Player* p = new Player(name, description, empty, graveyardOutside);
	elements.push_back(p);
	player = p;

	vector<Entity*> vigilantePertenences;
	vigilantePertenences.push_back(torch);
	//NPCs creation
	name = "vigilante";
	description = " a bored vigilante here";
	NPC* vigilante = new NPC(name, description, vigilantePertenences, graveyardEntrance);
	elements.push_back(vigilante);

	//since the vigilante was created after the Room he is in, he is added to the room to ease future interaction
	graveyardEntrance->addElement(vigilante);

	//adding the exits to the rooms aswell
	graveyardOutside->addElement(graveyardDoor);

	graveyardEntrance->addElement(graveyardDoor);
	graveyardEntrance->addElement(graveyardPathway);

	graveyardCenter->addElement(graveyardPathway);
	graveyardCenter->addElement(sanctumPathway);

	sanctumEntrance->addElement(sanctumPathway);
	sanctumEntrance->addElement(sanctumTunnel);

	sanctum->addElement(sanctumTunnel);


	totalCommands = 0;
}


World::~World()
{
}

void World::interpret(action a) {
	switch (a.a) {
		case LOOK:
			player->look(a);
			return;
		case INVENTORY:
			player->inventory();
			return;
		case GO:
			player->go(a);
			return;
		case GRAB:
			player->grab(a);
			return;
		case DROP:
			player->drop(a);
			return;
		case USE:
			player->use(a);
			return;
		case TALK:
			player->talk(a);
			return;
		case PUT:
			player->put(a);
			return;
		case ERROR:
			return;
	}
}

void World::update(string inp) {
	interpret(Parser::Parse(inp));
	totalCommands++;
}