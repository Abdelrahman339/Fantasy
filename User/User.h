#ifndef USER_H
#define USER_H

#pragma once
#include <iostream>
#include <vector>
#include "list"
#include <deque>
#include <stack>
#include "unordered_map"
#include <algorithm>

#include "Footballer.h"
#include "TheLeague.h"
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
	int points;
	float balance;
	unordered_map <string, Footballer*>TheMainSquad;
	unordered_map <string, Footballer*>SubstitutionSquad;
	queue<Game> UserGames; // queue of the user games that he will play in the round.
	time_t lastDatePlayedWheel; // Store the last date the wheel was played by this user.
	time_t nextSpinDate; // Store the next time the user will play the wheel.

public:

	User();
	//unordered_map<string, Footballer*> mainSquad, unordered_map<string, Footballer*> substitutionSquad
	User(int id, string fullName, string username, string Email, string password,
		string phoneNumber, int points, float balance,
		unordered_map<string, Footballer*> mainSquad, unordered_map<string, Footballer*> substitutionSquad,
		time_t lastDatePlayedWheel, time_t nextSpinDate);

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
	bool playWheel();
	int remainingMinutesUntilNextSpin() const;
	void scheduleNextSpin();

	bool SetFootballer(Footballer* footbaler);
	bool canPlayNextSpin() const;
	string GetFullName();
	string GetUsername();
	string GetPassword();
	string GetPhoneNumber();
	string GetEmail();
	int GetId();
	int GetRank();
	int GetPoints();
	float GetBalance();
	unordered_map<string, Footballer*>& GetMainSquad();
	unordered_map<string, Footballer*>& GetSubstitutionSquad();

	queue<Game>& GetUserGames();

	time_t getLastDatePlayedWheel() const;

	time_t getNextSpinDate() const;

	string formatDate(time_t date) const;

	bool hasFootballer(string& footballerName);

	// Method to handle playing the lucky wheel and handling the discounted footballer
	void handleLuckyWheelResult(pair<string, pair<float, Footballer*>>* result, User& user);


	///////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////

	// user functions
	///////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////
	string static spacing(int spaces, char character);

	string static avoidTypos(string& SearchName, User& currentUser, string status, vector <TheLeague> allLeagues, Teams& PlayerTeam);
	string static ReturnRightName(string status, Teams team, User currenUser, string SearchName, TheLeague Leageu);

	template <typename T>
	string static typosChecking(string SearchName, T currentsquad);

	pair<string, Teams> static GetPlayerName_Team(vector <TheLeague> allLeagues, User currentUser, string FootballerName);

	vector<string> static ToVector(unordered_map<string, Footballer>*& UserSquad);
	vector<string> static ToVector(unordered_map<string, Footballer*>& UserSquad);

	void static fromSubtoMain(unordered_map<string, Footballer*>* mainSquad, unordered_map<string, Footballer*>* SubSquad);

	///////////////////////////////////////////////////////////////////////////////////
	//User credentials
	///////////////////////////////////////////////////////////////////////////////////
	void static homePage(unordered_map<string, User>* Users, vector <TheLeague>& leagues, list<Game>* allGames);

	void static toLogin(unordered_map<string, User>* Users, vector <TheLeague>& leagues, list<Game>* allGames);
	static User* login(unordered_map<string, User>* users, string username, string password);
	void static signup(unordered_map<string, User>* Users);
	string static hidePassword(string username);
	void static userMenu(User* currentUser, unordered_map<string, User>* Users, vector <TheLeague>& leagues, list<Game>* allGames);

	///////////////////////////////////////////////////////////////////////////////////
	//User Squad and Format
	///////////////////////////////////////////////////////////////////////////////////

	void static squadFormat(int choice, unordered_map<string, Footballer*>& squad);
	void static Format433(unordered_map<string, Footballer*>& squad, string squadName);

	void static Format343(unordered_map<string, Footballer>* squad, string squadName);
	void static Format343(unordered_map<string, Footballer*>& squad, string squadName);
	void static Format442(unordered_map<string, Footballer*>& squad, string squadName);
	void static showSubstitutions(unordered_map<string, Footballer*>& squad);
	int  static Formatdistance(string name, int space, bool remaining, string prev);
	void static ShowSquad(User* currentUser);

	void static showPlayerInfo(Footballer footballer);
	void static Substitution(User* currentUser);
	void static SubstituteFunction(User* currentUser, string subFootballer, Footballer* mainFootballer);
	///////////////////////////////////////////////////////////////////////////////////
	//User Information
	///////////////////////////////////////////////////////////////////////////////////
	void static profile(User* currentUser, unordered_map<string, User>* Users);
	void static editInfo(User* currentUser, unordered_map<string, User>* Users);
	///////////////////////////////////////////////////////////////////////////////////
	//Market functions
	///////////////////////////////////////////////////////////////////////////////////
	void static Market(User* currentUser, vector<TheLeague>& leageus);

	bool static sell(User* currentUser, string footballerName);
	void static sellFunction(User* currentUser, string footballerName, string stauts);
	void static buy(User* currentUser, vector<TheLeague> leagues);
	void static buyFunction(User* currentUser, Footballer* footballer);

	bool static checkBalance(float& currentUserBalance, float& footballerPrice);
	void static replace(User* currentUser, Footballer* WantedFootballer);

	void static replaceFunction(User* currentUser, string UserFootballerName, Footballer* TeamFootballer, string status);
	void static search(User* currentUser, vector<TheLeague> leagues);
	static Footballer* returnPlayer(string footballerName, User currentUser, string status, vector<TheLeague>  leagues, Teams& footballerTeam);
	static Teams* findTeam(vector<TheLeague> TheLeague, string TeamName);

	void static PlayerFunction(Footballer* targetFootballer, User* currentUser);
	///////////////////////////////////////////////////////////////////////////////////
	//Play game functions
	///////////////////////////////////////////////////////////////////////////////////
	void static play(list<Game>* allGames, User* currentUser, unordered_map<string, User>* Users);

	bool static showCurrentMatch(queue<Game>& UserGames, list<Game>* allgames);

	void static FilteringTeams(list<Game> allGames, User* currentUser, stack<string> oldUserTeams, string status);

	void static insertToQueue(list<Game> allGames, stack<string>userTeams, queue<Game>& UserGames);

	void static sortingQueue(queue<Game>& UserGames);

	bool static compareGamesByRound(Game& Game1, Game& Game2);

	stack<string> static GetUserTeams(User* currentUser);

	void static findDuplicates(stack<string>& userTeams);
	void static RemoveDublicates(queue<Game>& UserGames);

	bool static areStacksEqual(stack<string>stack1, stack<string> stack2);
	///////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////

	/////////////////////////////////////////////////////////////////////////////////////
	//Top Users functions
	////////////////////////////////////////////////////////////////////////////////////

	vector <User> static moveTovector(unordered_map<string, User> Users);

	vector<User> static  sortingUsers(vector<User> TopUsers);


	bool static compareUsersByPoints(User& User1, User& User2);

	void static showTopUsers(unordered_map<string, User> Users);

	void static endOfSeasonScreen(list<Game>* allGames, unordered_map<string, User>Users);
};



//b3d kol action fi fucntion el market el queue bta3et el user mafroud yt3mlha update w save fel file bta3 el user 3lshan fi function el play bta3et el rounds mafroud y lef 3la kol el uesr w y get el user games w y3ml udpate ll points 3la 7sb el games.
#endif // GAME_H
