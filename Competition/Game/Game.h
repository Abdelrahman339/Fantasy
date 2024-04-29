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
	string statistics;	 // preferably written like this -->("shots 10-9, shotsOnTarget 2-3, possession: 55-45, fouls 3-1, offsides 0-0, saves 1-2")
	stack<HighlightsOfTheMatch> highlightsOfTheMatch;
	string date;//the date of the match (or the round in league)
	int GameId;

public:
	void displayGameOverview(queue<Game>currentGame);
	void displayTeamsAndScore(Game currentGame);
	void displayBorder(int type);
	void displayPlayerHighlights(Game CurrentGame);
	void displayStatisitcs(Game currentGame);

	//Game();

	//Game(Teams& away, Teams& home, string& winTeam, string& score, string& motm,
	//	string& stats, stack<HighlightsOfTheMatch>& highlights, string& date, int id);
	/////////////////////////////////////////
	///////////// Setters ///////////////////
	/////////////////////////////////////////

	void setAwayTeam(Teams team);
	void setHomeTeam(Teams team);
	void setScore(string newScore);
	void setManOfTheMatch(string newManOfTheMatch);
	void setStatistics(string newStatistics);
	void setHighlightsOfTheMatch(HighlightsOfTheMatch newHighlights);
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