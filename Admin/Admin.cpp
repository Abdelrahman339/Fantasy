#include <iostream>
#include <string>
#include<Windows.h>
#include "Admin.h"
#include "User.h"
#include "Teams.h"
#include"Leagues.h"
#include "UserValidations.h"
using namespace std;

int counter = 0;
bool answer = false;

void Admin::AdminMenu(unordered_map<string, User>& Users/*, unordered_map<string, Teams>& Team, unordered_map<string, Leagues>& League*/)
{
	int choice;
	cout << "\t     Admin Menu" << endl;
	cout << "--------------------------------------" << endl;
Menu:
	cout << "1-About Users \n2-About Teams \n3-About Leagues \n4-Go Back" << endl;
	cout << "--------------------------------------" << endl;
	cout << "Enter your choice: ";
	cin >> choice;
	cout << endl;
	if (choice == 1)
	{
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
		User::homePage(Users);
	}
	else
	{
		cout << "Please select a valid choice." << endl;
		system("cls");
		goto Menu;
	}
}

void Admin::AboutUsers(unordered_map<string, User>& Users/*, unordered_map<string, Teams>& Team, unordered_map<string, Leagues>& League*/)
{
	int choice;
Choose:
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
		answer = true;
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
		cout << "Please select a valid choice." << endl;
		system("cls");
		goto Choose;
	}
}

void Admin::DisplayAllUsers(unordered_map<string, User>& Users)
{
	counter = 0;
	Sleep(300);
	cout << "\t| Full Name\t| User Name" << endl;
	cout << "---------------------------------------------" << endl;
	for (auto it = Users.begin(); it != Users.end(); ++it)
	{
		cout << counter + 1 << "\t|" << Users.at(it->first).GetFullName() << "\t\t|" << it->first << endl;
		counter++;
	}
	cout << "---------------------------------------------" << endl;
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
		//lsa feh func t5leh y2dr y8yr el user balance, points, rank
		Users.at(userName).SetUsername(userName);
		ViewProfile(Users, Users.at(userName));
	}
}
void Admin::ViewProfile(unordered_map<string, User>& Users, User currentUser)
{
	int choice;
	cout << "User Information And Profile" << endl;
	cout << "--------------------------------------" << endl;
	cout << "Name:" << currentUser.GetFullName() << endl;;
	cout << "Username:" << currentUser.GetUsername() << endl;
	cout << "Email Address:" << currentUser.GetEmail() << endl;
	cout << "Phone number:" << currentUser.GetPhoneNumber() << endl;
	cout << "Password:" << currentUser.GetPassword() << endl;
	//cout << "Id:" << currentUser.GetId() << endl;
	//cout << "Balance:" << currentUser.GetBalance() << endl;
	//cout << "Points:" << currentUser.GetPoints() << endl;
	//cout << "Rank:" << currentUser.GetRank() << endl;
	cout << "--------------------------------------" << endl;
	cout << "1-Edit User Information\n2-User Squad And Players\n3-Delete User \n4-Go Back" << endl;
	cout << "Enter your choice: ";
	cin >> choice;
	if (choice == 1)
	{
		EditProfile(Users, currentUser);
	}
	else if (choice == 2)
	{
		UserSquadAndPlayers(Users);
	}
	else if (choice == 3)
	{
		Deletion(Users, currentUser);
	}
	else if (choice == 4)
	{
		AboutUsers(Users);
	}
}
void Admin::EditProfile(unordered_map<string, User>& Users, User currentUser)
{
	bool valid = false;
	int choice;
	choices:
	cout << "1-Edit Full Name.\n2-Edit Username\n3-Edit Email Address.\n4-Edit Phone Number.\n5-Edit Password.\n6-Edit Balance\n7-Edit Points\n8-Edit Rank\n9-Go Back" << endl;
	cout << "Enter your choice: ";
	cin >> choice;
	if (choice == 1)
	{
		UserValidations::signupinfo(&currentUser, "new Fullname", UserValidations::fullnameCheck, &User::SetFullName);
		cout << "full name updated successfully" << endl;
		system("pause");
		system("cls");
	}
	else if (choice == 2)
	{
		valid = true;
		auto it = Users.find(currentUser.GetUsername());//old username
		UserValidations::usernameCheck(Users, currentUser);
		if (it != Users.end()) 
		{
			Users.insert({ currentUser.GetUsername(), it->second});//updated username
			Users.erase(it);//erasing old username
		}
		else 
		{
			cout << "Username Not Found" << endl;
			valid = false;
		}
		cout << "Username updated successfully" << endl;
		system("pause");
		system("cls");
	}
	else if (choice == 3)
	{
		UserValidations::signupinfo(&currentUser, "new Email", UserValidations::emailAddressCheck, &User::SetEmail);
		cout << "Email updated successfully" << endl;
		system("pause");
		system("cls");
	}
	else if (choice == 4)
	{
		UserValidations::signupinfo(&currentUser, "new PhoneNumber", UserValidations::phoneNumberCheck, &User::SetPhoneNumber);
		cout << "PhoneNumber updated successfully" << endl;
		system("pause");
		system("cls");
	}
	else if (choice == 5)
	{
		UserValidations::signupinfo(&currentUser, "new Password", UserValidations::passwordCheck, &User::SetPassword);
		cout << "Password updated successfully" << endl;
		system("pause");
		system("cls");
	}
	/*else if (choice == 6)
	{
		UserValidations::signupinfo(&currentUser, "new Balance", UserValidations::balanceCheck, &User::SetBalance);
		cout << "Balance updated successfully" << endl;
	}
	else if (choice == 7)
	{
		UserValidations::signupinfo(&currentUser, "new Points", UserValidations::pointsCheck, &User::SetPoints);
		cout << "Points updated successfully" << endl;
	}
	else if (choice == 8)
	{
		UserValidations::signupinfo(&currentUser, "new Rank", UserValidations::rankCheck, &User::SetRank);
		cout << "Rank updated successfully" << endl;
	}*/
	else if (choice == 9)
	{
		ViewProfile(Users, currentUser);
	}
	else
	{
		cout << "Please select a valid choice." << endl;
		system("cls");
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
void Admin::UserSquadAndPlayers(unordered_map<string, User>&Users)
{
	if (answer)
	{
		User CurrentUser;
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
			CurrentUser = Users.at(userName);
			CurrentUser.SetUsername(userName);
			//User::Squad(CurrentUser.TheMainSquad, CurrentUser.SubstitutionSquad);// lma y5osh gowa function Squad w das go back hyro7 fe 7ta tnya 8er el AboutUsers function
			cout << "aaa";
		}
	}
	else
	{
		cout << "test";////////////////////////////////
	}
	answer = false;
};

void Admin::DeleteUser(unordered_map<string, User>& Users)
{
	User CurrentUser;
	string userName;
	if (counter==0)
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
			CurrentUser = Users.at(userName);
			CurrentUser.SetUsername(userName);
			Deletion(Users, CurrentUser);
		}
	}
}

void Admin::Deletion(unordered_map<string, User>& Users, User CurrentUser)
{
	cout << "Are you sure you want to delete " << CurrentUser.GetUsername() << "?" << endl;
	cout << "1. Yes \n2. No" << endl;
	int choice;
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
			AboutUsers(Users);
		}
		else
		{
			ShowAndEditUser(Users);
		}
	}
	else
	{
		cout << "Please select a valid choice." << endl;
		system("cls");
		Deletion(Users, CurrentUser);
	}
	answer = false;
}




void Admin::PauseAndClear()
{
	system("pause");
	system("cls");
}