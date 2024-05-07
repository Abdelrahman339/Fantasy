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





void Competition::ReducePoints(User& currentUser, Footballer& TargetedFootballer, string violence, string status, int& tempPoints)
{
	if (status == "User") {
		if (violence == "RedCard")
		{
			currentUser.AddPoints(-2);
			currentUser.addBalance(-20);
		}
		if (violence == "YellowCard") {
			currentUser.AddPoints(-1);
			currentUser.addBalance(-5);
		}
	}
	else if (status == "footballer") {
		if (violence == "RedCard")
		{
			TargetedFootballer.AddTotalpoints(-2);
			tempPoints += -2;

		}
		if (violence == "YellowCard") {
			TargetedFootballer.AddTotalpoints(-1);
			tempPoints += -1;
		}
	}



}

void Competition::AddContributesPoints(User& currentUser, Footballer& TargetedFootballer, string contributes, string status, int& tempPoints, Teams& team)
{
	//"goals 5 & assists 6"
	regex Goal_Assist_pattern(R"(&)");
	//"goals 5"
	regex Goalpattern(R"(Goal)");
	//"assist 2"
	regex Assistpattern(R"(Assist)");
	//"Clean sheets"
	regex CleanSheets(R"(CleanSheets)");
	if (regex_search(contributes, Goal_Assist_pattern)) { // if the player scord and did assist

		addGoalsAssistPoints(contributes, currentUser, TargetedFootballer, status, tempPoints, team);
	}
	// the player ethier scored a goal or did assist
	else if (regex_search(contributes, Goalpattern))
	{
		addPoints(contributes, currentUser, TargetedFootballer, Competition::goalPoints, status, tempPoints);

	}
	else if (regex_search(contributes, Assistpattern))
	{
		addPoints(contributes, currentUser, TargetedFootballer, Competition::assistPoints, status, tempPoints);
	}
	else if (regex_search(contributes, CleanSheets))
	{
		addPoints(contributes, currentUser, TargetedFootballer, Competition::cleanSheetPoints, status, tempPoints);

	}
	//the player didnt do any contributes in the match
	else
	{
		if (status == "User")
		{
			currentUser.AddPoints(-2);
		}
		else {
			TargetedFootballer.AddTotalpoints(-2);
		}
	}

}


void Competition::addPoints(string contributes, User& currentUser, Footballer& TargetedFootballer, int numPerpoints, string status, int& tempPoints)
{
	int numberOfcontributes = 0;
	regex pattern(R"(\d+)");

	smatch match;

	if (regex_search(contributes, match, pattern)) {
		numberOfcontributes = stoi(match[0]);

	}
	if (status == "footballer") {
		TargetedFootballer.AddTotalpoints(numPerpoints * numberOfcontributes);
		tempPoints = numPerpoints * numberOfcontributes;
	}
	else {
		currentUser.AddPoints(numPerpoints * numberOfcontributes);
		currentUser.addBalance(numPerpoints * numberOfcontributes);
	}
}



void Competition::addGoalsAssistPoints(string contributes, User currentUser, Footballer& TargetedFootballer, string status, int& tempPoints, Teams& team)
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

		//TargetedFootballer.AddTotalpoints(totalPoints);
		team.getFootballPlayer().at(TargetedFootballer.GetName()).AddTotalpoints(totalPoints);
		tempPoints = totalPoints;

	}
	else {
		currentUser.AddPoints(totalPoints);
		currentUser.addBalance(totalPoints * 3);
	}
}


void Competition::updateAllUserPoints(unordered_map<string, User>& Users, list <Game> allGames, User& UserinMoment)
{
	Teams team;
	for (auto user : Users)
	{
		User currentUser = user.second;
		stack<string> oldUserTeams;
		string status = "allUsers";
		if (user.first == UserinMoment.GetUsername())
		{
			currentUser = UserinMoment;
			status = "CurrentUser";
		}
		oldUserTeams = User::GetUserTeams(currentUser);
		User::FilteringTeams(allGames, currentUser, oldUserTeams, status);

		//findPlayers(currentUser, "User", team);
		cout << user.first << " games:" << endl;
		while (!currentUser.GetUserGames().empty())
		{
			cout << currentUser.GetUserGames().front().getHomeTeam().getName() << " X " << currentUser.GetUserGames().front().getAwayTeam().getName() << ". " << endl;
			currentUser.GetUserGames().pop();
		}
		cout << "----------------------------------------------------------------------------------------------------\n";
	}
}


void Competition::findPlayers(User& currentUser, string status, Teams& team)
{
	int tempPoints = 0;

	Game currentGame = currentUser.GetUserGames().front();
	while (!currentGame.getHighlightsOfTheMatch().empty())
	{

		string currentPlayerinMatch = currentGame.getHighlightsOfTheMatch().top().getName();
		for (auto& kv : currentUser.GetMainSquad()) {

			//get the data from the game
			string footballerName = kv.first;
			string contributes = currentGame.getHighlightsOfTheMatch().top().getContributions();
			string violation = currentGame.getHighlightsOfTheMatch().top().getViolation();

			if (footballerName == currentPlayerinMatch)
			{
				//AddContributesPoints(currentUser, kv.second, contributes, "User", tempPoints);
				ReducePoints(currentUser, kv.second, violation, "User", tempPoints);

			}
		}

		//go to the next player
		currentGame.getHighlightsOfTheMatch().pop();
	}


	//The end of the match
	currentUser.GetUserGames().pop();
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

void Competition::UpdateFootballerPrice(Footballer& player, int tempPoints, Teams& team) // for all the players
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

	team.getFootballPlayer().at(player.GetName()).SetPrice(priceChange);




}

void Competition::searchTeamInMatch(Teams& team, Game game, HighlightsOfTheMatch Highlights) {


	User currentUser;
	string status = "footballer";
	string currentFootballerName = Highlights.getName();

	string currentMOTM = game.getManOfTheMatch();

	for (auto& kv : team.getFootballPlayer()) {

		if (currentFootballerName == kv.first)
		{
			int tempPoints = 0;
			Footballer& currentFootballer = team.getFootballPlayer().at(kv.first);

			string contributions = Highlights.getContributions();
			string violation = Highlights.getViolation();

			Competition::AddContributesPoints(currentUser, currentFootballer, contributions, status, tempPoints, team);
			Competition::ReducePoints(currentUser, currentFootballer, violation, status, tempPoints); // for deducing redCards and yellowcards points
			Competition::UpdateFootballerPrice(currentFootballer, tempPoints, team);
		}


	}


}

void Competition::UpdateFootballerPoints(queue<Game>& GameWeek) //for both squads of the match for a game week
{
	Game game = GameWeek.front();
	Teams awayTeam = game.getAwayTeam();
	Teams homeTeam = game.getHomeTeam();
	HighlightsOfTheMatch highlights;
	string currentMOTM = game.getManOfTheMatch();
	int NumOfMatchesPlayed = 0;


	game = GameWeek.front();




	while (!game.getHighlightsOfTheMatch().empty()) {

		//get higlights for one player 
		highlights = game.getHighlightsOfTheMatch().top();

		Competition::searchTeamInMatch(awayTeam, game, highlights);
		Competition::searchTeamInMatch(homeTeam, game, highlights);


		game.getHighlightsOfTheMatch().pop();

	}

	//calculating the points for the man of the match
	int countAwayTeam = awayTeam.getFootballPlayer().count(currentMOTM);
	int countHomeTeam = homeTeam.getFootballPlayer().count(currentMOTM);
	if (countAwayTeam > 0)
	{
		float currentMOTMPlayerPrice = awayTeam.getFootballPlayer().at(currentMOTM).GetPrice();
		awayTeam.getFootballPlayer().at(currentMOTM).AddTotalpoints(Competition::MOTM_Bonus);
		awayTeam.getFootballPlayer().at(currentMOTM).SetPrice(currentMOTMPlayerPrice + 500.0f);
	}
	else
	{
		float currentMOTMPlayerPrice = homeTeam.getFootballPlayer().at(currentMOTM).GetPrice();
		homeTeam.getFootballPlayer().at(currentMOTM).AddTotalpoints(Competition::MOTM_Bonus);
		homeTeam.getFootballPlayer().at(currentMOTM).SetPrice(currentMOTMPlayerPrice + 500.0f);
	}



}












