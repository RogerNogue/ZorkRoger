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


void Parser::Parse(string str, Player* p)
{
	actionInfo res;
	res.action = LOOK;
	res.a1 = "";
	res.a2 = "";
	vector<string> tokens = split(str, ' '); // split the input into words
											 //health may be implemented
	int mida = tokens.size();
	//since switch case doesnt work with strings, if chain is being used
	if (mida == 0) {
		cout << "I beg your pardon ?" << endl;
		return;
	}
	else {
		if (tokens[0] == "look" || tokens[0] == "L") {
			cout << "lookin good" << endl;
			return;;
		}
		if (tokens[0] == "grab") {
			cout << "grabbin good" << endl;
			return;;
		}if (tokens[0] == "go") {
			if (tokens[1] == "north" || tokens[1] == "N") {
				cout << "goin north good" << endl;
				return;;
			}if (tokens[1] == "south" || tokens[1] == "S") {
				cout << "goin south good" << endl;
				return;;
			}if (tokens[1] == "east" || tokens[1] == "E") {
				cout << "goin east good" << endl;
				return;;
			}if (tokens[1] == "west" || tokens[1] == "W") {
				cout << "goin west good" << endl;
				return;;
			}
		}if (tokens[0] == "drop") {
			cout << "droppin good" << endl;
			return;;
		}if (tokens[0] == "talk") {
			cout << "talkin good" << endl;
			return;;
		}if (tokens[0] == "use") {
			cout << "usin good" << endl;
			return;;
		}if (tokens[0] == "put") {
			cout << "puttin good" << endl;
			return;;
		}
	}
	cout << "That's not a verb I recognise." << endl;
	return;
}

