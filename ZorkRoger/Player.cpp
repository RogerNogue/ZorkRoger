#include "Player.h"



Player::Player(string namep, string descriptionp, vector<Entity*> containsp, Room* locationp) :
	Creature(namep, descriptionp, containsp, locationp)
{
	t = PLAYER;
}


Player::~Player()
{
}
