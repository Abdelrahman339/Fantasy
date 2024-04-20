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

	public:
		void displayCurrentGame(queue<Game>& Gamehighlights);

};