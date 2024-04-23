#include <iostream>
#include <unordered_map>
#include <string>
#include"Teams.h"
#include <vector>
using namespace std;

class League {
private:
	string name;
	vector <Teams> teams;

public:
    League() {}


    void displayTeams();

    void updatePoints();

    void displayPointTable(vector <Teams> teamlist);

    ~League();
};