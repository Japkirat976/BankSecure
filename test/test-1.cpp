#include<iostream>
#include <mysql_driver.h>
#include <mysql_connection.h>
#include <cppconn/statement.h>
#include <cppconn/exception.h>
#include <sstream>


using namespace std;
using namespace sql::mysql;

int main(){
    MySQL_Driver* driver;
    sql::Connection* con;
    sql::Statement* stmt;
    try {
        // Initialize the MySQL driver
        driver = sql::mysql::get_mysql_driver_instance();
        
        // Create a connection to the MySQL server
        con = driver->connect("tcp://localhost:3306", "japkirat", "password"); // Adjust the IP, username, and password accordingly
        
        // Create a new statement
        stmt = con->createStatement();
        
        stmt->execute("USE mydatabase");
    } 
    
    catch (sql::SQLException &e) {
        cerr << "SQLException: " << e.what() << endl;
        cerr << "MySQL error code: " << e.getErrorCode() << endl;
        cerr << "SQLState: " << e.getSQLState() << endl;
    }

    std::stringstream queryStream;
    queryStream << "SELECT name FROM testData WHERE id = 1;";
    std::string getdetails = queryStream.str();
    string accntMoney="abc";
    sql::ResultSet* res1(stmt->executeQuery(getdetails));    
    if (res1->next()) {
        accntMoney = res1->getString("name");
    }

    cout<<accntMoney;
    return 0;
}