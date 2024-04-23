#include <iostream>
#include <deque>
#include <stack>
#include "User.h"
#include <set>
using namespace std;

void play(list<Game> allGames, User currentUser) {
	int choice;
	char ans;
	deque<Game>UserGames=User::FilteringTeams(allGames, currentUser);
	invalid:
	cout << "1-Play the current match \n 2-show the Games Highlights of the week\n 3-Go back" << endl;
	cin >> choice;
	if (choice==1)
	{
		User::showCurrentMatch(UserGames);
		cout << "ready to play the current match? (y/n)" << endl;
		cin >> ans;
		if (ans=='y')
		{
			//comp functions
		}
		else if (ans=='n')
		{
			User::play(allGames, currentUser);
		}
	}
	else if (choice==2)
	{

	}
	else if (choice == 3) {
		User::userMenu();
	}
	else {
		cout << "Invalid option please select a valid option" << endl;
		goto invalid;
	}
	//comp func

};
void User::Market() {


}
void User::showtopPlayer(vector<Footballer> TopPlayer)
{
	//User::Format433();
};
void User::showCurrentMatch(deque<Game>& UserGames)
{
	cout << " Current match " << endl;
	UserGames.front().getHomeTeam(); UserGames.front().getAwayTeam();
}
deque<Game> User::FilteringTeams(list<Game> allGames, User currentUser) {
	deque<Game> UserGames;
	stack<string> userTeams;
	for (int i = 0; i < currentUser.TheMainSquad.size(); i++)
	{
		userTeams.push(currentUser.TheMainSquad.at(i).GetName());
	}
	findDuplicates(userTeams);

	insertToDeque(allGames,userTeams,UserGames);
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
void User::insertToDeque(list<Game> allGames, stack<string>userTeams, deque<Game> &UserGames) {



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
	
}

void User::sell(User& currentUser) {

};
void User::buy(User& currentUser) {
};
void User::replace(User& currentUser) {
};