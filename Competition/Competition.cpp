#include <iostream>
#include <queue>
#include<list>
#include "Competition.h"
#include "Teams.h"
#include"Game/Game.h"
#include <unordered_map>
#include "User.h"
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

char Competition::priceCalculation(int points) {



	if (points < 3) {
		return '0';
	}
	else if (points < 6) {
		return '1';
	}
	else if (points < 9) {
		return '2';
	}
	else if (points < 12) {
		return '3';
	}
	else if (points < 15) {
		return '4';
	}
	else {
		return '5';
	}

}

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

void Competition::ReducePoints(string footballerName, User& currentUser, string violence, string status, Teams& team)
{
	if (status == "User") {
		if (violence == "RedCard")
		{
			currentUser.GetMainSquad().at(footballerName).AddTotalpoints(-2);
			currentUser.AddPoints(-2);
			currentUser.addBalance(-20);
		}
		if (violence == "YellowCard") {
			currentUser.GetMainSquad().at(footballerName).AddTotalpoints(-1);
			currentUser.AddPoints(-1);
			currentUser.addBalance(-5);
		}
	}
	else if (status == "Footballer") {
		if (violence == "RedCard")
		{
			team.getFootballPlayer().at(footballerName).AddTotalpoints(-2);
		}
		if (violence == "YellowCard") {
			team.getFootballPlayer().at(footballerName).AddTotalpoints(-1);
		}
	}



}

void Competition::updatePoints(string footballerName, User& currentUser, string contributes, string status, Teams& team)
{
	//"goals 5 & assists 6"
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

			addPoints(contributes, currentUser, footballerName, Competition::goalPoints, status, team);
		}
		else if (regex_match(contributes, Assistpattern)) {

			addPoints(contributes, currentUser, footballerName, Competition::assistPoints, status, team);
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
	int numberOfcontributes;
	regex pattern(R"(\d+)");

	smatch match;

	if (regex_search(contributes, match, pattern)) {
		numberOfcontributes = stoi(match[0]);

	}
	if (status == "footballer") {
		team.getFootballPlayer().at(footballerName).AddTotalpoints(numPerpoints * numberOfcontributes);
	}
	else {
		currentUser.GetMainSquad().at(footballerName).AddTotalpoints(numPerpoints * numberOfcontributes);
		currentUser.AddPoints(numPerpoints * numberOfcontributes);
		currentUser.addBalance(numPerpoints * numberOfcontributes);
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
			goalsnum = stoi(matches[0]);
		}
		else {
			assistsnum = stoi(matches[0]);
		}
		contributes = matches.suffix().str();
		foundNumbers++;
	}
	int totalPoints = (goalsnum * Competition::goalPoints) + (assistsnum * Competition::assistPoints);
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
				ReducePoints(currentPlayerinMatch, currentUser, currentGame.getHighlightsOfTheMatch().top().getViolation(), "User", team);

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
	char tier = Competition::priceCalculation(player.GetTotalpoints());
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

void Competition::UpdateFootballerPoints(queue<Game> UserGames, list<Game> CurrentGame) //for both squads of the match
{
	removeCurrentGame(UserGames, CurrentGame);

	Game game = UserGames.front();
	Teams team;
	User currentUser;


	string currentMOTM = game.getManOfTheMatch();
	auto AwayFootballPlayers = game.getAwayTeam().getFootballPlayer();
	auto HomeFootballPlayers = game.getHomeTeam().getFootballPlayer();
	string status = "footballer";

	while (!game.getHighlightsOfTheMatch().empty()) {
		for (auto& kv : AwayFootballPlayers) {

			string playerName = kv.first;
			Footballer& currentFootballer = kv.second;
			HighlightsOfTheMatch highlights = game.getHighlightsOfTheMatch().top();

			int yellowCardPenalty = 0;
			int redCardPenalty = 0;
			int cleanSheetPoints = 0;
			int ManOfTheMatchPoints = 0;
			string contributions = highlights.getContributions();



			if (Competition::IsManOfTheMatch(currentMOTM, currentFootballer.GetName()) == true) {
				ManOfTheMatchPoints = Competition::MOTM_Bonus;
			}

			if (highlights.getViolation() == "red") {
				redCardPenalty = -(Competition::redCardDeduction);
			}
			if (highlights.getViolation() == "yellow") {
				yellowCardPenalty = -(Competition::yellowCardDeduction);
			}

			Competition::updatePoints(playerName, currentUser, contributions, status, team);

			int totalPoints = yellowCardPenalty + redCardPenalty + cleanSheetPoints + ManOfTheMatchPoints + currentFootballer.GetTotalpoints();

			currentFootballer.SetTotalpoints(totalPoints);




			Competition::UpdateFootballerPrice(currentFootballer);

		}

	}


	for (auto& kv : HomeFootballPlayers) {

		string playerName = kv.first;
		Footballer& currentFootballer = kv.second;
		HighlightsOfTheMatch highlights = game.getHighlightsOfTheMatch().top();

		int yellowCardPenalty = 0;
		int redCardPenalty = 0;
		int cleanSheetPoints = 0;
		int ManOfTheMatchPoints = 0;
		string contributions = highlights.getContributions();



		if (Competition::IsManOfTheMatch(currentMOTM, currentFootballer.GetName()) == true) {
			ManOfTheMatchPoints = Competition::MOTM_Bonus;
		}

		if (highlights.getViolation() == "red") {
			redCardPenalty = -(Competition::redCardDeduction);
		}
		if (highlights.getViolation() == "yellow") {
			yellowCardPenalty = -(Competition::yellowCardDeduction);
		}

		Competition::updatePoints(playerName, currentUser, contributions, status, team);

		int totalPoints = yellowCardPenalty + redCardPenalty + cleanSheetPoints + ManOfTheMatchPoints + currentFootballer.GetTotalpoints();

		currentFootballer.SetTotalpoints(totalPoints);




		Competition::UpdateFootballerPrice(currentFootballer);

	}

	game.getHighlightsOfTheMatch().pop();
}

