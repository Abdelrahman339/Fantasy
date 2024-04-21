#include <iostream>
#include <queue>
#include <vector>
#include<list>
#include "Game.h"
using namespace std;

class Competition {

protected:

    const static int numOfPlayers = 22;

    //Basic points 
    const static int goalPoints = 4;
    const static int assistPoints = 2;
    const static int cleanSheetPoints = 3;
    const static int redCardDeduction = 2;
    const static int yellowCardDeduction = 1;

    //Bonus points
    const static int MOTM_Bonus = 3;
    const static int WinBonus = 2;




    void static UpdateFootballerPoints(list<Game>currentGame) ; // updating all the players in a game
    void static UpdateFootballerPrice(Footballer& player) ;//based on points for EVERY player (even if not in user's squad)
    bool static checkPosition(string footballerPosition) ; // checks if the player is a goalkeeper or a defender
    bool static IsManOfTheMatch(string currentMOTM, string playerName) ; //checks if the player is the MOTM
    char static priceCalculation(Footballer& player); //containing five tiers for changing the players price 


    

    void static updateUserPoints(queue<Game>& GameHighlights);
	void showAllGameHighlights();
    
};
