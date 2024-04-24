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

