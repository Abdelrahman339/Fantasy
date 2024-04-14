#include "UserValidiation.h"
#include <regex>
#include <iostream>
using namespace std;
void static signupinfo(User *newUser, string info, bool (*Check)(string), void (User::*set)(string))
{
    string input;
invalid:
    cout << "Enter you " << info << ": " << endl;
    getline(cin >> ws, input);
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
    regex specialChar_pattern(R"([!@#$%^&*-_=+<>])");
    regex numberandchar_pattern(R"([\d\w])");

    if (password.length() < 8)
    {
        cout << "Too short password!." << endl;
        cout << "You must provide a valid password with leanght greater than 8" << endl;
        return false;
    }

    else if (!regex_search(password, specialChar_pattern))
    {
        cout << "Too easy password!" << endl;
        cout << "You must provide a valid password with atleast 1 special charachter" << endl;
        return false;
    }
    else if (!regex_search(password, numberandchar_pattern))
    {
        cout << "Too easy password!" << endl;
        cout << "You must provide a valid password with atleast 1 charachter and number" << endl;
        return false;
    }
    else
    {
        return true;
    }
};
bool UserValidiation::usernameCheck(unordered_map<string, User> users, User &newuser)
{
    string input;
invalid:
    cout << "Enter you "<< "Username"<< ": " << endl;
    getline(cin >> ws, input);
    auto it = users.find(input);
    if (it == users.end())
    {
    newuser.SetUsername(input);
        return true;
    }
    else
    {
        cout << "Username already in use!" << endl;
        cout << "Please enter another username" << endl;
        goto invalid;
    }
};

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
