#include "Player.h"



Player::Player(string namep, string descriptionp, vector<Entity*> containsp, Room* locationp) :
	Creature(namep, descriptionp, containsp, locationp)
{
	t = PLAYER;
	key = false;
	lighted = false;
}


Player::~Player()
{
}


void Player::look(action a) {
	if (a.p1 == "") {
		cout << "You look around" << endl;
		location->printAllElements(lighted);
	}
	else {
		//look into something
		Entity* item = location->printSpecificElement(a.p1);
		if (item != NULL) {
			contains.push_back(item);
			if (item->name == "key") key = true;
		}
	}
	return;
}
void Player::inventory() {
	int elems = contains.size();
	if (elems == 0) {
		cout << "You have nothing " << endl;
	}
	else {
		for (int i = 0; i < contains.size(); ++i) {
			cout << "There is " << contains[i]->description << endl;
		}
	}
}
void Player::go(action a) {
	//i have to check the exit class.
	Room* newLoc = location->move(a.dir, key);
	if (newLoc != NULL) {
		location = newLoc;
	}
}
void Player::grab(action a) {
	Entity* item = location->grabItem(a.p1);
	if (item != NULL) {
		contains.push_back(item);
		if (item->name == "key") key = true;
		cout << "You grabbed " << item->description << endl;
	}
}
void Player::drop(action a) {

}
void Player::use(action a) {

}
void Player::talk(action a) {

}
void Player::put(action a) {

}