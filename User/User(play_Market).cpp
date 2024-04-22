#include <iostream>
#include <deque>
#include <stack>
#include "User.h"
#include <set>
using namespace std;
void User::Market() {

};
deque<Game> User::FilteringTeams(list<Game> allGames, User currentUser) {

	deque<Game> UserGames;
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
//deque<Game> User::insertToDeque(deque<Game> UserGames, list<Game> allGames, stack<string>userTeams) {}
//
//	while (!userTeams.empty())
//	{
//		for (auto it = allGames.begin(); it != allGames.end(); ++it) {
//			//if (userTeams.top() == it->getAwayTeam().getname() || userTeams.top() == it->getHomeTeam().getname())
//			{
//				Game game = *it;
//				UserGames.push_back(game);
//			}
//		}
//
//	};
//	return UserGames;
//}