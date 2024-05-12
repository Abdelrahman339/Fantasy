#include <iostream> 
#include <Windows.h>

// Files
#include "User.h"
#include "Competition.h"
#include "Game.h"
#include "LuckyWheel.h"
#include "fileManpulation.h"

// Data structures
#include <unordered_map>

int main() {
	//cout << "Reading from files: " << endl << endl;
	////League Data now Done!==> Usage
	map<string, unordered_map<string, Footballer>> footballersOfTeam = fileManipulation::getFootballersOfTeamData();
	map<string, Teams> allTeams;
	fileManipulation::getTeamsData(footballersOfTeam, allTeams);
	vector<TheLeague> leagues = fileManipulation::getLeagueData(allTeams);
	map<string, Teams*>* leagueTeams = leagues[0].GetTeams();
	Teams* team = leagueTeams->at("Chelsea");
	unordered_map<string, Footballer>* footballers = team->getFootballPlayer();
	//footballers->erase("Robert Sanchez");
	//leagueTeams->erase("Arsenal");
	//footballer->SetPrice(34.0f);
	
	

	////Get Games now Done!==> USAGE
	list<Game> games = fileManipulation::getGamesData(allTeams);
	//for (list<Game>::iterator it = games.begin(); it != games.end(); ++it) {
	//	stack<HighlightsOfTheMatch> highlights = it->getHighlightsOfTheMatch();
	//	while (!highlights.empty()) {
	//		cout << highlights.top().getContributions() << endl;
	//		highlights.pop();
	//	}
	//}
	//games.begin()->getAwayTeam()
	//Get User now Done!==> USAGE

	map<int, pair<unordered_map<string, Footballer*>, unordered_map<string, Footballer*>>> userSquads = fileManipulation::getUserSquadsData(footballersOfTeam);
	unordered_map<string, User> users = fileManipulation::getUsersData(userSquads);
	User user = users.at("william_l_81");

	//cout << user.GetMainSquad()["Courtois"].GetName() << endl;

	//Game::displayGameOverview(games);

	user.homePage(&users, leagues, &games);


}

