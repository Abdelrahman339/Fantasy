#include <iostream>
#include <string>
#include <algorithm>
#include <sstream>
#include <limits>
#include<Windows.h>
#include "Admin.h"
#include "User.h"
#include "Teams.h"
#include "TheLeague.h"
#include "UserValidations.h"
#undef max

using namespace std;

int counter = 0;
bool answer = false;

void Admin::CheckAdmin(unordered_map<string, User>& Users, vector<TheLeague> leagues)
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
			AdminMenu(Users, leagues);
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

void Admin::AdminMenu(unordered_map<string, User>& Users, vector<TheLeague> leagues)
{
	int choice;
Menu:
	system("cls");
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
		AboutUsers(Users, leagues);
		return;
	}
	else if (choice == 2)
	{
		TeamMenu(leagues);
		goto Menu;
	}
	else if (choice == 3)
	{
		LeaguesMenu(leagues);
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




void Admin::AboutUsers(unordered_map<string, User>& Users, vector<TheLeague> leagues)
{
	int choice;
Choose:
	cout << endl;
	DisplayAllUsers(Users, leagues);
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
		ShowAndEditUser(Users, leagues);
		PauseAndClear();
	}
	else if (choice == 3)
	{
		UserSquadAndPlayers(Users, leagues);
		PauseAndClear();
	}
	else if (choice == 4)
	{
		answer = true;
		DeleteUser(Users, leagues);
		PauseAndClear();
	}
	else if (choice == 5)
	{
		AdminMenu(Users, leagues);
		return;
	}
	else
	{
		system("cls");
		cout << endl << "Please select a valid choice.." << endl;
		goto Choose;
	}
}

void Admin::DisplayAllUsers(unordered_map<string, User>& Users, vector<TheLeague> leagues)
{
	counter = 0;
	Sleep(1000);
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

void Admin::ShowAndEditUser(unordered_map<string, User>& Users, vector<TheLeague> leagues)
{
	string userName;
	cout << "Enter Username To Show User Information: " << endl;
	cout << "Username: ";
	cin >> userName;
	cout << endl;
	if (Users.find(userName) == Users.end())
	{
		cout << "User Does Not Exist, Please Enter An Existing User" << endl;
		Sleep(700);
		ShowAndEditUser(Users, leagues);
	}
	else
	{
		ViewProfile(Users, Users.at(userName), leagues);
	}
}
void Admin::ViewProfile(unordered_map<string, User>& Users, User& currentUser, vector<TheLeague> leagues)
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
		EditProfile(Users, currentUser, leagues);
	}
	else if (choice == 2)
	{
		User::ShowSquad(currentUser);
		ViewProfile(Users, currentUser, leagues);
	}
	else if (choice == 3)
	{
		answer = false;
		Deletion(Users, currentUser, leagues);
	}
	else if (choice == 4)
	{
		AboutUsers(Users, leagues);
		return;
	}
	else
	{
		system("cls");
		cout << endl << "Please select a valid choice.." << endl;
		goto choices;
	}
}
void Admin::EditProfile(unordered_map<string, User>& Users, User& currentUser, vector<TheLeague> leagues)
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
		EditBalancePointsRank(currentUser, 1, "new Balance", leagues);
		cout << "Balance updated successfully" << endl;
		PauseAndClear();
	}
	else if (choice == 7)
	{
		EditBalancePointsRank(currentUser, 2, "new Points", leagues);
		cout << "Points updated successfully" << endl;
		PauseAndClear();
	}
	else if (choice == 8)
	{
		EditBalancePointsRank(currentUser, 3, "new Rank", leagues);
		cout << "Rank updated successfully" << endl;
		PauseAndClear();
	}
	else if (choice == 9)
	{
		ViewProfile(Users, currentUser, leagues);
	}
	else
	{
		cout << endl << "Please select a valid choice.." << endl;
		goto choices;
	}
	if (valid)
	{
		ViewProfile(Users, currentUser, leagues);
		return;
	}
	else
	{
		Users[currentUser.GetUsername()] = currentUser;
		ViewProfile(Users, currentUser, leagues);
		return;
	}
}
void Admin::EditBalancePointsRank(User& CurrentUser, int choice, string information, vector<TheLeague> leagues)
{
	float NewBalance = 1;
	int NewPointsOrRank = 1;
Redo:
	cout << "Enter Your " << information << ": " << endl;
	if (information == "new Balance")
	{
		cin >> NewBalance;
		if (!CheckBalancePointsRank(information, leagues))
		{
			goto Redo;
		}
	}
	else
	{
		cin >> NewPointsOrRank;
		if (CheckBalancePointsRank(information, leagues))
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
bool Admin::CheckBalancePointsRank(string information, vector<TheLeague> leagues)
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
void Admin::UserSquadAndPlayers(unordered_map<string, User>& Users, vector<TheLeague> leagues)
{
	string userName;
	cout << "Enter Username To Display User Squad: " << endl;
	cout << "Username: ";
	cin >> userName;
	if (Users.find(userName) == Users.end())
	{
		cout << "User Does Not Exist, Please Enter An Existing User" << endl;
		Sleep(700);
		UserSquadAndPlayers(Users, leagues);
	}
	else
	{
		User::ShowSquad(Users.at(userName));
		AboutUsers(Users, leagues);
	}
}

void Admin::DeleteUser(unordered_map<string, User>& Users, vector<TheLeague> leagues)
{
	string userName;
	if (counter == 0)
	{
		cout << "No Users To Delete" << endl;
		AboutUsers(Users, leagues);
	}
	else
	{
		cout << "Enter Username To Delete User: " << endl;
		cout << "Username: ";
		cin >> userName;
		if (Users.find(userName) == Users.end())
		{
			cout << "User Does Not Exist, Please Enter An Existing User" << endl;
			Sleep(700);
			DeleteUser(Users, leagues);
		}
		else
		{
			Deletion(Users, Users.at(userName), leagues);
		}
	}
}

void Admin::Deletion(unordered_map<string, User>& Users, User CurrentUser, vector<TheLeague> leagues)
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
			AboutUsers(Users, leagues);
		}
		else
		{
			Sleep(700);
			ViewProfile(Users, CurrentUser, leagues);
		}
	}
	else
	{
		cout << "Please Select a Valid Choice.." << endl;
		Deletion(Users, CurrentUser, leagues);
	}
}

void Admin::TeamMenu(vector<TheLeague> leagues) {
	int choice = -1;
	int InputInt = -1;
	string leagueName;
	TheLeague leagueToBeModified;
	cin.ignore();
beginning:
	cout << "Enter a League Name: ";
	getline(cin, leagueName);
	vector<TheLeague>::iterator it;
	if (!handleLeagueExistance(leagues, leagueToBeModified, leagueName)) {
		goto beginning;
	}
start:
	displayTeamsForSpecificLeague(leagueToBeModified);
	cout << "1) Modify a Team" << endl;
	cout << "2) Display Footballers in a Team" << endl;
	cout << "3) Go Back" << endl;
	cout << "Choice: ";
	cin >> choice;
	if (choice == 1) {
		ModifyTeams(leagueToBeModified.GetTeams());
		goto start;
	}
	else if (choice == 2) {
		FootballerMenu(leagueToBeModified.GetTeams());
		goto start;

	}
	else if (choice == 3) {
		return;
	}
	else {
		cout << "Invalid Choice!" << endl;
		choice = -1;
		goto start;
	}
}

void Admin::ModifyTeams(map<string, Teams>& teams) {
	Teams TeamToBeModified;
	int choice;
	string teamName;
	string InputString;
	int InputInt;
TeamNotFound:
	cout << "Enter Team Name: ";
	cin.ignore();
	getline(cin, teamName);
	if (!handleTeamExistance(teams, TeamToBeModified, teamName)) {
		goto TeamNotFound;
	}
	system("cls");
	do {
	ModifySameTeam:
		cout << "\tModifying " << teams[TeamToBeModified.getName()].getName() << " information" << endl;
		cout << "--------------------------------------------------" << endl;
		cout << "What do you wish to Edit?" << endl;
		cout << "1) Name" << endl;
		cout << "2) Points" << endl;
		cout << "3) Delete the Team" << endl;
		cout << "4) Go Back" << endl;
		cout << "Choice: ";
		cin >> choice;

		switch (choice) {
		case 1:
			handleTeamsUpdate(teams, teamName);
			break;
		case 2:
			cout << "Enter new Points: ";
			cin >> InputInt;
			teams[TeamToBeModified.getName()].SetPoints(InputInt);
			cout << "Updated Successfully!" << endl;
			break;
		case 3:
			teams.erase(TeamToBeModified.getName());
			cout << "Deleted Successfully!" << endl;
			Sleep(1000);
			break;
		case 4:
			return;
		default:
			cout << "Invalid Choice!" << endl;
			Sleep(1000);
			goto ModifySameTeam;
		}
		cout << "Continue Modifying? (Yes/No)" << endl;
		cout << "Answer: ";
		cin.ignore();
		getline(cin, InputString);
	} while (InputString._Starts_with("yes") || InputString._Starts_with("Yes"));
	return;
}

void Admin::displayTeamsForSpecificLeague(TheLeague league) {
	system("cls");
	cout << "\t\t~" << league.getLeagueName() << " Teams~" << endl << endl;
	TheLeague::displayTeams(league.GetTeams());
}


bool Admin::handleFootballerExistance(unordered_map<string, Footballer> players, Footballer& PlayerToBeModified, string& playerName) {
	auto it = players.find(playerName);
	if (it != players.end()) {
		PlayerToBeModified = it->second;
		return true;
	}
	else {
		cout << "Couldn't Find This Footballer.." << endl;
		Sleep(700);
		return false;
	}
}

void Admin::FootballerMenu(map<string, Teams> teams) {
	string teamName;
	Teams selectedTeam;
	cin.ignore();
TeamNotFound:
	cout << "Enter a Team Name: ";
	getline(cin, teamName);
	if (!handleTeamExistance(teams, selectedTeam, teamName)) {
		goto TeamNotFound;
	}
footballersDisplay:
	DisplayFootballersForSpecificTeam(selectedTeam);
	cout << "1) Modify a Footballer" << endl;
	cout << "2) Go Back" << endl;
	cout << "Choice: ";
	int choice;
	cin >> choice;
	switch (choice) {
	case 1:
		//Updating the player
		ModifyFootballer(selectedTeam.getFootballPlayer());
		goto footballersDisplay;
	case 2:
		return;
	default:
		break;
	}
}

void Admin::ModifyFootballer(unordered_map<string, Footballer>& players) {
	int choice;
	string InputString;
	float InputInt;
	bool InputBool;
	Footballer footballerToBeModified;
	string footballerName;
	cin.ignore();
PlayerNotFound:
	cout << "Enter a footballer's Name: ";
	getline(cin, footballerName);
	if (!handleFootballerExistance(players, footballerToBeModified, footballerName)) {
		goto PlayerNotFound;
	}
	system("cls");
	do {
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
		cout << "Choice: ";
	retryChoice:
		cin >> choice;
		switch (choice) {
		case 1:
			handlePlayersUpdate(players, footballerName);
			break;
		case 2:
		retryAgeInput:
			cout << "Enter new age: ";
			cin >> InputInt;
			if (InputInt < 17) {
				cout << "Age should be more than 17 years old." << endl;
				Sleep(2000);
				goto retryAgeInput;
			}
			else {
				footballerToBeModified.SetAge(InputInt);
				break;
			}
		case 3:
			cout << "Is the Player a Captain? (1 for Yes / 0 for No): ";
			cin >> InputBool;
			footballerToBeModified.SetCaptain(InputBool);
			break;
		case 4:
			cout << "Enter new position: ";
			cin.ignore();
			getline(cin, InputString);
			footballerToBeModified.SetPosition(InputString);
			break;
		case 5:
			cout << "Enter new team: ";
			cin.ignore();
			getline(cin, InputString);
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
			break;
		case 9:
			return;
		default:
			cout << "Invalid choice!" << endl;
			Sleep(1000);
			goto retryChoice;
		}
		if (choice == 8) {
			cout << "Deleted Successfully!" << endl;

		}
		else if (choice == 1) {
			cout << "Successfully Updated." << endl;

		}
		else {
			cout << "Successfully Updated." << endl;
			//Updating the hash table
			players.at(footballerName) = footballerToBeModified;
		}
		Sleep(1000);
		cout << "Continue Modifying? (Yes/No)" << endl;
		cin.ignore();
		getline(cin, InputString);
		system("cls");
	} while (InputString._Starts_with("yes") || InputString._Starts_with("Yes"));

}
bool Admin::handleTeamExistance(map<string, Teams> teams, Teams& TeamToBeModified, string teamName) {
	TeamToBeModified = Teams::getTeamByName(teams, teamName);
	if (!TeamToBeModified.getName()._Equal(teamName)) {
		cout << "Invalid Team Name!" << endl;
		Sleep(700);
		return false;
	}
	return true;
}

void Admin::handleTeamsUpdate(map<string, Teams>& teams, string oldName){
	string newName;
	cout << "Enter new name: ";
	cin.ignore();
	getline(cin, newName);
	auto it = teams.find(oldName);
	if (it != teams.end()) {
		teams[newName] = it->second;
		teams[newName].SetName(newName);
		teams.erase(it);
	}
	else {
		cout << "Key " << oldName << " not found." << endl;
	}
}

void Admin::DisplayFootballersForSpecificTeam(Teams selectedTeam) {
	unordered_map<string, Footballer> players = selectedTeam.getFootballPlayer();
	unordered_map<string, Footballer>::iterator it = players.begin();
	system("cls");
	cout << "\t\t~Players in " << selectedTeam.getName() << "~" << endl;
	cout << "------------------------------------------------" << endl;
	cout << "\t  Name" << User::spacing(15, ' ') << "\tPosition" << endl << endl;
	for (it; it != players.end(); ++it) {
		cout << "\t" << it->second.GetName() << "\t" << checkStrLengthFootballers(it->first) << it->second.GetPosition() << endl;
	}
	cout << "------------------------------------------------" << endl;
}

//vector<TheLeague> allleagues
//unordered_map of user
//map ll team
//unordered map ll footballer

bool Admin::handleLeagueExistance(vector<TheLeague> leagues, TheLeague& leagueToBeModified, string leagueName)
{
	for (int i = 0; i < leagues.size(); i++) {
		if (leagues[i].getLeagueName() == leagueName) {
			leagueToBeModified = leagues[i];
			return true;
		}
	}
	cout << "Invalid League Name!" << endl;
	Sleep(700);
	return false;
}

void Admin::LeaguesMenu(vector<TheLeague>& leagues) {
	int choice;
	string leagueName;
	string newLeagueName;
LeagueMenu:
	system("cls");
	DisplayAllLeagues(leagues);
	cout << "1) Select a League to Show it's Teams" << endl;
	cout << "2) Select a League to Edit it's Name" << endl;
	cout << "3) Go Back" << endl;
	cout << "Choice: ";
	cin >> choice;
	if (choice == 1) {
		TeamMenu(leagues);
		goto LeagueMenu;
	}
	else if (choice == 2) {
		UpdateLeagueName(leagues);
		goto LeagueMenu;
	}
	else if (choice == 3) {
		return;
	}
	else {
		cout << "Invalid Choice!" << endl;
		Sleep(1000);
		goto LeagueMenu;
	}
}

void Admin::DisplayAllLeagues(vector<TheLeague> leagues) {
	vector<TheLeague>::iterator it;
	cout << "\t\t~All Leagues~" << endl;
	cout << "------------------------------------------------" << endl;
	for (it = leagues.begin(); it != leagues.end(); ++it) {
		cout << "\t\t" << it->getLeagueName() << std::endl;
	}
	cout << "------------------------------------------------" << endl;

}

void Admin::UpdateLeagueName(vector<TheLeague>& leagues) {
	string leagueName;
	string newLeagueName;
	TheLeague leagueToBeModified;
	cin.ignore();
beginning:
	cout << "Enter a League Name: ";
	getline(cin, leagueName);
	if (!handleLeagueExistance(leagues, leagueToBeModified, leagueName)) {
		goto beginning;
	}
	else {
		cout << "Enter the new Name: ";
		getline(cin, newLeagueName);
		for (int i = 0; i < leagues.size(); i++) {
			if (leagues[i].getLeagueName() == leagueName) {
				leagues[i].setLeagueName(newLeagueName);
				cout << "Updated Successfully!" << endl;
				Sleep(1000);
			}
		}
	}
}

void Admin::handlePlayersUpdate(unordered_map<string, Footballer>& players, string oldName) {
	string newName;
	cout << "Enter new name: ";
	cin.ignore();
	getline(cin, newName);
	auto it = players.find(oldName);
	if (it != players.end()) {
		// Inserting a new element with the new key and same value
		players[newName] = it->second;
		players[newName].SetName(newName);
		// Erasing the old element
		players.erase(it);
	}
	else {
		cout << "Key " << oldName << " not found." << endl;
	}
}

string Admin::checkStrLengthFootballers(string str) {
	if (str.length() < 16 && str.length() >= 8) {
		return "\t";
	}
	else if (str.length() < 8) {
		return "\t\t";
	}
	return "";
}

void Admin::PauseAndClear()
{
	system("pause");
	system("cls");
}