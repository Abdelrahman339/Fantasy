#include <iostream>
#include <unordered_map>
#include <string>
#include "Leagues.h"
#include <algorithm>
#include"Teams.h"
using namespace std;

void League::displayTeams()
{
        cout << "Teams in the league:" << endl;
        for (auto const& pair : teams) {
            cout << pair.first << endl;
        }
   
    
}

void League::updatePoints(string teamName, int points)
{
    
    teams[teamName]->points += points;
    
}

void League::displayPointTable()
{
    {
        cout << "Point table:" << endl;
        // Convert to vector for sorting
        vector<Teams*> teamList;
        for (auto const& pair : teams) {
            teamList.push_back(pair.second);
        }
        // Sort teams by points
        sort(teamList.begin(), teamList.end(), [](const Teams* a, const Teams* b) {
            return a->points > b->points;
            });
        // Display point table
        for (int i = 0; i < teamList.size(); ++i) {
            cout << i + 1 << ". " << teamList[i]->name << ": " << teamList[i]->points << " points" << endl;
        }
    }
}

League::~League()
{
        for (auto const& pair : teams) {
            delete pair.second;
        }
    
}
