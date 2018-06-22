#pragma once

#include <string>
#include <vector>
#include <stdio.h>
#include <iostream>
using namespace std;
static class Parser
{
public:
	Parser();
	~Parser();
	vector<string> Parse(string str);

};

