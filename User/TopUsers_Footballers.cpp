#include <iostream>
#include "User.h"

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