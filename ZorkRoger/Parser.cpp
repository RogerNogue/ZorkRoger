#include "Parser.h"
#include <string>

Parser::Parser()
{
}


Parser::~Parser()
{
}

vector<string> Parser::Parse(string str)
{
	return vector<string>();
}


/*
template<typename Out>
void split(const std::string &s, char delim, Out result) {
	std::stringstream ss(s);
	std::string item;
	while (std::getline(ss, item, delim)) {
		*(result++) = item;
	}
}
*/
/*
vector<string> split(const std::string &s, char delim) {
	std::vector<std::string> elems;
	split(s, delim, std::back_inserter(elems));
	return elems;
}
*/
