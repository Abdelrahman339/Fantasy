#include <iostream>
#include "UserValidiation.h"
#include "User.h"
using namespace std;

void User::SetFullName(string fullName)
{
    this->fullName = fullName;
}

void User::SetUsername(string username)
{
    this->username = username;
}

void User::SetPassword(string password)
{
    this->password = password;
}

void User::SetPhoneNumber(string phoneNumber)
{
    this->phoneNumber = phoneNumber;
}

void User::SetEmail(string Email)
{
    this->Email = Email;
}

void User::SetId(int id)
{
    this->id = id;
}

void User::SetRank(int rank)
{
    this->rank = rank;
}

void User::SetPoints(int points)
{
    this->points = points;
}

void User::SetBalance(float balance)
{
    this->balance = balance;
}

void User::SetSquad(list<Footballer> squad)
{
    this->squad = squad;
}
string User::GetFullName()
{
    return fullName;
}

string User::GetUsername()
{
    return username;
}
string User::GetPassword()
{
    return password;
}

string User::GetPhoneNumber()
{
    return phoneNumber;
}

string User::GetEmail()
{
    return Email;
}

int User::GetId()
{
    return id;
}

int User::GetRank()
{
    return rank;
}

int User::GetPoints()
{
    return points;
}

float User::GetBalance()
{
    return balance;
}

list<Footballer> User::GetSquad()
{
    return squad;
}

queue<Game> User::GetUserGames()
{
    return userGames;
}