//#include <iostream>
//#include <unordered_map>
//#include <string>
//#include "Leagues.h"
//#include <algorithm>
//#include"Teams.h"
//#include "Game.h"
//using namespace std;
//
//void League::displayTeams() {
//    cout << "Teams in the league:" << endl;
//    for ( auto& team : teams) {
//        cout << team.getName()<< endl;
//    }
//}
//
//
//void League::updatePoints(vector<Teams> allteams, list<Game> allgames) {
// 
//    // Update points based on games played
//    for ( auto& game : allgames) {
//        for (auto& team : allteams) {
//            if (team.getName() == game.getwinningTeam()) {
//                team.addPoints(3);
//            }
//            else if ((team.getName() == game.getHomeTeam().getName() || team.getName() == game.getAwayTeam().getName()) && game.getwinningTeam() == "draw") {
//                team.addPoints(1);
//            }
//        }
//    }
//}
//
//    
//
//
//void League::displayPointTable(vector <Teams> teamlist)
//{
//    {
//        cout << "Point table:" << endl;
//        // Sort teams by points
//        sort(teamlist.begin(), teamlist.end(), []( Teams& a,  Teams& b) {
//            return a.getPoints() > b.getPoints();
//            });
//        // Display point table
//        for (int i = 0; i < teamlist.size(); ++i) {
//            cout << i + 1 << ". " << teamlist[i].getName() << ": " << teamlist[i].getPoints() << " points" <<","<< teamlist[i].getwins()<<"wins"<<"," << teamlist[i].getlose()<< "lose" <<"," << teamlist[i].getdraw()<<"draw" << endl;
//        }
//    }
//}
//
//
