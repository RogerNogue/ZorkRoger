#pragma once
#include <stdio.h>
#include <tchar.h>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

enum type {
	PLAYER, NPCE, EXIT, ROOM, ITEM
};

enum direction {
	N, S, E, W, NONE
};

enum actions {
	LOOK, GO, GRAB, DROP, USE, TALK, PUT, ERROR, INVENTORY
};

enum directionExit{
	BOTH
};

struct action {
	actions a;
	direction dir;
	string p1;
	string p2;
};