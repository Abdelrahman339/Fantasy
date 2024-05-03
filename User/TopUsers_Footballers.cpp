//#include <iostream>
//#include "User.h"
//
//
//
//vector<Footballer> User::GetAllFootballers(League league) {
//
//
//	vector <Footballer> allPlayersLeageu;
//
//	// looping on all teams in the league
//	for (auto currentTeam : league.GetTeams()) {
//
//		//loop through all players in the team
//		for (auto currentPlayer : currentTeam.second.getFootballPlayer()) {
//
//			//add the player in the vector of players
//			allPlayersLeageu.push_back(currentPlayer.second);
//		}
//	}
//	return allPlayersLeageu;
//
//}
//vector<Footballer> User::TopFootballersinLeague(vector<Footballer> Footballers)
//{
//	vector<Footballer> top5players;
//	sort(Footballers.begin(), Footballers.end(), comparePlayersByPoints);
//	for (int i = 0; i < 5; i++)
//	{
//		top5players.push_back(Footballers.at(i));
//	}
//	return top5players;
//}
//
//
//void User::toUnordredMap(unordered_map<string, Footballer>& topPlayers, vector<Footballer> top5players)
//{
//	for (auto player : top5players)
//	{
//		topPlayers.insert_or_assign(player.GetName(), player);
//	}
//}
//
//
//unordered_map<string, Footballer> User::TopFootballers(vector<League> leageus)
//{
//	unordered_map<string, Footballer> topPlayers;
//
//	vector <Footballer> allPlayersinLeague;
//
//	vector<Footballer>top5;
//	for (int i = 0; i < leageus.size(); i++)
//	{
//		allPlayersinLeague = GetAllFootballers(leageus[i]);
//		top5 = TopFootballersinLeague(allPlayersinLeague);
//		toUnordredMap(topPlayers, top5);
//	}
//
//	return topPlayers;
//};
//
//
//
//
//
//
//
//bool User::comparePlayersByPoints(Footballer& player1, Footballer& player2) {
//	return player1.GetTotalpoints() > player2.GetTotalpoints();
//}
//
//
//
//
//
//
//
//
//
