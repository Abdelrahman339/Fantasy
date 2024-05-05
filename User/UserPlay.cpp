#include <iostream>
#include <deque>
#include <stack>
#include "User.h"
#include <set>

#include "Competition.h"
using namespace std;

void User::play(list<Game> allGames, User currentUser) {
	int choice;
	char ans;
	queue <Game>UserGames = currentUser.GetUserGames();
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


void User::showCurrentMatch(queue<Game>& UserGames)
{
	cout << " Current match " << endl;
	UserGames.front().getHomeTeam(); UserGames.front().getAwayTeam();
}


void User::FilteringTeams(list<Game> allGames, User& currentUser, stack<string> oldUserTeams) {

	queue<Game> UserGames = currentUser.GetUserGames();


	stack<string> NewuserTeams;

	NewuserTeams = GetUserTeams(currentUser);

	if (areStacksEqual(oldUserTeams, NewuserTeams)) {
		return;
	}

	else {

		findDuplicates(NewuserTeams);

		insertToQueue(allGames, NewuserTeams, UserGames);

		currentUser.GetUserGames().swap(UserGames);
	}

}

stack<string> User::GetUserTeams(User currentUser)
{
	stack<string> userTeams;
	for (auto& kv : currentUser.GetMainSquad()) {
		string teamName = kv.second.GetTeam();
		userTeams.push(teamName);
	}
	return userTeams;
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

void User::sortingQueue(queue<Game>& UserGames)
{
	vector<Game> usergamesUS;//US for un sorted
	while (!UserGames.empty())
	{
		usergamesUS.push_back(UserGames.front());
		UserGames.pop();
	}

	sort(usergamesUS.begin(), usergamesUS.end(), compareGamesByRound);

	for (int i = 0; i < usergamesUS.size(); i++)
	{
		UserGames.push(usergamesUS[i]);
	}

}

bool User::compareGamesByRound(Game& Game1, Game& Game2) {
	return Game1.getRound() > Game2.getRound();
}

bool User::areStacksEqual(stack<string> stack1, stack<string> stack2)
{
	vector<string> v1;
	vector<string> v2;

	while (!stack1.empty())
	{
		v1.push_back(stack1.top());
		stack1.pop();
	}
	while (!stack2.empty())
	{
		v2.push_back(stack2.top());
		stack2.pop();
	}

	return v1 == v2;

}