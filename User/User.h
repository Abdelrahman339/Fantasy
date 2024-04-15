#pragma once
#include <iostream>
#include "list"
#include "queue"
#include "unordered_map"
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
    void userMenu(User& currentUser);
    void squatForamt(int choice);
    ///////////////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////////////
};
