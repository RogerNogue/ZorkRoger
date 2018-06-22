#include "Parser.h"

Parser::Parser()
{
}


Parser::~Parser()
{
}

template<typename Out>
void split(const string &s, char delim, Out result) {
	stringstream ss(s);
	string item;
	while (getline(ss, item, delim)) {
		*(result++) = item;
	}
}


vector<string> split(const string &s, char delim) {
	vector<string> elems;
	split(s, delim, back_inserter(elems));
	return elems;
}


vector<string> Parser::Parse(string str)
{
	vector<string> tokens = split(str, ' '); // split the input into words
											 //health may be implemented
	int mida = tokens.size();
	switch (mida) {
	case 0:
		cout << "I beg your pardon ?" << endl;
		break;
	case 1:
		/*
		switch
		else {
			cout << "That's not a verb I recognise." << endl;
		}
		*/
		break;
	case 2:
		/*
		switch
		else {
		cout << "That's not a verb I recognise." << endl;
		}
		*/
		break;
	case 3:
		/*
		switch
		else {
		cout << "That's not a verb I recognise." << endl;
		}
		*/
		break;
	default:
		break;

	}
	return vector<string>();
}

