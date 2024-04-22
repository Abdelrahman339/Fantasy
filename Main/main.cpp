#include <iostream> 
using namespace std;
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

using namespace sql;
using namespace mysql;

int main()
{



	//try {
	//	MySQL_Driver* driver;
	//	Connection* con;

	//	driver = get_mysql_driver_instance();
	//	con = driver->connect("127.0.0.1",
	//		"root", "password");

	//	con->setSchema("test"); // your database name 

	//	Statement* stmt;
	//	stmt = con->createStatement();

	//	// SQL query to create a table 
	//	string createTableSQL
	//		= "CREATE TABLE IF NOT EXISTS GFGCourses ("
	//		"id INT NOT NULL AUTO_INCREMENT PRIMARY KEY,"
	//		"courses VARCHAR(255) NOT NULL"
	//		")";

	//	stmt->execute(createTableSQL);

	//	string insertDataSQL
	//		= "INSERT INTO GFGCourses (courses) VALUES "
	//		"('DSA'),('C++'),('JAVA'),('PYTHON')";

	//	stmt->execute(insertDataSQL);

	//	// SQL query to retrieve data from the table 
	//	string selectDataSQL = "SELECT * FROM GFGCourses";

	//	ResultSet* res
	//		= stmt->executeQuery(selectDataSQL);

	//	// Loop through the result set and display data 
	//	int count = 0;
	//	while (res->next()) {
	//		cout << " Course " << ++count << ": "
	//			<< res->getString("courses") << endl;
	//	}

	//	delete res;
	//	delete stmt;
	//	delete con;
	//}
	//catch (SQLException& e) {
	//	std::cerr << "SQL Error: " << e.what() << std::endl;
	//}

	//return 0;
}


/*
*
* /////Important notes for used data structure :

 Hash table : to store all users in the application.

 linked list of Games: this lined list will contain all the matches in the application. The matches will be a static data will be in GameFile.txt this file will have all data for all mtaches in all the leagues.this linekd list will be static for all users.

 vecotr of Footballers: this vector will have a 11 player from the same team .the data of footballers will be stored in TeamFile.txt . this file will have the information about each team and the info for the footballers in this team.This vector will be in class "team".

 deque of Games: this deque will contain mtaches but it will  depend on the user squad . this deque will be different for each user.

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

