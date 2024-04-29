#include <iostream> 
//files
#include "User.h"
#include "Competition.h"
#include "Admin.h"
#include "Game.h"

//data structures
#include <unordered_map>


int main() {


	cout << "Code is running now" << endl;

}

/*
*
* /////Important notes for used data structure :

 Hash table : to store all users in the application.

 linked list of Games: this lined list will contain all the matches in the application. The matches will be a static data will be in GameFile.txt this file will have all data for all mtaches in all the leagues.this linekd list will be static for all users.

 hash table of Footballers: this vector will have a 11 player from the same team .the data of footballers will be stored in TeamFile.txt . this file will have the information about each team and the info for the footballers in this team.This vector will be in class "team".

 queue of Games: this deque will contain mtaches but it will  depend on the user squad . this queue will be different for each user.

 stack of string and set:internal usage in functions.


*/

//notes for functions:
/*
to calculate the footballers points and update the price : will use the linked list of all matches.

to calcualte the user points and get money for every player score form his squad: will use the deque of games.

to calcualte the points of each team: will use the linekd list of all games.

to edit on users: will use the hash table of all users and the functions on user file but with modifications.


*/


/*
class team : should contain the name ,the id ,the points , number of wins ,nubmer of draws and number of losses.
*/

