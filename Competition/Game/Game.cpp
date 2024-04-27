#include <iostream>
#include <sstream>
#include <iomanip>
#include <random>
#include "Game.h"
#include"Teams.h"
#include"Leagues.h"



using namespace std;


void Game:: displayBorder(int type) {

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

void Game:: displayTeamsAndScore(Game currentGame)
{
	string homeTeamName =   currentGame.getHomeTeam().getName();
	string awayTeamName=  currentGame.getAwayTeam().getName();
	
	cout << right << setw(20) <<"\u2022"<< homeTeamName << setw(20) << currentGame.getScore() << setw(25) <<"\u2022"<< awayTeamName << endl;

}

void Game:: displayPlayerHighlights(Game CurrentGame) {

	HighlightsOfTheMatch currentHighlight = CurrentGame.getHighlightsOfTheMatch().top();
	string playerName = CurrentGame.getHighlightsOfTheMatch().top().getName();
	string Contributes = CurrentGame.getHighlightsOfTheMatch().top().getContributions();
	string violation = CurrentGame.getHighlightsOfTheMatch().top().getViolation();

	size_t found_goals = Contributes.find("goals");
	random_device rd;
	mt19937 gen(rd()); // ----> engine used for generating random numbers

	int CurrentMin = 1;
	int max = 90;

	uniform_int_distribution<> dis;

	int goalsNumber = 0;
	if (found_goals != string::npos) {
		// Extracting the number of goals to be used in output
		goalsNumber = stoi(Contributes.substr(found_goals + 6));

		for (int i = 0; i < goalsNumber; i++) {

			dis = uniform_int_distribution<>(CurrentMin, max);
			int GoalMinute = dis(gen);
			cout << right << setw(45)<< playerName << " " << GoalMinute<< "'" << "\U000026BD" << endl;
			cout << "\n";
			CurrentMin = GoalMinute + 1;
			
		}

	}
	
	
	CurrentGame.getHighlightsOfTheMatch().pop();
	
}


void Game::displayGameOverview(queue <Game> currentGame) {

	Game game;

	
	system("cls");
	Game::displayBorder(1);
	cout <<left<<setw(50)<< game.getDate() <<right<<setw(33)<< "Full-time" << endl;
	cout << "\n";
	displayTeamsAndScore(game);
	Game::displayBorder(2);
	cout << right << setw(30) <<"\u2605"<< " Man of the Match : " << game.getManOfTheMatch() << endl;
	Game::displayBorder(2);
	cout << "\n\n";
	Game::displayPlayerHighlights(game);
	Game::displayBorder(3);
	

}

