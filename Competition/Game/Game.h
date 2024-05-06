#ifndef GAME_H
#define GAME_H

#pragma once
#include <iostream>
#include <sstream>
#include <iomanip>
#include <random>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <regex>


#include "Teams.h"
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
	int round;//the date of the match (or the round in league)
	int GameId;

public:
	void static displayGameOverview(queue<Game>currentGame);
	void static displayTeamsAndScore(Game currentGame);
	void static displayBorder(int type);
	void static displayPlayerHighlights(Game CurrentGame);
	void static displayStatisitcs(Game currentGame);

	Game();

	Game(int id, Teams home, Teams away, string winTeam, string score,
		string stats, stack<HighlightsOfTheMatch> highlights, string motm, int round);
	/////////////////////////////////////////
	///////////// Setters ///////////////////
	/////////////////////////////////////////

	void setAwayTeam(Teams team);
	void setHomeTeam(Teams team);
	void setScore(string newScore);
	void setManOfTheMatch(string newManOfTheMatch);
	void setStatistics(string newStatistics);
	void setHighlightsOfTheMatch(HighlightsOfTheMatch newHighlights);
	void setRound(int newRound);

	void setGameId(int id);


	/////////////////////////////////////////
	///////////// getters ///////////////////
	/////////////////////////////////////////

	Teams getAwayTeam();
	Teams getHomeTeam();
	string getScore();
	string getManOfTheMatch();
	string getStatistics();
	stack<HighlightsOfTheMatch> &getHighlightsOfTheMatch();
	int getRound();
	string getwinningTeam();
	int getGameId();


	//usefull website for games data --> (moved it to README.md becuase of an occuring error)


};
#endif // GAME_H
