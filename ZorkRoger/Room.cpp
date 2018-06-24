#include "Room.h"
#include "Exit.h"



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
				return item;
			}
			else {
				cout << "The item cannot be grabbed " << endl;
				return NULL;
			}
		}
	}
}

Room* Room::move(direction dir, bool key) {
	for (int i = 0; i < contains.size(); ++i) {
		if (contains[i]->t == EXIT) {
			
			Exit* pathway = dynamic_cast<Exit*>(contains[i]);//supposed to work
			if (pathway->source->name == name) {
				if (pathway->destinationDir == dir) {
					if (pathway->requiresKey && !key) {
						cout << "A key is required to travel this way " << endl;
						return NULL;
					}
					cout << "moving:  " << pathway->destination->description << endl;
					return pathway->destination;
				}
			}
			else if (pathway->destination->name == name) {
				if (pathway->sourceDir == dir) {
					if (pathway->requiresKey && !key) {
						cout << "A key is required to travel this way " << endl;
						return NULL;
					}
					cout << "moving:  " << pathway->source->description << endl;
					return pathway->source;
				}
			}
		}
	}
	cout << "no place in this direction "<< endl;
	return NULL;
}