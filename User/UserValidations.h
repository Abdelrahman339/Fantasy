#pragma once
#include <iostream>
#include "User.h"
using namespace std;
class UserValidations
{

public:
    bool static fullnameCheck(string fullName);
    bool static phoneNumberCheck(string phoneNumber);
    bool static emailAddressCheck(string emailAddress);
    bool static passwordCheck(string password);
    bool static usernameCheck(unordered_map<string, User> users, User& newuser);
    void static signupinfo(User* newUser, string info, bool (*Check)(string), void (User::* set)(string));
};