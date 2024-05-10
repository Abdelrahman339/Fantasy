#include "Admin.h"

#undef max

int counter = 0;
bool answer = false;

void Admin::CheckAdmin(unordered_map<string, User>& Users, vector<TheLeague>& leagues)
{
	int count = 0;
	string username, password;
	do
	{
		cout << "Enter Admin Username " << endl;
		cout << "Username: ";
		cin >> username;
		cout << "~~~~~~~" << endl;
		cout << "Enter Admin Password " << endl;
		cout << "Password: ";
		cin >> password;
		transform(username.begin(), username.end(), username.begin(), ::tolower);
		transform(password.begin(), password.end(), password.begin(), ::tolower);
		if ((username == "admin" && password == "admin") || (username == "1" && password == "1"))
		{
			PauseAndClear();
			cout << endl << "~~~ Welcome Back Admin! ~~~" << endl;
			AdminMenu(Users, leagues);
			return;
		}
		else
		{
			cout << endl << "Wrong Admin Username Or Password" << endl;
			count++;
			cout << "Please Try Again...  " << count << " / 3\n";
			PauseAndClear();
		}
	} while (count != 3);
}

void Admin::AdminMenu(unordered_map<string, User>& Users, vector<TheLeague>& leagues)
{
	int choice;
Menu:
	system("cls");
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
		AboutUsers(Users);
		goto Menu;
	}
	else if (choice == 2)
	{
		TeamMenu(leagues);
		goto Menu;
	}
	else if (choice == 3)
	{
		LeaguesMenu(leagues);
		goto Menu;
	}
	else if (choice == 4)
	{
		system("cls");
		return;
	}
	else
	{
		system("cls");
		cout << endl << "Please select a valid choice.." << endl;
		goto Menu;
	}
}




void Admin::AboutUsers(unordered_map<string, User>& Users)
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
		User::signup(&Users);
		cout << "Successfully Added Your New User " << endl;
		PauseAndClear();
		goto Choose;
	}
	else if (choice == 2)
	{
		ShowAndEditUser(Users);
		goto Choose;
	}
	else if (choice == 3)
	{
		UserSquadAndPlayers(Users);
	}
	else if (choice == 4)
	{
		answer = true;
		DeleteUser(Users);
		goto Choose;
	}
	else if (choice == 5)
	{
		return;
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
	cout << "\t| Full Name\t\t  | User Name" << endl;
	cout << "------------------------------------------------" << endl;
	for (auto it = Users.begin(); it != Users.end(); ++it)
	{
		cout << counter + 1 << "\t|" << Users.at(it->first).GetFullName() << "  \t\t  |" << it->first << endl;
		counter++;
	}
	cout << "------------------------------------------------" << endl;
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
		Sleep(700);
		ShowAndEditUser(Users);
	}
	else
	{
		ViewProfile(Users, Users.at(userName));
	}
}
void Admin::ViewProfile(unordered_map<string, User>& Users, User& currentUser)
{
	int choice;
choices:
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
	cout << "--------------------------------------" << endl;
	cout << "1-Edit User Information\n2-User Squad And Players\n3-Delete User \n4-Go Back" << endl;
	cout << "Enter your choice: ";
	cin >> choice;
	if (choice == 1)
	{
		EditProfile(Users, currentUser);
	}
	else if (choice == 2)
	{
		User::ShowSquad(&currentUser);
		ViewProfile(Users, currentUser);
	}
	else if (choice == 3)
	{
		answer = false;
		Deletion(Users, currentUser);
	}
	else if (choice == 4)
	{
		return;
	}
	else
	{
		system("cls");
		cout << endl << "Please select a valid choice.." << endl;
		goto choices;
	}
}
void Admin::EditProfile(unordered_map<string, User>& Users, User& currentUser)
{

	bool valid = false;
	int choice;
choices:
	Sleep(400);
	cout << endl;
	cout << "What Info Would You Like To Edit?" << endl;
	cout << "--------------------------------------" << endl;
	cout << "1-Full Name\t2-Username\n3-Email Address\t4-Phone Number\n5-Password\t6-Balance\n7-Points\t8-Go Back" << endl;
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
		User newusername;
		valid = true;
		auto it = Users.find(currentUser.GetUsername());//old username
		UserValidations::usernameCheck(&Users, currentUser);  //updated username
		if (it != Users.end()) // if old username exists
		{
			Users.insert({ currentUser.GetUsername(), currentUser });   //update the username
			newusername = currentUser;
			Users.erase(it);   //erasing old username
		}
		else
		{
			cout << "Username Not Found" << endl;
			valid = false;
		}
		cout << "Username updated successfully" << endl;
		PauseAndClear();
		ViewProfile(Users, newusername);
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
	else if (choice == 6)
	{
		EditBalancePoints(currentUser, 1, "new Balance");
		cout << "Balance updated successfully" << endl;
		PauseAndClear();
	}
	else if (choice == 7)
	{
		EditBalancePoints(currentUser, 2, "new Points");
		cout << "Points updated successfully" << endl;
		PauseAndClear();
	}
	else if (choice == 8)
	{
		ViewProfile(Users, currentUser);
		return;
	}
	else
	{
		cout << endl << "Please select a valid choice.." << endl;
		goto choices;
	}
	if (valid)
	{
		return;
	}
	else
	{
		Users[currentUser.GetUsername()] = currentUser;
		ViewProfile(Users, currentUser);
		return;
	}
}
void Admin::EditBalancePoints(User& CurrentUser, int choice, string information)
{
	float NewBalance = 1;
	int NewPoints = 1;
Redo:
	cout << "Enter Your " << information << ": " << endl;
	if (information == "new Balance")
	{
		cin >> NewBalance;
		if (!CheckBalancePoints(information))
		{
			goto Redo;
		}
	}
	else
	{
		cin >> NewPoints;
		if (!CheckBalancePoints(information))
		{
			goto Redo;
		}
	}
	if (NewBalance < 0 || NewPoints < 0)
	{
		cout << "Your " << information << " Cannot Be Negative" << endl;
		goto Redo;
	}
	else
	{
		if (choice == 1)
		{
			CurrentUser.SetBalance(NewBalance);
		}
		else
		{
			CurrentUser.SetPoints(NewPoints);
		}
	}
}
bool Admin::CheckBalancePoints(string information)
{
	if (cin.fail())
	{
		cout << "Your " << information << " Must Be A Value!" << endl;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		return false;
	}
	else
	{
		return true;
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
		Sleep(700);
		UserSquadAndPlayers(Users);
	}
	else
	{
		User::ShowSquad(&Users.at(userName));
		AboutUsers(Users);
	}
}

void Admin::DeleteUser(unordered_map<string, User>& Users)
{
	string userName;
start:
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
			Sleep(700);
			goto start;
		}
		else
		{
			Deletion(Users, Users.at(userName));
			return;
		}
	}
}

void Admin::Deletion(unordered_map<string, User>& Users, User CurrentUser)
{
start:
	int choice;
	cout << "Are you sure you want to delete " << CurrentUser.GetUsername() << "?" << endl;
	cout << "1. Yes \n2. No" << endl;
	cout << "Enter your choice: ";
	cin >> choice;
	if (choice == 1)
	{
		Users.erase(CurrentUser.GetUsername());
		cout << "Successfully Deleted " << CurrentUser.GetUsername() << endl;
		counter--;
	}
	else if (choice == 2)
	{
		if (answer)
		{
			cout << "Returning Back to the User Menu..." << endl;
			Sleep(500);
			answer = false;
			return;
		}
		else
		{
			Sleep(700);
			ViewProfile(Users, CurrentUser);
		}
	}
	else
	{
		cout << "Please Select a Valid Choice.." << endl;
		goto start;
	}
}

void Admin::TeamMenu(vector<TheLeague>& leagues) {
	int choice = -1;
	int InputInt = -1;
	string leagueName;
	cin.ignore();
beginning:
	vector<string> allNames = getStringsToSearchIn(leagues);
	cout << "Enter a League Name: ";
	getline(cin, leagueName);
	leagueName = toLowerCase(leagueName);
	string correctedLeagueName = getCorrectedString(allNames, leagueName);
	vector<TheLeague>::iterator it;
	TheLeague* leagueToBeModified = handleLeagueExistance(leagues, correctedLeagueName);
	if (leagueToBeModified == nullptr) {
		goto beginning;
	}
	map<string, Teams*>* modifiedTeams = leagueToBeModified->GetTeams();
start:
	displayTeamsForSpecificLeague(*leagueToBeModified);
	cout << "1) Modify a Team" << endl;
	cout << "2) Display Footballers in a Team" << endl;
	cout << "3) Go Back" << endl;
	cout << "Choice: ";
	cin >> choice;
	if (choice == 1) {
		modifiedTeams = ModifyTeams(modifiedTeams);
		leagueToBeModified->SetTeams(modifiedTeams);
		goto start;
	}
	else if (choice == 2) {
		FootballerMenu(modifiedTeams);
		goto start;

	}
	else if (choice == 3) {
		return;
	}
	else {
		cout << "Invalid Choice!" << endl;
		choice = -1;
		goto start;
	}
}

map<string, Teams*>* Admin::ModifyTeams(map<string, Teams*>* teams) {
	int choice;
	string teamName;
	string InputString;
	int InputInt;
	vector<string> allNames = getStringsToSearchIn(teams);
	cin.ignore();
TeamNotFound:
	cout << "Enter Team Name: ";
	getline(cin, teamName);
	teamName = toLowerCase(teamName);
	string correctedName = getCorrectedString(allNames, teamName);
	Teams* TeamToBeModified = handleTeamExistance(teams, correctedName);
	if (TeamToBeModified == nullptr) {
		goto TeamNotFound;
	}
	system("cls");
	do {
	ModifySameTeam:
		Teams* currentTeam = teams->at(TeamToBeModified->getName());
		cout << "\tModifying " << currentTeam->getName() << " information" << endl;
		cout << string(48, '-') << endl;
		cout << "What do you wish to Edit?" << endl;
		cout << "1) Name" << endl;
		cout << "2) Points" << endl;
		cout << "3) Delete the Team" << endl;
		cout << "4) Go Back" << endl;
		cout << "Choice: ";
		cin >> choice;

		switch (choice) {
		case 1:
			handleTeamsUpdate(teams, correctedName);
			break;
		case 2:
			cout << "Enter new Points: ";
			cin >> InputInt;
			currentTeam->SetPoints(InputInt);
			cout << "Updated Successfully!" << endl;
			break;
		case 3:
			teams->erase(currentTeam->getName());
			cout << "Deleted Successfully!" << endl;
			Sleep(1000);
			break;
		case 4:
			return teams;
		default:
			cout << "Invalid Choice!" << endl;
			Sleep(1000);
			goto ModifySameTeam;
		}
		cout << "Continue Modifying? (Yes/No)" << endl;
		cout << "Answer: ";
		cin.ignore();
		getline(cin, InputString);
	} while (InputString._Starts_with("yes") || InputString._Starts_with("Yes"));
	return teams;
}

void Admin::displayTeamsForSpecificLeague(TheLeague& league) {
	system("cls");
	cout << "\t\t~" << league.getLeagueName() << " Teams~" << endl << endl;
	TheLeague::displayTeams(league.GetTeams());
}


Footballer* Admin::handleFootballerExistance(unordered_map<string, Footballer>* players, string playerName) {
	auto it = players->find(toProperCase(playerName));
	if (it != players->end()) {
		return &it->second;
	}
	else {
		cout << "Couldn't Find This Footballer.." << endl;
		Sleep(700);
		return nullptr;
	}
}

void Admin::FootballerMenu(map<string, Teams*>* teams) {
	string teamName;
	vector<string> allNames = getStringsToSearchIn(teams);
	cin.ignore();
TeamNotFound:
	cout << "Enter a Team Name: ";
	getline(cin, teamName);
	teamName = toLowerCase(teamName);
	string correctedName = getCorrectedString(allNames, teamName);
	Teams* selectedTeam = handleTeamExistance(teams, correctedName);
	if (selectedTeam == nullptr) {
		goto TeamNotFound;
	}
	unordered_map<string, Footballer>* modifiedPlayers = selectedTeam->getFootballPlayer();
footballersDisplay:
	DisplayFootballersForSpecificTeam(*selectedTeam);
	cout << "1) Modify a Footballer" << endl;
	cout << "2) Go Back" << endl;
	cout << "Choice: ";
	int choice;
	cin >> choice;
	switch (choice) {
	case 1:
		//Updating the player
		modifiedPlayers = ModifyFootballer(selectedTeam->getFootballPlayer());
		selectedTeam->setPlayers(modifiedPlayers);
		goto footballersDisplay;
	case 2:
		return;
	default:
		cout << "Invalid Choice!" << endl;
		Sleep(1000);
		goto footballersDisplay;
	}
}

unordered_map<string, Footballer>* Admin::ModifyFootballer(unordered_map<string, Footballer>* players) {
	int choice;
	string InputString;
	float InputInt;
	bool InputBool;
	vector<string> allNames = getStringsToSearchIn(players);
	string footballerName;
	cin.ignore();
PlayerNotFound:
	cout << "Enter a footballer's Name: ";
	getline(cin, footballerName);
	footballerName = toLowerCase(footballerName);
	string correctedName = getCorrectedString(allNames, footballerName);
	Footballer* footballerToBeModified = handleFootballerExistance(players, correctedName);
	if (footballerToBeModified == nullptr) {
		goto PlayerNotFound;
	}
	system("cls");
	do {
		Footballer currentFootballer = players->at(footballerToBeModified->GetName());
		cout << "\tModifying " << currentFootballer.GetName() << " information" << endl;		cout << "Modify " << footballerToBeModified->GetName() << "'s information" << endl;
		cout << "What do you wish to Edit?" << endl;
		cout << "1) Name" << endl;
		cout << "2) Age" << endl;
		cout << "3) Captain" << endl;
		cout << "4) Position" << endl;
		cout << "5) Team" << endl;
		cout << "6) Price" << endl;
		cout << "7) Rating" << endl;
		cout << "8) Delete the Player" << endl;
		cout << "9) Go Back" << endl;
		cout << "Choice: ";
	retryChoice:
		cin >> choice;
		switch (choice) {
		case 1:
			handlePlayersUpdate(players, correctedName);
			cout << "Successfully Updated." << endl;
			break;
		case 2:
		retryAgeInput:
			cout << "Enter new age: ";
			cin >> InputInt;
			if (InputInt < 17) {
				cout << "Age should be more than 17 years old." << endl;
				Sleep(2000);
				goto retryAgeInput;
			}
			else {
				currentFootballer.SetAge(InputInt);
				cout << "Successfully Updated." << endl;
				break;
			}
		case 3:
			cout << "Is the Player a Captain? (1 for Yes / 0 for No): ";
			cin >> InputBool;
			currentFootballer.SetCaptain(InputBool);
			cout << "Successfully Updated." << endl;
			break;
		case 4:
			cout << "Enter new position: ";
			cin.ignore();
			getline(cin, InputString);
			currentFootballer.SetPosition(InputString);
			cout << "Successfully Updated." << endl;
			break;
		case 5:
			cout << "Enter new team: ";
			cin.ignore();
			getline(cin, InputString);
			currentFootballer.SetTeam(InputString);
			cout << "Successfully Updated." << endl;
			break;
		case 6:
			cout << "Enter new price: ";

			cin >> InputInt;
			currentFootballer.SetPrice(InputInt);
			cout << "Successfully Updated." << endl;
			break;
		case 7:
			cout << "Enter new rating: ";
			cin >> InputInt;
			currentFootballer.SetRating(InputInt);
			cout << "Successfully Updated." << endl;
			break;
		case 8:
			cout << "Deleted Successfully!" << endl;
			players->erase(footballerToBeModified->GetName());
			break;
		case 9:
			return players;
		default:
			cout << "Invalid choice!" << endl;
			Sleep(1000);
			goto retryChoice;
		}
		//Updating the hash table
		//players.at(footballerName) = *footballerToBeModified;
		Sleep(1000);
		cout << "Continue Modifying? (Yes/No)" << endl;
		cin.ignore();
		getline(cin, InputString);
		system("cls");
	} while (InputString._Starts_with("yes") || InputString._Starts_with("Yes"));
	return players;
}
Teams* Admin::handleTeamExistance(map<string, Teams*>* teams, string teamName) {

	auto it = teams->find(toProperCase(teamName));
	if (it != teams->end()) {
		return it->second;
	}
	else {
		cout << "Couldn't Find This Team.." << endl;
		Sleep(700);
		return nullptr;
	}
}
string Admin::toProperCase(const std::string& str) {
	std::stringstream ss(str);
	std::string word, result;

	// Iterate through each word in the string
	while (std::getline(ss, word, ' ')) {
		if (!word.empty()) {
			// Capitalize the first letter of the word
			word[0] = std::toupper(word[0]);

			// Append the word to the result string
			result += word + " ";
		}
	}

	// Remove trailing space
	if (!result.empty()) {
		result.pop_back();
	}

	return result;
}

void Admin::handleTeamsUpdate(map<string, Teams*>* teams, string oldName) {
	string newName;
	cout << "Enter new name: ";
	cin.ignore();
	getline(cin, newName);
	string properNewName = toProperCase(newName);
	auto it = teams->find(toProperCase(oldName));
	if (it != teams->end()) {
		teams->insert(make_pair(properNewName, it->second));
		teams->at(properNewName)->SetName(newName);
		teams->erase(it);
	}
	else {
		cout << "Key " << oldName << " not found." << endl;
	}
}

void Admin::DisplayFootballersForSpecificTeam(Teams& selectedTeam) {
	unordered_map<string, Footballer>* players = selectedTeam.getFootballPlayer();
	unordered_map<string, Footballer>::iterator it = players->begin();
	system("cls");
	cout << "\t\t~Players in " << selectedTeam.getName() << "~" << endl;
	cout << string(60,'-') << endl;
	cout << "\t  Name" << User::spacing(15, ' ') << "\tPosition" << User::spacing(15, ' ') << "\tPrice" << endl << endl;
	for (it; it != players->end(); ++it) {
		cout << "\t" << it->second.GetName() << "\t" << checkStrLengthFootballers(it->first) << it->second.GetPosition() << "\t" << checkStrLengthFootballers(it->second.GetPosition()) << it->second.GetPrice() << endl;
	}
	cout << string(60, '-') << endl;
}

//vector<TheLeague> allleagues
//unordered_map of user
//map ll team
//unordered map ll footballer

TheLeague* Admin::handleLeagueExistance(vector<TheLeague>& leagues, string leagueName)
{
	for (int i = 0; i < leagues.size(); i++) {
		string originalLeagueName = toLowerCase(leagues[i].getLeagueName());
		if (originalLeagueName == leagueName) {
			return &leagues[i];
		}
	}
	cout << "Invalid League Name!" << endl;
	Sleep(700);
	return nullptr;
}

void Admin::LeaguesMenu(vector<TheLeague>& leagues) {
	int choice;
	string leagueName;
	string newLeagueName;
LeagueMenu:
	system("cls");
	DisplayAllLeagues(leagues);
	cout << "1) Select a League to Show it's Teams" << endl;
	cout << "2) Select a League to Edit it's Name" << endl;
	cout << "3) Go Back" << endl;
	cout << "Choice: ";
	cin >> choice;
	if (choice == 1) {
		TeamMenu(leagues);
		goto LeagueMenu;
	}
	else if (choice == 2) {
		UpdateLeagueName(leagues);
		goto LeagueMenu;
	}
	else if (choice == 3) {
		return;
	}
	else {
		cout << "Invalid Choice!" << endl;
		Sleep(1000);
		goto LeagueMenu;
	}
}

void Admin::DisplayAllLeagues(vector<TheLeague>& leagues) {
	vector<TheLeague>::iterator it;
	cout << "\t\t~All Leagues~" << endl;
	cout << string(48, '-') << endl;
	for (it = leagues.begin(); it != leagues.end(); ++it) {
		cout << "\t\t" << it->getLeagueName() << std::endl;
	}
	cout << string(48, '-') << endl;

}

void Admin::UpdateLeagueName(vector<TheLeague>& leagues) {
	string leagueName;
	string newLeagueName;
	TheLeague* leagueToBeModified = nullptr;
	vector<string> allNames = getStringsToSearchIn(leagues);
	cin.ignore();
beginning:
	cout << "Enter a League Name: ";
	getline(cin, leagueName);
	leagueName = toLowerCase(leagueName);
	string correctedName = getCorrectedString(allNames, leagueName);
	leagueToBeModified = handleLeagueExistance(leagues, correctedName);
	if (leagueToBeModified == nullptr) {
		goto beginning;
	}
	else {
		cout << "Enter the new Name: ";
		getline(cin, newLeagueName);
		for (int i = 0; i < leagues.size(); i++) {
			string originalLeagueName = toLowerCase(leagues[i].getLeagueName());
			if (originalLeagueName == correctedName) {
				leagues[i].setLeagueName(newLeagueName);
				cout << "Updated Successfully!" << endl;
				Sleep(1000);
			}
		}
	}
}

string Admin::getCorrectedString(vector<string> allNames, string incorrectString) {
	if (incorrectString.size() < 4) {
		return "";
	}
	for (const string& str : allNames) {
		if (str.find(incorrectString) != string::npos) {
			return str;
		}
	}
	return "";
}

string Admin::toLowerCase(const string& str) {
	string result = str;
	transform(result.begin(), result.end(), result.begin(),
		[](unsigned char c) { return tolower(c); });
	return result;
}

vector<string> Admin::getStringsToSearchIn(vector<TheLeague>& leagues) {
	vector<string> leagueNames;
	for (size_t i = 0; i < leagues.size(); i++) {
		string leagueName = toLowerCase(leagues[i].getLeagueName());
		leagueNames.push_back(leagueName);
	}
	return leagueNames;
}

vector<string> Admin::getStringsToSearchIn(map<string, Teams*>* teams) {
	vector<string> teamNames;

	for (auto it = teams->begin(); it != teams->end(); ++it) {
		string teamName = toLowerCase(it->first);
		teamNames.push_back(teamName);
	}
	return teamNames;
}

vector<string> Admin::getStringsToSearchIn(unordered_map<string, Footballer>* players)
{
	vector<string> playerNames;
	for (auto it = players->begin(); it != players->end(); ++it) {
		string playerName = toLowerCase(it->first);
		playerNames.push_back(playerName);
	}
	return playerNames;
}

void Admin::handlePlayersUpdate(unordered_map<string, Footballer>* players, string oldName) {
	string newName;
	cout << "Enter new name: ";
	cin.ignore();
	getline(cin, newName);
	string properNewName = toProperCase(newName);
	auto it = players->find(toProperCase(oldName));
	if (it != players->end()) {
		// Inserting a new element with the new key and same value
		players->insert(make_pair(properNewName, it->second));
		players->at(properNewName).SetName(newName);
		// Erasing the old element
		players->erase(it);
	}
	else {
		cout << "Key " << oldName << " not found." << endl;
	}
}

string Admin::checkStrLengthFootballers(string str) {
	if (str.length() < 16 && str.length() >= 8) {
		return "\t";
	}
	else if (str.length() < 8) {
		return "\t\t";
	}
	return "";
}

void Admin::PauseAndClear()
{
	system("pause");
	system("cls");
}