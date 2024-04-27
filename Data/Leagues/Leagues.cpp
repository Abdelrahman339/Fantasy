#include <iostream>
#include <unordered_map>
#include <string>
#include "leagues.h"
#include <algorithm>
#include"teams.h"
#include "game.h"
using namespace std;

void league::displayteams() {
	cout << "teams in the league:" << endl;
	for (auto& team : teams) {
		cout << team.getname() << endl;
	}
}


void league::updatepoints(vector<teams> allteams, list<game> allgames) {

	// update points based on games played
	for (auto& game : allgames) {
		for (auto& team : allteams) {
			if (team.getname() == game.getwinningteam()) {
				team.addpoints(3);
			}
			else if ((team.getname() == game.gethometeam().getname() || team.getname() == game.getawayteam().getname()) && game.getwinningteam() == "draw") {
				team.addpoints(1);
			}
		}
	}
}




void league::displaypointtable(vector <teams> teamlist)
{
	{
		cout << "point table:" << endl;
		// sort teams by points
		sort(teamlist.begin(), teamlist.end(), [](teams& a, teams& b) {
			return a.getpoints() > b.getpoints();
			});
		// display point table
		for (int i = 0; i < teamlist.size(); ++i) {
			cout << i + 1 << ". " << teamlist[i].getname() << ": " << teamlist[i].getpoints() << " points" << "," << teamlist[i].getwins() << "wins" << "," << teamlist[i].getlose() << "lose" << "," << teamlist[i].getdraw() << "draw" << endl;
		}
	}
}

map<string, Teams> League::getTeams()
{
	return this->teams;
}
