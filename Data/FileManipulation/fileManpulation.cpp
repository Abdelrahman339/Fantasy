#pragma once
#include <fileManpulation.h>

string readFileData(string filename) {
	string currentDir = "Data/Files/";
	filename = currentDir + filename;
	ifstream file(filename);
	string file_data;

	if (file.is_open()) {
		// Use stringstream to efficiently read file into string
		stringstream ss;
		ss << file.rdbuf();
		file_data = ss.str();
	}
	else
		cout << "Error: Could not open file" << endl;
	file.close();
	return file_data;
}

vector<string> splitByRegex(string data, string reg) {
	vector<string> parts;
	regex re(reg);
	sregex_token_iterator iter(data.begin(), data.end(), re, -1);
	sregex_token_iterator end;

	while (iter != end) {
		parts.push_back(*iter);
		++iter;
	}

	return parts;
}


void fileManipulation::writeInfoInSpecificFile(string filename, vector<TheLeague> leagues) {
	//leagueDataNew.txt

	string currentDir = "Data/Files/";
	filename = currentDir + filename;

	ofstream file(filename);
	if (file.is_open()) {
		stringstream ss;
		ss << "League Name (Unique)\n";
		ss << "Teams Names(Prefered to delete if name doesn't end with - )\n";
		ss << "----\n";
		for (auto it = leagues.begin(); it != leagues.end(); ++it) {
			ss << it->getLeagueName() << "\n";
			const vector<string>& teamNames = it->getTeamNames(it->GetTeams());
			for (const auto& teamName : teamNames) {
				ss << teamName << "\n";
			}
			if (next(it) != leagues.end()) {
				ss << "----\n";
			}
		}

		// Write the content string to the file
		file << ss.str();

		// Close the file
		file.close();

		cout << "Data has been written to the file.\n";
	}
	else {
		cerr << "Unable to open the file.\n";
	}
}
void fileManipulation::writeUserSquaddata(string filename, unordered_map<string, User> allUsers)
{
	stringstream ss;
	string currentDir = "Data/Files/";
	filename = currentDir + filename;
	ofstream file(filename);
	if (file.is_open()) {
		ss << "User ID\n";
		ss << "--------\n";
		ss << "Team Name\n";
		ss << "User Main Footballer Name 1\n";
		ss << "User Main Footballer Name 2\n";
		ss << "----\n";
		ss << "Team Name\n";
		ss << "User Main Footballer Name 3\n";
		ss << "--------\n";
		ss << "Team Name\n";
		ss << "User Substitution Footballer Name 1\n";
		ss << "----\n";
		ss << "Team Name\n";
		ss << "User Substitution Footballer Name 2\n";
		ss << "User Substitution Footballer Name 3\n";
		ss << "----------------\n";
		int i = 0;
		for (auto& user : allUsers)
		{
			ss << user.second.GetId() << endl;
			ss << "--------\n";
			int j = 0;
			for (auto& player : user.second.GetMainSquad())
			{
				ss << player.second->GetTeam() << endl;
				ss << player.first << endl;
				j++;
				if (j != user.second.GetMainSquad().size())
				{
					ss << "----\n";

				}
			}
			if (user.second.GetSubstitutionSquad().size() != 0)
			{
				ss << "--------\n";

			}
			int k = 0;
			for (auto& player : user.second.GetSubstitutionSquad())
			{
				ss << player.second->GetTeam() << endl;
				ss << player.first << endl;
				k++;
				if (k != user.second.GetSubstitutionSquad().size())
				{
					ss << "----\n";

				}
			}
			i++;
			if (i != allUsers.size())
			{
				ss << "----------------\n";
			}
		}
		file << ss.str();

		// Close the file
		file.close();

		cout << "User Data has been written to the file.\n";
	}
	else {
		cerr << "Unable to open the file.\n";
	}

}
void fileManipulation::writeUserdata(string filename, unordered_map<string, User>allUsers)
{
	stringstream ss;
	string currentDir = "Data/Files/";
	filename = currentDir + filename;
	ofstream file(filename);
	if (file.is_open()) {
		ss << "int ID\n";
		ss << "string FullName\n";
		ss << "string Username\n";
		ss << "string Email\n";
		ss << "string Password\n";
		ss << "string Phone Number\n";
		ss << "int Rank\n";
		ss << "int Points\n";
		ss << "float Balance\n";
		ss << "----\n";
		for (auto& user : allUsers)
		{
			ss << user.second.GetId() << endl;
			ss << user.second.GetFullName() << endl;
			ss << user.second.GetUsername() << endl;
			ss << user.second.GetEmail() << endl;
			ss << user.second.GetPassword() << endl;
			ss << user.second.GetPhoneNumber() << endl;
			ss << user.second.GetPoints() << endl;
			ss << user.second.GetBalance() << endl;
			ss << user.second.getLastDatePlayedWheel() << endl;
			ss << user.second.getNextSpinDate() << endl;
			ss << "----\n";
		}
		file << ss.str();

		// Close the file
		file.close();

		cout << "User Data has been written to the file.\n";
	}
	else {
		cerr << "Unable to open the file.\n";
	}
}
void fileManipulation::writeSampleDataInFile(string filename) {
	stringstream ss;
	string currentDir = "Data/Files/";
	filename = currentDir + filename;
	ofstream file(filename);
	if (file.is_open()) {
		if (filename == currentDir + "teamsDataNew.txt") {
			ss << "Name of Team (Unique)\n";
			ss << "league\n";
			ss << "Points\n";
			ss << "Number of Wins\n";
			ss << "Number of Losses\n";
			ss << "Number of Draws\n";
			ss << "----\n";
		}
		else {
			ss << "Name of Team\n";
			ss << "--------\n";
			for (int i = 0; i < 2; i++) {
				ss << "Name (Unique)\n";
				ss << "Age\n";
				ss << "Position\n";
				ss << "Price in market\n";
				ss << "Rating\n";
				ss << "Total Goals\n";
				ss << "Total Assists\n";
				ss << "Total RedCards\n";
				ss << "Total YellowCards\n";
				ss << "Total Cleansheets\n";
				ss << "Total Points\n";
				if ((i + 1) < 2) {
					ss << "----\n";
				}
			}
		}
		file << ss.str();

		// Close the file
		file.close();

		cout << "Data has been written to the file.\n";
	}
	else {
		cerr << "Unable to open the file.\n";
	}
}
void fileManipulation::writeInfoInSpecificFile(string filename, map<string, Teams*>* teams) {
	//teamsDataNew.txt
	stringstream ss;
	string currentDir = "Data/Files/";
	filename = currentDir + filename;
	ofstream file(filename, ios::app);
	if (file.is_open()) {
		if (filename == currentDir + "teamsDataNew.txt") {
			for (auto it = teams->begin(); it != teams->end(); ++it) {
				ss << it->first << "\n";
				ss << it->second->getPoints() << "\n";
				ss << it->second->getwins() << "\n";
				ss << it->second->getlose() << "\n";
				ss << it->second->getdraw() << "\n";
				if (next(it) != teams->end()) {
					ss << "----\n";
				}
			}
			// Write the content string to the file


		}
		else {
			for (auto it = teams->begin(); it != teams->end(); ++it) {
				string teamName = it->first;
				ss << teamName << "\n";
				ss << "--------\n";
				unordered_map<string, Footballer>* footballersOfTeam = it->second->getFootballPlayer();
				for (auto inner_it = footballersOfTeam->begin(); inner_it != footballersOfTeam->end(); ++inner_it) {
					string playerName = inner_it->second.GetName();
					Footballer currentFootballer = inner_it->second;
					ss << playerName << "\n";
					ss << currentFootballer.GetAge() << "\n";
					ss << currentFootballer.GetPosition() << "\n";
					ss << currentFootballer.GetPrice() << "\n";
					ss << currentFootballer.GetRating() << "\n";
					ss << currentFootballer.GetTotalGoals() << "\n";
					ss << currentFootballer.GetTotalAssists() << "\n";
					ss << currentFootballer.GetTotalRedCard() << "\n";
					ss << currentFootballer.GetTotalYellowCard() << "\n";
					ss << currentFootballer.GetTotalCleansheets() << "\n";
					ss << currentFootballer.GetTotalpoints() << "\n";
					if (next(inner_it) != footballersOfTeam->end()) {
						ss << "----\n";
					}
				}
				if (next(it) != teams->end()) {
					ss << "----------------\n";
				}
			}
		}
		file << ss.str();

		// Close the file
		file.close();

		cout << "Data has been written to the file.\n";
	}
	else {
		cerr << "Unable to open the file.\n";
	}

}

//void fileManipulation::writeInfoInSpecificFile(string filename, map<string,Teams*>* team) {
//	string currentDir = "Data/Files/";
//	filename = currentDir + filename;
//
//	ofstream file(filename);
//	if (file.is_open()) {
//		stringstream ss;
//
//		ss << "Name of Team\n";
//		ss << "--------\n";
//		for (int i = 0; i < 2; i++) {
//			ss << "Name (Unique)\n";
//			ss << "Age\n";
//			ss << "Position\n";
//			ss << "Price in market\n";
//			ss << "Rating\n";
//			ss << "Total Goals\n";
//			ss << "Total Assists\n";
//			ss << "Total RedCards\n";
//			ss << "Total YellowCards\n";
//			ss << "Total Cleansheets\n";
//			ss << "Total Points\n";
//			if ((i + 1) < 2) {
//				ss << "----\n";
//			}
//		}
//		ss << "----------------\n";
//
//
//		for (auto it = footballersOfTeam->begin(); it != footballersOfTeam->end(); ++it) {
//			Footballer currentFootballer = it->second;
//			ss << currentFootballer.GetTeam() << "\n";
//			ss << "--------\n";
//			// Create an iterator for the inner unordered map
//			for (auto inner_it = footballersOfTeam->begin(); inner_it != footballersOfTeam->end(); ++inner_it) {
//				currentFootballer = inner_it->second;
//				ss << it->first << "\n";
//				ss << currentFootballer.GetAge() << "\n";
//				ss << currentFootballer.GetPosition() << "\n";
//				ss << currentFootballer.GetPrice() << "\n";
//				ss << currentFootballer.GetRating() << "\n";
//				ss << currentFootballer.GetTotalGoals() << "\n";
//				ss << currentFootballer.GetTotalAssists() << "\n";
//				ss << currentFootballer.GetTotalRedCard() << "\n";
//				ss << currentFootballer.GetTotalYellowCard() << "\n";
//				ss << currentFootballer.GetTotalCleansheets() << "\n";
//				ss << currentFootballer.GetTotalpoints() << "\n";
//				if (next(it) != footballersOfTeam->end()) {
//					ss << "----\n";
//				}
//			}
//			ss << "----------------\n";
//		}
//		// Write the content string to the file
//		file << ss.str();
//
//		// Close the file
//		file.close();
//
//		cout << "Data has been written to the file.\n";
//	}
//	else {
//		cerr << "Unable to open the file.\n";
//	}
//
//}

vector<TheLeague> fileManipulation::getLeagueData(map<string, Teams>& allTeams) {
	string filename = "leagueData.txt";
	string file_data = readFileData(filename);
	string regex = R"(\s*----\s*)";
	vector<string> parts = splitByRegex(file_data, regex);

	regex = R"(\n)";

	return parseLeagues(parts, regex, allTeams);
}

list<Game> fileManipulation::getGamesData(map<string, Teams>& teams) {
	string filename = "gameData.txt";
	string file_data = readFileData(filename);
	string regex = R"(\s*----\s*)";
	vector<string> parts = splitByRegex(file_data, regex);

	regex = R"(\n)";

	return parseGames(parts, regex, teams);
}

void fileManipulation::getTeamsData(map<string, unordered_map<string, Footballer>>& footballersOfTeam, map<string, Teams>& parsedTeams) {
	string filename = "teamsData.txt";
	string file_data = readFileData(filename);
	string regex = R"(\s*----\s*)";
	vector<string> parts = splitByRegex(file_data, regex);
	//cout << parts[0] << endl << parts[1] << endl;
	regex = R"(\n)";
	parseTeams(footballersOfTeam, parsedTeams, parts, regex);
}

map<string, unordered_map<string, Footballer>> fileManipulation::getFootballersOfTeamData() {
	string filename = "footballersOfTeam.txt";
	string file_data = readFileData(filename);
	string regex = R"(\s*----------------\s*)";
	vector<string> parts = splitByRegex(file_data, regex);
	map<string, unordered_map<string, Footballer>> parsedFootballersOfTeam;
	for (size_t i = 1; i < parts.size(); ++i) {
		regex = R"(\s*--------\s*)";
		vector<string> teamFootballersVector = splitByRegex(parts[i], regex);
		pair<string, string> teamFootballers = { teamFootballersVector[0], teamFootballersVector[1] };
		regex = R"(\s*----\s*)";
		parsedFootballersOfTeam.insert(
			parseFootballersOfTeam(teamFootballers, regex)
		);
	}
	return parsedFootballersOfTeam;
}

unordered_map<string, User> fileManipulation::getUsersData(map<int, pair<unordered_map<string, Footballer*>, unordered_map<string, Footballer*>>>& usersSquads) {
	string filename = "userData.txt";
	string file_data = readFileData(filename);
	string regex = R"(\s*----\s*)";
	vector<string> parts = splitByRegex(file_data, regex);

	regex = R"(\n)";

	return parseUsers(parts, regex, usersSquads);
}

//map<string, Teams> parseTeamsOfLeagues(map<string, Teams>& allTeams) {
//	for
//}

vector<TheLeague> fileManipulation::parseLeagues(vector<string> parts, string regex, map<string, Teams>& allTeams) {
	vector<TheLeague> parsedLeagues;

	for (size_t i = 1; i < parts.size(); ++i) {
		vector<string> leagueLines = splitByRegex(parts[i], regex);

		parsedLeagues.push_back(
			parseLeague(leagueLines, allTeams)
		);
	}

	return parsedLeagues;
}

list<Game> fileManipulation::parseGames(vector<string> parts, string regex, map<string, Teams>& allteams) {
	list<Game> parsedGames;

	for (size_t i = 1; i < parts.size(); ++i) {
		vector<string> gameLines = splitByRegex(parts[i], regex);

		parsedGames.push_back(
			parseGame(gameLines, allteams)
		);
	}

	return parsedGames;
}

void fileManipulation::parseTeams(map<string, unordered_map<string, Footballer>>& footballersOfTeam, map<string, Teams>& parsedTeams, vector<string> parts, string regex) {

	for (size_t i = 1; i < parts.size(); ++i) {
		vector<string> teamLines = splitByRegex(parts[i], regex);
		map<string, unordered_map<string, Footballer>>::iterator footballers = footballersOfTeam.find(teamLines[0]);
		unordered_map<string, Footballer>* footballersOfTeam = &footballers->second;

		Teams* team = parseTeam(teamLines, footballersOfTeam);
		parsedTeams.emplace(teamLines[0], *team);
	}
}

pair<string, unordered_map<string, Footballer>> fileManipulation::parseFootballersOfTeam(pair<string, string> teamFootballers, string regex) {
	vector<string> footballersOfTeam = splitByRegex(teamFootballers.second, regex);
	unordered_map<string, Footballer> parsedFootballersOfTeam;
	regex = R"(\n)";
	for (size_t i = 0; i < footballersOfTeam.size(); i++) {
		vector<string> footballerLines = splitByRegex(footballersOfTeam[i], regex);
		Footballer footballer = parseFootballer(footballerLines, teamFootballers.first);
		parsedFootballersOfTeam.insert(
			make_pair(footballer.GetName(), footballer)
		);
	}
	return make_pair(teamFootballers.first, parsedFootballersOfTeam);
}

pair<unordered_map<string, Footballer*>, unordered_map<string, Footballer*>> fileManipulation::parseUserSquads(vector<string> userIdMainSubSquads, string regex, map<string, unordered_map<string, Footballer>>& footballersOfTeam) {
	return make_pair(
		parseSquad(MAIN, userIdMainSubSquads, regex, footballersOfTeam),
		parseSquad(SUBSTITUTION, userIdMainSubSquads, regex, footballersOfTeam)
	);
}


unordered_map<string, User> fileManipulation::parseUsers(vector<string> parts, string regex, map<int, pair<unordered_map<string, Footballer*>, unordered_map<string, Footballer*>>>& usersSquads) {
	unordered_map<string, User> parsedUsers;

	for (size_t i = 1; i < parts.size(); ++i) {
		vector<string> userLines = splitByRegex(parts[i], regex);

		parsedUsers.insert(
			make_pair(userLines[2], parseUser(userLines, usersSquads))
		);
	}

	return parsedUsers;
}


TheLeague fileManipulation::parseLeague(vector<string> leagueLines, map<string, Teams>& allTeams) {
	string leagueName = leagueLines[0];
	map<string, Teams*>* teamsOfLeague = new map<string, Teams*>();

	for (size_t i = 1; i < leagueLines.size(); i++) {
		Teams* team = Teams::getTeamByName(allTeams, leagueLines[i]);

		teamsOfLeague->insert(
			make_pair(team->getName(), team)
		);
	}
	return TheLeague(leagueName, teamsOfLeague);
}
stack<HighlightsOfTheMatch> fileManipulation::analyzeTeamHighlights(string& homeTeamName, string& awayTeamName, int& gameID, map<string, Teams>& teams) {
	map<string, HighlightsOfTheMatch> highlights = getHighlights(gameID, teams, homeTeamName, awayTeamName);
	stack<HighlightsOfTheMatch> combinedHighlights;
	unordered_map<string, Footballer>* homeTeam = teams[homeTeamName].getFootballPlayer();
	unordered_map<string, Footballer>* awayTeam = teams[awayTeamName].getFootballPlayer();
	vector<pair<string, Footballer>> homeTeamFootballers(homeTeam->begin(), homeTeam->end());
	vector<pair<string, Footballer>> awayTeamFootballers(awayTeam->begin(), awayTeam->end());

	for (size_t i = 0; i < homeTeamFootballers.size(); i++) {
		string* homePlayerName = &homeTeam->at(homeTeamFootballers[i].first).GetAddressName();
		string* awayPlayerName = &awayTeam->at(awayTeamFootballers[i].first).GetAddressName();

		if (highlights.find(*homePlayerName) == highlights.end()) {
			// Player's highlight does not exist, create a new entry
			highlights[*homePlayerName] = HighlightsOfTheMatch(gameID, homePlayerName);
		}
		if (highlights.find(*awayPlayerName) == highlights.end()) {
			highlights[*awayPlayerName] = HighlightsOfTheMatch(gameID, awayPlayerName);
		}
	}
	//cout << "Address From Teams Data: " << &teams["Manchester City"].getFootballPlayer()->at("Walker").GetName() << endl;
	//cout << "Address From Highlights: " << highlights["Walker"].getName() << endl;
	//teams["Manchester City"].getFootballPlayer()->at("Walker").SetName("Moooo");
	// Convert highlights map to a stack
	for (auto it = highlights.rbegin(); it != highlights.rend(); ++it) {
		combinedHighlights.push(it->second);
	}
	return combinedHighlights;
}

Game fileManipulation::parseGame(vector<string> gameLines, map<string, Teams>& allteams) {
	int gameID = stoi(gameLines[0], nullptr);
	string homeTeamName = gameLines[1];
	string awayTeamName = gameLines[2];
	string winnerTeam = gameLines[3];
	string score = gameLines[4];
	string gameStatistics = parseGameStatistics(gameLines);
	string manOfTheMatch = gameLines[13];
	int round = stoi(gameLines[14], nullptr);
	stack<HighlightsOfTheMatch> combinedHighlights;

	combinedHighlights = analyzeTeamHighlights(homeTeamName, awayTeamName, gameID, allteams);

	return Game(gameID, Teams::getTeamByName(allteams, homeTeamName), Teams::getTeamByName(allteams, awayTeamName), winnerTeam, score, gameStatistics, combinedHighlights, manOfTheMatch, round);
}


Teams* fileManipulation::parseTeam(vector<string> teamLines, unordered_map<string, Footballer>* footballers) {
	string name = teamLines[0];
	int points = stoi(teamLines[2], nullptr);
	int wins = stoi(teamLines[3], nullptr);
	int losses = stoi(teamLines[4], nullptr);
	int draws = stoi(teamLines[5], nullptr);
	Teams* team = new Teams(name, points, wins, losses, draws, footballers);

	return team;
}

Footballer fileManipulation::parseFootballer(vector<string> footballerLines, string teamName) {
	string name = footballerLines[0];
	int age = stoi(footballerLines[1], nullptr);
	string position = footballerLines[2];
	float price = stof(footballerLines[3], nullptr);
	float rating = stof(footballerLines[4], nullptr);
	int totalGoals = stoi(footballerLines[5], nullptr);
	int totalAssists = stoi(footballerLines[6], nullptr);
	int totalRedCard = stoi(footballerLines[7], nullptr);
	int totalYellowCard = stoi(footballerLines[8], nullptr);
	int totalCleansheets = stoi(footballerLines[9], nullptr);
	int totalPoints = stoi(footballerLines[10], nullptr);

	return Footballer(
		name, age, teamName, position, price, rating,
		totalGoals, totalAssists, totalRedCard, totalYellowCard,
		totalCleansheets, totalPoints
	);

}

unordered_map<string, Footballer*> fileManipulation::getSquadUsingAllFootballers(vector<string>userTeamAndFootballerNames, map<string, unordered_map<string, Footballer>>& footballersOfTeam) {
	unordered_map<string, Footballer*> squad;

	for (size_t i = 1; i < userTeamAndFootballerNames.size(); i++) {
		unordered_map<string, Footballer>* allFootballersInTeam = &footballersOfTeam.at(userTeamAndFootballerNames[0]);
		Footballer* footballer = &allFootballersInTeam->at(userTeamAndFootballerNames[i]);

		squad.insert(
			make_pair(userTeamAndFootballerNames[i], footballer)
		);
	}
	return squad;
}

User fileManipulation::parseUser(vector<string> userLines, map<int, pair<unordered_map<string, Footballer*>, unordered_map<string, Footballer*>>>& usersSquads) {
	int userID = stoi(userLines[0], nullptr);
	string fullname = userLines[1];
	string username = userLines[2];
	string email = userLines[3];
	string password = userLines[4];
	string phoneNumber = userLines[5];
	int points = stoi(userLines[6], nullptr);
	float balance = stof(userLines[7], nullptr);
	unordered_map<string, Footballer*> mainSquad = {};
	unordered_map<string, Footballer*> substitutionSquad = {};
	time_t lastDatePlayedWheel = static_cast<time_t>(stoll(userLines[8]));
	time_t nextSpinDate = static_cast<time_t>(stoll(userLines[9]));

	try {
		mainSquad = usersSquads.at(userID).first;
	}
	catch (const exception&) {
		//cout << "User \"" << fullname << "\" has 0 Footballers in his main Squad." << endl;
	}

	try {
		substitutionSquad = usersSquads.at(userID).second;
	}
	catch (const exception&) {
		//cout << "User \"" << fullname << "\" has 0 Footballers in his substitution Squad." << endl;
	}

	return User(userID, fullname, username, email, password, phoneNumber, points, balance, mainSquad, substitutionSquad, lastDatePlayedWheel, nextSpinDate);
}
unordered_map<string, Footballer*> fileManipulation::parseSquad(Squad squadType, vector<string> userIdMainSubSquads, string regex, map<string, unordered_map<string, Footballer>>& footballersOfTeam) {
	vector<string> userTeamsAndFootballerNames;
	unordered_map<string, Footballer*> footballers;
	try {
		userTeamsAndFootballerNames = splitByRegex(userIdMainSubSquads[squadType], regex);
	}
	catch (const exception&) {
		//cout << "Found (0) Footballers in " << (userIdMainSubSquads.size() == 2 ? "SUBSTITUTION Squad" : "MAIN and SUBSTITUTION Squads") << " of User ID : (" << userIdMainSubSquads[0] << ")" << endl;
		return {};
	}

	regex = R"(\n)";

	for (const string& teamAndFootballerNamesString : userTeamsAndFootballerNames) {
		vector<string> userTeamAndFootballerNames = splitByRegex(teamAndFootballerNamesString, regex);
		unordered_map<string, Footballer*> subSquad = getSquadUsingAllFootballers(userTeamAndFootballerNames, footballersOfTeam);

		footballers.insert(
			make_move_iterator(subSquad.begin()),
			make_move_iterator(subSquad.end())
		);
	}

	return footballers;
}

string fileManipulation::parseGameStatistics(vector<string> gameLines) {
	string parsedStatistics;
	string statisticsNames[] = {
		"Shots on goal",
		"Shots",
		"Possession %",
		"Fouls",
		"Offsides",
		"Corner kicks",
		"Saves"
	};
	for (int i = 6; i < 13; i++) {
		parsedStatistics.append(statisticsNames[i - 6] + ": " + gameLines[i]);
		if (i != 12)
			parsedStatistics.append(", ");
	}
	return parsedStatistics;
}

map<string, HighlightsOfTheMatch> fileManipulation::parseHighlights(vector<string> highlights, int gameId, map<string, Teams>& teams, string regex, string& homeTeamName, string& awayTeamName) {
	map<string, HighlightsOfTheMatch> parsedHighlights;
	unordered_map<string, Footballer>* homefootballers = teams[homeTeamName].getFootballPlayer();
	unordered_map<string, Footballer>* awayfootballers = teams[awayTeamName].getFootballPlayer();
	regex = R"(\n)";

	for (size_t i = 0; i < highlights.size(); i++) {
		vector<string> highlightLines = splitByRegex(highlights[i], regex);
		string* footballerNamePtr = nullptr;

		for (auto& footballer_it : *homefootballers) {
			footballerNamePtr = &footballer_it.second.GetAddressName();
			if (*footballerNamePtr == highlightLines[0])
				break;
			footballerNamePtr = nullptr;
		}
		if (footballerNamePtr == nullptr) {
			for (auto& footballer_it : *awayfootballers) {
				footballerNamePtr = &footballer_it.second.GetAddressName();
				if (*footballerNamePtr == highlightLines[0])
					break;
				footballerNamePtr = nullptr;
			}
		}
		if (footballerNamePtr != nullptr)
			parsedHighlights.insert(
				make_pair(highlightLines[0], parseHighlight(highlightLines, gameId, footballerNamePtr))
			);
	}
	return parsedHighlights;
}

map<string, HighlightsOfTheMatch> fileManipulation::getHighlights(int gameID, map<string, Teams>& teams, string& homeTeamName, string& awayTeamName) {
	string filename = "HighlightsOfTheMatch.txt";
	string file_data = readFileData(filename);
	string regex = R"(\s*----------------\s*)";
	vector<string> parts = splitByRegex(file_data, regex);

	for (size_t i = 1; i < parts.size(); ++i) {
		regex = R"(\s*--------\s*)";
		vector<string> gameHighlights = splitByRegex(parts[i], regex);
		if (stoi(gameHighlights[0], nullptr) != gameID)
			continue;
		regex = R"(\s*----\s*)";
		vector<string> highlights;
		if (gameHighlights.size() > 1)
			highlights = splitByRegex(gameHighlights[1], regex);
		else
			return {};
		return parseHighlights(highlights, gameID, teams, regex, homeTeamName, awayTeamName);
	}
}

HighlightsOfTheMatch fileManipulation::parseHighlight(vector<string> highlightLines, int gameId, string* name) {
	string* footballerName = name;
	string contributes = highlightLines[1];
	string violation = highlightLines[2];

	return HighlightsOfTheMatch(gameId, name, contributes, violation);
}

map<int, pair<unordered_map<string, Footballer*>, unordered_map<string, Footballer*>>> fileManipulation::getUserSquadsData(map<string, unordered_map<string, Footballer>>& footballersOfTeam) {
	string filename = "userSquads.txt";
	string file_data = readFileData(filename);
	string regex = R"(\s*----------------\s*)";
	vector<string> parts = splitByRegex(file_data, regex);
	map<int, pair<unordered_map<string, Footballer*>, unordered_map<string, Footballer*>>> parsedUserSquads;

	for (size_t i = 1; i < parts.size(); ++i) {
		vector<string> userIdMainSubSquads;
		int userID;

		regex = R"(\s*--------\s*)";
		userIdMainSubSquads = splitByRegex(parts[i], regex);
		userID = stoi(userIdMainSubSquads[0], nullptr);
		regex = R"(\s*----\s*)";

		parsedUserSquads.insert(
			make_pair(userID, parseUserSquads(userIdMainSubSquads, regex, footballersOfTeam))
		);
	}
	return parsedUserSquads;
}
