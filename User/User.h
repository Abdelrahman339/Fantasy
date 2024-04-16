#pragma once
#include <iostream>
#include <vector>
#include "list"
#include "queue"
#include "unordered_map"
#include "Teams.h"
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

public:
    vector <Footballer >ThemainSquad;
    vector <Footballer >SubstitutionSquad;
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
    void homePage(unordered_map<string, User>& Users);
    User login(unordered_map<string, User>& users, string username, string password);
    void signup(unordered_map<string, User>& Users);
    string hidePassword(string username);
    void userMenu(User& currentUser, unordered_map<string, User>& Users);
    void squadFormat(int choice, vector <Footballer> squad);
    void Format433(vector <Footballer> squad);
    void Format343(vector <Footballer> squad);
    void Format442(vector <Footballer> squad);
    void Squad(vector <Footballer> squad, vector <Footballer> SubstitutionSquad);
    void showPlayerInfo(vector <Footballer> squad, vector <Footballer> SubstitutionSquad);
    void Substitution(vector <Footballer> mainSquad, vector <Footballer> SubstitutionSquad);
    void profile(User currentUser, unordered_map<string, User>& Users);
    void editInfo(User currentUser, unordered_map<string, User>& Users);
    ///////////////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////////////
};
