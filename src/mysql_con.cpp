#include<iostream>
#include <mysql_driver.h>
#include <mysql_connection.h>
#include <cppconn/statement.h>
#include <cppconn/exception.h>
#include "../inc/mysql_con.h"

using namespace std;
using namespace sql::mysql;

MysqlCon::MysqlCon() {
    try {
        // Initialize the MySQL driver
        driver_ = sql::mysql::get_mysql_driver_instance();
        
        // Create a connection to the MySQL server
        con_ = driver_->connect("tcp://localhost:3306", "japkirat", "password"); // Adjust the IP, username, and password accordingly
        
        // Create a new statement
        stmt_ = con_->createStatement();
        stmt_->execute("USE bankDatabase");

    } 
    
    catch (sql::SQLException &e) {
        cerr << "SQLException: " << e.what() << endl;
        cerr << "MySQL error code: " << e.getErrorCode() << endl;
        cerr << "SQLState: " << e.getSQLState() << endl;
    }
}

sql::ResultSet* MysqlCon::Query(string sql){
    return stmt_->executeQuery(sql);
}

void MysqlCon::Execute(string sql){
    stmt_->execute(sql);
}

MysqlCon *MysqlCon::GetObject() {
    static MysqlCon *my_db_object = nullptr;

    if(my_db_object == nullptr) {
        my_db_object = new MysqlCon();
    }

    return my_db_object;
}

MysqlCon::~MysqlCon() {
    delete con_;
    delete stmt_;
}
