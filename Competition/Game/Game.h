#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Game
    
{
    string score;
    string manOfTheMatch;
    string statistics;
    string highlightsOfTheMatch; //goals , assists , cards , etc...

    void displayCurrentGame(queue<Game>& Gamehighlights);
};
class FootballerInTheMatch //the team that will play the match (11 footballer from the same team)
{

    string name;
    string position;
    float rating;
    float price;
    int goals;
    int points; // footballer points should be intialized as 1 as he starts in the starting eleven
    int assists;
    bool redCards;
    bool yellowCards;
    bool cleanSheets; // For updating goalKeepers and defenders points



 ////////////////////////////////////////////////////////////////////////
 /////////////////// setters and getters ////////////////////////////////
 ////////////////////////////////////////////////////////////////////////

public:

    void setName(string name);
    void setPosition(string position);
    void setRating(float rating);
    void setGoals(int goals);
    void setAssists(int assists);
    void setYellowCards(bool card);
    void setRedCard(bool card);
    void setCleanSheets(bool cleanSheet);
    void setPrice(float price);
    void setPoints(int points);
   
    string getName();
    string getPosition();
    float getRating();
    int getGoals();
    int getAssists();
    bool getYellowCards();
    bool getRedCard();
    bool getCleanSheets();
    float getPrice();
    int getPoints();


    



};
