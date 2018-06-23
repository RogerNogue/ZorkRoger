#include "Player.h"



Player::Player(string namep, string descriptionp, vector<Entity*> containsp, Room* locationp) :
	Creature(namep, descriptionp, containsp, locationp)
{
	t = PLAYER;
}


Player::~Player()
{
}


void Player::look(action a) {
	if (a.p1 == "") {
		cout << "You look around" << endl;
		location->printAllElements();
	}
	else {
		//look into something
		location->printSpecificElement(a.p1);
	}
	return;
}
void Player::go(action a) {

}
void Player::grab(action a) {

}
void Player::drop(action a) {

}
void Player::use(action a) {

}
void Player::talk(action a) {

}
void Player::put(action a) {

}