#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include "Teams.h"
using namespace std;
class Game

{
	Teams awayTeam;
	Teams homeTeam;
	string score;
	string manOfTheMatch;
	string statistics;
	string highlightsOfTheMatch; //goals , assists , cards , etc...


	void displayCurrentGame(queue<Game>& Gamehighlights);
};
