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
		Entity* item = location->printSpecificElement(a.p1, lighted);
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
	bool itemFound = false;
	for (int i = 0; i < contains.size(); ++i) {
		if (contains[i]->name == a.p1) {
			location->addElement(contains[i]);
			contains.erase(contains.begin() + i);
			itemFound = true;
			cout << "You droped " << a.p1 << endl;
		}
	}
	if(!itemFound) cout << "You don't have that item " << endl;
}
void Player::use(action a) {
	bool itemFound = false;
	for (int i = 0; i < contains.size(); ++i) {
		if (contains[i]->name == a.p1) {
			Item* itemfound = dynamic_cast<Item*>(contains[i]);
			if (!itemfound->canBeUsed) {
				cout << "The item cannot be used " << endl;
				return;
			}
			else if(!itemfound->used){
				if (itemfound->name == "torch") {
					lighted = true;
					itemfound->used = true;
					cout << "Now you are lighting the way, things are easier to see " << endl;
				}
				else {
					itemfound->used = true;
				}
			}
			else {
				//case it is being used
				if (itemfound->name == "torch") {
					lighted = false;
					itemfound->used = false;
					cout << "You turned the torch off, you may have a hard time seeing properly " << endl;
				}
				else {
					itemfound->used = false;
				}
			}
			itemFound = true;
		}
	}
	if (!itemFound) cout << "You don't have that item " << endl;
}
void Player::talk(action a) {
	Entity* item = location->talkTo(a.p1);
	if (item != NULL) {
		contains.push_back(item);
		if (item->name == "key") key = true;
		cout << "You obtainted " << item->description << endl;
	}
}
void Player::put(action a) {

}