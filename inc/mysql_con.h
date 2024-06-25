#ifndef MYSQLCON_H
#define MYSQLCON_H

#include<iostream>
#include <mysql_driver.h>
#include <mysql_connection.h>
#include <cppconn/statement.h>
#include <cppconn/exception.h>

using namespace std;
using namespace sql::mysql;

class MysqlCon{
  private:
    MySQL_Driver* driver_;
    sql::Connection* con_;
    sql::Statement* stmt_;

  public:
    MysqlCon();
    sql::ResultSet* Query(string sql);
    void Execute(string sql);
    static MysqlCon *GetObject();
    ~MysqlCon();

};

#endif