#include "Competition.h"

bool firstTime = false;
int GameIdcounter = 0;







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





void Competition::ReducePoints(User* currentUser, Footballer* TargetedFootballer, string violence, string status, int& tempPoints)
{
	if (status == "User") {
		if (violence == "RedCard")
		{
			currentUser->AddPoints(-2);
			currentUser->addBalance(-20);
		}
		if (violence == "YellowCard") {
			currentUser->AddPoints(-1);
			currentUser->addBalance(-5);
		}
	}
	else if (status == "footballer") {
		if (violence == "RedCard")
		{
			TargetedFootballer->AddTotalpoints(-2);
			TargetedFootballer->SetTotalRedCard(TargetedFootballer->GetTotalRedCard() + 1);
			tempPoints += -2;

		}
		if (violence == "YellowCard") {
			TargetedFootballer->AddTotalpoints(-1);
			TargetedFootballer->SetTotalYellowcard(TargetedFootballer->GetTotalYellowCard() + 1);
			tempPoints += -1;
		}
	}



}

void Competition::AddContributesPoints(User* currentUser, Footballer* TargetedFootballer, string contributes, string status, int& tempPoints, Teams* team, string motm)
{
	//"goals 5 & assists 6"
	regex Goal_Assist_pattern(R"(&)");
	//"goals 5"
	regex Goalpattern(R"(Goal)");
	//"assist 2"
	regex Assistpattern(R"(Assist)");
	//"CleanSheets"
	regex CleanSheets(R"(CleanSheets)");
	if (regex_search(contributes, Goal_Assist_pattern)) { // if the player scord and did assist

		addGoalsAssistPoints(contributes, currentUser, TargetedFootballer, status, tempPoints, team, motm);
	}
	// the player ethier scored a goal or did assist
	else if (regex_search(contributes, Goalpattern))
	{
		addPoints(contributes, currentUser, TargetedFootballer, Competition::goalPoints, status, tempPoints, motm);

	}
	else if (regex_search(contributes, Assistpattern))
	{
		addPoints(contributes, currentUser, TargetedFootballer, Competition::assistPoints, status, tempPoints, motm);
	}
	else if (regex_search(contributes, CleanSheets))
	{

		addPoints(contributes, currentUser, TargetedFootballer, Competition::cleanSheetPoints, status, tempPoints, motm);

	}
	//the player didnt do any contributes in the match
	else
	{
		if (status == "User")
		{
			if (TargetedFootballer->GetName() == motm)
			{
				currentUser->AddPoints(3);
			}
			else
			{
				currentUser->AddPoints(-2);
			}
		}
		else {
			TargetedFootballer->AddTotalpoints(-2);
		}
	}

}


void Competition::addPoints(string contributes, User* currentUser, Footballer* TargetedFootballer, int numPerpoints, string status, int& tempPoints, string motm)
{
	int numberOfcontributes = 0;
	regex pattern(R"(\d+)");
	regex Goalpattern(R"(Goal)");
	regex Assistpattern(R"(Assist)");

	smatch match;

	if (regex_search(contributes, match, pattern)) {
		numberOfcontributes = stoi(match[0]);

	}
	if (status == "footballer") {
		TargetedFootballer->AddTotalpoints(numPerpoints * numberOfcontributes);
		tempPoints = numPerpoints * numberOfcontributes;

		if (regex_search(contributes, Goalpattern)) {
			TargetedFootballer->SetTotalGoals(TargetedFootballer->GetTotalGoals() + numberOfcontributes);
		}

		else if (regex_search(contributes, Assistpattern)) {
			TargetedFootballer->SetTotalAssists(TargetedFootballer->GetTotalAssists() + numberOfcontributes);
		}



	}
	else {
		if (TargetedFootballer->GetName() == motm)
		{
			numberOfcontributes += 3;
		}
		currentUser->AddPoints(numPerpoints * numberOfcontributes);
		currentUser->addBalance(200 * numberOfcontributes);
	}
}



void Competition::addGoalsAssistPoints(string contributes, User* currentUser, Footballer* TargetedFootballer, string status, int& tempPoints, Teams* team, string motm)
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

	
		team->getFootballPlayer()->at(TargetedFootballer->GetName()).AddTotalpoints(totalPoints);
		team->getFootballPlayer()->at(TargetedFootballer->GetName()).SetTotalGoals(TargetedFootballer->GetTotalGoals() + goalsnum);
		team->getFootballPlayer()->at(TargetedFootballer->GetName()).SetTotalAssists(TargetedFootballer->GetTotalAssists() + assistsnum);
		tempPoints = totalPoints;

	}
	else {
		if (TargetedFootballer->GetName() == motm)
		{
			totalPoints += 3;
		}
		currentUser->AddPoints(totalPoints);
		currentUser->addBalance(totalPoints * 3);
	}

}


void Competition::updateAllUserPoints(unordered_map<string, User>* Users, list <Game> allGames, User* currentUser)
{

	int gameRound = currentUser->GetUserGames().front().getRound();
	Teams* team = nullptr;
	for (auto& user : *Users)
	{
		User* User = &user.second;
		if (currentUser->GetUsername() == user.first && firstTime == false)
		{
			findPlayers(currentUser, "currentUser", team, gameRound);
			firstTime = true;
		}
		else if (currentUser->GetUsername() == user.first)
		{
			continue;
		}
		else
		{

			findPlayers(User, "allUser", team, gameRound);
		}

	}
}


void Competition::findPlayers(User* currentUser, string status, Teams* team, int round)
{
	int tempPoints = 0;

	Game currentGame;
	if (status == "currentUser")
	{
		currentGame = currentUser->GetUserGames().front();
		updatecurrentUserPoint(currentGame, currentUser);
		currentUser->GetUserGames().pop();
	}
	else
	{
		queue<Game>tempUserGames = currentUser->GetUserGames();

		while (!tempUserGames.empty())
		{

			currentGame = tempUserGames.front();

			if (currentGame.getRound() != round)
			{
				tempUserGames.pop();
				continue;
			}

			updatecurrentUserPoint(currentGame, currentUser);

			//The end of the match
			tempUserGames.pop();
		}
	}

}

void Competition::updatecurrentUserPoint(Game currentGame, User* currentUser)
{
	int tempPoints = 0;
	Teams* team = nullptr;

	while (!currentGame.getHighlightsOfTheMatch().empty())
	{


		string currentPlayerinMatch = *currentGame.getHighlightsOfTheMatch().top().getName();
		string motm = currentGame.getManOfTheMatch();
		for (auto& kv : currentUser->GetMainSquad()) {

			//get the data from the game
			string footballerName = kv.first;
			string contributes = currentGame.getHighlightsOfTheMatch().top().getContributions();
			string violation = currentGame.getHighlightsOfTheMatch().top().getViolation();

			if (footballerName == currentPlayerinMatch)
			{
				AddContributesPoints(currentUser, kv.second, contributes, "User", tempPoints, team, motm);
				ReducePoints(currentUser, kv.second, violation, "User", tempPoints);

			}
		}

		//go to the next player
		currentGame.getHighlightsOfTheMatch().pop();
	}
}

void Competition::deletefromList(list<Game>& allGames, int gameid)
{
	GameIdcounter++;
	for (auto i = allGames.begin(); i != allGames.end(); i++)
	{
		if (gameid == i->getGameId()) {
			allGames.erase(i);
			return;
		}
	}
}

void Competition::deleteallGameRound(list<Game>* allgames, int gameround)
{
	allgames->clear();
}


void Competition::UpdateFootballerPrice(Footballer* player, int tempPoints, Teams* team) // for all the players
{
	char tier = Competition::priceCalculation(tempPoints);
	float currentPlayerPrice = player->GetPrice();
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
	player->SetPrice(priceChange);
}

void Competition::searchTeamInMatch(Teams* team, Game game, HighlightsOfTheMatch Highlights) {


	User* currentUser = nullptr;
	string status = "footballer";
	string currentFootballerName = *Highlights.getName();

	string currentMOTM = game.getManOfTheMatch();

	for (auto& kv : *team->getFootballPlayer()) {

		if (currentFootballerName == kv.first)
		{
			int tempPoints = 0;
			Footballer* currentFootballer = &team->getFootballPlayer()->at(kv.first);

			string contributions = Highlights.getContributions();
			string violation = Highlights.getViolation();

			if (currentFootballerName == currentMOTM) {
				tempPoints = MOTM_Bonus;
			}

			Competition::AddContributesPoints(currentUser, currentFootballer, contributions, status, tempPoints, team, currentMOTM);
			Competition::ReducePoints(currentUser, currentFootballer, violation, status, tempPoints); // for deducing redCards and yellowcards points
			Competition::UpdateFootballerPrice(currentFootballer, tempPoints, team);
			break;
		}


	}


}

void Competition::UpdateFootballerPoints(list<Game>* GameWeek, int currentround) //for both squads of the match for a game week
{
	list<Game> tempGameWeek;
	for (auto i = GameWeek->begin(); i != GameWeek->end(); ++i)
	{
		Game game = *i;
		if (game.getRound() == currentround)
		{
			tempGameWeek.push_back(game);
		}
		if (tempGameWeek.size() == 8)
		{
			break;
		}
	}



	while (!tempGameWeek.empty()) {

		Game game = tempGameWeek.front();
		Teams* awayTeam = game.getAwayTeam();
		Teams* homeTeam = game.getHomeTeam();
		HighlightsOfTheMatch highlights;
		string currentMOTM = game.getManOfTheMatch();
		int NumOfMatchesPlayed = 0;



		while (!game.getHighlightsOfTheMatch().empty()) {

			//get higlights for one player 
			highlights = game.getHighlightsOfTheMatch().top();

			Competition::searchTeamInMatch(awayTeam, game, highlights);
			Competition::searchTeamInMatch(homeTeam, game, highlights);


			game.getHighlightsOfTheMatch().pop();

		}


		//the end of each game
		tempGameWeek.pop_front();

	}
}












