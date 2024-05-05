#include "HighlightsOfTheMatch.h"

HighlightsOfTheMatch::HighlightsOfTheMatch(int GameId, string name) {
	this->GameId = GameId;
	this->name = name;
	this->contributes = "None";
	this->violation = "None";
}

HighlightsOfTheMatch::HighlightsOfTheMatch(int GameId, string name, string contributes, string violation) {
	this->GameId = GameId;
	this->name = name;
	this->contributes = contributes;
	this->violation = violation;
}

void HighlightsOfTheMatch::setName(string name)
{
	this->name = name;
}

void HighlightsOfTheMatch::setContributions(string contributors)
{
	this->contributes = contributors;
}

void HighlightsOfTheMatch::setViolation(string violation)
{
	this->violation = violation;
}

string HighlightsOfTheMatch::getName()
{
	return name;
}

string HighlightsOfTheMatch::getContributions()
{
	return contributes;
}

string HighlightsOfTheMatch::getViolation()
{
	return violation;
}

int HighlightsOfTheMatch::GetGameId()
{
	return this->GameId;
}
