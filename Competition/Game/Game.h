#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include "Teams.h"
#include <stack>
#include "HighlightsOfTheMatch.h"


using namespace std;

class Game {

protected:
	Teams awayTeam;
	Teams homeTeam;
	string winningTeam;
	string score;
	string manOfTheMatch;
	string statistics; // (shots-shotsOnTarget-possesion-passes-pass accuracy) preferably written like this -->("shots: 10, shotsOnTarget: 7, possession: 55%, passes: 300, pass accuracy: 85%")
	stack<HighlightsOfTheMatch> highlightsOfTheMatch;
	string date;//the date of the match (or the round in league)
	int GameId;

public:
	void displayGameOverview(queue<Game>currentGame);
	void displayTeamsAndScore(Game currentGame);
	void displayBorder(int type);
	void displayHighlights(Game CurrentGame);


/////////////////////////////////////////
///////////// Setters ///////////////////
/////////////////////////////////////////

	void setAwayTeam(Teams team);
	void setHomeTeam(Teams team);
	void setScore(string newScore);
	void setManOfTheMatch(string newManOfTheMatch);
	void setStatistics(string newStatistics);
	void setHighlightsOfTheMatch( HighlightsOfTheMatch newHighlights);
	void setDate(string newDate);

	void setGameId(int id);


	/////////////////////////////////////////
	///////////// getters ///////////////////
	/////////////////////////////////////////

	Teams getAwayTeam();
	Teams getHomeTeam();
	string getScore();
	string getManOfTheMatch();
	string getStatistics();
	stack<HighlightsOfTheMatch> getHighlightsOfTheMatch();
	string getDate();
	string getwinningTeam();
	int getGameId();


	//usefull website for games data --> (moved it to README.md becuase of an occuring error)


};