#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include "Teams.h"
using namespace std;

class Game {

protected:
	Teams awayTeam;
	Teams homeTeam;
	string score;
	string manOfTheMatch;
	string statistics;
	string highlightsOfTheMatch; //goals , assists , cards , etc...
	string date;//the date of the match (or the round in league)

public:

	 string getManOfTheMatch();
	
	//void displayCurrentGame(queue<Game>& Gamehighlights);




//usefull website for games data --> (moved it to README.md becuase of an occuring error)



};