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

void printItem(Entity* e) {
	cout << "There is " << e->description << endl;
}

void Room::printAllElements(bool light) {
	cout << description << endl;
	for (int i = 0; i < contains.size(); i++) {
		//case the item needs light
		if (contains[i]->t == ITEM) {
			Item* itemfound = dynamic_cast<Item*>(contains[i]);//supposed to work
			if (itemfound->hardToSee) {
				if (light) {
					printItem(contains[i]);
				}
			}else {
				printItem(contains[i]);
			}
		}else printItem(contains[i]);
	}
}

Entity* Room::printSpecificElement(string name, bool light) {
	for (int i = 0; i < contains.size(); i++) {
		if (contains[i]->name == name) {
			cout << "You look into " << name << ": " << endl;
			bool something = false;
			for (int j = 0; j < contains[i]->contains.size(); j++) {
				Item* itemfound = dynamic_cast<Item*>(contains[i]->contains[j]);
				if (itemfound->hardToSee) {
					if (!light) {
						if (!something) cout << "Looks like There is nothing here" << endl;
						return NULL;
					}
				}
				cout << "You found a " << contains[i]->contains[j]->description << endl;
				Entity* item = contains[i]->contains[j];
				contains[i]->contains.erase(contains[i]->contains.begin() + j);
				something = true;
				return item;
			}
			if(!something) cout << "Looks like There is nothing else here" << endl;
			return NULL;
		}
	}
	cout << "There is no such thing here" << endl;
}

Entity* Room::grabItem(string n) {
	for (int i = 0; i < contains.size(); i++) {
		if (contains[i]->name == n){
			//cout << "item found, size =  " << contains[i]->contains.size() << contains[i]->contains[0] << endl;
			if (contains[i]->t == ITEM){
				Item* itemfound = dynamic_cast<Item*>(contains[i]);
				if (itemfound->canBeGrabbed) {
					//it can be grabbed
					Entity* item = contains[i];
					contains.erase(contains.begin() + i);
					return item;
				}else {
					cout << "The item cannot be grabbed " << endl;
					return NULL;
				}
			}else {
				cout << "The item cannot be grabbed " << endl;
				return NULL;
			}
		}
	}
}

Room* Room::move(direction dir, bool key) {
	for (int i = 0; i < contains.size(); ++i) {
		if (contains[i]->t == EXIT) {
			cout << "Checking the exit " << contains[i]->name << endl;
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