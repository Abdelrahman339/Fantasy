#include "Competition.h"

bool Competition::IsManOfTheMatch(string currentMOTM, string playerName)
{
	return (currentMOTM == playerName);
}


bool Competition::checkPosition(string footballerPosition) {

	if (footballerPosition == "defender" || footballerPosition == "goalkeeper") {
		return true;
	}

	else
		return false;

}

char Competition::priceCalculation(int points) {



	if (points < 3) {
		return '0';
	}
	else if (points < 6) {
		return '1';
	}
	else if (points < 9) {
		return '2';
	}
	else if (points < 12) {
		return '3';
	}
	else if (points < 15) {
		return '4';
	}
	else {
		return '5';
	}

}





void Competition::ReducePoints(string footballerName, User& currentUser, string violence, string status, Teams& team, int& tempPoints)
{
	if (status == "User") {
		if (violence == "RedCard")
		{
			currentUser.GetMainSquad().at(footballerName).AddTotalpoints(-2);
			currentUser.AddPoints(-2);
			currentUser.addBalance(-20);
		}
		if (violence == "YellowCard") {
			currentUser.GetMainSquad().at(footballerName).AddTotalpoints(-1);
			currentUser.AddPoints(-1);
			currentUser.addBalance(-5);
		}
	}
	else if (status == "Footballer") {
		if (violence == "RedCard")
		{
			team.getFootballPlayer().at(footballerName).AddTotalpoints(-2);
			tempPoints += -2;

		}
		if (violence == "YellowCard") {
			team.getFootballPlayer().at(footballerName).AddTotalpoints(-1);
			tempPoints += -1;
		}
	}



}

void Competition::AddContributesPoints(string footballerName, User& currentUser, string contributes, string status, Teams& team, string footballerPosition, int& tempPoints)
{
	//"goals 5 & assists 6"
	regex pattern(R"(&)");
	int numberofGoals;
	if (regex_match(contributes, pattern)) { // if the player scord and did assist

		addGoalsAssistPoints(contributes, currentUser, footballerName, status, team, tempPoints);
	}

	else if (!regex_match(contributes, pattern))
	{
		regex Goalpattern(R"(Goal)");
		regex Assistpattern(R"(Assist)");
		if (regex_match(contributes, Goalpattern)) {

			addPoints(contributes, currentUser, footballerName, Competition::goalPoints, status, team, tempPoints);
		}
		else if (regex_match(contributes, Assistpattern)) {

			addPoints(contributes, currentUser, footballerName, Competition::assistPoints, status, team, tempPoints);
		}
		else {
			if (checkPosition(footballerPosition)) {
				currentUser.GetMainSquad().at(footballerName).AddTotalpoints(cleanSheetPoints);
				currentUser.AddPoints(cleanSheetPoints);
				currentUser.addBalance(10);
			}
		}
	}
	else
	{
		currentUser.GetMainSquad().at(footballerName).AddTotalpoints(-10);
		currentUser.AddPoints(-10);
	}

}


void Competition::addPoints(string contributes, User currentUser, string footballerName, int numPerpoints, string status, Teams& team, int& tempPoints)
{
	int numberOfcontributes = 0;
	regex pattern(R"(\d+)");

	smatch match;

	if (regex_search(contributes, match, pattern)) {
		numberOfcontributes = stoi(match[0]);

	}
	if (status == "footballer") {
		team.getFootballPlayer().at(footballerName).AddTotalpoints(numPerpoints * numberOfcontributes);
		tempPoints = numPerpoints * numberOfcontributes;
	}
	else {
		currentUser.GetMainSquad().at(footballerName).AddTotalpoints(numPerpoints * numberOfcontributes);
		currentUser.AddPoints(numPerpoints * numberOfcontributes);
		currentUser.addBalance(numPerpoints * numberOfcontributes);
	}
}



void Competition::addGoalsAssistPoints(string contributes, User currentUser, string footballerName, string status, Teams& team, int& tempPoints)
{
	regex pattern(R"(\d+)");

	smatch matches;
	int goalsnum = 0, assistsnum = 0;
	int totalPoints = 0;

	int foundNumbers = 0;

	while (regex_search(contributes, matches, pattern)) {
		if (foundNumbers == 0) {
			goalsnum = stoi(matches[0]);
		}
		else {
			assistsnum = stoi(matches[0]);
		}
		contributes = matches.suffix().str();
		foundNumbers++;
	}
	totalPoints = ((goalsnum * Competition::goalPoints) + (assistsnum * Competition::assistPoints));

	if (status == "footballer") {
		team.getFootballPlayer().at(footballerName).AddTotalpoints(totalPoints);
		tempPoints = totalPoints;

	}
	else {
		currentUser.GetMainSquad().at(footballerName).AddTotalpoints(totalPoints);
		currentUser.AddPoints(totalPoints);
		currentUser.addBalance(totalPoints * 3);
	}
}


void Competition::updateAllUserPoints(unordered_map<string, User>& Users)
{
	Teams team;
	for (auto user : Users)
	{
		User currentUser = user.second;
		findPlayers(currentUser.GetUserGames(), currentUser, "User", team);
	}
}


void Competition::findPlayers(queue<Game>& UserGames, User& currentUser, string status, Teams& team)
{
	int tempPoints = 0;

	Game currentGame = UserGames.front();
	while (!currentGame.getHighlightsOfTheMatch().empty())
	{

		string currentPlayerinMatch = currentGame.getHighlightsOfTheMatch().top().getName();
		for (auto& kv : currentUser.GetMainSquad()) {
			string footballerName = kv.first;
			if (footballerName == currentPlayerinMatch)
			{
				AddContributesPoints(currentPlayerinMatch, currentUser, currentGame.getHighlightsOfTheMatch().top().getContributions(), "User", team, currentPlayerinMatch, tempPoints);
				ReducePoints(currentPlayerinMatch, currentUser, currentGame.getHighlightsOfTheMatch().top().getViolation(), "User", team, tempPoints);

			}
		}

		//go to the next player
		currentGame.getHighlightsOfTheMatch().pop();
	}


	//The end of the match
	UserGames.pop();
}

void Competition::showAllGameHighlights(queue<Game>Usergames, list <Game>& allGame)
{
	char ans;
	cout << "Highlights of the week" << endl;
	for (Game game : allGame) {
		cout << game.getAwayTeam().getName() << User::spacing(10, ' ') << game.getHomeTeam().getName() << endl;
		cout << game.getScore() << endl;
	}
}

void Competition::UpdateFootballerPrice(Footballer& player, int tempPoints) // for all the players
{
	char tier = Competition::priceCalculation(tempPoints);
	float currentPlayerPrice = player.GetPrice();
	float priceChange;

	switch (tier) {

	case '1':
		priceChange = currentPlayerPrice + 500.0f;
		break;

	case '2':
		priceChange = currentPlayerPrice + 1000.0f;
		break;

	case '3':
		priceChange = currentPlayerPrice + 1500.0f;
		break;

	case '4':
		priceChange = currentPlayerPrice + 2000.0f;
		break;

	case '5':
		priceChange = currentPlayerPrice + 2500.0f;
		break;

	default:
		//if the player doesn't perfom with any of the tiers
		priceChange = currentPlayerPrice - 200.0f;
	}

	player.SetPrice(priceChange);



}

void Competition::searchTeamInMatch(unordered_map<string, Footballer> TeamType, Game game) {


	Teams team;
	User currentUser;
	string status = "footballer";
	HighlightsOfTheMatch highlights = game.getHighlightsOfTheMatch().top();
	bool ManOfMatchPointsCalculated = false;


	string currentMOTM = game.getManOfTheMatch();

	for (auto& kv : TeamType) {

		int tempPoints = 0;
		string playerName = kv.first;
		Footballer& currentFootballer = kv.second;

		string contributions = highlights.getContributions();
		string violation = highlights.getViolation();

		Competition::AddContributesPoints(playerName, currentUser, contributions, status, team, currentFootballer.GetPosition(), tempPoints);
		Competition::ReducePoints(playerName, currentUser, violation, status, team, tempPoints); // for deducing redCards and yellowcards points
		Competition::UpdateFootballerPrice(currentFootballer, tempPoints);
	}
	//calculating the points for the man of the match
	int count = TeamType.count(currentMOTM);
	if (count > 0)
	{
		float currentMOTMPlayerPrice = TeamType.at(currentMOTM).GetPrice();
		TeamType.at(currentMOTM).AddTotalpoints(Competition::MOTM_Bonus);
		TeamType.at(currentMOTM).SetPrice(currentMOTMPlayerPrice + 500.0f);
	}

}

void Competition::UpdateFootballerPoints(list<Game> GameWeek) //for both squads of the match for a game week
{
	Game game;
	unordered_map<string, Footballer> AwayFootballPlayers;
	unordered_map<string, Footballer> HomeFootballPlayers;
	int NumOfMatchesPlayed = 0;

	while (NumOfMatchesPlayed < 8)
	{

		game = GameWeek.front();


		AwayFootballPlayers = game.getAwayTeam().getFootballPlayer();
		HomeFootballPlayers = game.getHomeTeam().getFootballPlayer();


		while (!game.getHighlightsOfTheMatch().empty()) {

			Competition::searchTeamInMatch(AwayFootballPlayers, game);
			Competition::searchTeamInMatch(HomeFootballPlayers, game);


			game.getHighlightsOfTheMatch().pop();
		}



		GameWeek.pop_front();
		NumOfMatchesPlayed++;
	}


}












