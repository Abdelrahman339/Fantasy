#include <iostream>
using namespace std;
class User
{
protected:
    string fullName;
    string username;
    string password;
    string phoneNumber;
    string Email;
    int id;
    int rank;
    int points;

public:
    void login();
    void signup();
};
