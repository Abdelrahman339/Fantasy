#include "Game.h"
//#include "League.h"

void Game::displayBorder(int type) {

	if (type == 1) {
		cout << "~-~-~-~-~-~-~-~-~-~-~~-~-~-~-~-~-~-~-~-~-~~-~-~-~-~-~-~-~-~-~-~~-~-~-~-~-~-~-~-~-~-~\n"
			"------------------------------------------------------------------------------------\n"
			"~-~-~-~-~-~-~-~-~-~-~~-~-~-~-~-~-~-~-~-~-~~-~-~-~-~-~-~-~-~-~-~~-~-~-~-~-~-~-~-~-~-~\n"
			"\n";
	}
	else if (type == 2) {
		cout << string(86, '_') << endl;
	}
	else if (type == 2) {
		cout << string(86, '-') << endl;
	}
}

void Game::displayTeamsAndScore(Game currentGame)
{
	string homeTeamName = currentGame.getHomeTeam().getName();
	string awayTeamName = currentGame.getAwayTeam().getName();

	cout << right << setw(20) << "\u2022" << homeTeamName << setw(20) << currentGame.getScore() << setw(25) << "\u2022" << awayTeamName << endl;

}

void Game::displayStatisitcs(Game currentGame)
{
	string matchStats = currentGame.getStatistics();

	regex pattern("(\\w+) (\\d+-\\d+)");

	// Iterate over matches
	auto words_begin = sregex_iterator(matchStats.begin(), matchStats.end(), pattern);
	auto words_end = sregex_iterator();

	for (sregex_iterator i = words_begin; i != words_end; ++i) {
		smatch match = *i;
		string word = "~~" + match[1].str() + "~~"; //statistics names
		string score = match[2]; //statistics scores

		// Calculate the padding 
		int padding_name = (89 - word.length()) / 2;
		int padding_score = (89 - score.length()) / 2;


		cout << setw(padding_name + word.length()) << word << endl;
		cout << setw(padding_score + score.length()) << score << endl;

		cout << "\n";

	}
}

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

void Game::displayPlayerHighlights(Game game) {

	Game CurrentGame = game; // for poping the stack without changing the actual one
	stack<HighlightsOfTheMatch> currentHighlight = CurrentGame.getHighlightsOfTheMatch();
	vector<pair<int, string>> timeStamps; //----> to sort goalscorers timeStamps

	while (!currentHighlight.empty()) {

		string playerName = currentHighlight.top().getName();
		string Contributes = currentHighlight.top().getContributions();
		size_t found_goals = Contributes.find("goals");

		random_device rd;
		mt19937 gen(rd()); // ----> engine used for generating random numbers

	//range for the number generator
		int CurrentMin = 1;
		int max = 90;

		uniform_int_distribution<> dis;

		int goalsNumber = 0;
		if (found_goals != string::npos) {
			// Extracting the number of goals to be used in output
			goalsNumber = stoi(Contributes.substr(found_goals+6 ));

			for (int i = 0; i < goalsNumber; i++) {

				dis = uniform_int_distribution<>(CurrentMin, max);
				int GoalMinute = dis(gen);

				timeStamps.push_back(make_pair(GoalMinute, playerName));
				
			}

		}


		CurrentGame.getHighlightsOfTheMatch().pop();
	}

	sort(timeStamps.begin(), timeStamps.end()); //sorting by goal minutes

	for (const auto& timeStamp : timeStamps) {
		cout << right << setw(45) << timeStamp.second << " " << timeStamp.first << "'" << endl;
		cout << "\n";
	}





}


void Game::displayGameOverview(queue <Game> currentGame) {

	Game game = currentGame.front();


	system("cls");
	Game::displayBorder(1);
	cout << left << setw(50) << game.getRound() << right << setw(33) << "Full-time" << endl;
	cout << "\n";
	displayTeamsAndScore(game);
	Game::displayBorder(2);
	cout << right << setw(30) << " Man of the Match : " << game.getManOfTheMatch() << endl;
	Game::displayBorder(2);
	cout << "\n\n";
	Game::displayPlayerHighlights(game);
	Game::displayBorder(3);
	displayStatisitcs(game);
	Game::displayBorder(1);

	currentGame.pop();
}

