#include <iostream>
#include "UserValidations.h"
#include "User.h"
#include "Teams.h"
using namespace std;



User::User() {
	srand(time(0));
	this->id = rand();
	this->fullName = "";
	this->username = "";
	this->password = "";
	this->phoneNumber = "";
	this->Email = "";
	this->points = 0;
	this->balance = 80000;
	this->lastDatePlayedWheel = -1;
	this->nextSpinDate = -1;
}

User::User(int id, string fullName, string username, string Email, string password,
	string phoneNumber, int points, float balance,
	unordered_map<string, Footballer*> mainSquad, unordered_map<string, Footballer*> substitutionSquad,
	time_t lastDatePlayedWheel, time_t nextSpinDate) {
	this->fullName = fullName;
	this->username = username;
	this->password = password;
	this->phoneNumber = phoneNumber;
	this->Email = Email;
	this->id = id;
	this->points = points;
	this->balance = balance;
	this->TheMainSquad = mainSquad;
	this->SubstitutionSquad = substitutionSquad;
	this->lastDatePlayedWheel = lastDatePlayedWheel;
	this->nextSpinDate = nextSpinDate;
}


void User::SetFullName(string fullName)
{
	this->fullName = fullName;
}

void User::SetUsername(string username)
{
	this->username = username;
}

void User::SetPassword(string password)
{
	this->password = password;
}

void User::SetPhoneNumber(string phoneNumber)
{
	this->phoneNumber = phoneNumber;
}

void User::SetEmail(string Email)
{
	this->Email = Email;
}

void User::SetId(int id)
{
	this->id = id;
}


void User::SetPoints(int points)
{
	this->points = points;
}

void User::AddPoints(int points)
{
	this->points += points;
}

void User::SetBalance(float balance)
{
	this->balance = balance;
}

void User::addBalance(float balance)
{
	this->balance += balance;
}

bool User::playWheel() {
	if (!canPlayNextSpin()) {
		int remainingMinutes = remainingMinutesUntilNextSpin();
		cout << "Next spin in " << remainingMinutes << " minutes." << endl;
		system("pause");
		system("cls");
		return false;
	}

	cout << this->lastDatePlayedWheel << endl;
	this->lastDatePlayedWheel = time(nullptr);
	scheduleNextSpin();
	return true;
}

int User::remainingMinutesUntilNextSpin() const {
	time_t currentTime = time(nullptr);
	int remainingSeconds = nextSpinDate - currentTime;
	int remainingMinutes = remainingSeconds / 60;

	return remainingMinutes + 1;
}

void User::scheduleNextSpin() {
	this->nextSpinDate = this->lastDatePlayedWheel + 180;
}
bool User::canPlayNextSpin() const {
	time_t currentTime = time(nullptr);

	return currentTime >= this->nextSpinDate;
}

string User::GetFullName()
{
	return fullName;
}


bool User::SetFootballer(Footballer* footballer)
{
	if (this->TheMainSquad.count(footballer->GetName()) > 0 || this->SubstitutionSquad.count(footballer->GetName()) > 0)
	{
		cout << "You have this player already!" << endl;
		return false;
	}
	if (TheMainSquad.size() < 11)
	{

		TheMainSquad.insert_or_assign(footballer->GetName(), footballer);
		return true;
	}
	else if (TheMainSquad.size() == 11 && SubstitutionSquad.size() < 4) {
		SubstitutionSquad.insert_or_assign(footballer->GetName(), footballer);
		return true;
	}
	else if (TheMainSquad.size() == 11 && SubstitutionSquad.size() == 4)
	{
		cout << "Your team is full!" << endl;
		cout << "You can only replace players to add new players" << endl;
		return false;
	}
}

string User::GetUsername()
{
	return username;
}
string User::GetPassword()
{
	return password;
}

string User::GetPhoneNumber()
{
	return phoneNumber;
}

string User::GetEmail()
{
	return Email;
}

int User::GetId()
{
	return id;
}


int User::GetPoints()
{
	return points;
}

float User::GetBalance()
{
	return balance;
}

unordered_map<string, Footballer*>& User::GetMainSquad()
{
	return this->TheMainSquad;
}

unordered_map<string, Footballer*>& User::GetSubstitutionSquad()
{
	return this->SubstitutionSquad;
}

queue<Game>& User::GetUserGames()
{
	return this->UserGames;
}

time_t User::getLastDatePlayedWheel() const {
	return this->lastDatePlayedWheel;
}
time_t User::getNextSpinDate() const {
	return this->nextSpinDate;
}
string User::formatDate(time_t date) const {
	struct tm timeinfo;
	stringstream ss;

	localtime_s(&timeinfo, &date);
	cout << date << endl;
	ss << put_time(&timeinfo, "%Y-%m-%d %H:%M:%S");

	return ss.str();
}

bool User::hasFootballer(string& footballerName) {
	return TheMainSquad.find(footballerName) != TheMainSquad.end() || SubstitutionSquad.find(footballerName) != SubstitutionSquad.end();
}

void User::handleLuckyWheelResult(pair<string, pair<float, Footballer*>>* result, User& user) {
	string choice;
	if (!result->first.empty()) {
		string& footballerName = result->first;
		float discount = result->second.first;
		Footballer* footballer = result->second.second;

		// Calculate discounted price
		float discountedPrice = footballer->calculateDiscountedPrice(discount);

		// Check if the user already has the footballer
		if (hasFootballer(footballerName)) {
			cout << "You already have this player in your main or substitution squad!" << endl;
			return;
		}
	invalid:
		// Print footballer name and discounted price
		cout << footballerName << endl;
		cout << "Price before -> " << footballer->GetPrice() << "\n(Discounted) Price -> " << discountedPrice << endl;
		cout << "1-Buy\n2-Replace\n3-Go back" << endl;
		cin >> choice;
		if (choice == "1")
		{
			buyFunction(&user, footballer);
			system("pause");
			system("cls");
		}
		else if (choice == "2")
		{
			Format433(user.GetMainSquad(), "Your player");
			cout << "\n\n\n";
			replace(&user, footballer);
			system("pause");
			system("cls");
		}
		else if (choice == "3")
		{
			system("cls");
			return;
		}
		else {
			cout << "Invalid input. Please try again." << endl;
			system("cls");
			goto invalid;
		}
	}
}