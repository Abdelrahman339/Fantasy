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
		void displayCurrentGame(queue<Game>& Gamehighlights);

};

//usefull website for games data

//https://www.soccer24.com/spain/laliga-2021-2022/#/MPV5cuep/table/overall

//https://ar.soccerway.com/national/spain/primera-division/20212022/regular-season/r63145/

