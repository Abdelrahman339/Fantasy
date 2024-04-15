#include <iostream>
#include "User.h"
#include "UserValidiation.h"
#include <unordered_map>
using namespace std;
int main(){
	User newuser;
	unordered_map<string, User> usres;
	newuser.homePage(usres);

}