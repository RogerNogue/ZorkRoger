#pragma once
#include "inclusions.h"
#include "Player.h"
static class Parser
{
public:
	Parser();
	~Parser();
	static void Parse(string str, Player* p);

};

