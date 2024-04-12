#include "UserValidiation.h"
#include <regex>
#include <iostream>
using namespace std;
bool UserValidiation::fullnameCheck(string fullName)
{
    regex pattern(R"([^a-zA-Z\s])");
    bool result = regex_search(fullName, pattern);
    if (result)
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
    regex pattern(R"([a-zA-Z])?|[^a-zA-Z0-9])");
    bool result = regex_search(phoneNumber, pattern);
    if (phoneNumber.length() < 11)
    {
        cout << "You must provide a valid phone number that contain 11 digits." << endl;
        return false;
    }
    else if (result)
    {
        cout << "You must provide a valid phone number with no letters." << endl;
        return false;
    }
    else
    {
        return true;
    }
};
bool UserValidiation::passwordCheck(string password)
{
    regex pattern(R"([^a-zA-Z]|)");
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
bool UserValidiation::usernameCheck(string username){return true;};

bool UserValidiation::emailAddressCheck(string emailAddress){return true;};
void static signupinfo(User *newUser, string point, bool (*Check)(string), void (User::*set)(string))
{
    string input;
point:
    cout << "Enter you" << point << ": " << endl;
    getline(cin, input);
    (newUser->*set)(input);
    cin >> ws;
    if (Check == false)
    {
        goto point;
    }
}