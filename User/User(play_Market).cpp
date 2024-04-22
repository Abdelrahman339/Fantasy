#include <iostream>
#include <deque>
#include <stack>
#include "User.h"
#include <set>
using namespace std;
void User::Market() {


};
deque<Game> User::FilteringTeams(list<Game> allGames, User currentUser) {

	stack<string> userTeams;
	for (int i = 0; i < currentUser.TheMainSquad.size(); i++)
	{
		userTeams.push(currentUser.TheMainSquad.at(i).GetName());
	}
	findDuplicates(userTeams);

	deque<Game> UserGames=insertToDeque(allGames,userTeams);

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
deque<Game> User::insertToDeque(list<Game> allGames, stack<string>userTeams) {

	deque<Game> UserGames;

	while (!userTeams.empty())
	{
		for (auto it = allGames.begin(); it != allGames.end(); ++it) {
			//if (userTeams.top() == it->getAwayTeam().getname() || userTeams.top() == it->getHomeTeam().getname())
			{
				Game game = *it;
				UserGames.push_back(game);
			}
		}
		userTeams.pop();	
	};
	return UserGames;
}