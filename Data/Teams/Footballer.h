#ifndef FOOTBALLER_H
#define FOOTBALLER_H
#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>

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
	~Footballer();
	Footballer();
	Footballer(string name, int age, string team, string position, float price, float rating,
		int totalGoals, int totalAssists, int totalRedCard, int totalYellowCard,
		int totalCleansheets, int totalPoints);


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

	float calculateDiscountedPrice(float discount);

	void SetTotalpoints(int points);
	void AddTotalpoints(int points);


	//---------------------------------------------------------------------------------------------------------------------



	/////////////////////////////////////////////////
	/////////////////Getter//////////////////////////
	/////////////////////////////////////////////////

	string GetName();
	string& GetAddressName();
	int GetAge();
	string GetPosition();
	string GetTeam();
	float GetRating();
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
#endif