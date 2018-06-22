#pragma once
#include <stdio.h>
#include <tchar.h>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

enum type {
	PLAYER, NPC, EXIT, ROOM, ITEM
};

enum direction {
	N, S, E, W
};

enum actions {
	LOOK, GO, GRAB, USE, TALK, PUT
};

struct actionInfo {
	actions action;
	string a1;
	string a2;
};