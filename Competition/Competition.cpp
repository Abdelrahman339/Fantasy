#include <iostream>
#include <queue>
#include<list>
#include "Game.h"
#include "Competition.h"

using namespace std;


	



bool Competition::checkPosition(queue<Game>& GameHighlights, string& footballerPosition) {
	string& currentPosition = footballerPosition;
	
	if (currentPosition == "defender" || currentPosition == "goalkeeper") {
		return true;
	}

	else
		 return false;

}



void Competition::UpdateFootballerPoints(queue<Game>& GameHighlights, list<FootballerInTheMatch>& players) //for both squads of the match
{
	
		
			queue <Game> currentGame = GameHighlights;
			GameHighlights.pop();

			int numPlayersCalculated=0;
			auto next = players.begin();

			while (numPlayersCalculated < competition->numOfPlayers) {
				FootballerInTheMatch& player = *next;

				int GoalPoints = ((competition->goalPoints) * player.getGoals()) + player.getPoints();
				int AssistPoints= ((competition->assistPoints) * player.getAssists() + player.getPoints();
				int yellowCardPenalty = 0;
				int redCardPenalty = 0;
				int cleanSheetPoints = 0;
				

				if (player.getYellowCards()) {
					yellowCardPenalty= player.getPoints()-(competition->yellowCardDeduction) ;
				}

				if (player.getRedCard()) {
					redCardPenalty = player.getPoints() - (competition->redCardDeduction);
				}

				//check if the player is a defender or a goalkeeper to add cleansheet bonus
				if(player.getCleanSheets()==true){
				if ( checkPosition(currentGame, player.getPosition() ) ) {
					cleanSheetPoints=player.getPoints()+(competition->cleanSheetPoints);
				}
				}

				int totalPoints = GoalPoints + AssistPoints + yellowCardPenalty + redCardPenalty + cleanSheetPoints;
				player.setPoints(totalPoints);


				









				auto tmp = next;
				next++;
				players.erase(tmp);


			}
		



		
	

}








void Competition::UpdateFootballerPrice(list<FootballerInTheMatch>& player) // for all the players
{
	FootballerInTheMatch& currentFootballer = player;
	string tier = priceCalculation(currentFootballer);
	float priceChange;

	switch (tier) {

	case "tier1":
		priceChange = currentFootballer.getPrice() + 0.5;
		break;

	case "tier2":
		priceChange = currentFootballer.getPrice() + 1;
		break;

	case "tier3":
		priceChange = currentFootballer.getPrice() + 1.5;
		break;

	case "tier4":
		priceChange = currentFootballer.getPrice() + 2;
		break;

	case "tier5":
		priceChange = currentFootballer.getPrice() + 3;
		break;

	default:
		//if the player doesn't perfom with any of the tiers
		priceChange = currentFootballer.getPrice() - 0.2;
	}

	currentFootballer.setPrice(priceChange);


	}






	
}
