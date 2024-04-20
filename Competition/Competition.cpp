#include <iostream>
#include <queue>
#include<list>
#include "Competition.h"
#include "Teams.h"

using namespace std;






bool Competition::checkPosition(queue<Game>& GameHighlights, string footballerPosition) {
	string currentPosition = footballerPosition;

	if (currentPosition == "defender" || currentPosition == "goalkeeper") {
		return true;
	}

	else
		return false;

}

char Competition::priceCalculation(Footballer& player) {

	int currentPoints = player.GetPoints();

	if (currentPoints < 3) {
		return '0';
	}
	else if (currentPoints < 6) {
		return '1';
	}
	else if (currentPoints < 9) {
		return '2';
	}
	else if (currentPoints < 12) {
		return '3';
	}
	else if (currentPoints < 15) {
		return '4';
	}
	else {
		return '5';
	}

}

void Competition::UpdateFootballerPrice(Footballer& player) // for all the players
{
	char tier = Competition::priceCalculation(player);
	float priceChange;

	switch (tier) {

	case '1':
		priceChange = player.GetPrice() + 0.5;
		break;

	case '2':
		priceChange = player.GetPrice() + 1;
		break;

	case '3':
		priceChange = player.GetPrice() + 1.5;
		break;

	case '4':
		priceChange = player.GetPrice() + 2;
		break;

	case '5':
		priceChange = player.GetPrice() + 3;
		break;

	default:
		//if the player doesn't perfom with any of the tiers
		priceChange = player.GetPrice() - 0.2;
	}

	player.SetPrice(priceChange);


}

void Competition::UpdateFootballerPoints(queue<Game>& GameHighlights, list<Footballer>& players) //for both squads of the match
{


	queue <Game> currentGame = GameHighlights;


	int numPlayersCalculated = 0;
	auto next = players.begin();

	while (numPlayersCalculated < Competition::numOfPlayers) {
		Footballer& player = *next;

		int GoalPoints = ((Competition::goalPoints)*player.GetGoals()) + player.GetPoints();
		int AssistPoints = ((Competition::assistPoints)*player.GetAssists() + player.GetPoints());
		int yellowCardPenalty = 0;
		int redCardPenalty = 0;
		int cleanSheetPoints = 0;


		if (player.GetYellowCards()) {
			yellowCardPenalty = player.GetPoints() - (Competition::yellowCardDeduction);
		}

		if (player.GetRedCard()) {
			redCardPenalty = player.GetPoints() - (Competition::redCardDeduction);
		}

		//check if the player is a defender or a goalkeeper to add cleansheet bonus
		//if (player.getCleanSheets() == true) {
		//	if (Competition::checkPosition(currentGame, player.getPosition())) {
		//		cleanSheetPoints = player.getPoints() + (Competition::cleanSheetPoints);
		//	}
		//}

		int totalPoints = GoalPoints + AssistPoints + yellowCardPenalty + redCardPenalty + cleanSheetPoints;
		player.setPoints(totalPoints);

		Competition::UpdateFootballerPrice(player);


		auto tmp = next;
		next++;
		players.erase(tmp);
		numPlayersCalculated++;


	}


}

