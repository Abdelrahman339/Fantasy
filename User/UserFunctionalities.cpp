#include <iostream>
#include "User.h"
#include "UserValidations.h"
#include "Teams.h"
#include <fcntl.h>
#include <io.h>
#include <iomanip>

using namespace std;
void User::spacing(int spacing, char character) {
	string space(spacing, character);
	cout << space;
};
void User::Squad(vector <Footballer> MainSquad, vector <Footballer> SubstitutionSquad) {
	int choice;
	cout << "your fantasy squad" << endl;
	squadFormat(2, MainSquad);
	choice:
	cout<<"1-Show information about your players\n2-Change your format\n3-Substitution\n4-Go back " << endl;
	cin >> choice;
	if (choice==1)
	{
		showPlayerInfo(MainSquad, SubstitutionSquad);
	}
	else if (choice == 2) {
		cout << "Available formats:" << endl;
		cout << "1- 4 3 3 \n2- 3 4 3\n3- 4 4 2";
		cout << "Choose your new format" << endl;
		cin >> choice;
		if (choice==1)
		{
			squadFormat(1, MainSquad);
		}
		else if (choice == 2) {
			squadFormat(2, MainSquad);
		}		
		
	else if (choice == 3) {
		squadFormat(3, MainSquad);
	}
		}
	else if (choice==3)
	{
		Substitution(MainSquad, SubstitutionSquad);
	}	else if (choice==4)
	{
		//userMenu(this);
	}
	else
	{
		cout << "Invalid choice.Please enter a valid choice" << endl;
		goto choice;
	}
	

}


void User::showPlayerInfo(vector <Footballer> MainSquad, vector <Footballer> SubstitutionSquad) {
	int choice;
	cout << "Choose your footballer to show his information.(use the index)" << endl;
	cin >> choice;
	cout << "--------------------------------------------------------------------------------"<<endl;
	cout << "Name:" << MainSquad.at(choice - 1).GetName();
	cout << "Age:" << MainSquad.at(choice - 1).GetAge();
	cout << "Captain:" << MainSquad.at(choice - 1).GetCaptain();
	cout << "Position:" << MainSquad.at(choice - 1).GetPosition();
	cout << "Price:" << MainSquad.at(choice - 1).GetPrice();
	cout << "Team:" << MainSquad.at(choice - 1).GetTeam();
	cout << "Total goals this season:" << MainSquad.at(choice - 1).GetGoals();
	cout << "Total assists this season:" << MainSquad.at(choice - 1).GetAssists();
	cout << "Total yellow card this season:" << MainSquad.at(choice - 1).GetYellowCard();
	cout << "Total red card this season:" << MainSquad.at(choice - 1).GetRedCard();
	cout << "--------------------------------------------------------------------------------\n" << endl;
	choice:
	cout << "1-Sell this player\n2-Go back" << endl;
	cin >> choice;
	if (choice==1)
	{
		//sell func
	}
	else if (choice==2)
	{
		system("pause");
		system("cls");
		Squad(MainSquad,SubstitutionSquad);
	}
	else
	{
		cout << "Invalid choice.Please enter a valid choice" << endl;
		goto choice;
	}
};


void User::Substitution(vector <Footballer> mainSquad, vector <Footballer> SubstitutionSquad) {
	int choice1;
	int choice2;
	Footballer tempPlayer;
	cout << "Choose player from your main squad to change him (Use the index)" << endl;
	cin>>choice1;
	cout << "Choose player from your main substitution to let him play (Use the index)" << endl;
	cin>>choice2;
	tempPlayer = mainSquad.at(choice1 - 1);
	mainSquad.at(choice1 - 1) = SubstitutionSquad.at(choice2 - 1);
	SubstitutionSquad.at(choice1 - 1) = tempPlayer;
	cout << "Player in your main squad now" << endl;
	system("pause");
	system("cls");
	Squad(mainSquad, SubstitutionSquad);
};

void User::profile(User currentUser, unordered_map<string, User>& Users) {
	int choice;
	cout << "profile" << endl;
	cout << "Name:" << currentUser.GetFullName() << endl;;
	cout << "Username:" << currentUser.GetUsername() << endl;
	cout << "Email Address:" << currentUser.GetEmail()<<endl;
	cout << "Phone number:" << currentUser.GetPhoneNumber() << endl;
	cout << "Password:" << currentUser.GetPassword() << endl;
	//cout << "Id:" << currentUser.GetId() << endl;
	//cout << "Balance:" << currentUser.GetBalance() << endl;
	//cout << "Points:" << currentUser.GetPoints() << endl;
	//cout << "Rank:" << currentUser.GetRank() << endl;
	cout << "--------------------------------------------------------------------------------\n" << endl;
	cout << "1-Edit information.\n2-Go back" << endl;
	cin >> choice;
	if (choice==1)
	{
		editInfo(currentUser, Users);
	}
	else if (choice==2)
	{
		userMenu(currentUser,Users);
	}
};

void User::editInfo(User currentUser, unordered_map<string, User>& Users) {
	int choice;
	invalid:
	cout << "What info you want to update:" << endl;
	cout << "1-Fullname\n2-Username\n3-Email Address\n4-Phone number\n5-Password\n6-Go back" << endl;
	cin >> choice;
	if (choice==1)
	{
		
		UserValidations::signupinfo(&currentUser, "new Fullname", UserValidations::fullnameCheck, &User::SetFullName);
		cout << "full name updated successfully" << endl;
		system("pause");
		system("cls");
		profile(currentUser, Users);
	}
	else if (choice==2)
	{
		UserValidations::usernameCheck(Users, currentUser);
		cout << "Username updated successfully" << endl;
		system("pause");
		system("cls");
		profile(currentUser, Users);
	}	else if (choice==3)
	{
		UserValidations::signupinfo(&currentUser, "new EmailAddress", UserValidations::emailAddressCheck, &User::SetEmail);
		cout << "EmailAddress updated successfully" << endl;
		system("pause");
		system("cls");
		profile(currentUser, Users);
	}	else if (choice==4)
	{
		
		UserValidations::signupinfo(&currentUser, "new PhoneNumber", UserValidations::phoneNumberCheck, &User::SetPhoneNumber);
		cout << "PhoneNumber updated successfully" << endl;
		system("pause");
		system("cls");
		profile(currentUser, Users);
	}	

	else if (choice==5)
	{
		UserValidations::signupinfo(&currentUser, "new Password", UserValidations::passwordCheck, &User::SetPassword);
		cout << "Password updated successfully" << endl;
		system("pause");
		system("cls");
		profile(currentUser, Users);
	}	
	else if (choice==6)
	{
		profile(currentUser, Users);
	}
	else {
		cout << "invalid input.Please select a valid option" << endl;
		goto invalid;
	}
};

void User::squadFormat(int choice, vector <Footballer> MainSquad) {
	if (choice==1)
	{
		//User::Format343(MainSquad);
	}
	else if (choice == 2) {
		User::Format433(MainSquad);
	}
	else if (choice == 3) {
		User::Format442(MainSquad);
	}
	else {
		cout << "invalid input!" << endl;
		cout << "Please select from the available formats." << endl;

	}

};
void User::Format433(vector <Footballer> MainSquad){
	cout << MainSquad.at(0).GetAge();
			wcout << L"①" << endl;
			for ( int i = 1; i < 5; i++)
			{
				cout << MainSquad.at(i).GetAge() << "     ";
			}
			wcout << L"②     ③     ④      ⑤" << endl;
			for (int i = 5; i < 7; i++)
			{
				cout << MainSquad.at(i).GetAge() << "     ";
			}
			wcout << L"⑥     ⑦     ⑧      " << endl;
			for (int i = 8; i < 10; i++)
			{
				cout << MainSquad.at(i).GetAge() << "     ";
			}
			wcout << L"⑨     ⑩     ⑪      " << endl;

};
void User::Format343(){
	_setmode(_fileno(stdout), _O_U16TEXT);
	//cout << MainSquad.at(0).GetName();
	//for (int i = 1; i < 3; i++)
	//{
	//	cout << MainSquad.at(i).GetName() << "     ";
	//}
	//for (int i = 4; i < 7; i++)
	//{
	//	cout << MainSquad.at(i).GetName() << "     ";
	//}
	//for (int i = 8; i < 10; i++)
	//{
	//	cout << MainSquad.at(i).GetName() << "     ";
	//}
	//cout << "format";
	wcout << setw(22)<< L"⑨     ⑩     ⑪      \n\n" << endl;
	wcout << setw(20)<< L"⑤     ⑥     ⑦     ⑧      \n\n" << endl;
	wcout << setw(20)<< L"②     ③     ④   \n\n" << endl;
	wcout << setw(10)<< L"①\n\n" << endl;
};
void User::Format442(vector <Footballer> MainSquad){
	//_setmode(_fileno(stdout), _O_U16TEXT);
	//wcout << L"①" << endl;
	//wcout << L"②     ③     ④   ⑤ " << endl;
	//wcout << L"⑥     ⑦     ⑧   ⑨    " << endl;
	//wcout << L"    ⑩     ⑪      " << endl;
	cout << "format";
};