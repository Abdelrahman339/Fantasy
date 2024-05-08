#include "LuckyWheel.h"


void LuckyWheel::playLuckyWheel(vector<TheLeague> leagues, User& user) {
	system("cls");

	if (!user.playWheel()) {
		user.handleLuckyWheelResult({});
		return;
	}
	time_t lastDate = user.getLastDatePlayedWheel();
	time_t nextSpinDate = user.getNextSpinDate();

	cout << "Last date played: " << user.formatDate(lastDate) << endl;
	cout << "Next spin scheduled for: " << user.formatDate(nextSpinDate) << endl;

	system("pause");
	system("cls");

	pair<string, pair<float, Footballer>> discountedFootballer = displayLuckyWheel(leagues);

	user.handleLuckyWheelResult(discountedFootballer);
}

void LuckyWheel::getFootballPlayersToBeDisplayed(vector<TheLeague> leagues, int& numberOfFootballersToBeDisplayed, unordered_map<string, Footballer>& footballersToBeDisplayed, bool& isRandomGeneratorSeeded) {

	// Seed the random number generator (optional but recommended)
	if (!isRandomGeneratorSeeded) {
		srand(static_cast<unsigned int>(time(nullptr)));
		isRandomGeneratorSeeded = true;
	}

	if (numberOfFootballersToBeDisplayed == 0)
		return;

	// Select a random league
	int random_league_index = rand() % leagues.size();
	TheLeague selectedLeague = leagues[random_league_index];
	map<string, Teams> teams = selectedLeague.GetTeams();
	// Print league information
	//cout << "Selected League: " << selectedLeague.getLeagueName() << endl;

	// Get team names from the selected league
	vector<string> teamNames = TheLeague::getTeamNames(teams);

	// Select a random team (assuming teamNames.size() <= 15)
	if (teamNames.empty()) {
		cout << "No teams found in selected league." << endl;
		system("pause");
		system("cls");
		// Check if you want to try again or not.
		return getFootballPlayersToBeDisplayed(leagues, numberOfFootballersToBeDisplayed, footballersToBeDisplayed, isRandomGeneratorSeeded);
	}
	int random_team_index = rand() % teamNames.size();
	string selectedTeamName = teamNames[random_team_index];
	Teams selectedTeam = teams[selectedTeamName];

	// Print selected team name
	//cout << "Selected Team Name: " << selectedTeamName << endl;
	unordered_map<string, Footballer> footballers = selectedTeam.getFootballPlayer();

	if (footballers.empty()) {
		cout << "No footballers found in selected league." << endl;
		system("pause");
		system("cls");
		// Check if you want to try again or not.
		return getFootballPlayersToBeDisplayed(leagues, numberOfFootballersToBeDisplayed, footballersToBeDisplayed, isRandomGeneratorSeeded);
	}

	// Get a random iterator to pick a random footballer
	unordered_map<string, Footballer>::iterator random_it = footballers.begin();
	advance(random_it, rand() % footballers.size());

	//cout << "Selected Footballer Name: " << selectedFootballerName << endl << endl;
	footballersToBeDisplayed.insert(
		make_pair(random_it->first, random_it->second)
	);
	numberOfFootballersToBeDisplayed--;


	return getFootballPlayersToBeDisplayed(leagues, numberOfFootballersToBeDisplayed, footballersToBeDisplayed, isRandomGeneratorSeeded);
}
string LuckyWheel::generateCongratulatoryMessage(string lottery, float discount) {
	vector<string> messages = {
		"Lottery jackpot winner! A surprise discount awaits!",
		"Congrats, lottery winner!\nYou've also unlocked a secret discount!",
		"Jackpot winner AND surprise discount? Talk about lucky!",
		"Winning feeling + discount surprise = Your best day ever!",
		"Time to celebrate in style!"
	};
	// Generate a random index
	int index = rand() % messages.size();

	string discountStr = to_string(round(discount * 1000) / 1000);
	string discountOfTwoDigits;

	discountOfTwoDigits.push_back(discountStr[0]);
	discountOfTwoDigits.push_back(discountStr[1]);
	discountOfTwoDigits.push_back(discountStr[2]);
	discountOfTwoDigits.push_back(discountStr[3]);

	// Return the randomly selected message
	return messages[index] + '\n' + string(30, '-') + '\n' + "Congrats you've won " + discountOfTwoDigits + "% on -> " + lottery;
}

pair<string, pair<float, Footballer>> LuckyWheel::displayLuckyWheel(vector<TheLeague> leagues) {
	int numberOfFootballersToBeDisplayed = 6;
	unordered_map<string, Footballer> footballersToBeDisplayed;
	bool isRandomGeneratorSeeded = false;

	getFootballPlayersToBeDisplayed(leagues, numberOfFootballersToBeDisplayed, footballersToBeDisplayed, isRandomGeneratorSeeded);

	displayFootballersInLuckyWheel(footballersToBeDisplayed);

	unordered_map<string, Footballer>::iterator random_it = footballersToBeDisplayed.begin();
	advance(random_it, rand() % footballersToBeDisplayed.size());

	float discount = static_cast<float>(rand()) / RAND_MAX * 0.35f;

	cout << generateCongratulatoryMessage(random_it->first, discount * 100) << endl;

	system("pause");
	system("cls");

	return make_pair(
		random_it->first,
		make_pair(discount, random_it->second)
	);
}
void LuckyWheel::displayFootballersInLuckyWheel(unordered_map<string, Footballer>& footballersToBeDisplayed) {
	for (size_t k = 0; k < 2; k++) {
		for (size_t i = 0; i < footballersToBeDisplayed.size(); ++i) {

			cout << "Fantasy Football Lucky Wheel!" << endl;
			cout << string(30, '-') << endl << endl;

			size_t j = 0;
			for (const auto& pair : footballersToBeDisplayed) {
				cout << pair.first << (j == i ? " <- " : "") << endl;
				j++;
			}

			cout << endl;
			cout << "You Might be the lucky winner of today..." << endl;
			cout << "Loading..." << endl;

			// Wait for a short duration
			this_thread::sleep_for(200ms);

			// Clear the console
			system("cls");
		}
		system("cls");
	}
}
