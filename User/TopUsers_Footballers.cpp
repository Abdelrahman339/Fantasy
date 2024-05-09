#include <iostream>
#include "User.h"



vector<Footballer> User::GetAllFootballers(TheLeague TheLeague) {


	vector <Footballer> allPlayersLeageu;

	// looping on all teams in the TheLeague
	for (auto currentTeam : TheLeague.GetTeams()) {

		//loop through all players in the team
		for (auto currentPlayer : currentTeam.second.getFootballPlayer()) {

			//add the player in the vector of players
			allPlayersLeageu.push_back(currentPlayer.second);
		}
	}
	return allPlayersLeageu;

}
vector<Footballer> User::TopFootballersinLeague(vector<Footballer> Footballers)
{
	vector<Footballer> top5players;
	sort(Footballers.begin(), Footballers.end(), comparePlayersByPoints);
	for (int i = 0; i < 5; i++)
	{
		top5players.push_back(Footballers.at(i));
	}
	return top5players;
}


void User::toUnordredMap(unordered_map<string, Footballer>& topPlayers, vector<Footballer> top5players)
{
	for (auto player : top5players)
	{
		topPlayers.insert_or_assign(player.GetName(), player);
	}
}


unordered_map<string, Footballer> User::TopFootballers(vector<TheLeague> leageus)
{
	unordered_map<string, Footballer> topPlayers;

	vector <Footballer> allPlayersinLeague;

	vector<Footballer>top5;
	for (int i = 0; i < leageus.size(); i++)
	{
		allPlayersinLeague = GetAllFootballers(leageus[i]);
		top5 = TopFootballersinLeague(allPlayersinLeague);
		toUnordredMap(topPlayers, top5);
	}

	return topPlayers;
};







bool User::comparePlayersByPoints(Footballer& player1, Footballer& player2) {
	return player1.GetTotalpoints() > player2.GetTotalpoints();
}





///////////////////////////////////////////////////////////////////////////////////////////
/////Top Users
///////////////////////////////////////////////////////////////////////////////////////////


vector <User> User::moveTovector(unordered_map<string, User> Users) {

	vector <User> topUsers;
	for (auto kv : Users) {
		topUsers.push_back(kv.second);
	}
	return topUsers;
};


vector<string> User::sortingUsers(vector<User> TopUsers) {

	sort(TopUsers.begin(), TopUsers.end(), compareUsersByPoints);

	vector<string>top5users;

	for (int i = 0; i < 5; i++)
	{
		top5users.push_back(TopUsers[i].GetUsername());
	}
	return top5users;
};



bool User::compareUsersByPoints(User& User1, User& User2) {

	return User1.GetPoints() > User2.GetPoints();
};



void User::showTopUsers(unordered_map<string, User> Users) {
	vector<User> users;
	users = moveTovector(Users);
	vector<string>topUsersNames;
	topUsersNames = sortingUsers(users);


	cout << spacing(60, ' ') << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << spacing(60, ' ') << "         ##Top Users in the season!!##           " << endl;
	cout << spacing(60, ' ') << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;

	if (topUsersNames.size() <= 0) {
		cout << spacing(60, ' ') << "Season not started yet!" << endl;
	}
	else {
		for (int i = 0; i < topUsersNames.size(); i++) {

			cout << spacing(topUsersNames[i].size() + 6, '*') << endl;
			cout << "* " << i + 1 << " -" << topUsersNames[i] << " * " << endl;
			cout << spacing(topUsersNames[i].size() + 6, '*') << endl;
		}
	}
};


