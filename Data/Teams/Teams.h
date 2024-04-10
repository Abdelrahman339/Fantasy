#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Teams
{
};

class Footballer
{
    string name;
    int age;
    string position;
    float price;
    vector <int> goals; // per season
    vector<int> assists; // per season
    vector<int> redCard; // per season
    vector<int> yellowCard; // per season
};