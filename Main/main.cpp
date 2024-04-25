#include <iostream> 
//files
#include "User.h"
#include "Competition.h"
#include "Admin.h"
#include "Game.h"

//data structures
#include <unordered_map>

//databse
#include <cppconn/driver.h> 
#include <cppconn/exception.h> 
#include <cppconn/statement.h> 
#include <mysql_connection.h> 
#include <mysql_driver.h>
#include<Admin.h>
#include<User.h>
#include<unordered_map>

using namespace std;
using namespace sql;
using namespace mysql;

int main() {


	//try {
	//	Driver* driver;
	//	Connection* con;

	//	string host = "tcp://127.0.0.1:3306";
	//	string user = "root";
	//	string password = "admin";
	//	string database = "fantasy";

	//	driver = get_mysql_driver_instance();
	//	con = driver->connect(host, user, password);

	//	if (con) {
	//		cout << "Connected to MySQL database server successfully!" << endl;

	//		// Create a statement object
	//		Statement* stmt = con->createStatement();

	//		// SQL statement to create the table
	//		string query = "INSERT INTO fantasy.soccer_league (rankf, team_name, matches_played, wins, draws, losses, goals_for, goals_against, points) VALUES(14, 'Elche', 38, 11, 9, 18, 40, 52, 42),(15, 'Getafe', 38, 8, 15, 15, 33, 41, 39),(16, 'Mallorca', 38, 10, 9, 19, 36, 63, 39),(17, 'Cadiz CF', 38, 8, 15, 15, 35, 51, -16),(18, 'Granada CF', 38, 8, 14, 16, -46, -17, -38),(19, 'Levante', 38, 8, -11, -19, -57, -25, -35),(20, 'Alaves', 38, -8, -7, -23, -31, -65, -34); ";

	//		// Execute the query
	//		stmt->execute(query);

	//		//cout << "Table 'fantasy' created successfully!" << endl;

	//		delete stmt;
	//	}
	//	
	//	else
	//		cout << "Failed to connect to database!" << endl;

	//	delete con;

	//}
	//catch (SQLException& e) {
	//	cout << "An error occurred: " << e.what() << endl;
	//}

	//return 0;
}

/*
*
* /////Important notes for used data structure :

 Hash table : to store all users in the application.

 linked list of Games: this lined list will contain all the matches in the application. The matches will be a static data will be in GameFile.txt this file will have all data for all mtaches in all the leagues.this linekd list will be static for all users.

 vecotr of Footballers: this vector will have a 11 player from the same team .the data of footballers will be stored in TeamFile.txt . this file will have the information about each team and the info for the footballers in this team.This vector will be in class "team".

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

