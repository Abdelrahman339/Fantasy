#ifndef COMPETITION_H
#define COMPETITION_H
#pragma once
#include <iostream>
#include <queue>
#include <vector>
#include <list>
#include "User.h"
#include "Game.h"
#include "Teams.h"

using namespace std;

class Competition {

protected:


	const static int goalPoints = 4;
	const static int assistPoints = 2;
	const static int cleanSheetPoints = 3;
	const static int redCardDeduction = 2;
	const static int yellowCardDeduction = 1;
	const static int numOfPlayers = 22;
	const static int MOTM_Bonus = 3;

public:


	void static UpdateFootballerPoints(list<Game>* gameweek,int currentround); // updating all the players in a game
	void static UpdateFootballerPrice(Footballer* player, int points, Teams* team);//based on points for EVERY player (even if not in user's squad)
	void static searchTeamInMatch(Teams* team, Game game, HighlightsOfTheMatch Highlights); //for looping over the hometeam and awayteam 
	char static priceCalculation(int points); //containing five tiers for changing the players price 



	void static updateAllUserPoints(unordered_map<string, User>* Users, list <Game> allGames, User *currentUser);
	void static ReducePoints(User* currentUser, Footballer* TargetedFootballer, string violation, string status, int& tempPoints);//this function used to reduce user points,balance and footballer points

	void static AddContributesPoints(User* currentUser, Footballer* TargetedFootballer, string contributes, string status, int& tempPoints, Teams* team, string motm);//this function used to update user points,balance and footballer points
	void static addPoints(string contributes, User* currentUser, Footballer* TargetedFootballer, int numPerpoints, string status, int& tempPoints,string motm); // goals or assits
	void static addGoalsAssistPoints(string contributes, User* currentUser, Footballer* TargetedFootballer, string status, int& tempPoints, Teams* team,string motm);// add both goals and assits
	void static findPlayers(User* currentUser, string status, Teams* team, int round);


	void static updatecurrentUserPoint(Game currentGame, User* currentUser);

	void static deletefromList(list<Game>& allGames, int gameid);

	void static deleteallGameRound(list<Game>* allgames,int gameround);
	//suspend functions

};
#endif
