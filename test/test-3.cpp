#include<iostream>
#include <mysql_driver.h>
#include <mysql_connection.h>
#include <cppconn/statement.h>
#include <cppconn/exception.h>

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
        
        stmt->query("USE mydatabase");
    } 
    
    catch (sql::SQLException &e) {
        cerr << "SQLException: " << e.what() << endl;
        cerr << "MySQL error code: " << e.getErrorCode() << endl;
        cerr << "SQLState: " << e.getSQLState() << endl;
    }

    int id = 1;
    int TotalAmount;

    sql::ResultSet* TA(stmt->executeQuery("SELECT amount,transaction_date FROM transactions WHERE account_id = '"+to_string(id)+"';"));
    while (TA->next()) {
            TotalAmount = TA->getString("amount");
            std::string timestamp = TA->getString("transaction_date");
            std::cout << "TimeStamp : " << timestamp << std::endl;
    }
    std::cout << "Amount: " << TotalAmount << std::endl;

}