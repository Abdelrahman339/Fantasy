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