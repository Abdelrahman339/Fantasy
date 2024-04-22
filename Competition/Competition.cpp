#include <iostream>
#include <queue>
#include<list>
#include "Competition.h"
#include "Teams.h"
#include"Game/Game.h"

using namespace std;




bool Competition::IsManOfTheMatch(string currentMOTM,string playerName)
{
	return (currentMOTM == playerName);
}


bool Competition::checkPosition(string footballerPosition) {

	if (footballerPosition == "defender" || footballerPosition == "goalkeeper") {
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
	float currentPlayerPrice = player.GetPrice();
	float priceChange;

	switch (tier) {

	case '1':
		priceChange = currentPlayerPrice + 0.5f;
		break;		
					
	case '2':		
		priceChange = currentPlayerPrice + 1.0f;
		break;		
					
	case '3':		
		priceChange = currentPlayerPrice + 1.5f;
		break;		
					
	case '4':		
		priceChange = currentPlayerPrice + 2.0f;
		break;		
					
	case '5':		
		priceChange = currentPlayerPrice + 2.5f;
		break;				 

	default:
		//if the player doesn't perfom with any of the tiers
		priceChange = currentPlayerPrice - 0.2f;
	}

	player.SetPrice(priceChange);


}

void Competition::UpdateFootballerPoints(list<Game> CurrentGame) //for both squads of the match
{
	Game game;
	Footballer CurrentPlayer;
	int numPlayersCalculated = 0;
	int index = 0;
	string currentMOTM = game.getManOfTheMatch();
	//int homeTeamScore = game.getHomeTeam().getScore();
	//int awayTeamScore = game.getAwayTeam().getScore();


	

	

	while (numPlayersCalculated < Competition::numOfPlayers) {

		bool isMatchWinner=false; //for adding match winning bonus

		///////////////////////////////////////////
		//getting players from home and away teams/
		///////////////////////////////////////////

		//Home team first then the away team

		//if (numPlayersCalculated < 11) 
		//{
		//	CurrentPlayer = game.getHomeTeam().getFootballPlayer(index).at(index);
		//	if (homeTeamScore > awayTeamScore) {
		//		isMatchWinner = true;
		//	}
		//}
		//else {
		//	CurrentPlayer = game.getAwayTeam().getFootballPlayer(index).at(index);
		//	if (homeTeamScore < awayTeamScore) {
		//		isMatchWinner = true;
		//	}
		//}

		///////////////////////////////////////////////////////////////////////


		int GoalPoints = ((Competition::goalPoints)*CurrentPlayer.GetGoals()) + CurrentPlayer.GetPoints();
		int AssistPoints = ((Competition::assistPoints)*CurrentPlayer.GetAssists() + CurrentPlayer.GetPoints());
		int yellowCardPenalty = 0;
		int redCardPenalty = 0;
		int cleanSheetPoints = 0;
		int ManOfTheMatchPoints = 0;
		int MatchWinningBonus = 0;
		


		if (CurrentPlayer.GetYellowCards()) {
			yellowCardPenalty = CurrentPlayer.GetPoints() - (Competition::yellowCardDeduction);
		}

		if (CurrentPlayer.GetRedCard()) {
			redCardPenalty = CurrentPlayer.GetPoints() - (Competition::redCardDeduction);
		}

		//check if the player is a defender or a goalkeeper to add cleansheet bonus

		if (CurrentPlayer.GetCleanSheets() == true) {
			if (Competition::checkPosition(CurrentPlayer.GetPosition())) {
				cleanSheetPoints = CurrentPlayer.GetPoints() + (Competition::cleanSheetPoints);
			}
		}

		if (Competition::IsManOfTheMatch(currentMOTM, CurrentPlayer.GetName()) == true) {
			ManOfTheMatchPoints = Competition::MOTM_Bonus;
		}

		//if (isMatchWinner) {
		//	MatchWinningBonus = Competition::WinBonus;
		//}


		int totalPoints = GoalPoints + AssistPoints + yellowCardPenalty + redCardPenalty + cleanSheetPoints +ManOfTheMatchPoints + MatchWinningBonus;
		CurrentPlayer.setPoints(totalPoints);



		
		Competition::UpdateFootballerPrice(CurrentPlayer);

		
		
		numPlayersCalculated++;
		index++;


	}


}

