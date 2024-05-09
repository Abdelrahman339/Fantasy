#include "Game.h"
#include<set>
//#include "League.h"

//void Game::displayBorder(int type) {
//
//	if (type == 1) {
//		cout << "~-~-~-~-~-~-~-~-~-~-~~-~-~-~-~-~-~-~-~-~-~~-~-~-~-~-~-~-~-~-~-~~-~-~-~-~-~-~-~-~-~-~\n"
//			"------------------------------------------------------------------------------------\n"
//			"~-~-~-~-~-~-~-~-~-~-~~-~-~-~-~-~-~-~-~-~-~~-~-~-~-~-~-~-~-~-~-~~-~-~-~-~-~-~-~-~-~-~\n"
//			"\n";
//	}
//	else if (type == 2) {
//		cout << string(86, '_') << endl;
//	}
//	else if (type == 3) {
//		cout << string(86, '-') << endl;
//	}
//}
//
//void Game::displayTeamsAndScore(Game currentGame)
//{
//	string homeTeamName = currentGame.getHomeTeam().getName();
//	string awayTeamName = currentGame.getAwayTeam().getName();
//
//	int totalWidth = 86;
//
//	// Calculate padding for home team and away team
//	int paddingHome =( (totalWidth - 5) - homeTeamName.length() - awayTeamName.length()) / 2;
//	int paddingAway = totalWidth - 5 - homeTeamName.length() - awayTeamName.length() - paddingHome;
//
//
//	cout << right << setw(paddingHome) <<"# " << homeTeamName << "  " << currentGame.getScore() << " " <<" # " << awayTeamName << endl;
//
//}
//
//void Game::displayStatisitcs(Game currentGame)
//{
//	string matchStats = currentGame.getStatistics();
//
//	regex pattern(R"([\w\s]+: (\d+ - \d+,))");
//
//	regex pattern2(R"(: \d+ - \d+,)");
//
//	regex pattern3(R"(,)");
//	// Iterate over matches
//	auto words_begin = sregex_iterator(matchStats.begin(), matchStats.end(), pattern);
//	auto words_end = sregex_iterator();
//
//	for (sregex_iterator i = words_begin; i != words_end; ++i) {
//		smatch match = *i;
//		string matchStat = match.str();
//		matchStat = regex_replace(matchStat, pattern2, " ");
//		string word = "~~ " + matchStat + "~~"; //statistics names
//		string score;//statistics scores
//		score = regex_replace(match[1].str(), pattern3, " ");
//
//		// Calculate the padding 
//		int padding_name = (89 - word.length()) / 2;
//		int padding_score = (89 - score.length()) / 2;
//
//
//		cout << setw(padding_name + word.length()) << word << endl;
//		cout << setw(padding_score + score.length()) << score << endl;
//
//		cout << "\n";
//
//	}
//}

Game::Game() {
	this->awayTeam = Teams();
	this->homeTeam = Teams();
	this->winningTeam = "";
	this->score = "";
	this->manOfTheMatch = "";
	this->statistics = "";
	this->round = -1;
	this->GameId = 0;
}


Game::Game(int id, Teams home, Teams away, string winTeam, string score,
	string stats, stack<HighlightsOfTheMatch> highlights, string motm, int round) {
	this->GameId = id;
	this->awayTeam = away;
	this->homeTeam = home;
	this->winningTeam = winTeam;
	this->score = score;
	this->manOfTheMatch = motm;
	this->statistics = stats;
	this->highlightsOfTheMatch = highlights;
	this->round = round;
}

//void Game::displayPlayerHighlights(Game game) {
//
//	Game CurrentGame = game; // for poping the stack without changing the actual one
//	stack<HighlightsOfTheMatch> currentHighlight = CurrentGame.getHighlightsOfTheMatch();
//	vector<pair<int, string>> timeStamps; //----> to sort goalscorers timeStamps
//
//	while (!currentHighlight.empty()) {
//
//		string playerName = currentHighlight.top().getName();
//		string Contributes = currentHighlight.top().getContributions();
//		size_t found_goals = Contributes.find("Goals:");
//		set<int> generatedMinutes; //----------->keeping track of GoalMinutes to avoid repitiion and keep it unique
//
//		random_device rd;
//		mt19937 gen(rd()); // ----> engine used for generating random numbers
//
//		//range for the number generator
//		int CurrentMin = 1;
//		int max = 90;
//
//		uniform_int_distribution<> dis;
//
//		int goalsNumber = 0;
//		if (found_goals != string::npos) {
//			// Extracting the number of goals to be used in output
//			goalsNumber = stoi(Contributes.substr(7, 8));
//
//			for (int i = 0; i < goalsNumber; i++) {
//
//				dis = uniform_int_distribution<>(CurrentMin, max);
//				int GoalMinute = dis(gen);
//
//				// Check if the generated minute is already in the set if it is then it will generate a new minute
//				while (generatedMinutes.find(GoalMinute) != generatedMinutes.end()) {
//					GoalMinute = dis(gen); 
//				}
//				generatedMinutes.insert(GoalMinute);
//
//				timeStamps.push_back(make_pair(GoalMinute, playerName));
//
//			}
//
//		}
//
//
//		currentHighlight.pop();
//	}
//
//	sort(timeStamps.begin(), timeStamps.end()); //sorting by goal minutes
//
//	for (const auto& timeStamp : timeStamps) {
//		cout << right << setw(48) << timeStamp.second << " " << timeStamp.first << "'" << endl;
//		cout << "\n";
//	}
//
//
//
//
//
//}
//
//
//void Game::displayGameOverview(queue <Game> currentGame) {
//
//	Game game = currentGame.front();
//
//
//	system("cls");
//	Game::displayBorder(1);
//	cout <<"Game-week : " << game.getRound() << right << setw(35) << "Full-time" << endl;
//	cout << "\n";
//	displayTeamsAndScore(game);
//	Game::displayBorder(2);
//	cout << "\n";
//	cout << right << setw(45) << " Man of the Match : " << game.getManOfTheMatch() << endl;
//	Game::displayBorder(2);
//	cout << "\n\n";
//	Game::displayPlayerHighlights(game);
//	Game::displayBorder(3);
//	displayStatisitcs(game);
//	Game::displayBorder(1);
//
//	currentGame.pop();
//}

