#include "Room.h"



Room::Room(string namep, string descriptionp, vector<Entity*> containsp):
	Entity(namep, descriptionp, containsp)
{
	t = ROOM;
}


Room::~Room()
{
}

void Room::addElement(Entity* e) {
	contains.push_back(e);
}

void Room::printAllElements() {
	cout << description << endl;
	for (int i = 0; i < contains.size(); i++) {
		cout << "There is " << contains[i]->description << endl;
	}
}

Entity* Room::printSpecificElement(string name) {
	for (int i = 0; i < contains.size(); i++) {
		if (contains[i]->name == name) {
			cout << "You look into " << name << ": " << endl;
			bool something = false;
			for (int j = 0; j < contains[i]->contains.size(); j++) {

				cout << "You found a " << contains[i]->contains[j]->description << endl;
				Entity* item = contains[i]->contains[j];
				contains[i]->contains.erase(contains[i]->contains.begin() + j);
				something = true;
				return item;
			}
			if(!something) cout << "Theire is nothing else here" << endl;
			return NULL;
		}
	}
	cout << "There is no such thing here" << endl;
}

Entity* Room::grabItem(string n) {
	for (int i = 0; i < contains.size(); i++) {
		if (contains[i]->name == n){
			//cout << "item found, size =  " << contains[i]->contains.size() << contains[i]->contains[0] << endl;
			if (contains[i]->t == ITEM and contains[i]->contains.size() == 0) {
				//it can be grabbed
				Entity* item = contains[i];
				contains.erase (contains.begin()+i);
			}
			else {
				cout << "The item cannot be grabbed " << endl;
				return NULL;
			}
		}
	}
}