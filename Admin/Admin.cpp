#include <iostream>
#include <string>
#include<Windows.h>
#include "Admin.h"
#include "User.h"
#include "Teams.h"
#include"Leagues.h"
using namespace std;

bool answer = false;

void Admin::AdminMenu(unordered_map<string, User>& Users/*, unordered_map<string, Teams>& Team, unordered_map<string, Leagues>& League*/)
{
	int choice;
	cout << "\t\t\tAdmin Menu" << endl;
Menu:
	cout << "1-About Users \n2-About Teams \n3-About Leagues \n4-Go Back" << endl;
	cout << "Enter your choice: ";
	cin >> choice;
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
		//User::homePage(Users);
	}
	else
	{
		cout << "Please select a valid choice." << endl;
		goto Menu;
	}
}

void Admin::AboutUsers(unordered_map<string, User>& Users/*, unordered_map<string, Teams>& Team, unordered_map<string, Leagues>& League*/)
{
	User NewUser;
	int choice;
	cout << "Displaying All Users..." << endl;
Choose:
	DisplayAllUsers(Users);
	cout << "1-Add New User \n2-About User \n3-User Squad And Players\n4-Delete User \n5-Go Back" << endl;
	cout << "Enter your choice: ";
	cin >> choice;
	if (choice == 1)
	{
		NewUser.signup(Users);
		cout << "Successfully Added " << NewUser.GetUsername() << " As A New User " << endl;
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
		goto Choose;
	}
}

void Admin::DisplayAllUsers(unordered_map<string, User>& Users)
{
	int counter = 0;
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
	int choice;
	User CurrentUser;
	string userName;
	cout << "Enter Username To Show User Information: "<<endl;
	cout << "Username: ";
	cin >> userName;
	if (Users.find(userName) == Users.end())
	{
		cout << "User Does Not Exist, Please Enter An Existing User" << endl;
		ShowAndEditUser(Users);
	}
	else
	{
		CurrentUser = Users.at(userName);
		CurrentUser.SetUsername(userName);
		CurrentUser.profile(CurrentUser, Users); // lma y5osh gowa function profile w das go back hyro7 fe 7ta tnya 8er el AboutUsers function
		 
		//lsa feh func t5leh y2dr y8yr el user balance, points, rank
		cout << "1-User Squad And Players\n2-Delete User \n3-Go Back" << endl;
		cout << "Enter your choice: ";
		cin >> choice;
		if (choice == 1)
		{
			UserSquadAndPlayers(Users);
		}
		else if (choice == 2)
		{
			Deletion(Users, CurrentUser);
		}
		else if (choice == 3)
		{
			AboutUsers(Users);
		}
	}
}
void Admin::UserSquadAndPlayers(unordered_map<string, User>& Users)
{
	if (answer)
	{
		User CurrentUser;
		string userName;
		cout << "Enter Username To Display User Squad: "<<endl;
		cout << "Username: ";
		cin >> userName;
		if (Users.find(userName) == Users.end())
		{
			cout << "User Does Not Exist, Please Enter An Existing User" << endl;
			UserSquadAndPlayers(Users);
		}
		else
		{
			CurrentUser = Users.at(userName);
			//Users[userName].Squad(CurrentUser.TheMainSquad, CurrentUser.SubstitutionSquad);// lma y5osh gowa function Squad w das go back hyro7 fe 7ta tnya 8er el AboutUsers function
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
	cout << "Enter Username To Delete User: "<<endl;
	cout << "Username: ";
	cin >> userName;
	if (Users.find(userName) == Users.end())
	{
		cout << "User Does Not Exist, Please Enter An Existing User" << endl;
		DeleteUser(Users);
	}
	else
	{
		CurrentUser = Users.at(userName);
		CurrentUser.SetUsername(userName);
		//CurrentUser.GetUsername() = userName;
		Deletion(Users, CurrentUser);
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
		//DisplayAllUsers(Users);
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
		Deletion(Users, CurrentUser);
	}
	answer = false;
}




void Admin::PauseAndClear()
{
	system("pause");
	system("cls");
}