#pragma once
#include <iostream>
using namespace std;
class HighlightsOfTheMatch {
protected:
	string name; // the name of the footballer
	string contributes;// the type of contribution (goal ,assists ,clean sheets)
	string violence; // the type of violence action (red card,yellow card)

public:
	void setName(string name);
	void setContributions(string contributors);
	void setViolence(string violation);
	string getName();
	string getContributions();
	string getViolence();
};

//2 soulutions 1- add all the 22 players in this class to know whos players scored goals and who didn't using contributes attribute  
//2- use stack to store players that scored goals and compare it with the original squads in both teams