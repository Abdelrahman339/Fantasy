#pragma once
#include <iostream>
#include <string>
#include <vector>


using namespace std;
class Footballer //the squad that the user own's
{
protected:
	//static datatypes --> constant per season
	string name;
	int age;
	string team;
	string position;

	//dynamic datatypes --> changes throughout the season
	float price;
	float rating;
	bool captain;
	bool matchWinner;


	/////////////////////////////////////////////
	//per season ////////////////////////////////
	/////////////////////////////////////////////

	int totalGoals;
	int totalAssists;
	int totalRedCard;
	int totalYellowCard;
	int totalCleansheets;
	int totalPoints;

	/////////////////////////////////////////////
	//per match//////////////////////////////////
	/////////////////////////////////////////////

	int goals;
	int points; // footballer points should be intialized as 1 as he starts in the starting eleven
	int assists;
	bool redCards;
	bool yellowCards;
	bool cleanSheets; // For updating goalKeepers and defenders points





public:


	////////////////////////////////////////////////////////////////////////
	/////////////////// setters ////////////////////////////////////////////
	////////////////////////////////////////////////////////////////////////



	void SetName(string name);
	void SetAge(int age);

	void SetTeam(string team);
	void SetPosition(string position);
	void SetPrice(float price);
	void SetCaptain(bool Captain);

	void SetRating(float rating);

	////////////////////////////////
	/////per season/////////////////
	////////////////////////////////

	void SetTotalGoals(int goals);
	void SetTotalAssists(int assists);

	void SetTotalYellowcard(int yellowCard);
	void SetTotalRedCard(int redCard);
	void SetTotalCleansheets(int yellowCard);

	void SetTotalpoints(int points);

	////////////////////////////////
	///////////per match////////////
	////////////////////////////////

	void setGoals(int goals);
	void setAssists(int assists);
	void setYellowCards(bool card);
	void setRedCard(bool card);

	void setCleanSheets(bool cleanSheet);
	void setPoints(int points);



	//---------------------------------------------------------------------------------------------------------------------



	/////////////////////////////////////////////////
	/////////////////Getter//////////////////////////
	/////////////////////////////////////////////////

	string GetName();
	int GetAge();
	string GetPosition();
	string GetTeam();
	float GetPrice();
	bool GetCaptain();

	////////////////////////////////
	/////per season/////////////////
	////////////////////////////////

	int GetTotalGoals();
	int GetTotalAssists();
	int GetTotalRedCard();
	int GetTotalYellowCard();
	int GetTotalCleansheets();
	int GetTotalpoints();

	////////////////////////////////
	///////////per match////////////
	////////////////////////////////

	int GetGoals();
	int GetAssists();
	bool GetYellowCards();
	bool GetRedCard();
	bool  GetCleanSheets();
	int GetPoints();

};

class Teams
{
protected:
	string name;
	int points;
	int wins;
	int lose;
	int draw;

	vector<Footballer> footballPlayers[11];

public:
	vector<Footballer> getFootballPlayer(int index);
	string getName();
	int getwins();
	int getlose();
	int getdraw();
	int getPoints();
	void SetPoints(int num);
	void addPoints(int num);
};

