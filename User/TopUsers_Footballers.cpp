#include <iostream>
#include "User.h"



//void User::GetAllFootballers(TheLeague& TheLeague, vector <Footballer*>* allPlayersLeageu) {
//	// looping on all teams in the TheLeague
//	for (auto& currentTeam : *TheLeague.GetTeams()) {
//
//		//loop through all players in the team
//		for (auto& currentPlayer : *currentTeam.second->getFootballPlayer()) {
//			Footballer* footballer = &currentPlayer.second;
//			//add the player in the vector of players
//			allPlayersLeageu->push_back(footballer);
//		}
//	}
//
//}
//vector<Footballer> User::TopFootballersinLeague(vector<Footballer*>* Footballers)
//{
//	vector<Footballer> top5players;
//	sort(Footballers->begin(), Footballers->end(), comparePlayersByPoints);
//	for (int i = 0; i < 5; i++)
//	{
//		top5players.push_back(*Footballers->at(i));
//	}
//	return top5players;
//}
//
//
//unordered_map<string, Footballer*>User::toUnordredMap(vector<Footballer>& top5players)
//{
//	unordered_map<string, Footballer*> topPlayers;
//	for (auto& player : top5players) {
//		Footballer* footballer = &player;
//		topPlayers.insert_or_assign(footballer->GetName(), footballer);
//	}
//	return topPlayers;
//}
//
//
//void User::TopFootballers(unordered_map<string, Footballer*>* topPlayers, vector<TheLeague>& leageus)
//{
//	unordered_map<string, Footballer*> topPlayersleague1;
//	unordered_map<string, Footballer*> topPlayersleague2;
//	unordered_map<string, Footballer*> topPlayersleague3;
//	vector <Footballer*>* allPlayersinLeague = new vector <Footballer*>();
//	vector<Footballer> top5;
//
//	for (int i = 0; i < leageus.size(); i++)
//	{
//		GetAllFootballers(leageus[i], allPlayersinLeague);
//		top5 = TopFootballersinLeague(allPlayersinLeague);
//		if (i == 0)
//		{
//			topPlayersleague1 = toUnordredMap(top5);
//
//		}
//		else if (i == 1) {
//			topPlayersleague2 = toUnordredMap(top5);
//		}
//		else {
//			topPlayersleague3 = toUnordredMap(top5);
//		}
//		allPlayersinLeague = new vector <Footballer*>();
//	}
//	topPlayers->insert(topPlayersleague1.begin(), topPlayersleague1.end());
//	topPlayers->insert(topPlayersleague2.begin(), topPlayersleague2.end());
//	topPlayers->insert(topPlayersleague3.begin(), topPlayersleague3.end());
//
//};
//
//
//
//
//
//
//
//bool User::comparePlayersByPoints(Footballer* player1, Footballer* player2) {
//	return player1->GetTotalpoints() > player2->GetTotalpoints();
//}
//




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

	vector<User>top3users;

	for (int i = 0; i < TopUsers.size(); i++)
	{
		top3users.push_back(TopUsers[i]);
	}
	return top3users;
};



bool User::compareUsersByPoints(User& User1, User& User2) {

	return User1.GetPoints() > User2.GetPoints();
};



void User::showTopUsers(unordered_map<string, User> Users) {
	vector<User> users;
	users = moveTovector(Users);
	vector<User>topUsers;
	try
	{

		topUsers = sortingUsers(users);
	}
	catch (const std::exception&)
	{
		cout << "The season didnt start yet!" << endl;
		return;
	}

	cout << "\n\n\n\n";
	cout << spacing(60, ' ') << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << spacing(60, ' ') << "         ##Top Users in the season!!##           " << endl;
	cout << spacing(60, ' ') << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;

	if (topUsers.size() <= 0) {
		cout << spacing(60, ' ') << "Season not started yet!" << endl;
	}
	else {
		for (int i = 0; i < topUsers.size(); i++) {

			//cout << spacing(topUsers[i].GetUsername().size() + 6, '*') << endl;
			cout << spacing(60, ' ') << "* " << i + 1 << " -" << topUsers[i].GetUsername() << " Points: " << topUsers[i].GetPoints() << " * " << endl;
			//cout << spacing(topUsers[i].size() + 6, '*') << endl;
		}

		system("pause");
	}
};


void User::endOfSeasonScreen(list<Game>* allGames, unordered_map<string, User>Users) {

	User topUser;
	vector<User> topUsers = moveTovector(Users);
	topUsers = sortingUsers(topUsers);
	topUser = topUsers.front();

	if (allGames->size() == 0)
	{
		cout << spacing(60, ' ') << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
		cout << spacing(60, ' ') << "     Fantasy season has ended!!!" << endl;
		cout << spacing(60, ' ') << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
		cout << "\n\n\n";
		cout << spacing(60, ' ') << "congratulations to our first rank winner!!!" << endl;

		cout << spacing(60, ' ') << "##################################################" << "\n\n";
		cout << spacing(85, ' ') << "* " << topUser.GetUsername() << " *" << endl;
		cout << spacing(60, ' ') << "##################################################" << "\n\n";


		system("pause");
		system("cls");
	}
};