#include <iostream>
using namespace std;
#include "Game.h"
#include <stack>
#include "highlightsOfTheMatch.h"

Teams* Game::getAwayTeam() { return &awayTeam; }
Teams* Game::getHomeTeam() { return &homeTeam; }
string Game::getScore() { return score; }
string Game::getManOfTheMatch() { return manOfTheMatch; }
string Game::getStatistics() { return statistics; }
stack<HighlightsOfTheMatch>& Game::getHighlightsOfTheMatch() { return highlightsOfTheMatch; }
int Game::getRound() { return round; }

string Game::getwinningTeam()
{
	return winningTeam;
}

int Game::getGameId()
{
	return this->GameId;
}



// Setters
void Game::setAwayTeam(Teams team) { awayTeam = team; }
void Game::setHomeTeam(Teams team) { homeTeam = team; }
void Game::setScore(string newScore) { score = newScore; }
void Game::setManOfTheMatch(string newManOfTheMatch) { this->manOfTheMatch = newManOfTheMatch; }
void Game::setStatistics(string newStatistics) { statistics = newStatistics; }
void Game::setHighlightsOfTheMatch(HighlightsOfTheMatch newHighlights) { highlightsOfTheMatch.push(newHighlights); }
void Game::setRound(int newRound) { round = newRound; }

void Game::setGameId(int id)
{
	this->GameId = id;
}

