#pragma once
#include <iostream>
#include <vector>
#include "list"
#include <deque>
#include <stack>
#include "unordered_map"
#include "Teams.h"
#include "Game.h"
#include "Leagues.h"

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

	User();
	//unordered_map<string, Footballer> mainSquad, unordered_map<string, Footballer> substitutionSquad
	User(int id, string fullName, string username, string Email, string password,
		string phoneNumber, int rank, int points, float balance, unordered_map<string, Footballer> mainSquad, unordered_map<string, Footballer> substitutionSquad);

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
	unordered_map<string, Footballer>& GetMainSquad();
	unordered_map<string, Footballer>& GetSubstitutionSquad();

	///////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////

	// user functions
	///////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////
	string static spacing(int spaces, char character);

	string static avoidTypos(string& footballerName, User& currentUser, string status, vector <League> allLeagues, Teams& PlayerTeam);
	string static CheckingPlayer(string status, Teams team, User currenUser, string inputName);

	pair<string, Teams> static getTeam(vector <League> allLeagues, User currentUser, string FootballerName);

	vector<string> static ToVector(unordered_map<string, Footballer> UserSquad);

	void static fromSubtoMain(unordered_map<string, Footballer>& mainSquad, unordered_map<string, Footballer>& SubSquad);

	///////////////////////////////////////////////////////////////////////////////////
	//User credentials
	///////////////////////////////////////////////////////////////////////////////////
	void static homePage(unordered_map<string, User>& Users,vector <League> leagues);

	void static toLogin(unordered_map<string, User>& Users,vector <League> leagues);
	User static login(unordered_map<string, User>& users, string username, string password);
	void static signup(unordered_map<string, User>& Users);
	string static hidePassword(string username);
	void static userMenu(User& currentUser, unordered_map<string, User>& Users, vector <League> leagues);

	///////////////////////////////////////////////////////////////////////////////////
	//User Squad and Format
	///////////////////////////////////////////////////////////////////////////////////

	void static squadFormat(int choice, unordered_map<string, Footballer>  squad);
	void static Format433(unordered_map<string, Footballer> squad);
	void static Format343(unordered_map<string, Footballer> squad);
	void static Format442(unordered_map<string, Footballer> squad);
	void static showSubstitutions(unordered_map<string, Footballer> squad);
	int  static Formatdistance(string name, int space, bool remaining, string prev);
	void static ShowSquad(User& currentUser, unordered_map<string, User>& Users);
	void static showPlayerInfo(Footballer footballer);
	void static Substitution(User& currentUser, unordered_map<string, User>& Users);
	void static SubstituteFunction(User& currentUser, string subFootballer, Footballer mainFootballer);
	///////////////////////////////////////////////////////////////////////////////////
	//User Information
	///////////////////////////////////////////////////////////////////////////////////
	void static profile(User& currentUser, unordered_map<string, User>& Users);
	void static editInfo(User& currentUser, unordered_map<string, User>& Users);
	///////////////////////////////////////////////////////////////////////////////////
	//Market functions
	///////////////////////////////////////////////////////////////////////////////////
	void static Market(User& currentUser, unordered_map<string, Footballer> TopPlayer, unordered_map<string, User>& Users, vector<League>leageus);
	void static showtopPlayer(unordered_map<string, Footballer> TopPlayer, User& currentUser, unordered_map<string, User>& Users, Teams& team);

	bool static sell(User& currentUser, unordered_map<string, Footballer> TopPlayer, unordered_map<string, User>& Users, string footballerName);
	void static sellFunction(User& currentUser, string footballerName, string stauts);
	void static buy(User& currentUser, Teams& team, unordered_map<string, Footballer> TopPlayer, unordered_map<string, User>& Users, vector<League> leagues);
	void static buyFunction(User& currentUser, Footballer footballer);

	bool static checkBalance(float& currentUserBalance, float& footballerPrice);
	void static replace(User& currentUser, Teams& team, unordered_map<string, Footballer> TopPlayer, unordered_map<string, User>& Users);

	void static search(User& currentUser, vector<League> leagues);
	Footballer static returnPlayer(string footballerName, User currentUser, string status, vector<League>  leagues, Teams& footballerTeam);
	Teams static  findTeam(vector<League> league, string TeamName);
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
