#include <iostream>
#include <string>
#include <conio.h>
#include "UserValidiation.h"
#include "User.h"
using namespace std;
bool loginstat = false;

void User::homePage(unordered_map<string, User> &Users)
{
    int choice;
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
    login:
        int count = 0;
        string user;
        string pass;
        system("cls");
        do
        {
            cout << "Log-in\n------------\n\n";
            cout << "Username: ";
            cin >> user;
            cout << "Password(Press '+' to show password): " << endl;
            pass = hidePassword(user);
            User CruentUser = login(Users, user, pass);
            if (loginstat == true)
            {
                system("pause");
                system("cls");
                userMenu(&CruentUser);
            }
            else
            {
                count++;
                cout << "Try again..\t" << count << " / 3\n";
                system("pause");
                system("cls");
            }
        } while (count != 3);
    }
    else if (choice == 3)
    {
        signup(Users);
        system("pause");
        goto login;
    }
    else
    {
        cout << "Please enter a valid choice" << endl;
        goto choice;
    }
};

User User::login(unordered_map<string, User> &users, string username, string password)
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
        return User();
    }
};

void User::signup(unordered_map<string, User> &Users)
{
    User newUser;
    cout << "Sign up" << endl;
    UserValidiation::signupinfo(&newUser, "fullname", UserValidiation::fullnameCheck, &User::SetFullName);
    UserValidiation::usernameCheck(Users,newUser);
    UserValidiation::signupinfo(&newUser, "Password", UserValidiation::passwordCheck, &User::SetPassword);
    UserValidiation::signupinfo(&newUser, "PhoneNumber", UserValidiation::phoneNumberCheck, &User::SetPhoneNumber);
    UserValidiation::signupinfo(&newUser, "EmailAddress", UserValidiation::emailAddressCheck, &User::SetEmail);
    Users.insert_or_assign(newUser.username, newUser);
}
void User::userMenu(User *currentUser)
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
};
string User::hidePassword(string username)
{
    string Minput, print;
    char input;
    input = getch();
    while (input != 13)
    {
        if (input == 8)
        {
            if (print.size() == 0)
            {
                print = "";
                Minput = "";
            }
            else
            {
                print.resize(print.size() - 1);
                cout << print;
                Minput.resize(Minput.size() - 1);
            }
        }
        else if (input == 43)
        {

            cout << Minput;
        }
        else
        {
            print.push_back('*');
            cout << print;
            Minput.push_back(input);
        }
        input = getch();
        system("cls");
        cout << "Log-in\n------------\n\n"; // the display
        cout << "Username: ";
        cout << username << endl;
        cout << "Password(Press '+' to show password): " << endl;
    }
    cout << endl;
    return Minput;
};