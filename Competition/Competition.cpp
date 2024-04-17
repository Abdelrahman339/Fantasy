#include <iostream>
#include <queue>
#include<vector>
#include "Game.h"
#include "Competition.h"

using namespace std;


	



bool Competition::checkPosition( queue<Game>& GameHighlights, vector<FootballerInTheMatch>& player) {

	if ((player.cleanSheets) && player.position == "defender" || player.position == "goalkeeper") {
		return true;
	}

	else
		false;

}

void Competition::UpdateFootballerPoints(queue<Game>& GameHighlights,vector<FootballerInTheMatch>&players ) //for both squads of the match
{
	Game currentGame = GameHighlights.front();
	GameHighlights.pop();

	while (!GameHighlights.empty()) {

		

		for (FootballerInTheMatch& player : players) {
			player.points += ( competition.goalPoints * player.goals);
			player.points += (competition.assistPoints * player.assist);

			if (player.yellowCards) {
				player.points -= competition.yellowCardDeduction;
			}

			if (player.redCards) {
				player.points -= redCardDeduction;
			}

			//check if the player is a defender or a goalkeeper to add cleansheet bonus
			if (checkPosition(currentGame, player)) {
				player.points += competition.cleanSheetPoints;
			}

		}


	}

}

void Competition::UpdateFootballerPrice()
{
	//the code
}
