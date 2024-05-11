#include <deque>
#include <stack>
#include <set>
#include "Competition.h"
#include "User.h"


using namespace std;

void User::Market(User* currentUser, vector <TheLeague>& leagues)
{
	cout << "\n\n\n\n";
	cout << spacing(60, ' ') << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << spacing(60, ' ') << "             Fatntasy Market" << endl;
	cout << spacing(60, ' ') << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << "\n\n\n\n";

	//unordered_map<string, Footballer*>* topPlayers = new unordered_map<string, Footballer*>();
	//TopFootballers(topPlayers, leagues);
	//Format343(*topPlayers, "Top Player");
	//cout << endl << endl << endl;

invlaidMarket:
	string choice;

	cout << spacing(60, ' ') << "1-search. 2-Sell your players. 3-Go back." << endl;
	cout << spacing(60, ' '); cin >> choice;
	if (choice == "1") {
		cout << spacing(60, ' '); search(currentUser, leagues);
		cout << spacing(60, ' '); system("pause"); system("cls");
		Market(currentUser, leagues);
	}
	else if (choice == "2") {
		cout << spacing(60, ' '); system("pause"); system("cls");
		string FootballerName;
		Format343(currentUser->GetMainSquad(), "Player");
		cout << endl << endl << endl;
		showSubstitutions(currentUser->GetSubstitutionSquad());
		cout << endl << endl;

		cout << spacing(60, ' '); cout << "Enter Footballer name that you want to sell." << endl;
		cout << spacing(60, ' '); getline(cin >> ws, FootballerName);
		sell(currentUser, FootballerName);
		cout << spacing(60, ' '); fromSubtoMain(&currentUser->GetMainSquad(), &currentUser->GetSubstitutionSquad());
		cout << spacing(60, ' '); system("cls");
		Market(currentUser, leagues);
	}
	else if (choice == "3") {
		system("pause"); system("cls");
		return;
	}
	else {
		cout << "invalid input.Please try again ";
		goto invlaidMarket;
	}

};

//void User::showtopFootballers(unordered_map<string, Footballer*> TopPlayer, User* currentUser, vector<TheLeague> Leageus)
//{
//	string footballerName;
//	int choice;
//invalid:
//	cout << "Welcome to top player in the session!" << endl;
//	User::Format343(TopPlayer, "Top Player");
//
//	cout << "\n\n";
//
//	cout << "1-Show information about player\n2-buy player\n3-Replace player\n4-Go back." << endl;
//	cin >> choice;
//	if (choice == 1) {
//
//		cout << "Enter the name of the player you want to show information about" << endl;
//		getline(cin >> ws, footballerName);
//		Footballer* targetFootballer;
//		Teams footballerTeam;
//
//		targetFootballer = returnPlayer(footballerName, *currentUser, "buy", Leageus, footballerTeam);
//
//		//checking if the object of footballer is empty or not 
//		if (targetFootballer != nullptr)
//		{
//			PlayerFunction(targetFootballer, currentUser);
//			Market(currentUser, Leageus);
//			return;
//		}
//
//	}
//
//	else if (choice == 2)
//	{
//		buy(currentUser, Leageus);
//		return;
//
//	}
//	else if (choice == 3) {
//
//		Footballer* targetFootballer;
//		string footballerName;
//		Teams team;
//	invalid_Footballer_name:
//		cout << "Enter the name of the player you want to Replace" << endl;
//		getline(cin >> ws, footballerName);
//		targetFootballer = returnPlayer(footballerName, *currentUser, "buy", Leageus, team);
//		if (targetFootballer != nullptr)
//		{
//
//			Format442(currentUser->GetMainSquad(), "Player");
//
//			cout << endl;
//
//			showSubstitutions(currentUser->GetSubstitutionSquad());
//
//			cout << endl << endl;
//
//			replace(currentUser, targetFootballer);
//			goto invalid;
//		}
//		else {
//			cout << "Please enter a valid name" << endl;
//			goto invalid_Footballer_name;
//		}
//	}
//	else if (choice == 4) {
//		return;
//	}
//	else {
//		cout << "Invalid choice.Please select valid choice" << endl;
//		goto invalid;
//	}
//
//
//}




void User::search(User* currentUser, vector<TheLeague>  leagues)
{
	// all the variables declartion
	int ans;
	string search;
	Teams footballerTeam;
	Footballer* targetFootballer = nullptr;
invalid:

	// the user enter a name either of (Player name) , (Team name).
	cout << "You can search by teams or the name of footballer." << endl;


	getline(cin >> ws, search);


	//funcion find team to find the team that the user entered
	Teams* Wantedteam = findTeam(leagues, search);

	//function typos start here to check if the user enterd any wrong Player name.after this function is done it return a object of type footballer
	int choice;
	targetFootballer = returnPlayer(search, *currentUser, "buy", leagues, footballerTeam);

	//checking if the object of footballer is empty or not 
	if (targetFootballer != nullptr)
	{
		PlayerFunction(targetFootballer, currentUser);
		return;
	}



	//checking if the find team return a team or a empty team
	else if (Wantedteam != nullptr)
	{
		system("cls");
		cout << "\n\n\n\n\n";
	invalid_input:
		int choice;
		string footballerName;
		// Make OverLoaded Method or convert unordered_map<string, Footballer*> to unordered_map<string, Footballer>*
		User::Format343(Wantedteam->getFootballPlayer(), Wantedteam->getName());
		cout << endl;
		cout << "1- show information about player\n2-buy player\n3-replace player\n4-go back" << endl;
		cin >> choice;
		switch (choice)
		{
		case 1:
			cout << "Enter the name of the player you want to show information about" << endl;
			getline(cin >> ws, footballerName);
			targetFootballer = returnPlayer(footballerName, *currentUser, "buy", leagues, footballerTeam);

			//checking if the object of footballer is empty or not 
			if (targetFootballer != nullptr)
			{
				PlayerFunction(targetFootballer, currentUser);
				goto invalid_input;
			}
			break;
		case 2:
			buy(currentUser, leagues);
			return;
			break;
		case 3:
		invalid_Footballer_name:
			cout << "Enter the name of the player you want to Replace" << endl;
			getline(cin >> ws, footballerName);
			targetFootballer = returnPlayer(footballerName, *currentUser, "buy", leagues, footballerTeam);
			if (targetFootballer != nullptr)
			{

				Format442(currentUser->GetMainSquad(), "Player");

				cout << endl;

				showSubstitutions(currentUser->GetSubstitutionSquad());

				cout << endl << endl;

				replace(currentUser, targetFootballer);
				goto invalid_input;
			}
			else {
				cout << "Please enter a valid name" << endl;
				goto invalid_Footballer_name;
			}
			return;
			break;
		case 4:
			return;
		default:
			cout << "Enter a valid option" << endl;
			system("pause"); system("cls");
			goto invalid_input;
			break;
		}
	}


	// the two method return false value so the user entered a wrong team and footballer name
	else
	{
		cout << "please enter a valid Team name or Footabller name" << endl;
		goto invalid;
	}


}
Footballer* User::returnPlayer(string footballerName, User currentUser, string status, vector<TheLeague> leagues, Teams& footballerTeam)
{

	string nameOfFootballer = avoidTypos(footballerName, currentUser, "buy", leagues, footballerTeam);
	Footballer* TargetedFootballer;
	bool found = false;
	int it = footballerTeam.getFootballPlayer()->count(nameOfFootballer);
	if (it > 0)
	{
		TargetedFootballer = &footballerTeam.getFootballPlayer()->at(nameOfFootballer);
		return TargetedFootballer;
	}
	else
	{
		return nullptr;
	}

}





Teams* User::findTeam(vector<TheLeague> leagues, string TeamName)
{
	User user;
	Teams team;
	string Teamexist = avoidTypos(TeamName, user, "Team", leagues, team);
	int teamfound;
	Teams* wantedTeam = nullptr;

	for (int i = 0; i < leagues.size(); i++) {
		teamfound = leagues[i].GetTeams()->count(Teamexist);
		if (teamfound > 0)
			wantedTeam = leagues[i].GetTeams()->at(Teamexist);
	}

	return wantedTeam;













	//Teams teamFound;
	//for (int i = 0; i < leagues.size(); i++)
	//{
	//	map<string, Teams> teamsInLeagus = leagues.at(i).GetTeams();
	//	int TeamExist = teamsInLeagus.count(TeamName);
	//	if (TeamExist > 0) {
	//		teamFound = teamsInLeagus.at(TeamName);
	//	}

	//}
	//return teamFound;
}










bool User::sell(User* currentUser, string footballerName) {


	char ans;
	Teams TeamName;
	string playerExist = User::avoidTypos(footballerName, *currentUser, "sell", {}, TeamName);



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



void User::sellFunction(User* currentUser, string footballerName, string status)
{
	unordered_map<string, Footballer*>* squad;
	if (status == "main")
	{
		squad = &currentUser->GetMainSquad();
	}

	else
	{
		squad = &currentUser->GetSubstitutionSquad();
	}

	cout << spacing(60, ' ') << "Player sold successfully.." << endl;

	float FootballerPrice = squad->at(footballerName)->GetPrice();

	squad->erase(footballerName);

	currentUser->addBalance(FootballerPrice);
	system("pause");
	system("cls");

}
;





void User::buy(User* currentUser, vector<TheLeague> Leagues) {

	// all used variables
	string footballerName;
	Footballer* wantedFootballer = nullptr;
	Teams PlayerTeam;
	string playerExist;
	char ans;


invalid:
	cout << "Enter the name of your wanted player to buy.\n";
	getline(cin >> ws, footballerName);
	playerExist = User::avoidTypos(footballerName, *currentUser, "buing", Leagues, PlayerTeam);


	//the user enterd the name of the player correctlly 
	if (playerExist == "exist")
	{
		//get the footballer object from the team
		wantedFootballer = &PlayerTeam.getFootballPlayer()->at(footballerName);

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
		wantedFootballer = &PlayerTeam.getFootballPlayer()->at(playerExist);
	invalidOption:
		cout << "You enterd a wrong player .Do you mean " << playerExist << "?" << endl;
		cin >> ans;


		//asking the user if he is the wanted player or not
		if (ans == 'y')
		{


			buyFunction(currentUser, wantedFootballer);

			return;

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


void User::buyFunction(User* currentUser, Footballer* footballer)
{
	float FootballerPrice = footballer->GetPrice();
	float currentBalance = currentUser->GetBalance();

	if (!checkBalance(currentBalance, FootballerPrice))
	{

		cout << "you don't have enough money to buy this player." << endl;
		return;
	}
	if (currentUser->SetFootballer(footballer)) {
		currentUser->addBalance(-FootballerPrice);
		cout << "\n\n\n\n";

		cout << spacing(40, ' ') << "Player bought successfully." << endl;
		system("pause");
		system("cls");

	}
};





bool User::checkBalance(float& currentUserBalance, float& footballerPrice)
{

	return currentUserBalance > footballerPrice;


}

void User::replace(User* currentUser, Footballer* wantedFootballer) {


	string TeamFootballerName = wantedFootballer->GetName();
	string UserFootballerName;
	Teams team;
	regex pattern(R"(main)");
	char ans;

invalidSquad:


	cout << "enter the name of player from your team that you want to replace " << TeamFootballerName << " with." << endl;
	getline(cin >> ws, UserFootballerName);

	Footballer* TeamFootballer = wantedFootballer;
	string existPlayer = avoidTypos(UserFootballerName, *currentUser, "sell", {}, team);


	if (existPlayer == "existMain")
	{

		replaceFunction(currentUser, UserFootballerName, TeamFootballer, "Main");
	}



	else if (existPlayer == "existSub")
	{
		replaceFunction(currentUser, UserFootballerName, TeamFootballer, "Sub");
	}


	else if (!existPlayer.empty())
	{
		if (regex_search(existPlayer, pattern))
		{
			existPlayer = regex_replace(existPlayer, pattern, "");
		invalidOp:
			cout << "You enterd a wrong player .Do you mean " << existPlayer << "?(y/n)" << endl;
			cin >> ans;
			switch (ans)
			{
			case'y':
				replaceFunction(currentUser, existPlayer, TeamFootballer, "Main");
				break;
			case'n':
				goto invalidSquad;
			default:
				cout << "Please enter a valid option" << endl;
				goto invalidOp;
				break;
			}

		}

		else
		{
			cout << "You enterd a wrong player .Do you mean " << existPlayer << "?(y/n)" << endl;
			cin >> ans;
			switch (ans)
			{
			case'y':
				replaceFunction(currentUser, existPlayer, TeamFootballer, "Sub");
				break;
			case'n':
				goto invalidSquad;
			default:
				cout << "Please enter a valid option" << endl;
				goto invalidOp;
				break;
			}
		}

	}

	else
	{
		cout << "Please select a valid Player name from your squad " << endl;
		goto invalidSquad;
	}



}

void User::replaceFunction(User* currentUser, string UserFootballerName, Footballer* TeamFootballer, string status)
{
	Footballer* UserFootballer;
	if (status == "Main")
	{
		UserFootballer = currentUser->GetMainSquad().at(UserFootballerName);
	}
	else {
		UserFootballer = currentUser->GetSubstitutionSquad().at(UserFootballerName);

	}


	float cost = UserFootballer->GetPrice() - TeamFootballer->GetPrice();
	if (cost > 0)
	{
		char ans;
		cout << "The cost of replacement will be:" << cost << "$ and will added to your account" << endl;
		cout << "Are you sure you want to continue?(y/n)\n";
		cin >> ans;
		switch (ans)
		{
		case'y':
			currentUser->addBalance(cost);
			currentUser->GetMainSquad().erase(UserFootballerName);
			currentUser->SetFootballer(TeamFootballer);
			cout << "\n\n\n";
			cout << spacing(60, ' ') << "Player Replaced successfully" << endl;
			system("pause");
			system("cls");
			break;
		case'n':
			system("cls");
			return;
		default:
			break;
		}
	}
	else
	{
		float userBalance = currentUser->GetBalance();
		cout << "The cost of replacement will be:" << abs(cost) << "$ and will deduct from your account" << endl;
		cout << "Are you sure you want to continue?(y/n)\n";
		char ans;
		cin >> ans;
		switch (ans)
		{
		case'y':

			if (checkBalance(userBalance, cost))
			{
				currentUser->addBalance(cost);
				currentUser->GetMainSquad().erase(UserFootballerName);
				currentUser->SetFootballer(TeamFootballer);
				cout << "\n\n\n";
				cout << spacing(60, ' ') << "Player Replaced successfully" << endl;
				system("pause");
				system("cls");
			}
			else
			{
				cout << "You don't have enough money to pay the cost" << endl;
				system("pause");
				system("cls");
				return;
			}
			break;
		case'n':
			return;
		default:
			break;
		}

	}

}





void User::PlayerFunction(Footballer* targetFootballer, User* currentUser)
{
	int choice;
invalidOption:
	User::showPlayerInfo(*targetFootballer, "market");
	cout << "1-buy the player\n2-Replace the player\n3-Go back" << endl;
	cin >> choice;
	switch (choice)
	{
	case 1:
		buyFunction(currentUser, targetFootballer);
		break;
	case 2:
		system("cls");
		cout << "your fantasy squad" << endl;
		squadFormat(2, currentUser->GetMainSquad());
		cout << "\n\n\ ";
		showSubstitutions(currentUser->GetSubstitutionSquad());
		cout << "\n\n\ ";


		replace(currentUser, targetFootballer);
		break;
	case 3:
		return;
	default:
		cout << "Please enter a valid option" << endl;
		system("pause");
		system("cls");
		goto invalidOption;
		break;
	}
}
;
