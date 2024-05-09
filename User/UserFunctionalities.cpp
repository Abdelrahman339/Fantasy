#include <iostream>
#include "User.h"
#include "UserValidations.h"
#include <algorithm>
#include <regex>

#include "Teams.h"

int formatchoice = 3;

using namespace std;
string User::spacing(int spacing, char character) {
	string space(spacing, character);
	return space;
}




string User::avoidTypos(string& SearchName, User& currentUser, string status, vector <TheLeague> allLeagues, Teams& PlayerTeam)
{

	Teams team;
	size_t whitespace_index = SearchName.find(' ');

	if (whitespace_index != string::npos) {
		if (whitespace_index + 1 < SearchName.size())
		{
			SearchName[whitespace_index + 1] = toupper(SearchName[whitespace_index + 1]);
		}
	}

	SearchName[0] = toupper(SearchName[0]);


	//checking if the name exist or not in sell function cause i use the user squad not the team squad
	if (status == "sell") {
		int it = currentUser.GetMainSquad().count(SearchName);
		int it2 = currentUser.GetSubstitutionSquad().count(SearchName);
		if (it > 0)
		{
			return "existMain";
		}
		else if (it2 > 0) {
			return "existSub";
		}
		else
		{
			string PlayerName = ReturnRightName("sellMain", team, currentUser, SearchName, {});
			if (!PlayerName.empty()) {
				return PlayerName + "main";
			}
			else {
				return ReturnRightName("sellSub", team, currentUser, SearchName, {});
			}
		}

	}

	// to check the team name that the user enterd (avoid typos for team name) 
	else if (status == "Team") {
		string TeamName;
		for (int i = 0; i < allLeagues.size(); i++)
		{
			TeamName = ReturnRightName("Team", team, currentUser, SearchName, allLeagues[i]);
			if (TeamName.empty())
			{
				continue;
			}
			else
				break;
		}
		return TeamName;
	}
	//checking if the name exist or not in a team not in user squad
	else
	{
		pair<string, Teams> PlayerName_TeamName = GetPlayerName_Team(allLeagues, currentUser, SearchName);

		PlayerTeam = PlayerName_TeamName.second;

		return PlayerName_TeamName.first;

	}
}



pair<string, Teams> User::GetPlayerName_Team(vector<TheLeague> allLeagues, User currentUser, string FootballerName)
{
	pair<string, Teams> playerExist;
	for (int i = 0; i < allLeagues.size(); i++)
	{
		for (auto team : allLeagues[i].GetTeams())
		{
			// player name| team name
			playerExist = make_pair(ReturnRightName("buy", team.second, currentUser, FootballerName, {}), team.second);//the footbalelrName and the team name to use it in search function at market
			if (playerExist.first.empty()) {
				continue;
			}

			return playerExist;

		}
	}

	return playerExist;

}

string User::ReturnRightName(string status, Teams team, User currentUser, string SearchName, TheLeague League)
{

	if (status == "sellMain")
	{
		unordered_map<string, Footballer> dataReference;
		dataReference = currentUser.GetMainSquad();
		return typosChecking(SearchName, dataReference);
	}
	else if (status == "sellSub")
	{
		unordered_map<string, Footballer> dataReference = currentUser.GetSubstitutionSquad();
		return typosChecking(SearchName, dataReference);
	}
	else if (status == "Team") {
		map<string, Teams> dataReference = League.GetTeams();
		return typosChecking(SearchName, dataReference);
	}
	else
	{
		unordered_map<string, Footballer> dataReference;
		dataReference = team.getFootballPlayer();
		return typosChecking(SearchName, dataReference);
	}



}
template <typename T>
string User::typosChecking(string SearchName, T dataReference)
{
	/*try
	{
		return dataReference.at(SearchName).getName();
	}
	catch (const std::exception&)
	{*/
	int minErrors = 10000;
	string matchedPlayer;
	for (auto kv : dataReference) {

		string currentPlayerName = kv.first;
		int errors = 0;
		for (int i = 0; i < max(SearchName.size(), currentPlayerName.size()); ++i) {
			if (SearchName[i] != currentPlayerName[i]) {
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
	if (SearchName.size() > 3 && minErrors < 3)
	{
		return matchedPlayer;

	}
	else
	{
		return "";
	}
}




vector<string> User::ToVector(unordered_map<string, Footballer> map)
{
	vector<string> Squad;

	for (auto kv : map)
	{
		Squad.push_back(kv.second.GetName());
	}

	return Squad;
}



void User::fromSubtoMain(unordered_map<string, Footballer>& mainSquad, unordered_map<string, Footballer>& SubSquad)
{
	if (mainSquad.size() < 11)
	{
		if (SubSquad.size() > 0) {

			auto it = SubSquad.begin();

			Footballer footballer = it->second;
			mainSquad.insert_or_assign(footballer.GetName(), footballer);
			SubSquad.erase(it);

		}
	}
}




void User::ShowSquad(User& currentUser) {
	int choice;
	unordered_map <string, Footballer> MainSquad = currentUser.GetMainSquad();
	unordered_map <string, Footballer> SubstitutionSquad = currentUser.GetSubstitutionSquad();

	cout << spacing(60, ' ') << "**Your fantasy squad**" << endl;
	cout << spacing(60, ' '); squadFormat(formatchoice, MainSquad);
	cout << "\n\n\ ";
	cout << spacing(60, ' '); showSubstitutions(SubstitutionSquad);
	cout << "\n\n\ ";
choice:
	cout << spacing(60, ' ') << "1-Show information about your players\n2-Change your format\n3-Substitution\n4-Go back " << endl;
	cin >> choice;
	if (choice == 1)
	{
		Teams team;
		string footballerName;
		char ans;
	invalid:

		cout << "Enter your footballer name " << endl;


		getline(cin >> ws, footballerName);

		string existPlayer = avoidTypos(footballerName, currentUser, "sell", { TheLeague() }, team);



		regex pattern(R"(main)");

		//the user enterd the name correctly

		if (existPlayer == "existMain")
		{
			//the player is from main squad
			showPlayerInfo(MainSquad.at(footballerName), "User");
			do
			{
				cout << "1-sell this player\n2-Go back " << endl;
				cin >> choice;
				switch (choice)
				{
				case 1:

					sellFunction(currentUser, footballerName, "main");
					fromSubtoMain(currentUser.GetMainSquad(), currentUser.GetSubstitutionSquad());
					ShowSquad(currentUser);
					return;
					break;
				case 2:
					ShowSquad(currentUser);
					return;
					break;
				default:
					cout << "Enter a valid choice please";
					break;
				}
			} while (choice != 1 || choice != 2);

		}

		//player is from sub squad
		else if (existPlayer == "existSub") {
			showPlayerInfo(SubstitutionSquad.at(footballerName), "User");

			do
			{
				cout << "1-sell this player\n2-Go back " << endl;
				cin >> choice;
				switch (choice)
				{
				case 1:

					sellFunction(currentUser, footballerName, "sub");
					ShowSquad(currentUser);
					return;
					break;
				case 2:
					ShowSquad(currentUser);
					return;
					break;
				default:
					cout << "Enter a valid choice please";
					break;
				}
			} while (choice != 1 || choice != 2);


		}


		//the user enterd tha name of player wrong 

		else if (!existPlayer.empty()) {

			//checking if the player from the main squad or sub squad
			if (regex_search(existPlayer, pattern))
			{

				//the player is from the main squad
				existPlayer = regex_replace(existPlayer, pattern, "");
				cout << "You enterd a wrong player .Do you mean " << existPlayer << "?(y/n)" << endl;
				cin >> ans;
				if (ans == 'y')
				{
					showPlayerInfo(MainSquad.at(existPlayer), "User");

					do
					{
						cout << "1-sell this player\n2-Go back " << endl;
						cin >> choice;
						switch (choice)
						{
						case 1:

							sellFunction(currentUser, existPlayer, "main");
							fromSubtoMain(currentUser.GetMainSquad(), currentUser.GetSubstitutionSquad());
							ShowSquad(currentUser);
							return;
							break;
						case 2:
							ShowSquad(currentUser);
							return;
							break;
						default:
							cout << "Enter a valid choice please";
							break;
						}
					} while (choice != 1 || choice != 2);

				}


				// not the wanted player
				else if (ans == 'n') {
					cout << "Plese enter a valid footballer name." << endl;
					goto invalid;
				}
			}


			// the plyaer is from the sub squad
			else {
				cout << "You enterd a wrong player .Do you mean " << existPlayer << "?(y/n)" << endl;
				cin >> ans;
				if (ans == 'y')
				{

					showPlayerInfo(SubstitutionSquad.at(existPlayer), "User");
					do
					{
						cout << "1-sell this player\n2-Go back " << endl;
						cin >> choice;
						switch (choice)
						{
						case 1:

							sellFunction(currentUser, existPlayer, "sub");
							ShowSquad(currentUser);
							return;
							break;
						case 2:
							ShowSquad(currentUser);
							return;
							break;
						default:
							cout << "Enter a valid choice please";
							break;
						}
					} while (choice != 1 || choice != 2);


				}
				else if (ans == 'n') {
					cout << "Plese enter a valid footballer name." << endl;
					goto invalid;
				}

			}
		}
		else {

			cout << "You enterd a wrong player.Please enter a exist player" << endl;
			goto invalid;
		}

	}



	else if (choice == 2) {


		cout << "Available formats:" << endl;
		cout << "1- 3 4 3 \n2- 4 3 3\n3- 4 4 2";
		cout << "Choose your new format" << endl;
		cin >> choice;
		if (choice == 1)
		{
			formatchoice = 1;
			squadFormat(1, MainSquad);
			ShowSquad(currentUser);
		}
		else if (choice == 2) {
			formatchoice = 2;
			squadFormat(2, MainSquad);
			ShowSquad(currentUser);

		}

		else if (choice == 3) {
			formatchoice = 3;
			squadFormat(3, MainSquad);
			ShowSquad(currentUser);

		}
	}


	else if (choice == 3)
	{
		Substitution(currentUser);
	}
	else if (choice == 4)
	{
		return;
	}
	else
	{
		cout << "Invalid choice.Please enter a valid choice" << endl;
		goto choice;
	}


}


void User::showPlayerInfo(Footballer footballer, string status) {
	cout << right;
	cout << "--------------------------------------------------------------------------------" << endl;
	cout << "Name:" << footballer.GetName() << endl;
	cout << "Age:" << footballer.GetAge() << endl;
	if (status == "User") {
		cout << "Captain:" << footballer.GetCaptain() << endl;
	}
	cout << "Position:" << footballer.GetPosition() << endl;
	cout << "Price:" << footballer.GetPrice() << endl;
	cout << "Team:" << footballer.GetTeam() << endl;
	cout << "Total goals this season:" << footballer.GetTotalGoals() << endl;
	cout << "Total assists this season:" << footballer.GetTotalAssists() << endl;
	if (footballer.GetPosition() == "Gk") {
		cout << "Total Clean sheets this season:" << footballer.GetTotalCleansheets() << endl;
	}
	cout << "Total yellow card this season:" << footballer.GetTotalYellowCard() << endl;
	cout << "Total red card this season:" << footballer.GetTotalRedCard() << endl;
	cout << "--------------------------------------------------------------------------------\n" << endl;

}


void User::Substitution(User& currentUser) {
	char ans;
	string PlayerName1;
	string PlayerName2;
	string existPlayer;
	Footballer tempPlayer;
	Teams team;
	regex pattern(R"(main)");
invalid_main:



	cout << "Choose player from your main squad to change him (Use the Name)" << endl;
	cin >> PlayerName1;

	//checking if the user entered a correct footballer name or not
	existPlayer = avoidTypos(PlayerName1, currentUser, "sell", { TheLeague() }, team);


	//the user entered a valid footballer name

	//check if the player entered from the main squad or not
	if (existPlayer == "existMain")
	{
		tempPlayer = currentUser.GetMainSquad().at(PlayerName1);
	}

	//the user enterd a wrong footballer name
	else if (!existPlayer.empty()) {
		//checking if the player is from the main squad or not
		if (regex_search(existPlayer, pattern))
		{

			existPlayer = regex_replace(existPlayer, pattern, "");
			cout << "You enterd a wrong player .Do you mean " << existPlayer << "? (y/n)" << endl;
			cin >> ans;
			if (ans == 'y')
			{
				tempPlayer = currentUser.GetMainSquad().at(existPlayer);
			}
			else if (ans == 'n') {
				cout << "Plese enter a valid footballer name." << endl;
				goto invalid_main;
			}
		}

		//the player is not from the main squad
		else {
			cout << "Please choose first the player from your main squad." << endl;
			goto invalid_main;
		}
	}
	//the user entered a unvalid player name
	else {

		cout << "You enterd a wrong player.Please enter a exist player" << endl;
		goto invalid_main;
	}





invalid_Sub:

	cout << "Choose player from your substitutions to let him play (Use the name)" << endl;

	cin >> PlayerName2;


	existPlayer = avoidTypos(PlayerName2, currentUser, "sell", {}, team);
	//checking if the player enterd a player from the substitution squad

	//the user enterd the name correctlly
	if (existPlayer == "existSub")
	{
		SubstituteFunction(currentUser, PlayerName2, tempPlayer);

	}

	//the user entered the name wrong


	else if (!existPlayer.empty()) {
		if (!regex_search(existPlayer, pattern))
		{
			cout << "You enterd a wrong player .Do you mean " << existPlayer << "?" << endl;
			cin >> ans;
			if (ans == 'y')
			{

				SubstituteFunction(currentUser, existPlayer, tempPlayer);

			}
			else if (ans == 'n') {
				cout << "Plese enter a valid footballer name." << endl;
				goto invalid_Sub;
			}
		}
		else {
			cout << "Please enter a player from your Substitution squad." << endl;
			goto invalid_Sub;
		}
	}
	else {

		cout << "You enterd a wrong player.Please enter a exist player" << endl;
		goto invalid_Sub;
	}

	cout << "Player in your main squad now" << endl;
	system("pause");
	system("cls");
	ShowSquad(currentUser);
}

void User::SubstituteFunction(User& currentUser, string subFootballer, Footballer mainFootballer)
{

	Footballer Subplayer = currentUser.GetSubstitutionSquad().at(subFootballer);
	currentUser.GetMainSquad().erase(mainFootballer.GetName());
	currentUser.GetMainSquad().insert_or_assign(Subplayer.GetName(), Subplayer);

	currentUser.GetSubstitutionSquad().erase(Subplayer.GetName());
	currentUser.GetSubstitutionSquad().insert_or_assign(mainFootballer.GetName(), mainFootballer);
};

void User::profile(User& currentUser, unordered_map<string, User>* Users) {
	int choice;
	cout << "\n\n\n\n\n\n\n";
	cout << spacing(60, ' ') << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << spacing(60, ' ') << "             **User profile**" << endl;
	cout << spacing(60, ' ') << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << spacing(60, ' ') << "Name:\t\t" << currentUser.GetFullName() << endl;;
	cout << spacing(60, ' ') << "Username:\t\t" << currentUser.GetUsername() << endl;
	cout << spacing(60, ' ') << "Email Address:\t\t" << currentUser.GetEmail() << endl;
	cout << spacing(60, ' ') << "Phone number:\t\t" << currentUser.GetPhoneNumber() << endl;
	cout << spacing(60, ' ') << "Password:\t\t" << currentUser.GetPassword() << endl;
	cout << spacing(60, ' ') << "Id:\t\t" << currentUser.GetId() << endl;
	cout << spacing(60, ' ') << "Balance:\t\t" << currentUser.GetBalance() << endl;
	cout << spacing(60, ' ') << "Points:\t\t" << currentUser.GetPoints() << endl;
	cout << spacing(60, ' ') << "--------------------------------------------------------------------------------\n" << endl;
	cout << spacing(60, ' ') << "1-Edit information." << endl;
	cout << spacing(60, ' ') << "2-Go back" << endl;
	cin >> choice;
	if (choice == 1)
	{
		editInfo(&currentUser, Users);
	}
	else if (choice == 2)
	{
		return;
	}
};

void User::editInfo(User* currentUser, unordered_map<string, User>* Users) {
	int choice;
invalid:
	cout << spacing(60, ' ') << "What info you want to update:" << endl;
	cout << spacing(60, ' ') << "1-Fullname" << endl;
	cout << spacing(60, ' ') << "2-Username" << endl;
	cout << spacing(60, ' ') << "3-Email Address" << endl;
	cout << spacing(60, ' ') << "4-Phone number" << endl;
	cout << spacing(60, ' ') << "5-Password" << endl;
	cout << spacing(60, ' ') << "6-Go back" << endl;
	cin >> choice;
	if (choice == 1)
	{

		UserValidations::signupinfo(currentUser, "new Fullname", UserValidations::fullnameCheck, &User::SetFullName);
		cout << spacing(60, ' ') << "full name updated successfully" << endl;
		system("pause");
		system("cls");
		profile(*currentUser, Users);
	}
	else if (choice == 2)
	{
		//User oldUser = *currentUser;
		//UserValidations::usernameCheck(*Users, *currentUser);
		//Users->erase(oldUser.GetUsername());
		//Users->insert_or_assign(currentUser->GetUsername(), currentUser);

		cout << "Username updated successfully" << endl;
		system("pause");
		system("cls");
		profile(*currentUser, Users);
	}
	else if (choice == 3)
	{
		UserValidations::signupinfo(currentUser, "new EmailAddress", UserValidations::emailAddressCheck, &User::SetEmail);
		cout << "EmailAddress updated successfully" << endl;
		system("pause");
		system("cls");
		profile(*currentUser, Users);
	}
	else if (choice == 4)
	{

		UserValidations::signupinfo(currentUser, "new PhoneNumber", UserValidations::phoneNumberCheck, &User::SetPhoneNumber);
		cout << "PhoneNumber updated successfully" << endl;
		system("pause");
		system("cls");
		profile(*currentUser, Users);
	}

	else if (choice == 5)
	{
		UserValidations::signupinfo(currentUser, "new Password", UserValidations::passwordCheck, &User::SetPassword);
		cout << "Password updated successfully" << endl;
		system("pause");
		system("cls");
		profile(*currentUser, Users);
	}
	else if (choice == 6)
	{
		profile(*currentUser, Users);
	}
	else {
		cout << "invalid input.Please select a valid option" << endl;
		goto invalid;
	}
};

void User::squadFormat(int choice, unordered_map<string, Footballer>  squad) {
	if (choice == 1)
	{
		User::Format343(squad, "Player");
	}
	else if (choice == 2) {
		User::Format433(squad, "Player");
	}
	else if (choice == 3) {
		User::Format442(squad, "Player");
	}
	else {
		cout << "invalid input!" << endl;
		cout << "Please select from the available formats." << endl;

	}

};
void User::Format433(unordered_map<string, Footballer> Squad, string squadName) {

	vector <string>MainSquad = ToVector(Squad);
	while (MainSquad.size() < 11)
	{
		MainSquad.push_back("XXXXXX");
	}

	cout << User::spacing(28, ' ') << "                    " << squadName << endl;
	cout << User::spacing(28, ' ') << "_____________    _____________    _____________" << "\n\n\n\n\n";
	cout << User::spacing(30, ' '); cout << User::spacing(User::Formatdistance(MainSquad[8], 0, false, MainSquad[8]), ' ') << "9"; cout << User::spacing(User::Formatdistance(MainSquad[9], 13, true, MainSquad[8]), ' ') << "10"; cout << User::spacing(User::Formatdistance(MainSquad[10], 13, true, MainSquad[9]), ' ') << "11" << endl;
	cout << User::spacing(30, ' '); cout << MainSquad[8] << User::spacing(13, ' ') << MainSquad[9] << User::spacing(13, ' ') << MainSquad[10] << "\n\n";

	cout << User::spacing(30, ' '); cout << User::spacing(User::Formatdistance(MainSquad[5], 0, false, MainSquad[5]), ' ') << "6"; cout << User::spacing(User::Formatdistance(MainSquad[6], 13, true, MainSquad[5]), ' ') << "7";  cout << User::spacing(User::Formatdistance(MainSquad[7], 13, true, MainSquad[6]), ' ') << "8" << endl;
	cout << User::spacing(30, ' '); cout << MainSquad[5] << User::spacing(13, ' ') << MainSquad[6] << User::spacing(13, ' ') << MainSquad[7] << endl;

	cout << User::spacing(20, ' '); cout << User::spacing(User::Formatdistance(MainSquad[1], 0, false, MainSquad[1]), ' ') << "2"; cout << User::spacing(User::Formatdistance(MainSquad[2], 13, true, MainSquad[1]), ' ') << "3"; cout << User::spacing(User::Formatdistance(MainSquad[3], 13, true, MainSquad[2]), ' ') << "4" << User::spacing(User::Formatdistance(MainSquad[4], 13, true, MainSquad[3]), ' ') << "5" << endl;
	cout << User::spacing(20, ' '); cout << MainSquad[1] << User::spacing(13, ' ') << MainSquad[2] << User::spacing(13, ' ') << MainSquad[3] << User::spacing(13, ' ') << MainSquad[4] << "\n\n";


	cout << User::spacing(30, ' '); cout << User::spacing(User::Formatdistance(MainSquad[0], 25, false, MainSquad[0]), ' ') << "1" << User::spacing(User::Formatdistance(MainSquad[0], 25, false, MainSquad[0]), ' ') << endl;
	cout << User::spacing(30, ' '); cout << User::spacing(25, ' ') << MainSquad[0] << User::spacing(25, ' ');
};





////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


void User::Format343(unordered_map<string, Footballer> Squad, string squadName) {

	vector <string>MainSquad = ToVector(Squad);
	while (MainSquad.size() < 11)
	{
		MainSquad.push_back("XXXXXX");
	}

	cout << User::spacing(60, ' ') << "                    " << squadName << endl;
	cout << User::spacing(60, ' ') << "_____________    _____________    _____________" << "\n\n\n\n";

	cout << User::spacing(64, ' '); cout << User::spacing(User::Formatdistance(MainSquad[8], 0, false, MainSquad[8]), ' ') << "9"; cout << User::spacing(User::Formatdistance(MainSquad[9], 12, true, MainSquad[8]), ' ') << "10"; cout << User::spacing(User::Formatdistance(MainSquad[10], 12, true, MainSquad[9]), ' ') << "11" << endl;
	cout << User::spacing(64, ' '); cout << MainSquad[8] << User::spacing(13, ' ') << MainSquad[9] << User::spacing(13, ' ') << MainSquad[10] << "\n\n";

	cout << User::spacing(User::Formatdistance(MainSquad[4], 55, false, MainSquad[4]), ' ') << "5"; cout << User::spacing(20, ' '); cout << User::spacing(User::Formatdistance(MainSquad[5], 0, true, MainSquad[4]), ' ') << "6"; cout << User::spacing(User::Formatdistance(MainSquad[6], 13, true, MainSquad[5]), ' ') << "7"; cout << User::spacing(User::Formatdistance(MainSquad[7], 13, true, MainSquad[6]), ' ') << "8" << endl;
	cout << User::spacing(55, ' ') << MainSquad[4]; cout << User::spacing(20, ' '); cout << MainSquad[5] << User::spacing(13, ' ') << MainSquad[6] << User::spacing(13, ' ') << MainSquad[7] << endl << endl;

	cout << User::spacing(64, ' '); cout << User::spacing(User::Formatdistance(MainSquad[1], 0, false, MainSquad[1]), ' ') << "2"; cout << User::spacing(User::Formatdistance(MainSquad[2], 13, true, MainSquad[1]), ' ') << "3"; cout << User::spacing(User::Formatdistance(MainSquad[3], 13, true, MainSquad[2]), ' ') << "4" << endl;
	cout << User::spacing(64, ' '); cout << MainSquad[1] << User::spacing(13, ' ') << MainSquad[2] << User::spacing(13, ' ') << MainSquad[3] << "\n\n";

	cout << User::spacing(60, ' '); cout << User::spacing(User::Formatdistance(MainSquad[0], 25, false, MainSquad[0]), ' ') << "1" << User::spacing(User::Formatdistance(MainSquad[0], 25, false, MainSquad[0]), ' ') << endl;
	cout << User::spacing(60, ' '); cout << User::spacing(25, ' ') << MainSquad[0] << User::spacing(25, ' ');



};



////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


void User::Format442(unordered_map<string, Footballer> Squad, string squadName) {

	vector <string>MainSquad = ToVector(Squad);

	while (MainSquad.size() < 11)
	{
		MainSquad.push_back("XXXXXX");
	}

	cout << User::spacing(28, ' ') << "                    " << squadName << endl;
	cout << User::spacing(28, ' ') << "_____________    _____________    _____________" << "\n\n\n\n";

	cout << User::spacing(38, ' '); cout << User::spacing(User::Formatdistance(MainSquad[9], 0, false, MainSquad[9]), ' ') << "10"; cout << User::spacing(User::Formatdistance(MainSquad[10], 9, true, MainSquad[9]), ' ') << "11" << endl;
	cout << User::spacing(38, ' '); cout << MainSquad[9] << User::spacing(10, ' ') << MainSquad[10] << "\n\n";

	cout << User::spacing(20, ' '); cout << User::spacing(User::Formatdistance(MainSquad[5], 0, false, MainSquad[5]), ' ') << "6"; cout << User::spacing(User::Formatdistance(MainSquad[6], 13, true, MainSquad[5]), ' ') << "7"; cout << User::spacing(User::Formatdistance(MainSquad[7], 13, true, MainSquad[6]), ' ') << "8"; cout << User::spacing(User::Formatdistance(MainSquad[8], 13, true, MainSquad[7]), ' ') << "9" << endl;
	cout << User::spacing(20, ' '); cout << MainSquad[5] << User::spacing(13, ' ') << MainSquad[6] << User::spacing(13, ' ') << MainSquad[7] << User::spacing(13, ' ') << MainSquad[8] << "\n\n";

	cout << User::spacing(20, ' '); cout << User::spacing(User::Formatdistance(MainSquad[1], 0, false, MainSquad[1]), ' ') << "2"; cout << User::spacing(User::Formatdistance(MainSquad[2], 13, true, MainSquad[1]), ' ') << "3"; cout << User::spacing(User::Formatdistance(MainSquad[3], 13, true, MainSquad[2]), ' ') << "4"; cout << User::spacing(User::Formatdistance(MainSquad[4], 13, true, MainSquad[3]), ' ') << "5" << endl;
	cout << User::spacing(20, ' '); cout << MainSquad[1] << User::spacing(13, ' ') << MainSquad[2] << User::spacing(13, ' ') << MainSquad[3] << User::spacing(13, ' ') << MainSquad[4] << "\n\n";

	cout << User::spacing(20, ' '); cout << User::spacing(User::Formatdistance(MainSquad[0], 25, false, MainSquad[0]), ' ') << "1" << User::spacing(User::Formatdistance(MainSquad[0], 25, false, MainSquad[0]), ' ') << endl;
	cout << User::spacing(20, ' '); cout << User::spacing(25, ' ') << MainSquad[0] << User::spacing(25, ' ');
}



void User::showSubstitutions(unordered_map<string, Footballer> Squad)
{

	vector <string>substitutionList = ToVector(Squad);


	cout << User::spacing(28, ' ') << "                   substitutions" << endl;
	cout << User::spacing(28, ' ') << "_____________     ________________    _____________" << "\n\n\n";
	cout << User::spacing(20, ' ');
	if (substitutionList.empty())
	{
		cout << "No substitution" << endl;

	}
	else
	{
		for (int i = 0; i < substitutionList.size(); i++)

		{


			cout << i + 1 << "- " << substitutionList.at(i) << User::spacing(10, ' ');
		}

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