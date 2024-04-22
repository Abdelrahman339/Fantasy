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
    vector <Footballer >TheMainSquad;
    vector <Footballer >SubstitutionSquad;
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
    void SetBalance(float balance);
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

    ///////////////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////////////

    // user functions
    ///////////////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////////////
    string static spacing(int spaces,char character);
    void static homePage(unordered_map<string, User>& Users);

    void static toLogin(unordered_map<string, User> &Users);
    User static login(unordered_map<string, User>& users, string username, string password);
    void static signup(unordered_map<string, User>& Users);
    string static hidePassword(string username);
    void static userMenu(User& currentUser, unordered_map<string, User>& Users);
    void squadFormat(int choice, vector <Footballer> squad);
    void Format433(vector <string> squad);
    void Format343(vector <string> MainSquad);
    void Format442(vector <string> squad);
	void showSubstitutions(vector <string> substitutionList);
    int Formatdistance(string name, int space, bool remaining,string prev);
    void Squad(vector <Footballer> squad, vector <Footballer> SubstitutionSquad);
    void showPlayerInfo(vector <Footballer> squad, vector <Footballer> SubstitutionSquad);
    void Substitution(vector <Footballer> mainSquad, vector <Footballer> SubstitutionSquad);
    void static profile(User &currentUser, unordered_map<string, User>& Users);
    void static editInfo(User &currentUser, unordered_map<string, User>& Users);
    void Market();
    deque<Game>FilteringTeams(list<Game> allGames,User currentUser);

    deque<Game> insertToDeque(deque<Game> UserGames,list<Game> allGames,stack<string>userTeams);
    void findDuplicates(stack<string>& userTeams);
    ///////////////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////////////
};
