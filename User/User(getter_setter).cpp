#include <iostream>
#include "UserValidiation.h"
#include "User.h"
#include "Teams.h"
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

string User::GetFullName()
{
    return fullName;
}


bool User::SetFootballer(Footballer footballer)
{
    if (ThemainSquad.size()<11)
    {

    ThemainSquad.push_back(footballer);
    }
    else if(ThemainSquad.size() == 11&& SubstitutionSquad.size()< 4){
        SubstitutionSquad.push_back(footballer);
    }
    else if (ThemainSquad.size() == 11&& SubstitutionSquad.size()==4)
    {
        cout << "Your team is full!" << endl;
        cout << "Buy or replace players to add new players" << endl;
        return false;
    }
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
