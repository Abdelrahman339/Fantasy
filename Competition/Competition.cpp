#include <iostream>
#include <queue>
#include<list>
#include "Game.h"
#include "Competition.h"

using namespace std;


	



bool Competition::checkPosition( queue<Game>& GameHighlights, list<FootballerInTheMatch>& player) {

	if ((player->cleanSheets) && player->position == "defender" || player->position == "goalkeeper") {
		return true;
	}

	else
		 return false;

}

void Competition::UpdateFootballerPoints(queue<Game>& GameHighlights,list<FootballerInTheMatch>&players ) //for both squads of the match
{
	
		
			queue <Game> currentGame = GameHighlights;
			int numPlayersCalculated=0;
			auto next = players.begin();

			while (numPlayersCalculated < competition->numOfPlayers) {
				FootballerInTheMatch& player = *next;

				player->points += (competition->goalPoints * player->goals);
				player->points += (competition->assistPoints * player->assist);

				if (player->yellowCards) {
					player->points -= competition->yellowCardDeduction;
				}

				if (player->redCards) {
					player->points -= redCardDeduction;
				}

				//check if the player is a defender or a goalkeeper to add cleansheet bonus
				if (checkPosition(currentGame, player)) {
					player->points += competition->cleanSheetPoints;
				}

				auto tmp = next;
				next++;
				players.erase(tmp);


			}
		



		
	

}

void Competition::UpdateFootballerPrice(list<FootballerInTheMatch>& player) // for all the players
{
	
}
