#include <iostream>
#include <deque>
#include <stack>
#include "User.h"
#include <set>
#include "Competition.h"
using namespace std;

void play(list<Game> allGames, User currentUser) {
	int choice;
	char ans;
	queue <Game>UserGames = User::FilteringTeams(allGames, currentUser);
invalid:
	cout << "1-Play the current match \n 2-show the Games Highlights of the week\n 3-Go back" << endl;
	cin >> choice;
	if (choice == 1)
	{
		User::showCurrentMatch(UserGames);
		cout << "ready to play the current match? (y/n)" << endl;
		cin >> ans;
		if (ans == 'y')
		{

		}
		else if (ans == 'n')
		{
			User::play(allGames, currentUser);
		}
	}
	else if (choice == 2)
	{

	}
	else if (choice == 3) {
		//User::userMenu();
	}
	else {
		cout << "Invalid option please select a valid option" << endl;
		goto invalid;
	}
	//comp func

};

void User::showtopPlayer(unordered_map<string, Footballer> TopPlayer, User& currentUser, unordered_map<string, User>& Users, Teams& team)
{
	string footballerName;
	int choice;
invalid:
	cout << "Welcome to top player in the session!" << endl;
	//User::Format343(TopPlayer);
	cout << "Enter the namr of your wanted player.";
	cin >> footballerName;
	system("cls");
	User::showPlayerInfo(TopPlayer, footballerName);
	cout << "1-Buy playern\2-Replace player\n3-Go back." << endl;
	cin >> choice;
	if (choice == 1) {
		//buy func 
	}
	else if (choice == 2) {
		//replace
	}
	else if (choice == 3) {
		Market(currentUser, team, TopPlayer, Users);
	}
	else {
		cout << "Invalid choice.Please select valid choice" << endl;
		goto invalid;
	}


}
void User::showCurrentMatch(queue<Game>& UserGames)
{
	cout << " Current match " << endl;
	UserGames.front().getHomeTeam(); UserGames.front().getAwayTeam();
}
queue<Game> User::FilteringTeams(list<Game> allGames, User currentUser) {
	queue<Game> UserGames;
	stack<string> userTeams;
	for (auto& kv : currentUser.GetMainSquad()) {
		string teamName = kv.second.GetTeam();
		userTeams.push(teamName);

	}
	findDuplicates(userTeams);

	insertToQueue(allGames, userTeams, UserGames);
	return UserGames;

}
void User::findDuplicates(stack<string>& userTeams)
{
	set<string> teams;
	stack<string> temp;

	while (!userTeams.empty()) {
		string team = userTeams.top();
		userTeams.pop();
		if (teams.count(team) == 0) {
			teams.insert(team);
			temp.push(team);
		}
	}

	userTeams.swap(temp);

}
void User::insertToQueue(list<Game> allGames, stack<string>userTeams, queue<Game>& UserGames) {



	while (!userTeams.empty())
	{
		for (auto it = allGames.begin(); it != allGames.end(); ++it) {
			if (userTeams.top() == it->getAwayTeam().getName() || userTeams.top() == it->getHomeTeam().getName())
			{
				Game game = *it;
				UserGames.push(game);
			}
		}
		userTeams.pop();
	};

}


void User::Market(User& currentUser, Teams& team, unordered_map<string, Footballer> TopPlayer, unordered_map<string, User>& Users)
{
	cout << "Fatntasy Market" << endl;
	int choice;
	User::showtopPlayer(TopPlayer,currentUser,Users,team);
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
void User::sell(User& currentUser, Teams& team) {

};
void User::buy(User& currentUser, Teams& team) {
};
void User::replace(User& currentUser, Teams& team) {
};