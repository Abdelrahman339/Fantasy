#include <iostream>
#include "User.h"
#include "Teams.h"
using namespace std;
void User::Squad(vector <Footballer> squad) {
	int choice;
	cout << "your fantasy squad" << endl;
	squadForamt(2, squad);
	choice:
	cout<<"1-Show information about your players\n2-Change your format\n3-Substitution\n4-Go back " << endl;
	cin >> choice;
	if (choice==1)
	{
		showPlayerInfo(squad);
	}
	else if (choice == 2) {
		cout << "Available formats:" << endl;
		cout << "1- 4 3 3 \n2- 3 4 3\n3- 4 4 2";
		cout << "Choose your new format" << endl;
		cin >> choice;
		if (choice==1)
		{
			squadForamt(1, squad);
		}
		else if (choice == 2) {
			squadForamt(2, squad);
		}		
		
	else if (choice == 3) {
		squadForamt(3, squad);
	}
		}
	else if (choice==3)
	{
		//Substitution func
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


void User::showPlayerInfo(vector <Footballer> squad) {
	int choice;
	cout << "Choose your footballer to show his information.(use the index)" << endl;
	cin >> choice;
	cout << "--------------------------------------------------------------------------------"<<endl;
	cout << "Name:" << squad.at(choice - 1).GetName();
	cout << "Age:" << squad.at(choice - 1).GetAge();
	cout << "Captain:" << squad.at(choice - 1).GetCaptain();
	cout << "Position:" << squad.at(choice - 1).GetPosition();
	cout << "Price:" << squad.at(choice - 1).GetPrice();
	cout << "Team:" << squad.at(choice - 1).GetTeam();
	cout << "Total goals this season:" << squad.at(choice - 1).GetGoals();
	cout << "Total assists this season:" << squad.at(choice - 1).GetAssists();
	cout << "Total yellow card this season:" << squad.at(choice - 1).GetYellowCard();
	cout << "Total red card this season:" << squad.at(choice - 1).GetRedCard();
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
		Squad(squad);
	}
	else
	{
		cout << "Invalid choice.Please enter a valid choice" << endl;
		goto choice;
	}
};







void User::squadForamt(int choice, vector <Footballer> squad) {
	if (choice==1)
	{
		User::fomat343(squad);
	}
	else if (choice == 2) {
		User::fomat433(squad);
	}
	else if (choice == 3) {
		User::fomat442(squad);
	}
	else {
		cout << "invlaid input!" << endl;
		cout << "Please select from the available formats." << endl;

	}

};
void User::fomat433(vector <Footballer> squad){
	cout << squad.at(0).GetName();
			wcout << L"①" << endl;
			for ( int i = 1; i < 5; i++)
			{
				cout << squad.at(i).GetName() << "     ";
			}
			wcout << L"②     ③     ④      ⑤" << endl;
			for (int i = 5; i < 7; i++)
			{
				cout << squad.at(i).GetName() << "     ";
			}
			wcout << L"⑥     ⑦     ⑧      " << endl;
			for (int i = 8; i < 10; i++)
			{
				cout << squad.at(i).GetName() << "     ";
			}
			wcout << L"⑨     ⑩     ⑪      " << endl;

};
void User::fomat343(vector <Footballer> squad){
	cout << squad.at(0).GetName();
	wcout << L"①" << endl;
	for (int i = 1; i < 3; i++)
	{
		cout << squad.at(i).GetName() << "     ";
	}
	wcout << L"②     ③     ④   " << endl;
	for (int i = 4; i < 7; i++)
	{
		cout << squad.at(i).GetName() << "     ";
	}
	wcout << L"⑤     ⑥     ⑦     ⑧      " << endl;
	for (int i = 8; i < 10; i++)
	{
		cout << squad.at(i).GetName() << "     ";
	}
	wcout << L"⑨     ⑩     ⑪      " << endl;
};
void User::fomat442(vector <Footballer> squad){
	wcout << L"①" << endl;
	wcout << L"②     ③     ④   ⑤ " << endl;
	wcout << L"⑥     ⑦     ⑧   ⑨    " << endl;
	wcout << L"    ⑩     ⑪      " << endl;
};