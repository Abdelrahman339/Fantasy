#include <iostream>
#include <deque>
#include <stack>
#include "User.h"
#include <set>
using namespace std;
void User::Market() {

};
deque<Game> User:: Play(vector<Game> allGames, User currentUser) {
	
	deque<Game> game;
	stack<string> userTeams;
	for (int i = 0; i < currentUser.TheMainSquad.size(); i++)
	{
		userTeams.push(currentUser.TheMainSquad.at(i).GetName());
	}
	findDuplicates(userTeams);
	while (!userTeams.empty())
	{
		cout << userTeams.top() << endl;
		userTeams.pop();
	}

	return game;

}
void User::findDuplicates(stack<string>& userTeams)
{
	set<string> Teams;
	stack<string> temp;

	while (!userTeams.empty()) {
		string team = userTeams.top();
		userTeams.pop();
		if (Teams.count(team) == 0) {
			Teams.insert(team);
			temp.push(team);
		}
	}
	
	userTeams.swap(temp);

}
