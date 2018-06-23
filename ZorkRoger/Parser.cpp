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


action Parser::Parse(string str)
{
	action ret;
	ret.a = ERROR;
	ret.dir = NONE;
	ret.p1 = "";
	ret.p2 = "";
	vector<string> tokens = split(str, ' '); // split the input into words
											 //health may be implemented
	int mida = tokens.size();
	//since switch case doesnt work with strings, if chain is being used
	if (mida == 0) {
		cout << "I beg your pardon ?" << endl;
		return ret;
	}
	else {
		if (tokens[0] == "look" || tokens[0] == "L") {
			//cout << "lookin good" << endl;
			if (mida == 1) {
				ret.a = LOOK;
				return ret;
			}
			else {
				ret.a = LOOK;
				ret.p1 = tokens[1];
				//cout << "look with more, we got" << ret.p1 << endl;
				return ret;
			}

		}
		if (tokens[0] == "inventory") {
			ret.a = INVENTORY;
			return ret;
		}
		if (tokens[0] == "grab") {
			//cout << "grabbin good" << endl;
			ret.a = GRAB;
			ret.p1 = tokens[1];
			return ret;
		}if (tokens[0] == "go") {
			if (tokens[1] == "north" || tokens[1] == "N") {
				//cout << "goin north good" << endl;
				ret.a = GO;
				ret.dir = N;
				return ret;
			}if (tokens[1] == "south" || tokens[1] == "S") {
				//cout << "goin south good" << endl;
				ret.a = GO;
				ret.dir = S;
				return ret;
			}if (tokens[1] == "east" || tokens[1] == "E") {
				//cout << "goin east good" << endl;
				ret.a = GO;
				ret.dir = E;
				return ret;
			}if (tokens[1] == "west" || tokens[1] == "W") {
				//cout << "goin west good" << endl;
				ret.a = GO;
				ret.dir = W;
				return ret;
			}
		}if (tokens[0] == "drop") {
			//cout << "droppin good" << endl;
			ret.a = DROP;
			ret.p1 = tokens[1];
			return ret;
		}if (tokens[0] == "talk") {
			//cout << "talkin good" << endl;
			ret.a = TALK;
			ret.p1 = tokens[1];
			return ret;
		}if (tokens[0] == "use") {
			//cout << "usin good" << endl;
			ret.a = USE;
			ret.p1 = tokens[1];
			return ret;
		}if (tokens[0] == "put") {
			//cout << "puttin good" << endl;
			ret.a = DROP;
			ret.p1 = tokens[1];
			ret.p2 = tokens[2];
			return ret;
		}
	}
	cout << "That's not a verb I recognise." << endl;
	return ret;
}

