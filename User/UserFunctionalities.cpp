#include <iostream>
#include "User.h"
#include "UserValidations.h"
#include "Teams.h"


using namespace std;
string User::spacing(int spacing, char character) {
	string space(spacing, character);
	return space;
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
		//User::Format433(MainSquad);
	}
	else if (choice == 3) {
		//User::Format442(MainSquad);
	}
	else {
		cout << "invalid input!" << endl;
		cout << "Please select from the available formats." << endl;

	}

};
void User::Format433(vector <string> MainSquad){
	cout << User::spacing(20, ' '); cout << User::spacing(User::Formatdistance(MainSquad[8], 0, false, MainSquad[8]), ' ') << "9"; cout << User::spacing(User::Formatdistance(MainSquad[9], 12, true, MainSquad[8]), ' ') << "10"; cout << User::spacing(User::Formatdistance(MainSquad[10], 12, true, MainSquad[9]), ' ') << "11" << endl;
	cout << User::spacing(20, ' '); cout << MainSquad[8] << User::spacing(13, ' ') << MainSquad[9] << User::spacing(13, ' ') << MainSquad[10] << "\n\n";

	cout << User::spacing(20, ' '); cout << User::spacing(User::Formatdistance(MainSquad[1], 0, false, MainSquad[1]), ' ') << "2"; cout << User::spacing(User::Formatdistance(MainSquad[2], 13, true, MainSquad[1]), ' ') << "3"; cout << User::spacing(User::Formatdistance(MainSquad[3], 13, true, MainSquad[2]), ' ') << "4" << endl;
	cout << User::spacing(20, ' '); cout << MainSquad[1] << User::spacing(13, ' ') << MainSquad[2] << User::spacing(13, ' ') << MainSquad[3] << "\n\n";

	cout << User::spacing(User::Formatdistance(MainSquad[4], 13, false, MainSquad[4]), ' ') << "5"; cout << User::spacing(20, ' '); cout << User::spacing(User::Formatdistance(MainSquad[5], 0, true, MainSquad[4]), ' ') << "6"; cout << User::spacing(User::Formatdistance(MainSquad[6], 13, true, MainSquad[5]), ' ') << "7"; cout << User::spacing(User::Formatdistance(MainSquad[7], 13, true, MainSquad[6]), ' ') << "8" << endl;
	cout << User::spacing(13, ' ') << MainSquad[4]; cout << User::spacing(20, ' '); cout << MainSquad[5] << User::spacing(13, ' ') << MainSquad[6] << User::spacing(13, ' ') << MainSquad[7] << endl;

	cout << User::spacing(20, ' '); cout << User::spacing(User::Formatdistance(MainSquad[0], 25, false, MainSquad[0]), ' ') << "1" << User::spacing(User::Formatdistance(MainSquad[0], 25, false, MainSquad[0]), ' ') << endl;
	cout << User::spacing(20, ' '); cout << User::spacing(25, ' ') << MainSquad[0] << User::spacing(25, ' ');
};
void User::Format343(vector <string> MainSquad){




	cout << User::spacing(28, ' '); cout << User::spacing(User::Formatdistance(MainSquad[8], 0, false, MainSquad[8]), ' ') << "9";
	for (int i = 8; i < 10; i++)
	{
		cout << User::spacing(User::Formatdistance(MainSquad[i + 1], 13, true, MainSquad[i]), ' ') << i + 2;
	}
	cout << endl;
	////////////////////////////////////////////////////////
	cout << User::spacing(28, ' ') << MainSquad[8];
	for (int i = 9; i < 11; i++)
	{
		cout << User::spacing(13, ' ') << MainSquad[i];
	}
	cout << "\n\n";

	cout << User::spacing(User::Formatdistance(MainSquad[4], 20, false, MainSquad[4]), ' ') << "5";
	for (int i = 4; i < 7; i++)
	{
		cout << User::spacing(User::Formatdistance(MainSquad[i + 1], 13, true, MainSquad[i]), ' ') << i + 2;
	}
	cout << endl;

	//////////////////////////////////////////////////
	cout << User::spacing(20, ' ') << MainSquad[4];
	for (int i = 5; i < 8; i++)
	{
		cout << User::spacing(13, ' ') << MainSquad[i];
	}
	cout << "\n\n";
	cout << User::spacing(28, ' '); cout << User::spacing(User::Formatdistance(MainSquad[1], 0, false, MainSquad[1]), ' ') << "2";
	for (int i = 1; i < 3; i++)
	{
		cout << User::spacing(User::Formatdistance(MainSquad[i + 1], 13, true, MainSquad[i]), ' ') << i + 2;
	}
	cout << endl;
	cout << User::spacing(28, ' '); cout << MainSquad[1];
	for (int i = 2; i < 4; i++)
	{
		cout << User::spacing(13, ' ') << MainSquad[i];
	}
	cout << "\n\n" << endl;
	cout << User::spacing(20, ' '); cout << User::spacing(User::Formatdistance(MainSquad[0], 25, false, MainSquad[0]), ' ') << "1" << User::spacing(User::Formatdistance(MainSquad[0], 25, false, MainSquad[0]), ' ') << endl;
	cout << User::spacing(20, ' '); cout << User::spacing(25, ' ') << MainSquad[0] << User::spacing(25, ' ');
};
void User::Format442(vector <string> MainSquad){

	cout << User::spacing(38, ' '); cout << User::spacing(User::Formatdistance(MainSquad[9], 0, false, MainSquad[9]), ' ') << "10"; cout << User::spacing(User::Formatdistance(MainSquad[10], 9, true, MainSquad[9]), ' ') << "11"<<endl;
	cout << User::spacing(38, ' '); cout << MainSquad[9] << User::spacing(10, ' ') << MainSquad[10] << "\n\n";

	cout << User::spacing(20, ' '); cout << User::spacing(User::Formatdistance(MainSquad[5], 0, false, MainSquad[5]), ' ') << "6";
	for (int i = 5; i < 8; i++)
	{
		cout << User::spacing(User::Formatdistance(MainSquad[i + 1], 13, true, MainSquad[i]), ' ') << i + 2;
	}
	cout << endl;
	cout << User::spacing(20, ' ') << MainSquad[5];
	for (int i = 6; i < 9; i++)
	{
		cout << User::spacing(13, ' ') << MainSquad[i];
	}
	cout << "\n\n";
	cout << User::spacing(20, ' '); cout << User::spacing(User::Formatdistance(MainSquad[1], 0, false, MainSquad[1]), ' ') << "2";
	for (int i = 1; i < 4; i++)
	{
		cout << User::spacing(User::Formatdistance(MainSquad[i+1], 13, true, MainSquad[i]), ' ') <<i+2;
	}	
	cout << endl;
	cout << User::spacing(20, ' '); cout << MainSquad[1];
	for (int i = 2; i < 5; i++)
	{
		cout << User::spacing(13, ' ') << MainSquad[i];
	}
	cout << "\n\n" << endl;
	cout << User::spacing(20, ' '); cout << User::spacing(User::Formatdistance(MainSquad[0], 25, false, MainSquad[0]), ' ') << "1" << User::spacing(User::Formatdistance(MainSquad[0], 25, false, MainSquad[0]), ' ') << endl;
	cout << User::spacing(20, ' '); cout << User::spacing(25, ' ') << MainSquad[0] << User::spacing(25, ' ');
};


int User::Formatdistance(string name, int space, bool remaining,string prev) {
	int length = name.length();
	int distance = name.length() / 2;
	int remain = prev.length() - (prev.length() / 2);
	if (remaining==true) {

	distance = distance + space+ remain;
	}
	else
	{
			distance = distance + space;
	}
	return distance-1;
};

void User::displayFormat(vector <string> players, User currentUser) {

	cout << User::spacing(38, ' ') << "Player" << endl;
	cout << User::spacing(20, ' ') << "--------        --------       --------"<< endl<<endl;
	Format433(players);
	cout << endl<<endl;
	cout << User::spacing(67, ' ') << User::spacing(currentUser.GetFullName().size(), '_')<<endl;
	cout << User::spacing(60, ' ')<<"coach: " << "|" << currentUser.GetFullName() << "|" << endl;
	cout << User::spacing(67, ' ') << User::spacing(currentUser.GetFullName().size(), '_')<< endl;

};












//#include <iostream>
//#include <vector>
//#include "User.h"
//using namespace std;
//int main() {
//
//	vector <string> players = { "Courtois","Carvajal","Rudiger","Tchouameni","Mendy","Camavinga","Kroos","Bellingham","Valverde","Rodrygo","Vinicius" };
//	vector <string> players2 = { "Stegen","Koundé","Araújo","Cubarsí","Cancelo","Pedri","Gündoğan","Frenkie ","Lamine ","Lewandowski","Raphinha" };
//
//
//
//	cout << "\n\n\n";
//	cout << User::spacing(20, ' '); cout << "              10                  11 " << endl;
//	cout << User::spacing(20, ' '); cout << "            Rodrygo            Vinicius  \n" << endl;
//
//	cout << User::spacing(20, ' '); cout << "   6                 7                8                  9         " << endl;
//	cout << User::spacing(20, ' '); cout << "Camavinga          Kroos          Bellingham          Valverde        \n\n" << endl;
//
//	cout << User::spacing(20, ' '); cout << "   2                 3                 4                 5            " << endl;
//	cout << User::spacing(20, ' '); cout << "Carvajal          Rudiger          Tchouameni          Mendy\n\n" << endl;
//
//	cout << User::spacing(20, ' '); cout << "                            1              " << endl;
//	cout << User::spacing(20, ' '); cout << "                         Courtois                    " << endl;
//	cout << User::spacing(110, '*') << endl << endl;
//	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//	User user;
//	user.Format442(players2);
//	cout << endl;
//	cout << User::spacing(110, '*') << endl << endl;
//	user.Format343(players2);
//	cout << endl;
//	cout << User::spacing(110, '*') << endl << endl;
//	user.Format433(players2);
//}