#include <iostream>
#include <string>
#include <algorithm>
#include<Windows.h>
#include "Admin.h"
#include "User.h"
#include "Teams.h"
#include"Leagues.h"
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
			User::homePage(Users);
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
		User::homePage(Users);
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
	cout << "Id:" << currentUser.GetId() << endl;
	cout << "Balance:" << currentUser.GetBalance() << endl;
	cout << "Points:" << currentUser.GetPoints() << endl;
	cout << "Rank:" << currentUser.GetRank() << endl;
	cout << "--------------------------------------" << endl;
choices:
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
		////////////////////by7sl hena error////////////////////////////////
		User::ShowSquad(currentUser, Users);// lma y5osh gowa function Squad w das go back hyro7 fe 7ta tnya 5ales
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
	/*else if (choice == 6)
	{
		UserValidations::signupinfo(&currentUser, "new Balance", UserValidations::balanceCheck, &User::SetBalance);
		cout << "Balance updated successfully" << endl;
		PauseAndClear();
	}
	else if (choice == 7)
	{
		UserValidations::signupinfo(&currentUser, "new Points", UserValidations::pointsCheck, &User::SetPoints);
		cout << "Points updated successfully" << endl;
		PauseAndClear();
	}
	else if (choice == 8)
	{
		UserValidations::signupinfo(&currentUser, "new Rank", UserValidations::rankCheck, &User::SetRank);
		cout << "Rank updated successfully" << endl;
		PauseAndClear();
	}*/
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
		////////////////////by7sl hena error////////////////////////////////
		Users.at(userName).SetUsername(userName);
		User::ShowSquad(Users.at(userName), Users);// lma y5osh gowa function Squad w das go back hyro7 fe 7ta tnya 5ales
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
			Users.at(userName).SetUsername(userName);
			Deletion(Users, Users.at(userName));
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
			cout << "Returning Back To The User Menu..." << endl;
			Sleep(200);
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