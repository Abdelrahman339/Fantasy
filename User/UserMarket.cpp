#include <iostream>
#include <deque>
#include <stack>
#include <set>


#include "Competition.h"
#include "User.h"
#include "Leagues.h"
#include <regex>
using namespace std;

//void User::Market(User& currentUser, Teams& team, unordered_map<string, Footballer> TopPlayer, unordered_map<string, User>& Users)
//{
//	string FootballerName;
//	cout << "Fatntasy Market" << endl;
//	int choice = 0;
//	User::showtopPlayer(TopPlayer, currentUser, Users, team);
//invalid:
//	cout << "1-search.\n2-Choose Top player.\n3-Sell your players.\n4-Go back." << endl;
//	if (choice == 1) {
//		//search
//	}
//	else if (choice == 2) {
//		//TopPlayer
//	}
//	else if (choice == 3) {
//		cout << "Enter Footballer name that you want to sell." << endl;
//		cin >> FootballerName;
//		sell(currentUser, team, TopPlayer, Users, FootballerName);
//	}
//	else if (choice == 4) {
//		User::userMenu(currentUser, Users);
//	}
//	else {
//		cout << "Invalid input.Please try again." << endl;
//		goto invalid;
//	}
//};
//
//void User::showtopPlayer(unordered_map<string, Footballer> TopPlayer, User& currentUser, unordered_map<string, User>& Users, Teams& team)
//{
//	string footballerName;
//	int choice;
//invalid:
//	cout << "Welcome to top player in the session!" << endl;
//	User::Format343(TopPlayer);
//	system("cls");
//
//	cout << "1-Show information about player\n2-buy player\n3-Replace player\n4-Go back." << endl;
//	cin >> choice;
//	if (choice == 1) {
//		cout << "Enter the name of the player you want to show information about" << endl;
//		cin >> footballerName;
//		if (TopPlayer.count(footballerName) > 0)
//		{
//			showPlayerInfo(TopPlayer.at(footballerName));
//		}
//		else
//		{
//			cout << "Please enter a valid name" << endl;
//			goto invalid;
//		}
//	}
//	else if (choice == 2)
//	{
//		buy(currentUser, team, TopPlayer, Users);
//
//	}
//	else if (choice == 3) {
//		replace(currentUser, team, TopPlayer, Users);
//	}
//	else if (choice == 4) {
//		Market(currentUser, team, TopPlayer, Users);
//	}
//	else {
//		cout << "Invalid choice.Please select valid choice" << endl;
//		goto invalid;
//	}
//
//
//}
//
//
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
//		cout << "buy";
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
//	for (int i = 0; i < leagues.size(); i++)// n=3  to enter the league
//	{
//
//		map<string, Teams > LeagueTeams = leagues.at(i).GetTeams(); // all teams in the league
//		for (auto team : LeagueTeams) { // to get one team from teams in league
//			Teams currentTeam = team.second;
//			int footballerExist = currentTeam.getFootballPlayer().count(footballerName);
//			if (footballerExist > 0)
//			{
//				footballer = &currentTeam.getFootballPlayer().at(footballerName);
//			}
//
//		}
//	}
//	return footballer;
//}
//
//Teams* User::findTeam(vector<League> leagues, string TeamName)
//{
//	Teams* teamFound;
//	for (int i = 0; i < leagues.size(); i++)
//	{
//		map<string, Teams> teamsInLeagus = leagues.at(i).GetTeams();
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
////
////
//
//
//
//
//bool User::sell(User& currentUser, Teams& team, unordered_map<string, Footballer> TopPlayer, unordered_map<string, User>& Users, string footballerName) {
//
//
//	char ans;
//
//	string playerExist = User::avoidTypos(footballerName, team, currentUser, "sell");
//
//
//
//	//if the user enterd the name of the player correctly
//
//	//the player exist in the main squad
//	if (playerExist == "existMain") {
//		sellFunction(currentUser, footballerName, "main");
//		return true;
//	}
//
//	//the player exist in sub squad
//	else if ("existSub")
//	{
//		sellFunction(currentUser, footballerName, "sub");
//		return true;
//	}
//
//
//	//the user enterd the name wrong
//
//	else if (!playerExist.empty()) {
//
//		regex pattern(R"(main)");
//
//		// check if the player from the main squad or not
//		if (regex_search(playerExist, pattern))
//		{
//			playerExist = regex_replace(playerExist, pattern, "");
//			cout << "You enterd a wrong player .Do you mean " << playerExist << "?(y/n)" << endl;
//			cin >> ans;
//
//			switch (ans)
//			{
//			case'y':
//				sellFunction(currentUser, playerExist, "main");
//				return true;
//			case'n':
//				cout << "Plese enter a valid footballer name." << endl;
//				return false;
//
//			default:
//				break;
//			}
//
//		}
//
//
//		// the player is from sub squad
//		else {
//			cout << "You enterd a wrong player .Do you mean " << playerExist << "?(y/n)" << endl;
//			cin >> ans;
//			if (ans == 'y')
//			{
//				sellFunction(currentUser, playerExist, "sub");
//				return true;
//			}
//			else if (ans == 'n') {
//				cout << "Plese enter a valid footballer name." << endl;
//				return false;
//			};
//		}
//	}
//
//	// the player dosen't exist in main and sub squad
//	else
//	{
//		cout << "There is no matching football player." << endl;
//		cout << "Plese enter a valid footballer name." << endl;
//		return false;
//	}
//
//}
//
//
//
void User::sellFunction(User& currentUser, string footballerName, string status)
{
	unordered_map<string, Footballer>* squad;
	if (status == "main")
	{
		squad = &currentUser.GetMainSquad();
	}

	else
	{
		squad = &currentUser.GetSubstitutionSquad();
	}

	cout << "Player sold successfully.." << endl;

	float FootballerPrice = squad->at(footballerName).GetPrice();

	squad->erase(footballerName);

	currentUser.addBalance(FootballerPrice);

}
;
//
//
//
//
//
//void User::buy(User& currentUser, Teams& team, unordered_map<string, Footballer> TopPlayer, unordered_map<string, User>& Users) {
//	string footballerName;
//	char ans;
//invalid:
//	cout << "Enter the name of your wanted player to buy.\n";
//	cin >> footballerName;
//
//	string playerExist = User::avoidTypos(footballerName, team, currentUser, "buing");
//
//
//	if (playerExist == "exist")
//	{
//
//		cout << "Are you sure you want to buy " << footballerName << " ?(y/n)" << endl;
//		cin >> ans;
//		if (ans == 'y')
//		{
//			cout << "Player bought successfully." << endl;
//
//
//			float FootballerPrice = team.getFootballPlayer().at(footballerName).GetPrice();
//			currentUser.addBalance(-FootballerPrice);
//
//
//			Footballer footballer = team.getFootballPlayer().at(footballerName);
//			currentUser.SetFootballer(footballer);
//
//		}
//		else if (ans == 'n') {
//			Market(currentUser, team, TopPlayer, Users);
//		}
//		else {
//			cout << "Please enter a valid option." << endl;
//			goto invalidOption;
//		}
//	}
//
//
//
//
//
//	else if (!playerExist.empty()) {
//	invalidOption:
//		cout << "You enterd a wrong player .Do you mean " << playerExist << "?" << endl;
//		cin >> ans;
//		if (ans == 'y')
//		{
//			cout << "Player bought successfully." << endl;
//
//
//			float FootballerPrice = team.getFootballPlayer().at(footballerName).GetPrice();
//			currentUser.addBalance(-FootballerPrice);
//
//
//			Footballer footballer = team.getFootballPlayer().at(footballerName);
//			currentUser.SetFootballer(footballer);
//		}
//		else if (ans == 'n') {
//			cout << "Plese enter a valid footballer name." << endl;
//			goto invalid;
//		}
//		else
//		{
//			cout << "Please enter a valid option." << endl;
//			goto invalidOption;
//		}
//	}
//
//
//
//	else
//	{
//		cout << "There is no matching football player." << endl;
//		cout << "Plese enter a valid footballer name." << endl;
//		goto invalid;
//	}
//
//};
//
//
//
//
//
//void User::replace(User& currentUser, Teams& team, unordered_map<string, Footballer> TopPlayer, unordered_map<string, User>& Users) {
//
//
//	string TeamFootballerName;
//	string UserFootballerName;
//invalidTeam:
//	cout << "enter the name of player you want to replace." << endl;
//	cin >> TeamFootballerName;
//	if (team.getFootballPlayer().count(TeamFootballerName) > 0)
//	{
//	invalidSquad:
//		cout << "enter the name of player from your team that you want to replace " << TeamFootballerName << " with." << endl;
//		cin >> UserFootballerName;
//
//		Footballer TeamFootballer = team.getFootballPlayer().at(TeamFootballerName);
//		int mainIT = currentUser.GetMainSquad().count(UserFootballerName);
//		int subIT = currentUser.GetSubstitutionSquad().count(UserFootballerName);
//		if (mainIT > 0)
//		{
//
//			Footballer UserFootballer = currentUser.GetMainSquad().at(UserFootballerName);
//			float cost = UserFootballer.GetPrice() - TeamFootballer.GetPrice();
//			if (cost > 0)
//			{
//				cout << "The cost of replacement will be " << cost << "will added to your account" << endl;
//				currentUser.addBalance(cost);
//			}
//			else
//			{
//				cout << "The cost of replacement will be " << abs(cost) << "will deduct from your account" << endl;
//				currentUser.addBalance(cost);
//			}
//		}
//		else if (subIT > 0)
//		{
//			Footballer UserFootballer = currentUser.GetSubstitutionSquad().at(UserFootballerName);
//			float cost = UserFootballer.GetPrice() - TeamFootballer.GetPrice();
//			if (cost > 0)
//			{
//				cout << "The cost of replacement will be: " << cost << " will added to your account" << endl;
//				currentUser.addBalance(cost);
//			}
//			else
//			{
//				cout << "The cost of replacement will be: " << abs(cost) << " will deduct from your account" << endl;
//				currentUser.addBalance(cost);
//			}
//		}
//		else
//		{
//			cout << "Please select a valid Player name from your squad " << endl;
//			goto invalidSquad;
//		}
//
//	}
//	else {
//		cout << "Please select a valid Player name from team " << endl;
//		goto invalidTeam;
//	}
//
//}
