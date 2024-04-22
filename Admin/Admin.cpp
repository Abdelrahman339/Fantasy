//#include <iostream>
//#include <string>
//#include<Windows.h>
//#include "Admin.h"
//#include "User.h"
//#include "Teams.h"
//#include"Leagues.h"
//using namespace std;
//void Admin::AdminMenu(unordered_map<string, User>& Users, unordered_map<string, Teams>& Team, unordered_map<string, Leagues>& League)
//{
//	int choice;
//	cout << "Admin Menu" << endl;
//Menu:
//	cout << "1-About Users \n 2-About Teams \n 3-About Leagues \n 4-Go Back" << endl;
//	cout << "Enter your choice: ";
//	cin >> choice;
//	if (choice == 1)
//	{
//		AboutUsers(Users, Team, League);
//	}
//	else if (choice == 2)
//	{
//		);
//	}
//	else if (choice == 3)
//	{
//
//	}
//	else if (choice == 4)
//	{
//
//		//User::homePage(Users);
//	}
//	else
//	{
//		cout << "Please select a valid choice." << endl;
//		goto Menu;
//	}
//}
//
//void Admin::AboutUsers(unordered_map<string, User>& Users, unordered_map<string, Teams>& Team, unordered_map<string, Leagues>& League)
//{
//	User NewUser;
//	int choice;
//Choose:
//	cout << "1-Display All The Users \n 2-Add New User \n 3-Show And Edit User Information \n 4-User Squad And Players\n 5-Delete User \n 6-Go Back" << endl;
//	cout << "Enter your choice: ";
//	cin >> choice;
//	system("cls");
//	if (choice == 1)
//	{
//		DisplayAllUsers(Users);
//		PauseAndClear();
//	}
//	if (choice == 2)
//	{
//		NewUser.signup(Users);
//		cout << "Successfully Added New User " << endl;
//		PauseAndClear();
//	}
//	else if (choice == 3)
//	{
//		ShowAndEditUser(Users);
//		PauseAndClear();
//	}
//	else if (choice == 4)
//	{
//		UserSquadAndPlayers(Users);
//		PauseAndClear();
//	}
//	else if (choice == 5)
//	{
//		DeleteUser(Users);
//		PauseAndClear();
//	}
//	else if (choice == 6)
//	{
//		AdminMenu(Users, Team, League);////////////////////////////////
//	}
//	else
//	{
//		cout << "Please select a valid choice." << endl;
//		goto Choose;
//	}
//}
//
//void Admin::DisplayAllUsers(unordered_map<string, User>& Users)
//{
//	int index = 1;
//	cout << "Displaying All Users..." << endl;
//	Sleep(300);
//	for (auto it = Users.begin(); it != Users.end(); ++it)
//	{
//		cout << index << "-" << it->first << endl;
//		index++;
//	}
//}
//
//void Admin::ShowAndEditUser(unordered_map<string, User>& Users)
//{
//	User CurrentUser;
//	string userName;
//	string passWord;
//	cout << "Enter Username And Password To Show And Edit User Information: ";
//	cout << "Username: ";
//	cin >> userName;
//	cout << "Password(Press '+' to show password): ";
//	passWord = CurrentUser.hidePassword(userName);
//	if (Users.find(userName) == Users.end() || Users[userName].GetPassword() != passWord)
//	{
//		cout << "User Does Not Exist, Please Enter An Existing User" << endl;
//		ShowAndEditUser(Users);
//	}
//	else
//	{
//		Users[userName].profile(CurrentUser, Users);// lma y5osh gowa function profile w das go back hyro7 fe 7ta tnya 8er el AboutUsers function
//		//lsa feh func t5leh y2dr y8yr el user balance, points, rank
//	}
//}
//
//void Admin::UserSquadAndPlayers(unordered_map<string, User>& Users)
//{
//	User CurrentUser;
//	string userName;
//	string passWord;
//	cout << "Enter Username And Password To Display User Squad: ";
//	cout << "Username: ";
//	cin >> userName;
//	cout << "Password(Press '+' to show password): ";
//	passWord = CurrentUser.hidePassword(userName);
//	if (Users.find(userName) == Users.end() || Users[userName].GetPassword() != passWord)
//	{
//		cout << "User Does Not Exist, Please Enter An Existing User" << endl;
//		UserSquadAndPlayers(Users);
//	}
//	else
//	{
//		Users[userName].Squad(CurrentUser.ThemainSquad(), CurrentUser.SubstitutionSquad());// lma y5osh gowa function Squad w das go back hyro7 fe 7ta tnya 8er el AboutUsers function
//	}
//}
//
//void Admin::DeleteUser(unordered_map<string, User>& Users)
//{
//	User CurrentUser;
//	string userName;
//	string passWord;
//	cout << "Enter Username And Password To Delete User: ";
//	cout << "Username: ";
//	cin >> userName;
//	cout << "Password(Press '+' to show password): ";
//	passWord = CurrentUser.hidePassword(userName);
//	if (Users.find(userName) == Users.end() || Users[userName].GetPassword() != passWord)
//	{
//		cout << "User Does Not Exist, Please Enter An Existing User" << endl;
//		DeleteUser(Users);
//	}
//	else
//	{
//	deleteion:
//		CurrentUser.GetUsername() = userName;
//		cout << "Are you sure you want to delete " << CurrentUser.GetUsername() << "?" << endl;
//		cout << "1. Yes \n 2. No" << endl;
//		int choice;
//		cin >> choice;
//		if (choice == 1)
//		{
//			Users.erase(CurrentUser.GetUsername());
//			cout << "Successfully Deleted User " << CurrentUser.GetUsername() << endl;
//		}
//		else if (choice == 2)
//		{
//			DeleteUser(Users);
//		}
//		else
//		{
//			cout << "Please select a valid choice." << endl;
//			goto deleteion;
//		}
//	}
//}
//void Admin::AboutTeams(unordered_map<string, User>& Users, unordered_map<string, Teams>& Team, unordered_map<string, Leagues>& League)
//{
//	int choice;
//choose:
//	cout << "1-Display All The Teams \n 2-Show And Edit Team Information \n 3-Go Back" << endl;
//	cout << "Enter your choice: ";
//	cin >> choice;
//	system("cls");
//	if (choice == 1)
//	{
//		PauseAndClear();
//	}
//	else if (choice == 2)
//	{
//
//		PauseAndClear();
//	}
//	else if (choice == 3)
//	{
//		AdminMenu(Users, Team, League);////////////////
//	}
//}
//
//
//
//void Admin::PauseAndClear()
//{
//
//	system("pause");
//	system("cls");
//
//}