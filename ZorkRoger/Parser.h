#pragma once
#include "inclusions.h"
#include "Player.h"
static class Parser
{
public:
	Parser();
	~Parser();
	static action Parse(string str);

};

