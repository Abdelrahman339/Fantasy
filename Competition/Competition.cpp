#include <iostream>
#include <queue>
#include<list>
#include "Competition.h"
#include "Teams.h"
#include"Game/Game.h"
#include <unordered_map>
#include <regex>


using namespace std;




bool Competition::IsManOfTheMatch(string currentMOTM, string playerName)
{
	return (currentMOTM == playerName);
}


bool Competition::checkPosition(string footballerPosition) {

	if (footballerPosition == "defender" || footballerPosition == "goalkeeper") {
		return true;
	}

	else
		return false;

}

//char Competition::priceCalculation(Footballer& player) {
//
//	int currentPoints = player.GetPoints();
//
//	if (currentPoints < 3) {
//		return '0';
//	}
//	else if (currentPoints < 6) {
//		return '1';
//	}
//	else if (currentPoints < 9) {
//		return '2';
//	}
//	else if (currentPoints < 12) {
//		return '3';
//	}
//	else if (currentPoints < 15) {
//		return '4';
//	}
//	else {
//		return '5';
//	}
//
//}

void Competition::removeCurrentGame(queue<Game> UserGames, list<Game>& allGames)
{
	while (!UserGames.empty())
	{

		for (Game game : allGames) {
			if (UserGames.front().getGameId() == game.getGameId())
			{
				allGames.remove(game);
			}
		}
		UserGames.pop();
	}
}

void Competition::ReduceUserPoints(string footballerName, User& currentUser, string violence)
{
	if (violence == "RedCard")
	{
		currentUser.GetMainSquad().at(footballerName).AddTotalpoints(-2);
		currentUser.AddPoints(-2);
		currentUser.addBalance(-20);
	}
	else if (violence == "YelloCard") {
		currentUser.GetMainSquad().at(footballerName).AddTotalpoints(-1);
		currentUser.AddPoints(-1);
		currentUser.addBalance(-5);
	}

	else
	{
		currentUser.GetMainSquad().at(footballerName).AddTotalpoints(0);
	}

}

void Competition::updatePoints(string footballerName, User& currentUser, string contributes, string status, Teams& team)
{
	//"golas 5 & assits 6"
	regex pattern(R"(&)");
	int numberofGoals;
	if (regex_match(contributes, pattern)) { // if the player scord and did assist

		addGoalsAssistPoints(contributes, currentUser, footballerName, status, team);
	}

	else if (!regex_match(contributes, pattern))
	{
		regex Goalpattern(R"(Goal)");
		regex Assistpattern(R"(Assist)");
		if (regex_match(contributes, Goalpattern)) {

			addPoints(contributes, currentUser, footballerName, 4, status, team);
		}
		else if (regex_match(contributes, Assistpattern)) {

			addPoints(contributes, currentUser, footballerName, 3, status, team);
		}
		else {
			currentUser.GetMainSquad().at(footballerName).AddTotalpoints(3);
			currentUser.AddPoints(3);
			currentUser.addBalance(10);
		}
	}
	else
	{
		currentUser.GetMainSquad().at(footballerName).AddTotalpoints(-10);
		currentUser.AddPoints(-10);
	}

}


void Competition::addPoints(string contributes, User currentUser, string footballerName, int numPerpoints, string status, Teams& team)
{
	int nmuberOfcontributes;
	regex pattern(R"(\d+)");

	smatch match;

	if (regex_search(contributes, match, pattern)) {
		nmuberOfcontributes = stoi(match[0]);

	}
	if (status == "footballer") {
		team.getFootballPlayer().at(footballerName).AddTotalpoints(numPerpoints * nmuberOfcontributes);
	}
	else {
		currentUser.GetMainSquad().at(footballerName).AddTotalpoints(numPerpoints * nmuberOfcontributes);
		currentUser.AddPoints(numPerpoints * nmuberOfcontributes);
		currentUser.addBalance(numPerpoints * nmuberOfcontributes);
	}
}



void Competition::addGoalsAssistPoints(string contributes, User currentUser, string footballerName, string status, Teams& team)
{
	regex pattern(R"(\d+)");

	smatch matches;
	int goalsnum, assistsnum;

	int foundNumbers = 0;

	while (regex_search(contributes, matches, pattern)) {
		if (foundNumbers == 0) {
			goalsnum = std::stoi(matches[0]);
		}
		else {
			assistsnum = std::stoi(matches[0]);
		}
		contributes = matches.suffix().str();
		foundNumbers++;
	}
	int totalPoints = (goalsnum * 4) + (assistsnum * 3);
	if (status == "footballer") {
		team.getFootballPlayer().at(footballerName).AddTotalpoints(totalPoints);
	}
	else {
		currentUser.GetMainSquad().at(footballerName).AddTotalpoints(totalPoints);
		currentUser.AddPoints(totalPoints);
		currentUser.addBalance(totalPoints * 3);
	}
}

void Competition::findPlayers(queue<Game>& UserGames, User& currentUser, string status, Teams& team)
{

	Game currentGame = UserGames.front();
	while (!currentGame.getHighlightsOfTheMatch().empty())
	{

		string currentPlayerinMatch = currentGame.getHighlightsOfTheMatch().top().getName();
		for (auto& kv : currentUser.GetMainSquad()) {
			string footballerName = kv.first;
			if (footballerName == currentPlayerinMatch)
			{
				updatePoints(currentPlayerinMatch, currentUser, currentGame.getHighlightsOfTheMatch().top().getContributions(), "User", team);
				ReduceUserPoints(currentPlayerinMatch, currentUser, currentGame.getHighlightsOfTheMatch().top().getViolation());

			}
		}

		//go to the next player
		currentGame.getHighlightsOfTheMatch().pop();
	}


	//The end of the match
	UserGames.pop();
}

void Competition::showAllGameHighlights(queue<Game>Usergames, list <Game>& allGame)
{
	char ans;
	removeCurrentGame(Usergames, allGame);
	cout << "Highlights of the week" << endl;
	for (Game game : allGame) {
		cout << game.getAwayTeam().getName() << User::spacing(10, ' ') << game.getHomeTeam().getName() << endl;
		cout << game.getScore() << endl;
	}
}

void Competition::UpdateFootballerPrice(Footballer& player) // for all the players
{
	char tier = Competition::priceCalculation(player);
	float currentPlayerPrice = player.GetPrice();
	float priceChange;

	switch (tier) {

	case '1':
		priceChange = currentPlayerPrice + 0.5f;
		break;

	case '2':
		priceChange = currentPlayerPrice + 1.0f;
		break;

	case '3':
		priceChange = currentPlayerPrice + 1.5f;
		break;

	case '4':
		priceChange = currentPlayerPrice + 2.0f;
		break;

	case '5':
		priceChange = currentPlayerPrice + 2.5f;
		break;

	default:
		//if the player doesn't perfom with any of the tiers
		priceChange = currentPlayerPrice - 0.2f;
	}

	player.SetPrice(priceChange);


}

//void Competition::UpdateFootballerPoints(list<Game> CurrentGame) //for both squads of the match
//{
//	Game game;
//	Footballer CurrentPlayer;
//	int numPlayersCalculated = 0;
//	int index = 0;
//	string currentMOTM = game.getManOfTheMatch();
//	//int homeTeamScore = game.getHomeTeam().getScore();
//	//int awayTeamScore = game.getAwayTeam().getScore();
//
//
//	
//
//	
//
//	while (numPlayersCalculated < Competition::numOfPlayers) {
//
//		bool isMatchWinner=false; //for adding match winning bonus
//
//		///////////////////////////////////////////
//		//getting players from home and away teams/
//		///////////////////////////////////////////
//
//		//Home team first then the away team
//
//		//if (numPlayersCalculated < 11) 
//		//{
//		//	CurrentPlayer = game.getHomeTeam().getFootballPlayer(index).at(index);
//		//	if (homeTeamScore > awayTeamScore) {
//		//		isMatchWinner = true;
//		//	}
//		//}
//		//else {
//		//	CurrentPlayer = game.getAwayTeam().getFootballPlayer(index).at(index);
//		//	if (homeTeamScore < awayTeamScore) {
//		//		isMatchWinner = true;
//		//	}
//		//}
//
//		///////////////////////////////////////////////////////////////////////
//
//
//		int GoalPoints = ((Competition::goalPoints)*CurrentPlayer.GetGoals()) + CurrentPlayer.GetPoints();
//		int AssistPoints = ((Competition::assistPoints)*CurrentPlayer.GetAssists() + CurrentPlayer.GetPoints());
//		int yellowCardPenalty = 0;
//		int redCardPenalty = 0;
//		int cleanSheetPoints = 0;
//		int ManOfTheMatchPoints = 0;
//		int MatchWinningBonus = 0;
//		
//
//
//		if (CurrentPlayer.GetYellowCards()) {
//			yellowCardPenalty = CurrentPlayer.GetPoints() - (Competition::yellowCardDeduction);
//		}
//
//		if (CurrentPlayer.GetRedCard()) {
//			redCardPenalty = CurrentPlayer.GetPoints() - (Competition::redCardDeduction);
//		}
//
//		//check if the player is a defender or a goalkeeper to add cleansheet bonus
//
//		if (CurrentPlayer.GetCleanSheets() == true) {
//			if (Competition::checkPosition(CurrentPlayer.GetPosition())) {
//				cleanSheetPoints = CurrentPlayer.GetPoints() + (Competition::cleanSheetPoints);
//			}
//		}
//
//		if (Competition::IsManOfTheMatch(currentMOTM, CurrentPlayer.GetName()) == true) {
//			ManOfTheMatchPoints = Competition::MOTM_Bonus;
//		}
//
//		//if (isMatchWinner) {
//		//	MatchWinningBonus = Competition::WinBonus;
//		//}
//
//
//		int totalPoints = GoalPoints + AssistPoints + yellowCardPenalty + redCardPenalty + cleanSheetPoints +ManOfTheMatchPoints + MatchWinningBonus;
//		CurrentPlayer.setPoints(totalPoints);
//
//
//
//		
//		Competition::UpdateFootballerPrice(CurrentPlayer);
//
//		
//		
//		numPlayersCalculated++;
//		index++;
//
//
//	}
//
//
//}
//
