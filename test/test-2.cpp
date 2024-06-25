#include<iostream>
#include <mysql_driver.h>
#include <mysql_connection.h>
#include <cppconn/statement.h>
#include <cppconn/exception.h>
#include <sstream>

using namespace std;
using namespace sql::mysql;

class testData {
    public:
        int id;
        std::string name;
        int age;
        void dataTry();
}a;

void testData :: dataTry(){
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

    std::string arr[] = {"id","age"};
    //std::string arr1[2];
    std::stringstream queryStream;
    //int size = sizeof(arr)/sizeof(string);
    //cout<<size<<endl;
    //int x=0;
    for(int i=0;i<2;i++){
        queryStream << "SELECT " << arr[i] << " FROM testData where id =1";
        std::string getdetails = queryStream.str();
        cout<<getdetails<<endl;
        sql::ResultSet* res1(stmt->executeQuery(getdetails));
        if (res1->next()) {
            arr[i] = res1->getString(arr[i]);
            cout<<arr[i]<<endl;
        }
        delete res1;
    }
}

int main(){
    a.dataTry();
    return 0;
}