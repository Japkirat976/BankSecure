#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include <mysql_driver.h>
#include <mysql_connection.h>
#include <iostream>
#include <string>

using namespace std;
using namespace sql;

bool nameExists(const string &name) {
    try {
        // Create a MySQL driver instance
        sql::mysql::MySQL_Driver *driver = sql::mysql::get_mysql_driver_instance();

        // Establish a connection to the database
        unique_ptr<sql::Connection> con(driver->connect("tcp://localhost:3306", "japkirat", "password"));

        // Connect to the specific database
        con->setSchema("mydatabase");

        // Create a statement object
        unique_ptr<sql::Statement> stmt(con->createStatement());

        // Execute a query to check if the name exists
        sql::ResultSet* res(stmt->executeQuery("SELECT COUNT(*) AS count FROM Customers WHERE first_name = '" + name + "'"));

        // Process the result
        if (res->next()) {
            int count = res->getInt("count");
            return count > 0;  // Return true if the name exists
        }
    } catch (sql::SQLException &e) {
        cerr << "SQLException: " << e.what() << endl;
        cerr << "SQLState: " << e.getSQLState() << endl;
        cerr << "ErrorCode: " << e.getErrorCode() << endl;
    }

    return false;  // Return false if the name does not exist or an exception occurs
}

string nameToCheck;
void SetUsername(){
    for(int i=0;i<2;i++){
        cout << "Enter the name to check: ";
        cin >> nameToCheck;
        if(nameExists(nameToCheck)){
            throw runtime_error("Username already exists");
            continue;
        } else {
            break;
        }
    }
}

int main() {
    for(int i=0;i<5;i++){
        try{
            SetUsername();
            cout<<nameToCheck;
            break;
        } catch (const runtime_error &e) {
            cerr << "Error: " << e.what() << endl;
            continue;
        }
    }
    // string nameToCheck;
    // cout << "Enter the name to check: ";
    // cin >> nameToCheck;

    // if (nameExists(nameToCheck)) {
    //     cout << "The name " << nameToCheck << " exists in the database." << endl;
    // } else {
    //     cout << "The name " << nameToCheck << " does not exist in the database." << endl;
    // }

    return 0;
}
