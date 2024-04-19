#include "Game.h"





////////////////////////////////////////
// Setters//////////////////////////////
////////////////////////////////////////


void Game::setName(string name) {
    this->name = name;
}

void Game::setPosition(string position) {
    this->position = position;
}

void Game::setRating(float rating) {
    this->rating = rating;
}

void Game::setGoals(int goals) {
    this->goals = goals;
}

void Game::setAssists(int assists) {
    this->assists = assists;
}

void Game::setYellowCards(bool card) {
    this->yellowCards = card;
}

void Game::setRedCard(bool card) {
    this->redCard = card;
}

void Game::setCleanSheets(bool cleanSheet) {
    this->cleanSheets = cleanSheet;
}

void Game::setPrice(float price) {
    this->price = price;
}

void Game::setPoints(int points) {
    this->points = points;
}





/////////////////////////////////////////////////////
// Getters///////////////////////////////////////////
/////////////////////////////////////////////////////


string Game::getName() {
    return name;
}

string Game::getPosition() {
    return position;
}

float Game::getRating() {
    return rating;
}

int Game::getGoals() {
    return goals;
}

int Game::getAssists() {
    return assists;
}

bool Game::getYellowCards() {
    return yellowCards;
}

bool Game::getRedCard() {
    return redCard;
}

bool Game::getCleanSheets() {
    return cleanSheets;
}

float Game::getPrice() {
    return price;
}

int Game::getPoints() {
    return points;
}
