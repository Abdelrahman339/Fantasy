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
	string statistics;
	stack<HighlightsOfTheMatch> highlightsOfTheMatch;
	string date;//the date of the match (or the round in league)

public:
	//void displayCurrentGame(queue<Game>& Gamehighlights);


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


	//usefull website for games data --> (moved it to README.md becuase of an occuring error)



};