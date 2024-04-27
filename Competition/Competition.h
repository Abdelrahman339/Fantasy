#include <iostream>
#include <queue>
#include <vector>
#include<list>
#include "Game.h"
#include "User.h"
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




	void static UpdateFootballerPoints(queue<Game> UserGames, list<Game> CurrentGame); // updating all the players in a game
	void static UpdateFootballerPrice(Footballer& player);//based on points for EVERY player (even if not in user's squad)
	bool static checkPosition(string footballerPosition); // checks if the player is a goalkeeper or a defender
	void static searchTeamInMatch(unordered_map<string, Footballer> TeamType, Game game);
	bool static IsManOfTheMatch(string currentMOTM, string playerName); //checks if the player is the MOTM
	char static priceCalculation(int points); //containing five tiers for changing the players price 





	void static removeCurrentGame(queue<Game> UserGames, list<Game>& allGames);//use this function before updating all the players points. to prevent duplicate games between UserGames and allGames

	void static ReducePoints(string footballerName, User& currentUser, string violation, string status, Teams& team);//this function used to reduce user points,balance and footballer points

	void static updatePoints(string footballerName, User& currentUser, string contributes, string status, Teams& team);//this function used to update user points,balance and footballer points
	void static addPoints(string contributes, User currentUser, string footballerName, int numPerpoints, string status, Teams& team); // goals or assits
	void static addGoalsAssistPoints(string contributes, User currentUser, string footballerName, string status, Teams& team);// add both goals and assits
	void static findPlayers(queue<Game>& UserGames, User& currentUser, string status, Teams& team);


	void showAllGameHighlights(queue<Game>Usergames, list <Game>& allGames);// show all the games that played in this week or round.


	//suspend functions

};
