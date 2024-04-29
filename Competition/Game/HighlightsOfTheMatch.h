#pragma once
#include <iostream>
using namespace std;

class HighlightsOfTheMatch {
protected:

	string name; // the name of the footballer
	string contributes;// the type of contribution (goals ,assists ,clean sheets) goals 2 & assist 1
	string violation; // the type of violence action (red cards,yellow cards)


public:

	//HighlightsOfTheMatch(string name, string contributes, string violation);
	//HighlightsOfTheMatch();
	void setName(string name);
	void setContributions(string contributors);
	void setViolation(string violation);
	string getName();
	string getContributions();
	string getViolation();
};


