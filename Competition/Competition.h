#include <iostream>
#include <queue>
#include <vector>
#include<list>
#include "Game.h"
using namespace std;

class Competition {

protected:


    const static int goalPoints = 4;
    const static int assistPoints = 2;
    const static int cleanSheetPoints = 3;
    const static int redCardDeduction = 2;
    const static int yellowCardDeduction = 1;
    const static int numOfPlayers = 22;
    const static int MOTM_Bonus = 3;




    void static UpdateFootballerPoints(list<Game>currentGame) ; // updating all the players in a game
    void static UpdateFootballerPrice(Footballer& player) ;//based on points for EVERY player (even if not in user's squad)
    bool static checkPosition(string footballerPosition) ;
    bool static IsManOfTheMatch(Game& currentGame, Footballer& player) ; //checks if the player is the MOTM
    char static priceCalculation(Footballer& player); //containing five tiers for changing the players price 
    

    void static updateUserPoints(queue<Game>& GameHighlights);
	void showAllGameHighlights();
    
};
