#ifndef HIGHLIGHTSOFTHEMATCH_H
#define HIGHLIGHTSOFTHEMATCH_H
#pragma once
#include <iostream>
using namespace std;

class HighlightsOfTheMatch {
protected:
	int GameId;
	string* name; // the name of the footballer
	string contributes;// the type of contribution (goals ,assists ,clean sheets) goals 2 & assist 1
	string violation; // the type of violence action (red cards,yellow cards)


public:
	HighlightsOfTheMatch();
	HighlightsOfTheMatch(int GameId, string* name);
	HighlightsOfTheMatch(int GameId, string* name, string contributes, string violation);
	void setName(string* name);
	void setContributions(string contributors);
	void setViolation(string violation);
	string* getName();
	string getContributions();
	string getViolation();
	int GetGameId();
};

// the class will contain the 22 footballer of the two teams.
#endif