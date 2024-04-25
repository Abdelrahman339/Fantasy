#include "HighlightsOfTheMatch.h"

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
