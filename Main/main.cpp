#include <iostream> 
#include <Windows.h>

// Files
#include "User.h"
#include "Competition.h"
#include "Game.h"
#include "LuckyWheel.h"
#include "fileManpulation.h"

// Data structures
#include <unordered_map>

int main() {
	//cout << "Reading from files: " << endl << endl;
	////League Data now Done!==> Usage
	map<string, unordered_map<string, Footballer>> footballersOfTeam = fileManipulation::getFootballersOfTeamData();
	map<string, Teams> allTeams = fileManipulation::getTeamsData(footballersOfTeam);
	vector<TheLeague> leagues = fileManipulation::getLeagueData(allTeams);


	////Get Games now Done!==> USAGE
	list<Game> games = fileManipulation::getGamesData(allTeams);
	//for (list<Game>::iterator it = games.begin(); it != games.end(); ++it) {
	//	stack<HighlightsOfTheMatch> highlights = it->getHighlightsOfTheMatch();
	//	while (!highlights.empty()) {
	//		cout << highlights.top().getContributions() << endl;
	//		highlights.pop();
	//	}
	//}

	//Get User now Done!==> USAGE

	map<int, pair<unordered_map<string, Footballer>, unordered_map<string, Footballer>>> userSquads = fileManipulation::getUserSquadsData(footballersOfTeam);
	unordered_map<string, User> users = fileManipulation::getUsersData(userSquads);
	User user = users.at("william_l_81");

	//cout << user.GetMainSquad()["Courtois"].GetName() << endl;

	//Game::displayGameOverview(games);

	user.homePage(&users, leagues, games);


}

/*
*
* /////Important notes for used data structure :

 Hash table : to store all users in the application.

 linked list of Games: this lined list will contain all the matches in the application. The matches will be a static data will be in GameFile.txt this file will have all data for all mtaches in all the leagues.this linekd list will be static for all users.

 hash table of Footballers: this vector will have a 11 player from the same team .the data of footballers will be stored in TeamFile.txt . this file will have the information about each team and the info for the footballers in this team.This vector will be in class "team".

 queue of Games: this deque will contain mtaches but it will  depend on the user squad . this queue will be different for each user.

 stack of string and set:internal usage in functions.

 vector of leagues

 map of teams


*/

//notes for functions:
/*
to calculate the footballers points and update the price : will use the linked list of all matches.

to calcualte the user points and get money for every player score form his squad: will use the deque of games.

to calcualte the points of each team: will use the linekd list of all games.

to edit on users: will use the hash table of all users and the functions on user file but with modifications.


*/


/*
class team : should contain the name ,the id ,the points , number of wins ,nubmer of draws and number of losses.
*/


//vector <string> players = { "Courtois","Carvajal","Rudiger","Tchouameni","Mendy","Camavinga","Kroos","Bellingham","Valverde","Rodrygo","Vinicius","Stegen","Koundé","Araújo","Cubarsí","Cancelo","Pedri","Gündoğan","Frenkie ","Lamine ","Lewandowski","Raphinha" };
//unordered_map <string, Footballer> footballer;
//unordered_map<string, User> Users;
//User user;
//for (int i = 0; i < players.size(); i++)
//{
//	Footballer player;
//	player.SetName(players[i]);
//	footballer.insert_or_assign(player.GetName(), player);
//}
//for (int i = 0; i < 15; i++)
//{
//	user.SetFootballer(footballer.at(players[i]));
//}
//user.userMenu(user, Users);