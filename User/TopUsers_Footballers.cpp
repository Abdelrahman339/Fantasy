#include <iostream>
#include "User.h"



void User::GetAllFootballers(TheLeague& TheLeague, vector <Footballer*>* allPlayersLeageu) {
	// looping on all teams in the TheLeague
	for (auto& currentTeam : *TheLeague.GetTeams()) {

		//loop through all players in the team
		for (auto& currentPlayer : *currentTeam.second->getFootballPlayer()) {
			Footballer* footballer = &currentPlayer.second;
			//add the player in the vector of players
			allPlayersLeageu->push_back(footballer);
		}
	}

}
vector<Footballer> User::TopFootballersinLeague(vector<Footballer*>* Footballers)
{
	vector<Footballer> top5players;
	sort(Footballers->begin(), Footballers->end(), comparePlayersByPoints);
	for (int i = 0; i < 5; i++)
	{
		top5players.push_back(*Footballers->at(i));
	}
	return top5players;
}


void User::toUnordredMap(unordered_map<string, Footballer*>& topPlayers, vector<Footballer>& top5players)
{
	for (auto& player : top5players) {
		Footballer* footballer = &player;
		topPlayers.insert_or_assign(footballer->GetName(), footballer);
	}
}


void User::TopFootballers(unordered_map<string, Footballer*>* topPlayers, vector<TheLeague>& leageus)
{
	vector <Footballer*>* allPlayersinLeague = new vector <Footballer*>();
	vector<Footballer> top5;

	for (int i = 0; i < leageus.size(); i++)
	{
		GetAllFootballers(leageus[i], allPlayersinLeague);
		top5 = TopFootballersinLeague(allPlayersinLeague);
		toUnordredMap(*topPlayers, top5);
		allPlayersinLeague = new vector <Footballer*>();
	}
};







bool User::comparePlayersByPoints(Footballer* player1, Footballer* player2) {
	return player1->GetTotalpoints() > player2->GetTotalpoints();
}





///////////////////////////////////////////////////////////////////////////////////////////
/////Top Users
///////////////////////////////////////////////////////////////////////////////////////////


vector <User> User::moveTovector(unordered_map<string, User> Users) {

	vector <User> topUsers;
	for (auto& kv : Users) {
		topUsers.push_back(kv.second);
	}
	return topUsers;
};


vector<User> User::sortingUsers(vector<User> TopUsers) {

	sort(TopUsers.begin(), TopUsers.end(), compareUsersByPoints);

	vector<User>top5users;

	for (int i = 0; i < 3; i++)
	{
		top5users.push_back(TopUsers[i]);
	}
	return top5users;
};



bool User::compareUsersByPoints(User& User1, User& User2) {

	return User1.GetPoints() > User2.GetPoints();
};



void User::showTopUsers(unordered_map<string, User> Users) {
	vector<User> users;
	users = moveTovector(Users);
	vector<User>topUsers;
	topUsers = sortingUsers(users);


	cout << spacing(60, ' ') << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << spacing(60, ' ') << "         ##Top Users in the season!!##           " << endl;
	cout << spacing(60, ' ') << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;

	if (topUsers.size() <= 0) {
		cout << spacing(60, ' ') << "Season not started yet!" << endl;
	}
	else {
		for (int i = 0; i < topUsers.size(); i++) {

			//cout << spacing(topUsers[i].GetUsername().size() + 6, '*') << endl;
			cout << "* " << i + 1 << " -" << topUsers[i].GetUsername() << " Points: " << topUsers[i].GetPoints() << " * " << endl;
			//cout << spacing(topUsers[i].size() + 6, '*') << endl;
		}
	}
};


