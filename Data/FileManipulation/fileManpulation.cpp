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
/*
 * 'parseGame' function should return all Games in the gameData.txt
 */
void parseGames(vector<string> parts, string regex) {
	for (size_t i = 1; i < parts.size(); i++) {
		// Line of Game Data
		vector<string> gameLines = splitByRegex(parts[i], regex);

		// ID Parse
		int gameID = stoi(gameLines[0], nullptr);
		cout << "Game ID: " << gameID << endl;
		// Home Team Parse 1
			
		// Away Team Parse 2
		
		// Winner Team Name 3
		cout << "Winner Team: " << gameLines[3] << endl;
		// Score 4
		cout << "Score: " << gameLines[4] << endl;
		// Statistics
		string gameStatistics = fileManipulation::parseGameStatistics(gameLines);
		cout << "Game Statistics: " << gameStatistics << endl;
		// Man Of The Match (Footballer Name) 13
		cout << "Man Of The Match: " << gameLines[13] << endl;
		// Game Due Date
		cout << "Date: " << gameLines[14] << endl << endl;
	}
}
void fileManipulation::getGamesData() {
	string filename = "gameData.txt";
	string file_data = readFileData(filename);
	string regex = R"(\s+----\s+)";

	vector<string> parts = splitByRegex(file_data, regex);
	//cout << parts[1] << endl;
	regex = R"(\n)";
	parseGames(parts, regex);

	//cout << "Game Statistics: " << gameStatistics << endl;




	//cout << "Split data:" << endl;
	//for (size_t i = 1; i < parts.size(); i++)
	//	cout << parts[i] << endl;
}

