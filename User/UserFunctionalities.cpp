#include <iostream>
#include "User.h"
#include "Teams.h"
#include <fcntl.h>
#include <io.h>

using namespace std;
void User::Squad(vector <Footballer> MainSquad, vector <Footballer> SubstitutionSquad) {
	int choice;
	cout << "your fantasy squad" << endl;
	squadForamt(2, MainSquad);
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
			squadForamt(1, MainSquad);
		}
		else if (choice == 2) {
			squadForamt(2, MainSquad);
		}		
		
	else if (choice == 3) {
		squadForamt(3, MainSquad);
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
		system("paues");
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
	system("paues");
	system("cls");
	Squad(mainSquad, SubstitutionSquad);
};




void User::squadForamt(int choice, vector <Footballer> MainSquad) {
	if (choice==1)
	{
		User::fomat343(MainSquad);
	}
	else if (choice == 2) {
		User::fomat433(MainSquad);
	}
	else if (choice == 3) {
		User::fomat442(MainSquad);
	}
	else {
		cout << "invlaid input!" << endl;
		cout << "Please select from the available formats." << endl;

	}

};
void User::fomat433(vector <Footballer> MainSquad){
	_setmode(_fileno(stdout), _O_U16TEXT);
	cout << MainSquad.at(0).GetName();
			wcout << L"①" << endl;
			for ( int i = 1; i < 5; i++)
			{
				cout << MainSquad.at(i).GetName() << "     ";
			}
			wcout << L"②     ③     ④      ⑤" << endl;
			for (int i = 5; i < 7; i++)
			{
				cout << MainSquad.at(i).GetName() << "     ";
			}
			wcout << L"⑥     ⑦     ⑧      " << endl;
			for (int i = 8; i < 10; i++)
			{
				cout << MainSquad.at(i).GetName() << "     ";
			}
			wcout << L"⑨     ⑩     ⑪      " << endl;

};
void User::fomat343(vector <Footballer> MainSquad){
	_setmode(_fileno(stdout), _O_U16TEXT);
	cout << MainSquad.at(0).GetName();
	wcout << L"①" << endl;
	for (int i = 1; i < 3; i++)
	{
		cout << MainSquad.at(i).GetName() << "     ";
	}
	wcout << L"②     ③     ④   " << endl;
	for (int i = 4; i < 7; i++)
	{
		cout << MainSquad.at(i).GetName() << "     ";
	}
	wcout << L"⑤     ⑥     ⑦     ⑧      " << endl;
	for (int i = 8; i < 10; i++)
	{
		cout << MainSquad.at(i).GetName() << "     ";
	}
	wcout << L"⑨     ⑩     ⑪      " << endl;
};
void User::fomat442(vector <Footballer> MainSquad){
	_setmode(_fileno(stdout), _O_U16TEXT);
	wcout << L"①" << endl;
	wcout << L"②     ③     ④   ⑤ " << endl;
	wcout << L"⑥     ⑦     ⑧   ⑨    " << endl;
	wcout << L"    ⑩     ⑪      " << endl;
};