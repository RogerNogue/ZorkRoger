// main.cpp: main del projecte
//
//<>
#include "inclusions.h"
#include "World.h"

int main()
{
	World myWorld;
	cout << "Welcome to ZorkRoger!" << endl;
	//game loop
	while (1) {
		cout << endl;
		string inp;
		getline(cin, inp); //get the input line

		myWorld.update(inp);
	}
	return 0;
}

