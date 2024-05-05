#include <iostream>
#include <string>
#include <algorithm>
#include <sstream>
#include <limits>
#include<Windows.h>
#include "Admin.h"
#include "User.h"
#include "Teams.h"
#include "UserValidations.h"
#undef max

using namespace std;

int counter = 0;
bool answer = false;

void Admin::CheckAdmin(unordered_map<string, User>& Users, map<string, Teams>& teams, vector<TheLeague> leagues)
{
	int count = 0;
	string username, password;
	do
	{
		cout << "Enter Admin Username " << endl;
		cout << "Username: ";
		cin >> username;
		cout << "~~~~~~~~~~~~~~~~~~~~~" << endl;
		cout << "Enter Admin Password " << endl;
		cout << "Password: ";
		cin >> password;
		transform(username.begin(), username.end(), username.begin(), ::tolower);
		transform(password.begin(), password.end(), password.begin(), ::tolower);
		if ((username == "admin" && password == "admin") || (username == "1" && password == "1"))
		{
			PauseAndClear();
			cout << endl << "~~~~~~~~ Welcome Back Admin! ~~~~~~~~" << endl;
			AdminMenu(Users, teams, leagues);
			return;
		}
		else
		{
			cout << endl << "Wrong Admin Username Or Password" << endl;
			count++;
			cout << "Please Try Again...  " << count << " / 3\n";
			PauseAndClear();
		}
	} while (count != 3);
}

void Admin::AdminMenu(unordered_map<string, User>& Users, map<string, Teams>& teams, vector<TheLeague> leagues)
{
	int choice;
Menu:
	cout << endl << "\t     Admin Menu" << endl;
	cout << "--------------------------------------" << endl;
	cout << "1-About Users \n2-About Teams \n3-About Leagues \n4-Go Back" << endl;
	cout << "--------------------------------------" << endl;
	cout << "Enter your choice: ";
	cin >> choice;
	cout << endl;
	if (choice == 1)
	{
		system("cls");
		AboutUsers(Users, teams, leagues);
		return;
	}
	else if (choice == 2)
	{
		displayTeamsForSpecificLeague(leagues);
	}
	else if (choice == 3)
	{
		LeaguesMenu(leagues, teams);
		goto Menu;
	}
	else if (choice == 4)
	{
		system("cls");
		return;
	}
	else
	{
		system("cls");
		cout << endl << "Please select a valid choice.." << endl;
		goto Menu;
	}
}




void Admin::AboutUsers(unordered_map<string, User>& Users, map<string, Teams>& teams, vector<TheLeague> leagues)
{
	int choice;
Choose:
	cout << endl;
	DisplayAllUsers(Users, teams, leagues);
	cout << "1-Add New User \n2-About User \n3-User Squad And Players\n4-Delete User \n5-Go Back" << endl;
	cout << "Enter your choice: ";
	cin >> choice;
	if (choice == 1)
	{
		User::signup(Users);
		cout << "Successfully Added Your New User " << endl;
		PauseAndClear();
	}
	if (choice == 2)
	{
		ShowAndEditUser(Users, teams, leagues);
		PauseAndClear();
	}
	else if (choice == 3)
	{
		UserSquadAndPlayers(Users, teams, leagues);
		PauseAndClear();
	}
	else if (choice == 4)
	{
		answer = true;
		DeleteUser(Users, teams, leagues);
		PauseAndClear();
	}
	else if (choice == 5)
	{
		AdminMenu(Users, teams, leagues);
		return;
	}
	else
	{
		system("cls");
		cout << endl << "Please select a valid choice.." << endl;
		goto Choose;
	}
}

void Admin::DisplayAllUsers(unordered_map<string, User>& Users, map<string, Teams>& teams, vector<TheLeague> leagues)
{
	counter = 0;
	Sleep(300);
	cout << "\t| Full Name\t\t  | User Name" << endl;
	cout << "------------------------------------------------" << endl;
	for (auto it = Users.begin(); it != Users.end(); ++it)
	{
		cout << counter + 1 << "\t|" << Users.at(it->first).GetFullName() << "  \t\t  |" << it->first << endl;
		counter++;
	}
	cout << "------------------------------------------------" << endl;
	cout << "Total Number of Users: " << counter << endl;
}

void Admin::ShowAndEditUser(unordered_map<string, User>& Users, map<string, Teams>& teams, vector<TheLeague> leagues)
{
	string userName;
	cout << "Enter Username To Show User Information: " << endl;
	cout << "Username: ";
	cin >> userName;
	cout << endl;
	if (Users.find(userName) == Users.end())
	{
		cout << "User Does Not Exist, Please Enter An Existing User" << endl;
		Sleep(200);
		ShowAndEditUser(Users, teams, leagues);
	}
	else
	{
		ViewProfile(Users, Users.at(userName), teams, leagues);
	}
}
void Admin::ViewProfile(unordered_map<string, User>& Users, User& currentUser, map<string, Teams>& teams, vector<TheLeague> leagues)
{
	int choice;
choices:
	cout << "User Information And Profile" << endl;
	cout << "--------------------------------------" << endl;
	cout << "Name:" << currentUser.GetFullName() << endl;;
	cout << "Username:" << currentUser.GetUsername() << endl;
	cout << "Email Address:" << currentUser.GetEmail() << endl;
	cout << "Phone number:" << currentUser.GetPhoneNumber() << endl;
	cout << "Password:" << currentUser.GetPassword() << endl;
	cout << "Id:" << currentUser.GetId() << endl;
	cout << "Balance:" << currentUser.GetBalance() << endl;
	cout << "Points:" << currentUser.GetPoints() << endl;
	cout << "Rank:" << currentUser.GetRank() << endl;
	cout << "--------------------------------------" << endl;
	cout << "1-Edit User Information\n2-User Squad And Players\n3-Delete User \n4-Go Back" << endl;
	cout << "Enter your choice: ";
	cin >> choice;
	if (choice == 1)
	{
		EditProfile(Users, currentUser, teams, leagues);
	}
	else if (choice == 2)
	{
		User::ShowSquad(currentUser);
		ViewProfile(Users, currentUser, teams, leagues);
	}
	else if (choice == 3)
	{
		answer = false;
		Deletion(Users, currentUser, teams, leagues);
	}
	else if (choice == 4)
	{
		AboutUsers(Users, teams, leagues);
		return;
	}
	else
	{
		system("cls");
		cout << endl << "Please select a valid choice.." << endl;
		goto choices;
	}
}
void Admin::EditProfile(unordered_map<string, User>& Users, User& currentUser, map<string, Teams>& teams, vector<TheLeague> leagues)
{
	bool valid = false;
	int choice;
choices:
	Sleep(400);
	cout << endl;
	cout << "What Info Would You Like To Edit?" << endl;
	cout << "--------------------------------------" << endl;
	cout << "1-Full Name\t2-Username\t3-Email Address\n4-Phone Number\t5-Password\t6-Balance\n7-Points\t8-Rank\t\t9-Go Back" << endl;
	cout << "Enter your choice: ";
	cin >> choice;
	if (choice == 1)
	{
		UserValidations::signupinfo(&currentUser, "new Fullname", UserValidations::fullnameCheck, &User::SetFullName);
		cout << "Full name updated successfully" << endl;
		PauseAndClear();
	}
	else if (choice == 2)
	{
		valid = true;
		auto it = Users.find(currentUser.GetUsername());//old username
		UserValidations::usernameCheck(Users, currentUser);  //updated username
		if (it != Users.end()) // if old username exists
		{
			Users.insert({ currentUser.GetUsername(), it->second });   //update the username
			Users.erase(it);   //erasing old username
		}
		else
		{
			cout << "Username Not Found" << endl;
			valid = false;
		}
		cout << "Username updated successfully" << endl;
		PauseAndClear();
	}
	else if (choice == 3)
	{
		UserValidations::signupinfo(&currentUser, "new Email", UserValidations::emailAddressCheck, &User::SetEmail);
		cout << "Email updated successfully" << endl;
		PauseAndClear();
	}
	else if (choice == 4)
	{
		UserValidations::signupinfo(&currentUser, "new PhoneNumber", UserValidations::phoneNumberCheck, &User::SetPhoneNumber);
		cout << "PhoneNumber updated successfully" << endl;
		PauseAndClear();
	}
	else if (choice == 5)
	{
		UserValidations::signupinfo(&currentUser, "new Password", UserValidations::passwordCheck, &User::SetPassword);
		cout << "Password updated successfully" << endl;
		PauseAndClear();
	}
	else if (choice == 6)
	{
		EditBalancePointsRank(currentUser, 1, "new Balance", teams, leagues);
		cout << "Balance updated successfully" << endl;
		PauseAndClear();
	}
	else if (choice == 7)
	{
		EditBalancePointsRank(currentUser, 2, "new Points", teams, leagues);
		cout << "Points updated successfully" << endl;
		PauseAndClear();
	}
	else if (choice == 8)
	{
		EditBalancePointsRank(currentUser, 3, "new Rank", teams, leagues);
		cout << "Rank updated successfully" << endl;
		PauseAndClear();
	}
	else if (choice == 9)
	{
		ViewProfile(Users, currentUser, teams, leagues);
	}
	else
	{
		cout << endl << "Please select a valid choice.." << endl;
		goto choices;
	}
	if (valid)
	{
		ViewProfile(Users, currentUser, teams, leagues);
		return;
	}
	else
	{
		Users[currentUser.GetUsername()] = currentUser;
		ViewProfile(Users, currentUser, teams, leagues);
		return;
	}
}
void Admin::EditBalancePointsRank(User& CurrentUser, int choice, string information, map<string, Teams>& teams, vector<TheLeague> leagues)
{
	float NewBalance = 1;
	int NewPointsOrRank = 1;
Redo:
	cout << "Enter Your " << information << ": " << endl;
	if (information == "new Balance")
	{
		cin >> NewBalance;
		if (!CheckBalancePointsRank(information, teams, leagues))
		{
			goto Redo;
		}
	}
	else
	{
		cin >> NewPointsOrRank;
		if (CheckBalancePointsRank(information, teams, leagues))
		{
			goto Redo;
		}
	}
	if (NewBalance < 0 || NewPointsOrRank < 0)
	{
		cout << "Your " << information << " Cannot Be Negative" << endl;
		goto Redo;
	}
	else if (choice == 3 && NewPointsOrRank == 0)
	{
		cout << "Your " << information << " Cannot Be Zero" << endl;
		goto Redo;
	}
	else
	{
		if (choice == 1)
		{
			CurrentUser.SetBalance(NewBalance);
		}
		else if (choice == 2)
		{
			CurrentUser.SetPoints(NewPointsOrRank);
		}
		else if (choice == 3)
		{
			CurrentUser.SetRank(NewPointsOrRank);
		}
	}
}
bool Admin::CheckBalancePointsRank(string information, map<string, Teams>& teams, vector<TheLeague> leagues)
{
	if (cin.fail())
	{
		cout << "Your " << information << " Must Be A Value!" << endl;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		return false;
	}
	else
	{
		return true;
	}
}
void Admin::UserSquadAndPlayers(unordered_map<string, User>& Users, map<string, Teams>& teams, vector<TheLeague> leagues)
{
	string userName;
	cout << "Enter Username To Display User Squad: " << endl;
	cout << "Username: ";
	cin >> userName;
	if (Users.find(userName) == Users.end())
	{
		cout << "User Does Not Exist, Please Enter An Existing User" << endl;
		Sleep(200);
		UserSquadAndPlayers(Users, teams, leagues);
	}
	else
	{
		User::ShowSquad(Users.at(userName));
		AboutUsers(Users, teams, leagues);
	}
}

void Admin::DeleteUser(unordered_map<string, User>& Users, map<string, Teams>& teams, vector<TheLeague> leagues)
{
	string userName;
	if (counter == 0)
	{
		cout << "No Users To Delete" << endl;
		AboutUsers(Users, teams, leagues);
	}
	else
	{
		cout << "Enter Username To Delete User: " << endl;
		cout << "Username: ";
		cin >> userName;
		if (Users.find(userName) == Users.end())
		{
			cout << "User Does Not Exist, Please Enter An Existing User" << endl;
			Sleep(200);
			DeleteUser(Users, teams, leagues);
		}
		else
		{
			Deletion(Users, Users.at(userName), teams, leagues);
		}
	}
}

void Admin::Deletion(unordered_map<string, User>& Users, User CurrentUser, map<string, Teams>& teams, vector<TheLeague> leagues)
{
	int choice;
	cout << "Are you sure you want to delete " << CurrentUser.GetUsername() << "?" << endl;
	cout << "1. Yes \n2. No" << endl;
	cout << "Enter your choice: ";
	cin >> choice;
	if (choice == 1)
	{
		Users.erase(CurrentUser.GetUsername());
		cout << "Successfully Deleted " << CurrentUser.GetUsername() << endl;
		counter--;
	}
	else if (choice == 2)
	{
		if (answer)
		{
			cout << "Returning Back to the User Menu..." << endl;
			Sleep(500);
			answer = false;
			AboutUsers(Users, teams, leagues);
		}
		else
		{
			Sleep(200);
			ViewProfile(Users, CurrentUser, teams, leagues);
		}
	}
	else
	{
		cout << "Please Select a Valid Choice.." << endl;
		Deletion(Users, CurrentUser, teams, leagues);
	}
}

void Admin::TeamMenu(map<string, Teams> teams) {
	int choice = -1;
	int InputInt = -1;
start:
	cout << "1) Modify a Team" << endl;
	cout << "2) Display Footballers in a Team" << endl;
	cout << "3) Go Back" << endl;
	cout << "Choice: " << endl;
	cin >> choice;
	if (choice == 1) {
		ModifyTeams(teams);
	}
	else if (choice == 2) {
		DisplayFootballersForSpecificTeam(teams);

	}
	else if (choice == 3) {
		return;
	}
	else {
		cout << "Invalid Choice!" << endl;
		goto start;
	}
}

void Admin::ModifyTeams(map<string, Teams> teams) {
	Teams TeamToBeModified;
	int choice;
	string InputString;
	int InputInt;
SearchTeam:
	cout << "Enter Team Name: ";
	cin >> InputString;
	handleTeamExistance(teams, TeamToBeModified, InputString);
ModifySameTeam:
	cout << "Modify " << TeamToBeModified.getName() << " information" << endl;
	cout << "What do you wish to Edit?" << endl;
	cout << "1) Name" << endl;
	cout << "2) Points" << endl;
	cout << "3) Delete the Team" << endl;
	cout << "4) Go Back" << endl;
	cin >> choice;

	switch (choice) {
	case 1:
		cout << "Enter new Name: ";
		cin >> InputString;
		TeamToBeModified.SetName(InputString);
		break;
	case 2:
		cout << "Enter new Points: ";
		cin >> InputInt;
		TeamToBeModified.SetPoints(InputInt);
		break;
	case 3:
		teams.erase(TeamToBeModified.getName());
		cout << "Deleted Successfully!" << endl;
		Sleep(300);
		break;
	case 4:
		goto SearchTeam;
	default:
		cout << "Invalid choice!" << endl;
		Sleep(300);
		goto ModifySameTeam;
	}
}

void Admin::displayTeamsForSpecificLeague(vector<TheLeague> leagues) {
	string leagueName;
beginning:
	cout << "Enter a TheLeague Name: ";
	cin >> leagueName;
	while (!leagues.empty()) {
		int i = 0;
		if (leagues[i].getLeagueName() == leagueName) {
			cout << "TheLeague: " << leagues[i].getLeagueName() << endl;
			TheLeague::displayTeams(leagues[i].GetTeams());
			TeamMenu(leagues[i].GetTeams());
		}
		else {
			i++;
		}
	}
	if (leagues.empty()) {
		cout << "Invalid TheLeague Name!" << endl;
		goto beginning;
	}
}


void Admin::handleFootballerExistance(unordered_map<string, Footballer> players, Footballer& PlayerToBeModified, string& playerName) {
	try {
		cout << "Enter a footballer's Name: ";
		cin >> playerName;
		//fetching the player to update
		PlayerToBeModified = players.at(playerName);
	}
	catch (const std::exception&) {
		cout << "Couldn't Find This Player.." << endl;
		handleFootballerExistance(players, PlayerToBeModified, playerName);
	}
}

void Admin::FootballerMenu(unordered_map<string, Footballer>& players) {
	Footballer footballerToBeModified;
	string footballerName;
	handleFootballerExistance(players, footballerToBeModified, footballerName);
start:
	cout << "1) Modify a Footballer" << endl;
	cout << "2) Go Back" << endl;
	cout << "Choice: " << endl;
	int choice;
	cin >> choice;
	switch (choice) {
	case 1:
		//Updating the player
		ModifyFootballer(players, footballerToBeModified);
		break;
	case 2:
		return;
	default:
		break;
	}
	//Updating the hash table
	players.at(footballerName) = footballerToBeModified;
}

void Admin::ModifyFootballer(unordered_map<string, Footballer> players, Footballer& footballerToBeModified) {
	int choice;
	string InputString;
	float InputInt;
	bool InputBool;

	do
	{
		cout << "Modify " << footballerToBeModified.GetName() << "'s information" << endl;
		cout << "What do you wish to Edit?" << endl;

		cout << "1) Name" << endl;
		cout << "2) Age" << endl;
		cout << "3) Captain" << endl;
		cout << "4) Position" << endl;
		cout << "5) Team" << endl;
		cout << "6) Price" << endl;
		cout << "7) Rating" << endl;
		cout << "8) Delete the Player" << endl;
		cout << "9) Go Back" << endl;

		cin >> choice;

		switch (choice) {
		case 1:
			cout << "Enter new name: ";
			cin >> InputString;
			footballerToBeModified.SetName(InputString);
			break;
		case 2:
			cout << "Enter new age: ";
			cin >> InputInt;
			footballerToBeModified.SetAge(InputInt);
			break;
		case 3:
			cout << "Is the Player a Captain? (1 for Yes / 0 for No): ";
			cin >> InputBool;
			footballerToBeModified.SetCaptain(InputBool);
			break;
		case 4:
			cout << "Enter new position: ";
			cin >> InputString;
			footballerToBeModified.SetPosition(InputString);
			break;
		case 5:
			cout << "Enter new team: ";
			cin >> InputString;
			footballerToBeModified.SetTeam(InputString);
			break;
		case 6:
			cout << "Enter new price: ";

			cin >> InputInt;
			footballerToBeModified.SetPrice(InputInt);
			break;
		case 7:
			cout << "Enter new rating: ";
			cin >> InputInt;
			footballerToBeModified.SetRating(InputInt);
			break;
		case 8:
			players.erase(footballerToBeModified.GetName());
			cout << "Deleted Successfully!" << endl;
			Sleep(300);
			continue;
		case 9:
			//test this pls
			return;
		default:
			cout << "Invalid choice!" << endl;
			Sleep(300);
			continue;
		}

		cout << "Successfully Updated." << endl;
		Sleep(300);
		cout << "Continue Modifying? (Yes/No)" << endl;
		cin >> InputString;
		PauseAndClear();
	} while (InputString == "Yes" || "yes" || "YES");

}
void Admin::handleTeamExistance(map<string, Teams> teams, Teams& TeamToBeModified, string teamName) {
	try {
		cout << "Enter a Team Name: ";
		TeamToBeModified = Teams::getTeamByName(teams, /*this is the teamName*/ teamName);
	}
	catch (const std::exception&) {
		cout << "Invalid Team Name!" << endl;
		Sleep(200);
	}
}

void Admin::DisplayFootballersForSpecificTeam(map<string, Teams> teams) {
	string teamName;
	cout << "Enter a Team Name: ";
	cin >> teamName;
	handleTeamExistance(teams, teams.at(teamName), teamName);
	unordered_map<string, Footballer> TeamSquad = teams.at(teamName).getFootballPlayer();
	unordered_map<string, Footballer>::iterator it;
	it = TeamSquad.begin();
	cout << "Team: " << teamName << endl;
	for (it; it != TeamSquad.end(); ++it) {
		cout << it->first << endl;
	}
	FootballerMenu(TeamSquad);
	return;
}

//vector<TheLeague> allleagues
//unordered_map of user
//map ll team
//unordered map ll footballer

void Admin::LeaguesMenu(vector<TheLeague> leagues, map<string, Teams> teams) {
	int choice;
	string leagueName;
	string newLeagueName;
	DisplayAllLeagues(leagues);
	cout << "1) Select a TheLeague to Show it's Teams" << endl;
	cout << "2) Select a TheLeague to Edit it's Name" << endl;
	cout << "3) Go Back" << endl;
	cin >> choice;
	if (choice == 1) {
		displayTeamsForSpecificLeague(leagues);
		ModifyTeams(teams);
	}
	else if (choice == 2) {
		UpdateLeagueName(leagues);
	}
	else if (choice == 3) {
		return;
	}
	else {
		cout << "Invalid choice!" << endl;
	}
}

void Admin::DisplayAllLeagues(vector<TheLeague> leagues) {
	for (int i = 0; i < leagues.size(); ++i) {
		cout << leagues[i].getLeagueName() << endl;
	}
}

void Admin::UpdateLeagueName(vector<TheLeague> leagues) {
	string leagueName;
	string newLeagueName;
	vector<TheLeague>::iterator it = leagues.begin();
beginning:
	cout << "Enter a TheLeague Name: ";
	cin >> leagueName;
	while (it != leagues.end()) {
		int i = 0;
		if (leagues[i].getLeagueName() == leagueName) {

			cout << "Enter the new Name: ";
			cin >> newLeagueName;
			leagues[i].setLeagueName(newLeagueName);
			break;
		}
		it++;
	}
	if (it == leagues.end()) {
		cout << "Invalid TheLeague Name!" << endl;
		Sleep(300);
		goto beginning;
	}
}

void Admin::PauseAndClear()
{
	system("pause");
	system("cls");
}