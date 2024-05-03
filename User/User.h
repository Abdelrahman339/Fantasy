#pragma once
#include <iostream>
#include <vector>
#include "list"
#include <deque>
#include <stack>
#include "unordered_map"
#include <algorithm>
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
	queue<Game> UserGames; // queue of the user games that he will play in the round.
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

	queue<Game>& GetUserGames();
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
	void static homePage(unordered_map<string, User>& Users, vector <League> leagues);

	void static toLogin(unordered_map<string, User>& Users, vector <League> leagues);
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
	void static ShowSquad(User& currentUser);
	void static showPlayerInfo(Footballer footballer);

	void static showPlayerInfolayout();
	void static Substitution(User& currentUser);
	void static SubstituteFunction(User& currentUser, string subFootballer, Footballer mainFootballer);
	///////////////////////////////////////////////////////////////////////////////////
	//User Information
	///////////////////////////////////////////////////////////////////////////////////
	void static profile(User& currentUser, unordered_map<string, User>& Users);
	void static editInfo(User& currentUser, unordered_map<string, User>& Users);
	///////////////////////////////////////////////////////////////////////////////////
	//Market functions
	///////////////////////////////////////////////////////////////////////////////////
	void static Market(User& currentUser, vector<League>leageus);

	bool static sell(User& currentUser, unordered_map<string, Footballer> TopPlayer, string footballerName);
	void static sellFunction(User& currentUser, string footballerName, string stauts);
	void static buy(User& currentUser, vector<League> leagues);
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

	///////////////////////////////////////////////////////////////////////////////////
	//Top Footballers functions
	///////////////////////////////////////////////////////////////////////////////////

	vector<Footballer> static GetAllFootballers(League league);// this function used to stor all the players in the league in a single vector 

	vector <Footballer> static TopFootballersinLeague(vector <Footballer> Footballers); // this function takes a vector of all players in the league and return just the top 5 players .

	void static toUnordredMap(unordered_map<string, Footballer>& topPlayers, vector<Footballer> top5players); // store the 3 vectors of top 5 players in each leageu into one single unordred map 

	unordered_map <string, Footballer> static TopFootballers(vector <League> leageus);// this function used to return unordered map of top players in leageus (5 players per league).

	void static showtopFootballers(unordered_map<string, Footballer> TopPlayer, User& currentUser, vector<League> Leageus);

	bool static comparePlayersByPoints(Footballer& player1, Footballer& player2);

	/////////////////////////////////////////////////////////////////////////////////////
	//Top Users functions
	////////////////////////////////////////////////////////////////////////////////////

	vector <User> moveTovector(unordered_map<string, User> Users);
	void sortingUsers(vector<User> users);

};



//b3d kol action fi fucntion el market el queue bta3et el user mafroud yt3mlha update w save fel file bta3 el user 3lshan fi function el play bta3et el rounds mafroud y lef 3la kol el uesr w y get el user games w y3ml udpate ll points 3la 7sb el games.