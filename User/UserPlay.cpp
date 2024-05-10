#include <iostream>
#include <deque>
#include <stack>
#include "User.h"
#include <set>

#include "Competition.h"
using namespace std;
bool loaded = false;
bool firstPlay = false;
int oldGameround = 1;
int currentRound = 1;
void User::play(list<Game>* allGames, User* currentUser, unordered_map<string, User>* Users) {
	//get all usergames for all user
	if (loaded == false)
	{

		for (auto& user : *Users)
		{
			User* User = &user.second;
			stack<string> oldUserTeams;
			string status = "allUsers";
			User::FilteringTeams(*allGames, User, {}, status);
		}
		loaded = true;
	}

	stack<string>oldUserTeams = GetUserTeams(currentUser);
	FilteringTeams(*allGames, currentUser, oldUserTeams, "Team");
	int choice;
	char ans = ' ';
	queue <Game>UserGames = currentUser->GetUserGames();
	Teams team;
invalid:
	cout << "\n\n\n\n";

	cout << spacing(30, ' ') << "1-Play the current match" << endl;
	cout << spacing(30, ' ') << "2-Go back" << endl;
	cin >> choice;
	if (choice == 1)
	{
		bool seasonEnded = showCurrentMatch(UserGames);

		if (seasonEnded)
		{
			cout << " ready to play the current match? (y/n)" << endl;
			cin >> ans;
			if (ans == 'y')
			{
				if (firstPlay == false)
				{
					Game::displayGameOverview(UserGames.front());
					int gameid = currentUser->GetUserGames().front().getGameId();
					Competition::updateAllUserPoints(Users, *allGames, currentUser);
					Competition::deletefromList(*allGames, gameid);
					firstPlay = true;
				}
				else
				{
					Teams* team = nullptr;
					currentRound = currentUser->GetUserGames().front().getRound();
					int gameid = currentUser->GetUserGames().front().getGameId();
					Game::displayGameOverview(UserGames.front());
					Competition::findPlayers(currentUser, "currentUser", team, currentRound);

					if (currentRound != oldGameround)
					{
						Competition::updateAllUserPoints(Users, *allGames, currentUser);
						Competition::deleteallGameRound(allGames);
						oldGameround = currentRound;
					}
					//delete the game form the list
					Competition::deletefromList(*allGames, gameid);
				}
				system("pause");
				system("cls");
				return;
			}
			else
			{
				system("pause");
				system("cls");
				return;
			}
		}
		else if (ans == 'n')
		{
			User::play(allGames, currentUser, Users);
		}
	}
	else if (choice == 2)
	{
		return;
	}
	else {
		cout << "Invalid option please select a valid option" << endl;
		goto invalid;
	}
	//comp func

};


bool User::showCurrentMatch(queue<Game>& UserGames)
{
	if (UserGames.size() == 0)
	{
		cout << spacing(30, ' ') << "##The season not started yet!##" << endl;
		return false;
	}
	else
	{
		cout << spacing(30, ' ') << " Current match " << endl;
		cout << spacing(30, ' ') << UserGames.front().getHomeTeam()->getName() << "   " << UserGames.front().getAwayTeam()->getName() << endl;
		cout << spacing(30, ' ') << "round:" << UserGames.front().getRound() << endl;
		return true;
	}
}


void User::FilteringTeams(list<Game> allGames, User* currentUser, stack<string> oldUserTeams, string status) {

	queue<Game> UserGames = currentUser->GetUserGames();


	stack<string> NewuserTeams;

	NewuserTeams = GetUserTeams(currentUser);

	if (status == "CurrentUser" && areStacksEqual(oldUserTeams, NewuserTeams)) {
		return;
	}

	else {

		findDuplicates(NewuserTeams);

		insertToQueue(allGames, NewuserTeams, UserGames);

		sortingQueue(UserGames);
		RemoveDublicates(UserGames);

		currentUser->GetUserGames().swap(UserGames);
	}

}

stack<string> User::GetUserTeams(User* currentUser)
{
	stack<string> userTeams;
	for (auto& kv : currentUser->GetMainSquad()) {
		string teamName = kv.second.GetTeam();
		userTeams.push(teamName);
	}
	return userTeams;
}



void User::insertToQueue(list<Game> allGames, stack<string>userTeams, queue<Game>& UserGames) {

	bool round1 = true;
	bool round2 = true;
	bool round3 = true;

	while (!userTeams.empty())
	{
		for (auto it = allGames.begin(); it != allGames.end(); ++it) {
			if (userTeams.top() == it->getAwayTeam()->getName() || userTeams.top() == it->getHomeTeam()->getName())
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
	return Game1.getRound() < Game2.getRound();
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

void User::RemoveDublicates(queue<Game>& UserGames)
{
	set<int> uniqueGamesID;
	queue<Game>tempQueue;
	while (!UserGames.empty())
	{
		Game game = UserGames.front();
		UserGames.pop();
		if (uniqueGamesID.count(game.getGameId()) == 0)
		{
			uniqueGamesID.insert(game.getGameId());
			tempQueue.push(game);
		}
	}
	UserGames.swap(tempQueue);
}
