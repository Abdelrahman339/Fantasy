#include <iostream>
#include "User.h"
#include "UserValidations.h"
#include "Teams.h"
#include <algorithm>


using namespace std;
string User::spacing(int spacing, char character) {
	string space(spacing, character);
	return space;
}



string User::avoidTypos(string footballerName, Teams team, User currentUser, string status)
{

	string LowercaseName = footballerName;
	transform(LowercaseName.begin(), LowercaseName.end(), LowercaseName.begin(), ::tolower);

	//checking if the name exist or not in sell function cause i use the user squad not the team squad
	if (status == "sell") {
		int it = currentUser.GetMainSquad().count(footballerName);
		int it2 = currentUser.GetSubstitutionSquad().count(footballerName);
		if (it > 0)
		{
			return "exist";
		}

	}

	//checking if the name exist or not 
	else
	{

		auto it = team.getFootballPlayer().count(LowercaseName);
		if (it > 0)
		{
			return "exist";
		}
		else // the player doesn't exist in the map . try to find the best similar name
		{
			int minErrors = 10000;
			string matchedPlayer;
			for (auto kv : team.getFootballPlayer()) {

				string currentPlayerName = kv.first;
				int errors = 0;
				for (int i = 0; i < min(LowercaseName.size(), currentPlayerName.size()); ++i) {
					if (LowercaseName[i] != currentPlayerName[i]) {
						errors++;
						if (errors > 2) {
							break;
						}
					}
				}
				if (errors < minErrors) {
					minErrors = errors;
					matchedPlayer = currentPlayerName;
				}
			}
			return matchedPlayer;
		}
	}
}
void User::CheckingPlayer(string status, Teams team, User currenUser, string inputName)
{

	int minErrors = 10000;
	string matchedPlayer;
	for (auto kv : team.getFootballPlayer()) {

		string currentPlayerName = kv.first;
		int errors = 0;
		for (int i = 0; i < min(inputName.size(), currentPlayerName.size()); ++i) {
			if (inputName[i] != currentPlayerName[i]) {
				errors++;
				if (errors > 2) {
					break;
				}
			}
		}
		if (errors < minErrors) {
			minErrors = errors;
			matchedPlayer = currentPlayerName;
		}
	}

}
;




void User::Squad(vector <Footballer> MainSquad, vector <Footballer> SubstitutionSquad) {
	int choice;
	cout << "your fantasy squad" << endl;
	squadFormat(2, MainSquad);
choice:
	cout << "1-Show information about your players\n2-Change your format\n3-Substitution\n4-Go back " << endl;
	cin >> choice;
	if (choice == 1)
	{
		Teams team;
		User user;
		string footballerName;
		cout << "Enter your footballer name " << endl;
		cin >> footballerName;
		string playerExist = avoidTypos(footballerName, team, user, "sell");
		if (playerExist == "exist")
		{

		}
	}
	else if (choice == 2) {
		cout << "Available formats:" << endl;
		cout << "1- 4 3 3 \n2- 3 4 3\n3- 4 4 2";
		cout << "Choose your new format" << endl;
		cin >> choice;
		if (choice == 1)
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
	else if (choice == 3)
	{
		Substitution(MainSquad, SubstitutionSquad);
	}
	else if (choice == 4)
	{
		//userMenu(this);
	}
	else
	{
		cout << "Invalid choice.Please enter a valid choice" << endl;
		goto choice;
	}


}


void User::showPlayerInfo(Footballer footballer) {
	cout << "--------------------------------------------------------------------------------" << endl;
	cout << "Name:" << footballer.GetName();
	cout << "Age:" << footballer.GetAge();
	cout << "Captain:" << footballer.GetCaptain();
	cout << "Position:" << footballer.GetPosition();
	cout << "Price:" << footballer.GetPrice();
	cout << "Team:" << footballer.GetTeam();
	cout << "Total goals this season:" << footballer.GetTotalGoals();
	cout << "Total assists this season:" << footballer.GetTotalAssists();
	if (footballer.GetPosition() == "Gk") {
		cout << "Total Clean sheets this season:" << footballer.GetTotalCleansheets();
	}
	cout << "Total yellow card this season:" << footballer.GetTotalYellowCard();
	cout << "Total red card this season:" << footballer.GetTotalRedCard();
	cout << "--------------------------------------------------------------------------------\n" << endl;

};


void User::Substitution(vector <Footballer> mainSquad, vector <Footballer> SubstitutionSquad) {
	int choice1;
	int choice2;
	Footballer tempPlayer;
	cout << "Choose player from your main squad to change him (Use the index)" << endl;
	cin >> choice1;
	cout << "Choose player from your main substitution to let him play (Use the index)" << endl;
	cin >> choice2;
	tempPlayer = mainSquad.at(choice1 - 1);
	mainSquad.at(choice1 - 1) = SubstitutionSquad.at(choice2 - 1);
	SubstitutionSquad.at(choice1 - 1) = tempPlayer;
	cout << "Player in your main squad now" << endl;
	system("pause");
	system("cls");
	Squad(mainSquad, SubstitutionSquad);
};

void User::profile(User& currentUser, unordered_map<string, User>& Users) {
	int choice;
	cout << "profile" << endl;
	cout << "Name:" << currentUser.GetFullName() << endl;;
	cout << "Username:" << currentUser.GetUsername() << endl;
	cout << "Email Address:" << currentUser.GetEmail() << endl;
	cout << "Phone number:" << currentUser.GetPhoneNumber() << endl;
	cout << "Password:" << currentUser.GetPassword() << endl;
	cout << "Id:" << currentUser.GetId() << endl;
	cout << "Balance:" << currentUser.GetBalance() << endl;
	cout << "Points:" << currentUser.GetPoints() << endl;
	cout << "Rank:" << currentUser.GetRank() << endl;
	cout << "--------------------------------------------------------------------------------\n" << endl;
	cout << "1-Edit information.\n2-Go back" << endl;
	cin >> choice;
	if (choice == 1)
	{
		editInfo(currentUser, Users);
	}
	else if (choice == 2)
	{
		userMenu(currentUser, Users);
	}
};

void User::editInfo(User& currentUser, unordered_map<string, User>& Users) {
	int choice;
invalid:
	cout << "What info you want to update:" << endl;
	cout << "1-Fullname\n2-Username\n3-Email Address\n4-Phone number\n5-Password\n6-Go back" << endl;
	cin >> choice;
	if (choice == 1)
	{

		UserValidations::signupinfo(&currentUser, "new Fullname", UserValidations::fullnameCheck, &User::SetFullName);
		cout << "full name updated successfully" << endl;
		system("pause");
		system("cls");
		profile(currentUser, Users);
	}
	else if (choice == 2)
	{
		UserValidations::usernameCheck(Users, currentUser);
		cout << "Username updated successfully" << endl;
		system("pause");
		system("cls");
		profile(currentUser, Users);
	}
	else if (choice == 3)
	{
		UserValidations::signupinfo(&currentUser, "new EmailAddress", UserValidations::emailAddressCheck, &User::SetEmail);
		cout << "EmailAddress updated successfully" << endl;
		system("pause");
		system("cls");
		profile(currentUser, Users);
	}
	else if (choice == 4)
	{

		UserValidations::signupinfo(&currentUser, "new PhoneNumber", UserValidations::phoneNumberCheck, &User::SetPhoneNumber);
		cout << "PhoneNumber updated successfully" << endl;
		system("pause");
		system("cls");
		profile(currentUser, Users);
	}

	else if (choice == 5)
	{
		UserValidations::signupinfo(&currentUser, "new Password", UserValidations::passwordCheck, &User::SetPassword);
		cout << "Password updated successfully" << endl;
		system("pause");
		system("cls");
		profile(currentUser, Users);
	}
	else if (choice == 6)
	{
		profile(currentUser, Users);
	}
	else {
		cout << "invalid input.Please select a valid option" << endl;
		goto invalid;
	}
};

void User::squadFormat(int choice, vector <Footballer> MainSquad) {
	if (choice == 1)
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
void User::Format433(vector <Footballer> MainSquad) {

	cout << User::spacing(28, ' ') << "                    Players" << endl;
	cout << User::spacing(28, ' ') << "_____________    _____________    _____________" << "\n\n\n\n\n";
	cout << User::spacing(20, ' '); cout << User::spacing(User::Formatdistance(MainSquad[8].GetName(), 0, false, MainSquad[8].GetName()), ' ') << "9"; cout << User::spacing(User::Formatdistance(MainSquad[9].GetName(), 12, true, MainSquad[8].GetName()), ' ') << "10"; cout << User::spacing(User::Formatdistance(MainSquad[10].GetName(), 12, true, MainSquad[9].GetName()), ' ') << "11" << endl;
	cout << User::spacing(20, ' '); cout << MainSquad[8].GetName() << User::spacing(13, ' ') << MainSquad[9].GetName() << User::spacing(13, ' ') << MainSquad[10].GetName() << "\n\n";

	cout << User::spacing(20, ' '); cout << User::spacing(User::Formatdistance(MainSquad[1].GetName(), 0, false, MainSquad[1].GetName()), ' ') << "2"; cout << User::spacing(User::Formatdistance(MainSquad[2].GetName(), 13, true, MainSquad[1].GetName()), ' ') << "3"; cout << User::spacing(User::Formatdistance(MainSquad[3].GetName(), 13, true, MainSquad[2].GetName()), ' ') << "4" << endl;
	cout << User::spacing(20, ' '); cout << MainSquad[1].GetName() << User::spacing(13, ' ') << MainSquad[2].GetName() << User::spacing(13, ' ') << MainSquad[3].GetName() << "\n\n";

	cout << User::spacing(User::Formatdistance(MainSquad[4].GetName(), 13, false, MainSquad[4].GetName()), ' ') << "5"; cout << User::spacing(20, ' '); cout << User::spacing(User::Formatdistance(MainSquad[5].GetName(), 0, true, MainSquad[4].GetName()), ' ') << "6"; cout << User::spacing(User::Formatdistance(MainSquad[6].GetName(), 13, true, MainSquad[5].GetName()), ' ') << "7"; cout << User::spacing(User::Formatdistance(MainSquad[7].GetName(), 13, true, MainSquad[6].GetName()), ' ') << "8" << endl;
	cout << User::spacing(13, ' ') << MainSquad[4].GetName(); cout << User::spacing(20, ' '); cout << MainSquad[5].GetName() << User::spacing(13, ' ') << MainSquad[6].GetName() << User::spacing(13, ' ') << MainSquad[7].GetName() << endl;

	cout << User::spacing(20, ' '); cout << User::spacing(User::Formatdistance(MainSquad[0].GetName(), 25, false, MainSquad[0].GetName()), ' ') << "1" << User::spacing(User::Formatdistance(MainSquad[0].GetName(), 25, false, MainSquad[0].GetName()), ' ') << endl;
	cout << User::spacing(20, ' '); cout << User::spacing(25, ' ') << MainSquad[0].GetName() << User::spacing(25, ' ');
};





////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



void User::Format343(vector <Footballer> MainSquad) {

	cout << User::spacing(28, ' ') << "                    Players" << endl;
	cout << User::spacing(28, ' ') << "_____________    _____________    _____________" << "\n\n\n\n";

	cout << User::spacing(28, ' '); cout << User::spacing(User::Formatdistance(MainSquad[8].GetName(), 0, false, MainSquad[8].GetName()), ' ') << "9";
	for (int i = 8; i < 10; i++)
	{
		cout << User::spacing(User::Formatdistance(MainSquad[i + 1].GetName(), 13, true, MainSquad[i].GetName()), ' ') << i + 2;
	}
	cout << endl;
	////////////////////////////////////////////////////////
	cout << User::spacing(28, ' ') << MainSquad[8].GetName();
	for (int i = 9; i < 11; i++)
	{
		cout << User::spacing(13, ' ') << MainSquad[i].GetName();
	}
	cout << "\n\n";

	cout << User::spacing(User::Formatdistance(MainSquad[4].GetName(), 20, false, MainSquad[4].GetName()), ' ') << "5";
	for (int i = 4; i < 7; i++)
	{
		cout << User::spacing(User::Formatdistance(MainSquad[i + 1].GetName(), 13, true, MainSquad[i].GetName()), ' ') << i + 2;
	}
	cout << endl;

	//////////////////////////////////////////////////
	cout << User::spacing(20, ' ') << MainSquad[4].GetName();
	for (int i = 5; i < 8; i++)
	{
		cout << User::spacing(13, ' ') << MainSquad[i].GetName();
	}
	cout << "\n\n";
	cout << User::spacing(28, ' '); cout << User::spacing(User::Formatdistance(MainSquad[1].GetName(), 0, false, MainSquad[1].GetName()), ' ') << "2";
	for (int i = 1; i < 3; i++)
	{
		cout << User::spacing(User::Formatdistance(MainSquad[i + 1].GetName(), 13, true, MainSquad[i].GetName()), ' ') << i + 2;
	}
	cout << endl;
	cout << User::spacing(28, ' '); cout << MainSquad[1].GetName();
	for (int i = 2; i < 4; i++)
	{
		cout << User::spacing(13, ' ') << MainSquad[i].GetName();
	}
	cout << "\n\n" << endl;
	cout << User::spacing(20, ' '); cout << User::spacing(User::Formatdistance(MainSquad[0].GetName(), 25, false, MainSquad[0].GetName()), ' ') << "1" << User::spacing(User::Formatdistance(MainSquad[0].GetName(), 25, false, MainSquad[0].GetName()), ' ') << endl;
	cout << User::spacing(20, ' '); cout << User::spacing(25, ' ') << MainSquad[0].GetName() << User::spacing(25, ' ');
};



////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


void User::Format442(vector <Footballer> MainSquad) {

	cout << User::spacing(28, ' ') << "                    Players" << endl;
	cout << User::spacing(28, ' ') << "_____________    _____________    _____________" << "\n\n\n\n";

	cout << User::spacing(38, ' '); cout << User::spacing(User::Formatdistance(MainSquad[9].GetName(), 0, false, MainSquad[9].GetName()), ' ') << "10"; cout << User::spacing(User::Formatdistance(MainSquad[10].GetName(), 9, true, MainSquad[9].GetName()), ' ') << "11" << endl;
	cout << User::spacing(38, ' '); cout << MainSquad[9].GetName() << User::spacing(10, ' ') << MainSquad[10].GetName() << "\n\n";

	cout << User::spacing(20, ' '); cout << User::spacing(User::Formatdistance(MainSquad[5].GetName(), 0, false, MainSquad[5].GetName()), ' ') << "6";
	for (int i = 5; i < 8; i++)
	{
		cout << User::spacing(User::Formatdistance(MainSquad[i + 1].GetName(), 13, true, MainSquad[i].GetName()), ' ') << i + 2;
	}
	cout << endl;
	cout << User::spacing(20, ' ') << MainSquad[5].GetName();
	for (int i = 6; i < 9; i++)
	{
		cout << User::spacing(13, ' ') << MainSquad[i].GetName();
	}
	cout << "\n\n";
	cout << User::spacing(20, ' '); cout << User::spacing(User::Formatdistance(MainSquad[1].GetName(), 0, false, MainSquad[1].GetName()), ' ') << "2";
	for (int i = 1; i < 4; i++)
	{
		cout << User::spacing(User::Formatdistance(MainSquad[i + 1].GetName(), 13, true, MainSquad[i].GetName()), ' ') << i + 2;
	}
	cout << endl;
	cout << User::spacing(20, ' '); cout << MainSquad[1].GetName();
	for (int i = 2; i < 5; i++)
	{
		cout << User::spacing(13, ' ') << MainSquad[i].GetName();
	}
	cout << "\n\n" << endl;
	cout << User::spacing(20, ' '); cout << User::spacing(User::Formatdistance(MainSquad[0].GetName(), 25, false, MainSquad[0].GetName()), ' ') << "1" << User::spacing(User::Formatdistance(MainSquad[0].GetName(), 25, false, MainSquad[0].GetName()), ' ') << endl;
	cout << User::spacing(20, ' '); cout << User::spacing(25, ' ') << MainSquad[0].GetName() << User::spacing(25, ' ');
}


void User::showSubstitutions(vector<Footballer> substitutionList)
{

	cout << User::spacing(28, ' ') << "                   substitutions" << endl;
	cout << User::spacing(28, ' ') << "_____________     ________________    _____________" << "\n\n\n";
	cout << User::spacing(20, ' ');
	for (int i = 0; i < substitutionList.size(); i++)
	{
		cout << i + 1 << "- " << substitutionList.at(i).GetName() << User::spacing(10, ' ');
	}
};



int User::Formatdistance(string name, int space, bool remaining, string prev) {
	int length = name.length();
	int distance = name.length() / 2;
	int remain = prev.length() - (prev.length() / 2);
	if (remaining == true) {

		distance = distance + space + remain;
	}
	else
	{
		distance = distance + space;
	}
	return distance - 1;
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