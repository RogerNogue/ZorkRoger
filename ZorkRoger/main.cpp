// main.cpp: main del projecte
//
//<>
#include "inclusions.h"
#include "World.h"

int main()
{
	World myWorld;
	//game loop
	while (1) {
		
		string inp;
		getline(cin, inp); //get the input line

		myWorld.update(inp);
	}
}

