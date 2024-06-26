#include "UserValidations.h"

void UserValidations::signupinfo(User* newUser, string info, bool (*Check)(string), void (User::* set)(string))
{
	string input;
invalid:
	cout << User::spacing(60, ' '); cout << "Enter your " << info << ": " << endl;
	cout << User::spacing(60, ' '); getline(cin >> ws, input);
	(newUser->*set)(input);
	if (Check(input) == false)
	{
		goto invalid;
	}
}
bool UserValidations::fullnameCheck(string fullName)
{
	regex pattern(R"([A-z]+(?: [A-z]+)*)");
	bool result = regex_match(fullName, pattern);
	if (!result)
	{
		cout << "You must provide a valid Fullname with no numbers or special character ." << endl;
		return false;
	}
	else
	{
		return true;
	}
};
bool UserValidations::phoneNumberCheck(string phoneNumber)
{
	regex pattern(R"(\d{11})");
	bool result = regex_match(phoneNumber, pattern);
	if (!result)
	{
		cout << "You must provide a valid phone number with no letters and contain 11 digits." << endl;
		return false;
	}
	else
	{
		return true;
	}
};
bool UserValidations::passwordCheck(string password)
{
	bool result = true;
	regex specialChar_pattern(R"([!@#$%]+)");
	regex number_pattern(R"([\d]+)");



	if (password.length() < 8)
	{
		cout << "Too short password!." << endl;
		cout << "You must provide a valid password with length greater than 8" << endl;
		result = false;
	}

	if (!regex_search(password, specialChar_pattern))
	{
		cout << "Too easy password!" << endl;
		cout << "You must provide a valid password with at least 1 special character" << endl;
		result = false;
	}
	if (!regex_search(password, number_pattern))
	{
		cout << "Too easy password!" << endl;
		cout << "You must provide a valid password with at least 1 number" << endl;
		result = false;
	}

	if (regex_match(password, number_pattern))
	{
		cout << "Too easy password!" << endl;
		cout << "You must provide a valid password with numbers and characters" << endl;
		result = false;
	}
	return result;
};
bool UserValidations::usernameCheck(unordered_map<string, User> *users, User &Newser)
{
	string input;
invalid:
	cout << User::spacing(60, ' ') << "Enter your " << "Username" << ": " << endl;
	cout << User::spacing(60, ' '); getline(cin >> ws, input);
	auto it = users->find(input);
	if (it == users->end())
	{
		Newser.SetUsername(input);
		return true;
	}
	else
	{
		cout << "Username already in use!" << endl;
		cout << "Please enter another username" << endl;
		goto invalid;
	}
};

bool UserValidations::emailAddressCheck(string emailAddress)
{
	regex pattern(R"([A-z0-9\.]+@[A-z0-9]+\.[A-z]+)");
	bool result = regex_match(emailAddress, pattern);
	if (!result)
	{
		cout << "You must provide a valid Email Address." << endl;
		return false;
	}
	else
	{
		return true;
	}
};
