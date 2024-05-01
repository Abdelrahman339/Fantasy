#include <iostream>
#include <deque>
#include <stack>
#include <set>


#include "Competition.h"
#include "User.h"
#include "Leagues.h"
#include <regex>
#include <string>
using namespace std;

void User::Market(User& currentUser, unordered_map<string, Footballer> TopPlayer, unordered_map<string, User>& Users, vector <League> leagues)
{

	cout << "Fatntasy Market" << endl;
	int choice = 0;
	//User::showtopPlayer(TopPlayer, currentUser, Users, team);
invalid:
	cout << "1-search.\n2-Choose Top player.\n3-Sell your players.\n4-Go back." << endl;
	cin >> choice;
	if (choice == 1) {
		search(currentUser, leagues);
		userMenu(currentUser, Users, leagues);
	}
	else if (choice == 2) {
		//TopPlayer
	}
	else if (choice == 3) {
		string FootballerName;
		Format343(currentUser.GetMainSquad());
		cout << endl << endl << endl;
		showSubstitutions(currentUser.GetSubstitutionSquad());
		cout << endl << endl;

		cout << "Enter Footballer name that you want to sell." << endl;
		getline(cin >> ws, FootballerName);
		sell(currentUser, TopPlayer, Users, FootballerName);
		system("cls");
		Market(currentUser, TopPlayer, Users, leagues);
	}
	else if (choice == 4) {
		User::userMenu(currentUser, Users, leagues);
	}
	else {
		cout << "Invalid input.Please try again." << endl;
		goto invalid;
	}
};

void User::showtopPlayer(unordered_map<string, Footballer> TopPlayer, User& currentUser, unordered_map<string, User>& Users, Teams& team)
{
	string footballerName;
	int choice;
invalid:
	cout << "Welcome to top player in the session!" << endl;
	User::Format343(TopPlayer);
	system("cls");

	cout << "1-Show information about player\n2-buy player\n3-Replace player\n4-Go back." << endl;
	cin >> choice;
	if (choice == 1) {
		cout << "Enter the name of the player you want to show information about" << endl;
		cin >> footballerName;
		if (TopPlayer.count(footballerName) > 0)
		{
			showPlayerInfo(TopPlayer.at(footballerName));
		}
		else
		{
			cout << "Please enter a valid name" << endl;
			goto invalid;
		}
	}
	else if (choice == 2)
	{
		/*buy(currentUser, team, TopPlayer, Users);*/

	}
	else if (choice == 3) {
		replace(currentUser, team, TopPlayer, Users);
	}
	else if (choice == 4) {
		//Market(currentUser, team, TopPlayer, Users);
	}
	else {
		cout << "Invalid choice.Please select valid choice" << endl;
		goto invalid;
	}


}


void User::search(User& currentUser, vector<League>  leagues)
{
	// all the variables declartion
	int ans;
	string search;
	Teams footballerTeam;
	Footballer targetFootballer;
invalid:

	// the user enter a name either of (Player name) , (Team name).
	cout << "You can search by teams or the name of footballer." << endl;

	getline(cin >> ws, search);
	//function typos start here to check if the user enterd any wrong Player name.after this function is done it return a object of type footballer
	targetFootballer = returnPlayer(search, currentUser, "buy", leagues, footballerTeam);

	//funcion find team to find the team that the user entered
	Teams Wantedteam = findTeam(leagues, search);

	//checking if the object of footballer is empty or not 
	if (!targetFootballer.GetName().empty())
	{
		User::showPlayerInfo(targetFootballer);
		cout << "1-buy the player\n2-Go back" << endl;
		cin >> ans;
		switch (ans)
		{
		case 1:
			buyFunction(currentUser, targetFootballer);

		case 2:

		default:
			break;
		}
	}


	//checking if the find team return a team or a nullptr
	else if (!Wantedteam.getName().empty())
	{
		User::Format343(Wantedteam.getFootballPlayer());

	}


	// the two method return false value so the user entered a wrong team and footballer name
	else
	{
		cout << "please enter a valid Team name or Footabller name" << endl;
		goto invalid;
	}


}
Footballer User::returnPlayer(string footballerName, User currentUser, string status, vector<League> leagues, Teams& footballerTeam)
{

	string nameOfFootballer = avoidTypos(footballerName, currentUser, "buy", leagues, footballerTeam);
	Footballer TargetedFootballer;
	bool found = false;
	int it = footballerTeam.getFootballPlayer().count(nameOfFootballer);
	if (it > 0)
	{
		TargetedFootballer = footballerTeam.getFootballPlayer().at(nameOfFootballer);
		return TargetedFootballer;
	}
	else
	{
		return Footballer();
	}

}





Teams User::findTeam(vector<League> leagues, string TeamName)
{
	Teams teamFound;
	for (int i = 0; i < leagues.size(); i++)
	{
		map<string, Teams> teamsInLeagus = leagues.at(i).GetTeams();
		int TeamExist = teamsInLeagus.count(TeamName);
		if (TeamExist > 0) {
			teamFound = teamsInLeagus.at(TeamName);
		}

	}
	return teamFound;
};










bool User::sell(User& currentUser, unordered_map<string, Footballer> TopPlayer, unordered_map<string, User>& Users, string footballerName) {


	char ans;
	Teams TeamName;
	string playerExist = User::avoidTypos(footballerName, currentUser, "sell", {}, TeamName);



	//if the user enterd the name of the player correctly

	//the player exist in the main squad
	if (playerExist == "existMain") {
		sellFunction(currentUser, footballerName, "main");
		return true;
	}

	//the player exist in sub squad
	else if (playerExist == "existSub")
	{
		sellFunction(currentUser, footballerName, "sub");
		return true;
	}


	//the user enterd the name wrong

	else if (!playerExist.empty()) {

		regex pattern(R"(main)");

		//check if the player from the main squad or not
		if (regex_search(playerExist, pattern))
		{
			playerExist = regex_replace(playerExist, pattern, "");
			cout << "You enterd a wrong player .Do you mean " << playerExist << "?(y/n)" << endl;
			cin >> ans;

			switch (ans)
			{
			case'y':
				sellFunction(currentUser, playerExist, "main");
				return true;
			case'n':
				cout << "Plese enter a valid footballer name." << endl;
				return false;

			default:
				break;
			}

		}


		//the player is from sub squad
		else {
			cout << "You enterd a wrong player .Do you mean " << playerExist << "?(y/n)" << endl;
			cin >> ans;
			if (ans == 'y')
			{
				sellFunction(currentUser, playerExist, "sub");
				return true;
			}
			else if (ans == 'n') {
				cout << "Plese enter a valid footballer name." << endl;
				return false;
			};
		}
	}

	//the player dosen't exist in main and sub squad
	else
	{
		cout << "There is no matching football player." << endl;
		cout << "Plese enter a valid footballer name." << endl;
		return false;
	}

}



void User::sellFunction(User& currentUser, string footballerName, string status)
{
	unordered_map<string, Footballer>* squad;
	if (status == "main")
	{
		squad = &currentUser.GetMainSquad();
	}

	else
	{
		squad = &currentUser.GetSubstitutionSquad();
	}

	cout << "Player sold successfully.." << endl;

	float FootballerPrice = squad->at(footballerName).GetPrice();

	squad->erase(footballerName);

	currentUser.addBalance(FootballerPrice);

}
;





void User::buy(User& currentUser, Teams& team, unordered_map<string, Footballer> TopPlayer, unordered_map<string, User>& Users, vector<League> Leagues) {

	// all used variables
	string footballerName;
	Footballer wantedFootballer;
	Teams PlayerTeam;
	string playerExist;
	char ans;


invalid:
	cout << "Enter the name of your wanted player to buy.\n";
	cin >> footballerName;
	playerExist = User::avoidTypos(footballerName, currentUser, "buing", Leagues, PlayerTeam);


	//the user enterd the name of the player correctlly 
	if (playerExist == "exist")
	{
		//get the footballer object from the team
		wantedFootballer = PlayerTeam.getFootballPlayer().at(footballerName);

		cout << "Are you sure you want to buy " << footballerName << " ?(y/n)" << endl;
		cin >> ans;
		if (ans == 'y')
		{



			buyFunction(currentUser, wantedFootballer);

			//Market(currentUser, team, TopPlayer, Users);

		}
		else if (ans == 'n') {
			//Market(currentUser, team, TopPlayer, Users);
		}
		else {
			cout << "Please enter a valid option." << endl;
			goto invalidOption;
		}
	}




	// the user enterd the player name wrong.
	else if (!playerExist.empty()) {
		wantedFootballer = PlayerTeam.getFootballPlayer().at(playerExist);
	invalidOption:
		cout << "You enterd a wrong player .Do you mean " << playerExist << "?" << endl;
		cin >> ans;


		//asking the user if he is the wanted player or not
		if (ans == 'y')
		{


			buyFunction(currentUser, wantedFootballer);

			//Market(currentUser, team, TopPlayer, Users);

		}
		else if (ans == 'n') {
			cout << "Plese enter a valid footballer name." << endl;
			goto invalid;
		}
		// invalid input from the user
		else
		{
			cout << "Please enter a valid option." << endl;
			goto invalidOption;
		}
	}


	// the function typos didnt find the player so the user enterd a player dose not exist
	else
	{
		cout << "There is no matching football player." << endl;
		cout << "Plese enter a valid footballer name." << endl;
		goto invalid;
	}

}


void User::buyFunction(User& currentUser, Footballer footballer)
{
	float FootballerPrice = footballer.GetPrice();
	float currentBalance = currentUser.GetBalance();

	if (!checkBalance(currentBalance, FootballerPrice))
	{

		cout << "you don't have enough money to buy this player." << endl;
		return;
	}
	if (currentUser.SetFootballer(footballer)) {
		currentUser.addBalance(-FootballerPrice);
		cout << "Player bought successfully." << endl;
	}
};





bool User::checkBalance(float& currentUserBalance, float& footballerPrice)
{

	return currentUserBalance > footballerPrice;


}

void User::replace(User& currentUser, Teams& team, unordered_map<string, Footballer> TopPlayer, unordered_map<string, User>& Users) {


	string TeamFootballerName;
	string UserFootballerName;
invalidTeam:
	cout << "enter the name of player you want to replace." << endl;
	cin >> TeamFootballerName;
	if (team.getFootballPlayer().count(TeamFootballerName) > 0)
	{
	invalidSquad:
		cout << "enter the name of player from your team that you want to replace " << TeamFootballerName << " with." << endl;
		cin >> UserFootballerName;

		Footballer TeamFootballer = team.getFootballPlayer().at(TeamFootballerName);
		int mainIT = currentUser.GetMainSquad().count(UserFootballerName);
		int subIT = currentUser.GetSubstitutionSquad().count(UserFootballerName);
		if (mainIT > 0)
		{

			Footballer UserFootballer = currentUser.GetMainSquad().at(UserFootballerName);
			float cost = UserFootballer.GetPrice() - TeamFootballer.GetPrice();
			if (cost > 0)
			{
				cout << "The cost of replacement will be " << cost << "will added to your account" << endl;
				currentUser.addBalance(cost);
			}
			else
			{
				cout << "The cost of replacement will be " << abs(cost) << "will deduct from your account" << endl;
				currentUser.addBalance(cost);
			}
		}
		else if (subIT > 0)
		{
			Footballer UserFootballer = currentUser.GetSubstitutionSquad().at(UserFootballerName);
			float cost = UserFootballer.GetPrice() - TeamFootballer.GetPrice();
			if (cost > 0)
			{
				cout << "The cost of replacement will be: " << cost << " will added to your account" << endl;
				currentUser.addBalance(cost);
			}
			else
			{
				cout << "The cost of replacement will be: " << abs(cost) << " will deduct from your account" << endl;
				currentUser.addBalance(cost);
			}
		}
		else
		{
			cout << "Please select a valid Player name from your squad " << endl;
			goto invalidSquad;
		}

	}
	else {
		cout << "Please select a valid Player name from team " << endl;
		goto invalidTeam;
	}

}
