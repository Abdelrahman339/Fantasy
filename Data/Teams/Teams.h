#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Teams
{
    int points;
};

class Footballer //the squad that the user own's
{
    string name;
    int age;
    string position;
    float price;
    bool captain;
    int goals;      // per season
    int assists;    // per season
    int redCard;    // per season
    int yellowCard; // per season
};
