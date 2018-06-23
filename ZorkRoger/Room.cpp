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

void Room::printSpecificElement(string name) {
	for (int i = 0; i < contains.size(); ++i) {
		if (contains[i]->name == name) {
			cout << "You look into " << name << ": " << endl;
			for (int j = 0; j < contains[i]->contains.size(); ++j) {
				cout << contains[i]->contains[j]->description << endl;
			}
			return;
		}
	}
	cout << "There is no such thing here" << endl;
}