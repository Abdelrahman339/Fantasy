#include <iostream>
using namespace std;
#include "Game.h"
Teams Game::getAwayTeam() { return awayTeam; }
Teams Game::getHomeTeam() { return homeTeam; }
string Game::getScore() { return score; }
string Game::getManOfTheMatch() { return manOfTheMatch; }
string Game::getStatistics() { return statistics; }
string Game::getHighlightsOfTheMatch() { return highlightsOfTheMatch; }
string Game::getDate() { return date; }

// Setters
void Game::setAwayTeam(Teams team) { awayTeam = team; }
void Game::setHomeTeam(Teams team) { homeTeam = team; }
void Game::setScore(string newScore) { score = newScore; }
void Game::setManOfTheMatch(string newManOfTheMatch) { this->manOfTheMatch = newManOfTheMatch; }
void Game::setStatistics(string newStatistics) { statistics = newStatistics; }
void Game::setHighlightsOfTheMatch(string newHighlights) { highlightsOfTheMatch = newHighlights; }
void Game::setDate(string newDate) { date = newDate; }