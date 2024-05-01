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


vector<League> fileManipulation::getLeagueData(map<string, Teams> allTeams) {
	string filename = "leagueData.txt";
	string file_data = readFileData(filename);
	string regex = R"(\s*----\s*)";
	vector<string> parts = splitByRegex(file_data, regex);

	regex = R"(\n)";

	return parseLeagues(parts, regex, allTeams);
}

list<Game> fileManipulation::getGamesData() {
	string filename = "gameData.txt";
	string file_data = readFileData(filename);
	string regex = R"(\s*----\s*)";
	vector<string> parts = splitByRegex(file_data, regex);

	regex = R"(\n)";

	return parseGames(parts, regex);
}

map<string, Teams> fileManipulation::getTeamsData(map<string, unordered_map<string, Footballer>> footballersOfTeam) {
	string filename = "teamsData.txt";
	string file_data = readFileData(filename);
	string regex = R"(\s*----\s*)";
	vector<string> parts = splitByRegex(file_data, regex);
	//cout << parts[0] << endl << parts[1] << endl;
	regex = R"(\n)";
	return parseTeams(footballersOfTeam, parts, regex);
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

unordered_map<string, User> fileManipulation::getUsersData() {
	string filename = "userData.txt";
	string file_data = readFileData(filename);
	string regex = R"(\s*----\s*)";
	vector<string> parts = splitByRegex(file_data, regex);

	regex = R"(\n)";

	return parseUsers(parts, regex);
}


vector<League> fileManipulation::parseLeagues(vector<string> parts, string regex, map<string, Teams> allTeams) {
	vector<League> parsedLeagues;

	for (size_t i = 1; i < parts.size(); ++i) {
		vector<string> leagueLines = splitByRegex(parts[i], regex);

		parsedLeagues.push_back(
			parseLeague(leagueLines, allTeams)
		);
	}

	return parsedLeagues;
}

list<Game> fileManipulation::parseGames(vector<string> parts, string regex) {
	list<Game> parsedGames;

	for (size_t i = 1; i < parts.size(); ++i) {
		vector<string> gameLines = splitByRegex(parts[i], regex);

		parsedGames.push_back(
			parseGame(gameLines)
		);
	}

	return parsedGames;
}

map<string, Teams> fileManipulation::parseTeams(map<string, unordered_map<string, Footballer>> footballersOfTeam, vector<string> parts, string regex) {
	map<string, Teams> parsedTeams;

	for (size_t i = 1; i < parts.size(); ++i) {
		vector<string> teamLines = splitByRegex(parts[i], regex);

		parsedTeams.insert(
			make_pair(teamLines[0], parseTeam(teamLines, footballersOfTeam.at(teamLines[0])))
		);
	}

	return parsedTeams;
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

pair<unordered_map<string, Footballer>, unordered_map<string, Footballer>> fileManipulation::parseUserSquads(vector<string> userIdMainSubSquads, string regex, map<string, unordered_map<string, Footballer>> footballersOfTeam) {
	return make_pair(
		parseSquad(MAIN, userIdMainSubSquads, regex, footballersOfTeam), 
		parseSquad(SUBSTITUTION, userIdMainSubSquads, regex, footballersOfTeam)
	);
}


unordered_map<string, User> fileManipulation::parseUsers(vector<string> parts, string regex) {
	unordered_map<string, User> parsedUsers;

	for (size_t i = 1; i < parts.size(); ++i) {
		vector<string> userLines = splitByRegex(parts[i], regex);

		parsedUsers.insert(
			make_pair(userLines[2], parseUser(userLines))
		);
	}

	return parsedUsers;
}


League fileManipulation::parseLeague(vector<string> leagueLines, map<string, Teams> allTeams) {
	string leagueName = leagueLines[0];
	map<string, Teams> leagueTeams;

	for (size_t i = 1; i < leagueLines.size(); i++) {
		Teams team = Teams::getTeamByName(allTeams, leagueLines[i]);

		leagueTeams.insert(
			make_pair(team.getName(), team)
		);
	}
	return League(leagueName, leagueTeams);
}

Game fileManipulation::parseGame(vector<string> gameLines) {
	int gameID = stoi(gameLines[0], nullptr);
	string winnerTeam = gameLines[3];
	string score = gameLines[4];
	string gameStatistics = parseGameStatistics(gameLines);
	string manOfTheMatch = gameLines[13];
	string gameDate = gameLines[14];
	stack<HighlightsOfTheMatch> highlights = getHighlights(gameID);

	return Game(gameID, winnerTeam, score, gameStatistics, highlights, manOfTheMatch, gameDate);
}


Teams fileManipulation::parseTeam(vector<string> teamLines, unordered_map<string, Footballer> footballers) {
	string name = teamLines[0];
	int points = stoi(teamLines[2], nullptr);
	int wins = stoi(teamLines[3], nullptr);
	int losses = stoi(teamLines[4], nullptr);
	int draws = stoi(teamLines[5], nullptr);

	return Teams(name, points, wins, losses, draws, footballers);
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

unordered_map<string, Footballer> fileManipulation::getSquadUsingAllFootballers(vector<string>userTeamAndFootballerNames, map<string, unordered_map<string, Footballer>> footballersOfTeam) {
	unordered_map<string, Footballer> squad;
	for (size_t i = 1; i < userTeamAndFootballerNames.size(); i++) {
		unordered_map<string, Footballer> allFootballersInTeam = footballersOfTeam.at(userTeamAndFootballerNames[0]);
		squad.insert(
			make_pair(userTeamAndFootballerNames[i], allFootballersInTeam.at(userTeamAndFootballerNames[i])
			)
		);
	}
	return squad;
}

User fileManipulation::parseUser(vector<string> userLines) {
	int userID = stoi(userLines[0], nullptr);
	string fullname = userLines[1];
	string username = userLines[2];
	string email = userLines[3];
	string password = userLines[4];
	string phoneNumber = userLines[5];
	int rank = stoi(userLines[6], nullptr);
	int points = stoi(userLines[7], nullptr);
	float balance = stof(userLines[8], nullptr);

	return User(userID, fullname, username, email, password, phoneNumber, rank, points, balance);
}

unordered_map<string, Footballer> fileManipulation::parseSquad(Squad squadType, vector<string> userIdMainSubSquads, string regex, map<string, unordered_map<string, Footballer>> footballersOfTeam) {
	vector<string> userTeamsAndFootballerNames = splitByRegex(userIdMainSubSquads[squadType], regex);
	unordered_map<string, Footballer> footballers;

	regex = R"(\n)";

	for (const string& teamAndFootballerNamesString : userTeamsAndFootballerNames) {
		vector<string> userTeamAndFootballerNames = splitByRegex(teamAndFootballerNamesString, regex);
		unordered_map<string, Footballer> subSquad = getSquadUsingAllFootballers(userTeamAndFootballerNames, footballersOfTeam);

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

stack<HighlightsOfTheMatch> fileManipulation::parseHighlights(vector<string> highlights, int gameId, string regex) {
	stack<HighlightsOfTheMatch> parsedHighlights;
	for (size_t i = 0; i < highlights.size(); i++) {
		vector<string> highlightLines = splitByRegex(highlights[i], regex);

		parsedHighlights.push(
			parseHighlight(highlightLines, gameId)
		);
	}
	return parsedHighlights;
}

stack<HighlightsOfTheMatch> fileManipulation::getHighlights(int gameID) {
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
		vector<string> highlights = splitByRegex(gameHighlights[1], regex);
		regex = R"(\n)";
		return parseHighlights(highlights, gameID, regex);
	}
	// No Highlights found for this game.
	return {};
}

HighlightsOfTheMatch fileManipulation::parseHighlight(vector<string> highlightLines, int gameId) {
	string name = highlightLines[0];
	string contributes = highlightLines[1];
	string violation = highlightLines[2];

	return HighlightsOfTheMatch(gameId, name, contributes, violation);
}

map<int, pair<unordered_map<string, Footballer>, unordered_map<string, Footballer>>> fileManipulation::getUserSquadsData(map<string, unordered_map<string, Footballer>> footballersOfTeam) {
	string filename = "userSquads.txt";
	string file_data = readFileData(filename);
	string regex = R"(\s*----------------\s*)";
	vector<string> parts = splitByRegex(file_data, regex);
	map<int, pair<unordered_map<string, Footballer>, unordered_map<string, Footballer>>> parsedUserSquads;
	for (size_t i = 1; i < parts.size(); ++i) {
		regex = R"(\s*--------\s*)";
		vector<string> userIdMainSubSquads = splitByRegex(parts[i], regex);
		int userID = stoi(userIdMainSubSquads[0], nullptr);
		regex = R"(\s*----\s*)";

		parsedUserSquads.insert(
			make_pair(userID, parseUserSquads(userIdMainSubSquads, regex, footballersOfTeam))
		);
	}
	return parsedUserSquads;
}
