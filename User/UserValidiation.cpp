#include "UserValidiation.h"
#include <regex>
#include <iostream>
using namespace std;
void static signupinfo(User *newUser, string info, bool (*Check)(string), void (User::*set)(string))
{
    string input;
invalid:
    cout << "Enter you " << info << ": " << endl;
    cin.ignore();
    getline(cin, input);
    (newUser->*set)(input);
    if (Check(input) == false)
    {
        goto invalid;
    }
}
bool UserValidiation::fullnameCheck(string fullName)
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
bool UserValidiation::phoneNumberCheck(string phoneNumber)
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
bool UserValidiation::passwordCheck(string password)
{
    regex pattern(R"([^a-zA-Z0-9]+)");
    bool result = regex_search(password, pattern);
    if (password.length() < 8)
    {
        cout << "Too short password" << endl;
        cout << "You must provide a valid password with length greater than 8." << endl;
        return false;
    }
    else if (result)
    {
        return true;
    }
};
bool UserValidiation::usernameCheck(string username) { return true; };

bool UserValidiation::emailAddressCheck(string emailAddress)
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
