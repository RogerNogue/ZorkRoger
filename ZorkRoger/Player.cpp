#include "Player.h"



Player::Player(type tp, string namep, string descriptionp, vector<Entity*> containsp, Room* locationp) :
	Creature(tp, namep, descriptionp, containsp, locationp)
{
}


Player::~Player()
{
}
