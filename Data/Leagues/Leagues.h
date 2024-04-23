#include <iostream>
#include <unordered_map>
#include <string>
#include"Teams.h"
using namespace std;

class League {
private:
    unordered_map<string, Teams > teams;

public:
    League() {}


    void displayTeams();

    void updatePoints(string teamName, int points);

    void displayPointTable();

    ~League();
};