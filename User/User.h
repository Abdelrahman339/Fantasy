#pragma once
#include <iostream>
#include <vector>
#include "list"
#include <deque>
#include <stack>
#include "unordered_map"
#include "Teams.h"
#include "Game.h"

using namespace std;

class User
{
protected:
	string fullName;
	string username;
	string password;
	string phoneNumber;
	string Email;
	int id;
	int rank;
	int points;
	float balance;
	unordered_map <string, Footballer >TheMainSquad;
	unordered_map <string, Footballer >SubstitutionSquad;
public:
	// getter and setter and constructor
	///////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////
	void SetFullName(string fullName);
	void SetUsername(string username);
	void SetPassword(string password);
	void SetPhoneNumber(string phoneNumber);
	void SetEmail(string Email);
	void SetId(int id);
	void SetRank(int rank);

	void SetPoints(int points);
	void AddPoints(int points);
	void SetBalance(float balance);
	void addBalance(float balance);
	bool SetFootballer(Footballer footbaler);
	string GetFullName();
	string GetUsername();
	string GetPassword();
	string GetPhoneNumber();
	string GetEmail();
	int GetId();
	int GetRank();
	int GetPoints();
	float GetBalance();
	unordered_map<string, Footballer> GetMainSquad();

	///////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////

	// user functions
	///////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////
	string static spacing(int spaces, char character);

	///////////////////////////////////////////////////////////////////////////////////
	//User credentials
	///////////////////////////////////////////////////////////////////////////////////
	void static homePage(unordered_map<string, User>& Users);

	void static toLogin(unordered_map<string, User>& Users);
	User static login(unordered_map<string, User>& users, string username, string password);
	void static signup(unordered_map<string, User>& Users);
	string static hidePassword(string username);
	void static userMenu(User& currentUser, unordered_map<string, User>& Users);

	///////////////////////////////////////////////////////////////////////////////////
	//User Squad and Format
	///////////////////////////////////////////////////////////////////////////////////

	void squadFormat(int choice, vector <Footballer> squad);
	void Format433(vector <Footballer> squad);
	void Format343(vector <Footballer> MainSquad);
	void Format442(vector <Footballer> squad);
	void showSubstitutions(vector <Footballer> substitutionList);
	int Formatdistance(string name, int space, bool remaining, string prev);
	void Squad(vector <Footballer> squad, vector <Footballer> SubstitutionSquad);
	void showPlayerInfo(unordered_map<string, Footballer> players, string name);
	void Substitution(vector <Footballer> mainSquad, vector <Footballer> SubstitutionSquad);
	///////////////////////////////////////////////////////////////////////////////////
	//User Information
	///////////////////////////////////////////////////////////////////////////////////
	void static profile(User& currentUser, unordered_map<string, User>& Users);
	void static editInfo(User& currentUser, unordered_map<string, User>& Users);
	///////////////////////////////////////////////////////////////////////////////////
	//Market functions
	///////////////////////////////////////////////////////////////////////////////////
	void Market(User& currentUser, Teams& team, unordered_map<string, Footballer> TopPlayer, unordered_map<string, User>& Users);
	void showtopPlayer(unordered_map<string, Footballer> TopPlayer, User& currentUser, unordered_map<string, User>& Users, Teams& team);

	void sell(User& currentUser, Teams& team);
	void buy(User& currentUser, Teams& team);
	void replace(User& currentUser, Teams& team);

	void search();
	///////////////////////////////////////////////////////////////////////////////////
	//Play game functions
	///////////////////////////////////////////////////////////////////////////////////
	void static play(list<Game> allGames, User currentUser);
	void static showCurrentMatch(queue<Game>& UserGames);
	queue<Game>static FilteringTeams(list<Game> allGames, User currentUser);

	void static insertToQueue(list<Game> allGames, stack<string>userTeams, queue<Game>& UserGames);
	void static findDuplicates(stack<string>& userTeams);
	///////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////
};
