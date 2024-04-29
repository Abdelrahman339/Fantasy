#include <iostream>
#include <deque>
#include <stack>
#include <set>


#include "Competition.h"
#include "User.h"
#include "Leagues.h"
using namespace std;

void User::Market(User& currentUser, Teams& team, unordered_map<string, Footballer> TopPlayer, unordered_map<string, User>& Users)
{
	cout << "Fatntasy Market" << endl;
	int choice=0;
	User::showtopPlayer(TopPlayer, currentUser, Users, team);
invalid:
	cout << "1-search.\n2-Choose Top player.\n3-Sell your players.\n4-Go back." << endl;
	if (choice == 1) {
		//search
	}
	else if (choice == 2) {
		//TopPlayer
	}
	else if (choice == 3) {
		//sell
	}
	else if (choice == 4) {
		User::userMenu(currentUser, Users);
	}
	else {
		cout << "Invalid input.Please try again." << endl;
		goto invalid;
	}
};




//void User::search(string footballerName, Teams team, User currentUser, string status, vector<League>  leagues)
//{
//	string search;
//invalid:
//	cout << "You can search by teams or the name of footballer." << endl;
//	cin >> search;
//	Footballer* footballer = findPlayer(leagues, search);
//	Teams* teams = findTeam(leagues, search);
//	if (footballer != nullptr)
//	{
//		User::showPlayerInfo(*footballer);
//	}
//
//	else if (teams != nullptr)
//	{
//		//findTeam(leagues, search).displayPlayers();
//
//	}
//	else
//	{
//		cout << "please enter a valid Team name or Footabller name" << endl;
//		goto invalid;
//	}
//
//
//}
//Footballer* User::findPlayer(vector<League> leagues, string footballerName)
//{
//	Footballer* footballer;
//	for (int i = 0; i < leagues.size(); i++)// n=3 laliga
//	{
//		for (int i = 0; i < leagues.at(i).getTeams().size(); i++)
//		{
//			map<string, Teams > LeagueTeams = leagues.at(i).getTeams();
//			for (auto team : LeagueTeams) {
//				Teams currentTeam = team.second;
//				int footballerExist = currentTeam.getFootballPlayer().count(footballerName);
//				if (footballerExist > 0)
//				{
//					footballer = &currentTeam.getFootballPlayer().at(footballerName);
//				}
//			}
//		}
//	}
//	return footballer;
//}
//Teams* User::findTeam(vector<League> leagues, string TeamName)
//{
//	Teams* teamFound;
//	for (int i = 0; i < leagues.size(); i++)
//	{
//		map<string, Teams> teamsInLeagus = leagues.at(i).getTeams();
//		int TeamExist = teamsInLeagus.count(TeamName);
//		if (TeamExist > 0) {
//			teamFound = &teamsInLeagus.at(TeamName);
//		}
//
//	}
//	return teamFound;
//};
//
//
//
//
//
//




void User::sell(User& currentUser, Teams& team, unordered_map<string, Footballer> TopPlayer, unordered_map<string, User>& Users) {
	string footballerName;
	char ans;
invalid:
	cout << "Enter the name of your wanted player to sell.\n";
	cin >> footballerName;
	string playerExist = User::avoidTypos(footballerName, team, currentUser, "sell");

	if (playerExist == "existMain") {
		cout << "Player sold successfully.." << endl;
		currentUser.GetMainSquad().erase(footballerName);

		float FootballerPrice = currentUser.GetMainSquad().at(footballerName).GetPrice();

		currentUser.addBalance(FootballerPrice);
	}
	else if ("existSub")
	{
		currentUser.GetSubstitutionSquad().erase(footballerName);

		float FootballerPrice = currentUser.GetSubstitutionSquad().at(footballerName).GetPrice();

		currentUser.addBalance(FootballerPrice);
	}



	else if (!playerExist.empty()) {
	invalidOption:
		cout << "You enterd a wrong player .Do you mean " << playerExist << "?" << endl;
		cin >> ans;
		if (ans == 'y')
		{
			cout << "Player sold successfully.." << endl;
			currentUser.GetMainSquad().erase(footballerName);

			float FootballerPrice = currentUser.GetMainSquad().at(footballerName).GetPrice();

			currentUser.addBalance(FootballerPrice);
		}
		else if (ans == 'n') {
			cout << "Plese enter a valid footballer name." << endl;
			goto invalid;
		}
		else
		{
			cout << "Please enter a valid option." << endl;
			goto invalidOption;
		}
	}



	else
	{
		cout << "There is no matching football player." << endl;
		cout << "Plese enter a valid footballer name." << endl;
		goto invalid;
	}


};





void User::buy(User& currentUser, Teams& team, unordered_map<string, Footballer> TopPlayer, unordered_map<string, User>& Users) {
	string footballerName;
	char ans;
invalid:
	cout << "Enter the name of your wanted player to buy.\n";
	cin >> footballerName;

	string playerExist = User::avoidTypos(footballerName, team, currentUser, "buing");


	if (playerExist == "exist")
	{

		cout << "Are you sure you want to buy " << footballerName << " ?(y/n)" << endl;
		cin >> ans;
		if (ans == 'y')
		{
			cout << "Player bought successfully." << endl;


			float FootballerPrice = team.getFootballPlayer().at(footballerName).GetPrice();
			currentUser.addBalance(-FootballerPrice);


			Footballer footballer = team.getFootballPlayer().at(footballerName);
			currentUser.SetFootballer(footballer);

		}
		else if (ans == 'n') {
			Market(currentUser, team, TopPlayer, Users);
		}
		else {
			cout << "Please enter a valid option." << endl;
			goto invalidOption;
		}
	}





	else if (!playerExist.empty()) {
	invalidOption:
		cout << "You enterd a wrong player .Do you mean " << playerExist << "?" << endl;
		cin >> ans;
		if (ans == 'y')
		{
			cout << "Player bought successfully." << endl;


			float FootballerPrice = team.getFootballPlayer().at(footballerName).GetPrice();
			currentUser.addBalance(-FootballerPrice);


			Footballer footballer = team.getFootballPlayer().at(footballerName);
			currentUser.SetFootballer(footballer);
		}
		else if (ans == 'n') {
			cout << "Plese enter a valid footballer name." << endl;
			goto invalid;
		}
		else
		{
			cout << "Please enter a valid option." << endl;
			goto invalidOption;
		}
	}



	else
	{
		cout << "There is no matching football player." << endl;
		cout << "Plese enter a valid footballer name." << endl;
		goto invalid;
	}

};





void User::replace(User& currentUser, Teams& team, unordered_map<string, Footballer> TopPlayer, unordered_map<string, User>& Users) {


}
