#include <iostream>
#include <sstream>
#include <iomanip>
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
}

void Game:: displayTeamsAndScore(Game currentGame)
{
	string homeTeamName =   currentGame.getHomeTeam().getName();
	string awayTeamName=  currentGame.getAwayTeam().getName();
	
	cout << right << setw(20) <<"\u2022"<< homeTeamName << setw(20) << currentGame.getScore() << setw(25) <<"\u2022"<< awayTeamName << endl;

}

void Game:: displayHighlights(Game CurrentGame) {
	string playerName = CurrentGame.getHighlightsOfTheMatch().top().getName();
	string Contributes = CurrentGame.getHighlightsOfTheMatch().top().getContributions();
	
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

	Game::displayBorder(1);

}

