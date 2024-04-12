#include <iostream>
#include "UserValidiation.h"
#include "User.h"
using namespace std;
bool loginstat = false;

void User::homePage(unordered_map<string, User> &Users)
{
    int choice;
choice:
    cout << "Welcome to Fantasy game!" << endl;
    cout << "It's time for another season of fantasy football glory!" << endl;
    cout << "1-Admin \n 2- login \n 3-sign up" << endl;
    cout << "Enter your option" << endl;
    cin >> choice;
    if (choice == 1)
    {
        // admin
    }
    else if (choice == 2)
    {
        string username;
        string password;
        cout << "Login page" << endl;
    credentials:
        cout << "Please enter your username" << endl;
        cin >> username;
        cout << "Please enter your password" << endl;
        cin >> password;
        login(Users, username, password);
        if (loginstat == true)
        {
            userMenu();
        }
        else
        {
            goto credentials;
        }
    }
    else if (choice == 3)
    {
        signup(Users);
    }
    else
    {
        cout << "Please enter a valid choice" << endl;
        goto choice;
    }
};

User login(unordered_map<string, User> &users, string username, string password)
{
    if (users[username].GetPassword() == password)
    {
        cout << "Login successful!" << endl;
        cout << "Welcome back boss!" << endl;
        loginstat = true;
        return users.at(username);
    }
    else
    {
        cout << "Login failed!. Please make sure of your username and password" << endl;
        return;
    }
};

void User::signup(unordered_map<string, User> &Users)
{
    User newUser;
    cout << "Sign up" << endl;
    UserValidiation::signupinfo(&newUser, "fullname", UserValidiation::fullnameCheck, SetFullName);
    UserValidiation::signupinfo(&newUser, "userName", UserValidiation::usernameCheck, SetUsername);
    UserValidiation::signupinfo(&newUser, "Password", UserValidiation::passwordCheck, SetPassword);
    UserValidiation::signupinfo(&newUser, "PhoneNumber", UserValidiation::phoneNumberCheck, SetPhoneNumber);
    UserValidiation::signupinfo(&newUser, "EmailAddress", UserValidiation::emailAddressCheck, SetEmail);
    Users.insert_or_assign(newUser.username, newUser);
}
void User::userMenu()
{
    int choice;
choice:
    cout << "Main Menu" << endl;
    cout << "1-Profle \n 2-Squad \n 3-Market \n 4-Play \n 5-logout" << endl;
    cout << "Enter you option..." << endl;
    cin >> choice;
    if (choice == 1)
    {
        // profile function
    }
    else if (choice == 2)
    {
        // squad function
    }
    else if (choice == 3)
    {
        // market function
    }
    else if (choice == 4)
    {
        // play function
    }
    else if (choice == 5)
    {
        // logout function
    }
    else
    {
        cout << "Please select a valid choice." << endl;
        goto choice;
    }
}
void User::squatForamt(int choice){};