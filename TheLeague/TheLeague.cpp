#include "TheLeague.h"

void TheLeague::displayTeams(map<string, Teams> teams) {
	cout << "Name" << "\t\t\t       " << "Points" << endl;
	for (auto& team : teams) {
		cout << team.second.getName() << "\t\t" << checkStrLengthTeams(team.second.getName()) << team.second.getPoints() << endl;
	}
	cout << "--------------------------------------------------" << endl;
}
//Test this later 5/5/2024
string TheLeague::checkStrLengthTeams(const std::string& str) {
	if (str.length() <= 16 && str.length() >= 8) {
		return "\t";
	}
	else if (str.length() < 8) {
		return "\t\t";
	}
	return "";
}

//void League::updatePoints( list <Game> allgames) {
//    // Update points based on games played
//    for ( auto& game : allgames) {
//        auto homeTeam = teams.find(game.getHomeTeam().getName());
//        auto awayTeam = teams.find(game.getAwayTeam().getName());
//        if (homeTeam != teams.end() && awayTeam != teams.end()) {
//            if (game.getwinningTeam() == homeTeam->first) {
//                homeTeam->second.addPoints(3);
//            }
//            else if (game.getwinningTeam() == awayTeam->first) {
//                awayTeam->second.addPoints(3);
//            }
//            else if (game.getwinningTeam() == "draw") {
//                homeTeam->second.addPoints(1);
//                awayTeam->second.addPoints(1);
//            }
//        }
//    }
//}




//void League::displayPointTable()
//{ 
//    {
//        cout << "Point table:" << endl;
//        vector<pair<string, Teams>> teamlist(teams.begin(), teams.end());
//
//         Custom sort using lambda expression
//        sort(teamlist.begin(), teamlist.end(), []( pair<string, Teams>& a,  pair<string, Teams>& b) {
//            return a.second.getPoints() > b.second.getPoints();
//            });
//         Display point table
//        for (int i = 0; i < teamlist.size(); ++i) {
//            cout << i + 1 << ". " << teamlist[i].second.getName() << ": " << teamlist[i].second.getPoints() << " points" <<","<< teamlist[i].second.getwins()<<"wins"<<"," << teamlist[i].second.getlose()<< "lose" <<"," << teamlist[i].second.getdraw()<<"draw" << endl;
//        }
//    }
//}

string TheLeague::getLeagueName()
{
	return this->name;
}

void TheLeague::setLeagueName(string newLeagueName) {
	this->name = newLeagueName;
}

TheLeague::TheLeague() {
	this->name = "";
	this->teams = {};
}

TheLeague::TheLeague(string name, map<string, Teams> teams) {
	this->name = name;
	this->teams = teams;
}

map<string, Teams>& TheLeague::GetTeams()
{
	return this->teams;
}

void TheLeague::SetTeams(map<string, Teams> teams){
	this->teams = teams;
}

vector<string> TheLeague::getTeamNames(map<string, Teams> teams) {
	vector<string> teamNames;

	for (auto& [teamName, teamData] : teams)
		teamNames.push_back(teamName);

	return teamNames;
}

