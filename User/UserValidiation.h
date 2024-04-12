#include <iostream>
#include "User.h"
using namespace std;
class UserValidiation
{

public:
    bool static fullnameCheck(string fullName){};
    bool static phoneNumberCheck(string phoneNumber){};
    bool static emailAddressCheck(string emailAddress){};
    bool static passwordCheck(string password){};
    bool static usernameCheck(string username){};
    void static signupinfo(User *newUser, string point, bool (*Check)(string), void (User::*set)(string)){};
};