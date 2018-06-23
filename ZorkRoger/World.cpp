#include "World.h"




World::World()
{
	string name, description;
	vector<Entity*> empty;
	//Items creation
	name = "key";
	description = "a rusty old key";
	Item* key = new Item(name, description, empty, false, false);
	elements.push_back(key);

	vector<Entity*> stonePertenences;
	stonePertenences.push_back(key);
	name = "stone";
	description = "a suspicious wierd shaped stone";
	Item* stone = new Item(name, description, stonePertenences, false, false);
	elements.push_back(stone);

	name = "torch";
	description = "a torch that can help me see";
	Item* torch = new Item(name, description, empty, false, true);
	elements.push_back(torch);

	name = "paper";
	description = "a small paper that says \" legend says this person was rich\"";
	Item* paper = new Item(name, description, empty, false, false);
	elements.push_back(paper);
	
	vector<Entity*> boxPertenences;
	boxPertenences.push_back(paper);
	name = "box";
	description = "a little wooden box";
	Item* box = new Item(name, description, boxPertenences, false, false);
	elements.push_back(box);

	name = "prize";
	description = "wow, a bitcoin cupon";
	Item* secretPrize = new Item(name, description, empty, true, false);
	elements.push_back(secretPrize);

	vector<Entity*> tombPertenences;
	tombPertenences.push_back(secretPrize);
	name = "tomb";
	description = "looks like arelatively recent tomb";
	Item* tomb = new Item(name, description, tombPertenences, false, false);
	elements.push_back(tomb);

	//Rooms creation
	vector<Entity*> graveyardOutsidePertenences;
	graveyardOutsidePertenences.push_back(stone);
	name = "graveyardOutside";
	description = "Looks like I'm right in front of the graveyard doors";
	Room* graveyardOutside = new Room(name, description, graveyardOutsidePertenences);
	elements.push_back(graveyardOutside);

	name = "graveyardEntrance";
	description = "I'm right inside the graveyard, there is a path to get deep in the graveyard in the north";
	Room* graveyardEntrance = new Room(name, description, empty);
	elements.push_back(graveyardEntrance);

	name = "graveyard";
	description = "I'm deep inside of the graveyard, i can see a sanctum in the east";
	Room* graveyardCenter = new Room(name, description, empty);
	elements.push_back(graveyardCenter);

	vector<Entity*> sanctumEntrancePertenences;
	sanctumEntrancePertenences.push_back(box);
	name = "sanctumEntrance";
	description = "I'm right in front of the sanctum, there's an inscription saying \"Hideo Kojima\" and a tunnel to the inside of the sanctum in the east";
	Room* sanctumEntrance = new Room(name, description, sanctumEntrancePertenences);
	elements.push_back(sanctumEntrance);

	vector<Entity*> sanctumPertenences;
	sanctumPertenences.push_back(tomb);
	name = "sanctum";
	description = "I'm inside the sanctum";
	Room* sanctum = new Room(name, description, sanctumPertenences);
	elements.push_back(sanctum);

	//exits creation
	name = "graveyardDoor";
	description = "Closed door to the graveyard";
	Exit* graveyardDoor = new Exit(name, description, empty, BOTH, graveyardOutside, graveyardEntrance, true);
	elements.push_back(graveyardDoor);

	name = "graveyardPathway";
	description = "Pathway to the center of the graveyard";
	Exit* graveyardPathway = new Exit(name, description, empty, BOTH, graveyardEntrance, graveyardCenter, false);
	elements.push_back(graveyardPathway);

	name = "sanctumPathway";
	description = "Pathway to the sanctum entrance";
	Exit* sanctumPathway = new Exit(name, description, empty, BOTH, graveyardCenter, sanctumEntrance, false);
	elements.push_back(sanctumPathway);

	name = "sanctumTunnel";
	description = "Tunnel to the inside of the sanctum";
	Exit* sanctumTunnel = new Exit(name, description, empty, BOTH, sanctumEntrance, sanctum, false);
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
	description = "Looks like there is a bored vigilante here";
	NPC* vigilante = new NPC(name, description, vigilantePertenences, graveyardEntrance);
	elements.push_back(vigilante);

	//sine the vigilante was created after the Room he is in, he is added to the room to ease future interaction
	graveyardEntrance->addElement(vigilante);


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