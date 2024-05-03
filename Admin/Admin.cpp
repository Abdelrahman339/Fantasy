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

using namespace std;

int counter = 0;
bool answer = false;

bool Admin::CheckAdmin()
{
	int count = 1;
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
			return true;
		}
		else if (count == 3)
		{
			return false;
		}
		else
		{
			cout << endl << "Wrong Admin Username Or Password" << endl;
			cout << "Please Try Again...  " << count << " / 3\n";
			count++;
			PauseAndClear();
		}
	} while (true);
}

void Admin::AdminMenu(unordered_map<string, User>& Users/*, unordered_map<string, Teams>& Team, unordered_map<string, Leagues>& League*/)
{
	if (CheckAdmin())
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
			AboutUsers(Users/*, Team, League*/);
		}
		else if (choice == 2)
		{

		}
		else if (choice == 3)
		{

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
	else
	{
		cout << "Failed To Enter Admin Menu   3 / 3" << endl;
		cout << "Going Back To Home Page..." << endl;
		Sleep(3200);
		system("cls");
		return;
	}
}

void Admin::AboutUsers(unordered_map<string, User>& Users/*, unordered_map<string, Teams>& Team, unordered_map<string, Leagues>& League*/)
{
	int choice;
Choose:
	cout << endl;
	DisplayAllUsers(Users);
	cout << "1-Add New User \n2-About User \n3-User Squad And Players\n4-Delete User \n5-Go Back" << endl;
	cout << "Enter your choice: ";
	cin >> choice;
	if (choice == 1)
	{
		User::signup(Users);
		cout << "Successfully Added Your New User " << endl;
		PauseAndClear();
		goto Choose;
	}
	if (choice == 2)
	{
		ShowAndEditUser(Users);
		PauseAndClear();
		goto Choose;
	}
	else if (choice == 3)
	{
		UserSquadAndPlayers(Users);
		PauseAndClear();
		goto Choose;
	}
	else if (choice == 4)
	{
		answer = true;
		DeleteUser(Users);
		PauseAndClear();
		goto Choose;
	}
	else if (choice == 5)
	{
		AdminMenu(Users/*, Team, League*/);////////////////////////////////
	}
	else
	{
		system("cls");
		cout << endl << "Please select a valid choice.." << endl;
		goto Choose;
	}
}

void Admin::DisplayAllUsers(unordered_map<string, User>& Users)
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

void Admin::ShowAndEditUser(unordered_map<string, User>& Users)
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
		ShowAndEditUser(Users);
	}
	else
	{
		ViewProfile(Users, Users.at(userName));
	}
}
void Admin::ViewProfile(unordered_map<string, User>& Users, User& currentUser)
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
	cout << endl;
	cout << "1-Edit User Information\n2-User Squad And Players\n3-Delete User \n4-Go Back" << endl;
	cout << "Enter your choice: ";
	cin >> choice;
	if (choice == 1)
	{
		EditProfile(Users, currentUser);
	}
	else if (choice == 2)
	{
		User::ShowSquad(currentUser);
		ViewProfile(Users, currentUser);
	}
	else if (choice == 3)
	{
		Deletion(Users, currentUser);
	}
	else if (choice == 4)
	{
		AboutUsers(Users);
	}
	else
	{
		system("cls");
		cout << endl << "Please select a valid choice.." << endl;
		goto choices;
	}
}
void Admin::EditProfile(unordered_map<string, User>& Users, User& currentUser)
{
	bool valid = false;
	int choice;
choices:
	Sleep(200);
	cout << "1-Edit Full Name.\n2-Edit Username\n3-Edit Email Address.\n4-Edit Phone Number.\n5-Edit Password.\n6-Edit Balance\n7-Edit Points\n8-Edit Rank\n9-Go Back" << endl;
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
		UserValidations::usernameCheck(Users, currentUser);
		if (it != Users.end())
		{
			Users.insert({ currentUser.GetUsername(), it->second });//updated username
			Users.erase(it);//erasing old username
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
		EditBalancePointsRank(currentUser, 1, "new Balance");
		cout << "Balance updated successfully" << endl;
		PauseAndClear();
	}
	else if (choice == 7)
	{
		EditBalancePointsRank(currentUser, 2, "new Points");
		cout << "Points updated successfully" << endl;
		PauseAndClear();
	}
	else if (choice == 8)
	{
		EditBalancePointsRank(currentUser, 3, "new Rank");
		cout << "Rank updated successfully" << endl;
		PauseAndClear();
	}
	else if (choice == 9)
	{
		ViewProfile(Users, currentUser);
	}
	else
	{
		system("cls");
		cout << endl << "Please select a valid choice.." << endl;
		goto choices;
	}
	if (valid)
	{
		ViewProfile(Users, currentUser);
	}
	else
	{
		Users[currentUser.GetUsername()] = currentUser;
		ViewProfile(Users, currentUser);
	}
}
static bool isInteger(string& input)
{
	istringstream iss(input);
	int value;
	if (iss >> value) {
		// Check if the entire string was consumed by the conversion
		return iss.eof() && !iss.fail();
	}
	return false;
}
static bool isFloat(string& input)
{
	istringstream iss(input);
	double value;
	if (iss >> value) {
		// Check if the entire string was consumed by the conversion
		return iss.eof() && !iss.fail();
	}
	return false;
}
void Admin::EditBalancePointsRank(User& CurrentUser, int choice, string information)
{
	string NewBalance = "1", NewPointsOrRank = "1";
Redo:
	cout << "Enter Your " << information << ": " << endl;
	if (information == "new Balance")
	{
		getline(cin, NewBalance);
	}
	else
	{
		getline(cin, NewPointsOrRank);
	}
	if (!isInteger(NewBalance) && !isFloat(NewBalance))
	{
		cout << "Your " << information << " Must Be A Value!" << endl;
		goto Redo;
	}
	else if (!isInteger(NewPointsOrRank))
	{
		cout << "Your " << information << " Must Be Integer!" << endl;
		goto Redo;
	}
	else
	{
		if (stof(NewBalance) < 0 || stoi(NewPointsOrRank) < 0)
		{
			cout << "Your " << information << " Cannot Be Negative" << endl;
			goto Redo;
		}
		else if (stoi(NewPointsOrRank) == 0 && choice == 3)
		{
			cout << "Your " << information << " Cannot Be Zero" << endl;
			goto Redo;
		}
		else
		{
			if (choice == 1)
			{
				CurrentUser.SetBalance(stof(NewBalance));
			}
			else if (choice == 2)
			{
				CurrentUser.SetPoints(stoi(NewPointsOrRank));
			}
			else if (choice == 3)
			{
				CurrentUser.SetRank(stoi(NewPointsOrRank));
			}
		}
	}
}
void Admin::UserSquadAndPlayers(unordered_map<string, User>& Users)
{
	string userName;
	cout << "Enter Username To Display User Squad: " << endl;
	cout << "Username: ";
	cin >> userName;
	if (Users.find(userName) == Users.end())
	{
		cout << "User Does Not Exist, Please Enter An Existing User" << endl;
		Sleep(200);
		UserSquadAndPlayers(Users);
	}
	else
	{
		User::ShowSquad(Users.at(userName));
		AboutUsers(Users);
	}
}

void Admin::DeleteUser(unordered_map<string, User>& Users)
{
	string userName;
	if (counter == 0)
	{
		cout << "No Users To Delete" << endl;
		AboutUsers(Users);
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
			DeleteUser(Users);
		}
		else
		{
			Deletion(Users, Users.at(userName));
		}
	}
}

void Admin::Deletion(unordered_map<string, User>& Users, User CurrentUser)
{
	int choice;
	cout << "Are you sure you want to delete " << CurrentUser.GetUsername() << "?" << endl;
	cout << "1. Yes \n2. No" << endl;
	cout << "Enter your choice: ";
	cin >> choice;
	if (choice == 1)
	{
		Users.erase(CurrentUser.GetUsername());
		cout << "Successfully Deleted User " << CurrentUser.GetUsername() << endl;
		counter--;
	}
	else if (choice == 2)
	{
		if (answer)
		{
			cout << "Returning Back To The User Menu..." << endl;
			Sleep(500);
			answer = false;
			AboutUsers(Users);
		}
		else
		{
			Sleep(200);
			ViewProfile(Users, CurrentUser);
		}
	}
	else
	{
		cout << "Please select a valid choice." << endl;
		Deletion(Users, CurrentUser);
	}
}

//void Admin::displayTeamsForSpecificLeague(unordered_map<string, League> leagues){
//	cout << "Choose a League to show all";
//}

//Footballer* Admin::getFootballerToBeUpdated(vector<League> allleagues, string teamName, string footballerName) {
//	Teams team = Teams::getTeamByName(allleagues, teamName);
//	Footballer* footballerToBeUpdated = team.getFootballerByTeamName(team, footballerName);
//	return footballerToBeUpdated;
//}

//void Admin::updateFootballer(Footballer* footballerToBeUpdated, vector<League> allleagues, string teamName, string footballerName) {
//	int choice;
//	string InputString;
//	float InputInt;
//	bool InputBool;
//	footballerToBeUpdated = getFootballerToBeUpdated(allleagues, teamName, footballerName);
//
//	do
//	{
//	beginning:
//		cout << "Update " << footballerToBeUpdated->GetName() << "'s info" << endl;
//		cout << "What do you wish to modify?" << endl;
//		cout << "1) Name" << endl;
//		cout << "2) Age" << endl;
//		cout << "3) Captain" << endl;
//		cout << "4) Position" << endl;
//		cout << "5) Team" << endl;
//		cout << "6) Price" << endl;
//		cout << "7) Rating" << endl;
//
//		cin >> choice;
//
//		switch (choice) {
//		case 1:
//			cout << "Enter new name: ";
//			cin >> InputString;
//			footballerToBeUpdated->SetName(InputString);
//			break;
//		case 2:
//			cout << "Enter new age: ";
//			cin >> InputInt;
//			footballerToBeUpdated->SetAge(InputInt);
//			break;
//		case 3:
//			cout << "Is the Player a Captain? (1 for Yes / 0 for No): ";
//			cin >> InputBool;
//			footballerToBeUpdated->SetCaptain(InputBool);
//			break;
//		case 4:
//			cout << "Enter new position: ";
//			cin >> InputString;
//			footballerToBeUpdated->SetPosition(InputString);
//			break;
//		case 5:
//			cout << "Enter new team: ";
//			cin >> InputString;
//			footballerToBeUpdated->SetTeam(InputString);
//			break;
//		case 6:
//			cout << "Enter new price: ";
//
//			cin >> InputInt;
//			footballerToBeUpdated->SetPrice(InputInt);
//			break;
//		case 7:
//			cout << "Enter new rating: ";
//			cin >> InputInt;
//			footballerToBeUpdated->SetRating(InputInt);
//			break;
//		default:
//			cout << "Invalid choice!" << endl;
//			Sleep(300);
//			goto beginning;
//		}
//		cout << "Successfully Updated." << endl;
//		Sleep(300);
//		cout << "Continue Modifying? (Yes/No)" << endl;
//		cin >> InputString;
//		PauseAndClear();
//	} while (InputString == "Yes" || "yes" || "YES");
//
//}

//void Admin::DisplayAllLeagues(unordered_map<string, League> leagues) {
//	for (auto it = leagues.begin(); it != leagues.end(); ++it) {
//		cout << it->first << endl;
//	}
//}

void Admin::PauseAndClear()
{
	system("pause");
	system("cls");
}