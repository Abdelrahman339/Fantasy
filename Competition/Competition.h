#include <iostream>
#include <queue>
#include <vector>
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




    void static UpdateFootballerPoints(queue<Game>& GameHighlights, list<Footballer>& players) ; // updating all the players in a game
    void static UpdateFootballerPrice(Footballer& player) ;//based on points for EVERY player (even if not in user's squad)
    bool static checkPosition(queue<Game>& GameHighlights,string footballerPosition) ;
    void static addPointsToMOTM(queue<Game>& GameHighlights) ; //Adds extra points to the man of the match
    char static priceCalculation(Footballer& player); //containing five tiers for changing the players price 
    
    void static updateUserPoints(queue<Game>& GameHighlights);

	void showAllGameHighlights();
    
};
