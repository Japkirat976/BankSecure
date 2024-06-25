#include "../inc/mysql_con.h"
#include<sstream>
#include<iostream>
#include<string>

int main(){
    
    MysqlCon *mydb = MysqlCon::GetObject();

    try {
        mydb->Execute("use mydatabase;");
    } catch (sql::SQLException &e) {
        cerr << "SQLException: " << e.what() << endl;
        cerr << "MySQL error code: " << e.getErrorCode() << endl;
        cerr << "SQLState: " << e.getSQLState() << endl;
    }

    sql::ResultSet *res = mydb->Query("select * from transactions;");
     while (res->next()) {
        // You can use either numeric offsets...
        cout << "trid id = " << res->getInt(1)<<endl; // getInt(1) returns the first column
    }

    MysqlCon *mydb1 = MysqlCon::GetObject();

    if(mydb == mydb1) {
        cout << "mydb and mydb1 are same"<<endl;
    } else {
        cout << "mydb and mydb1 differ, singleton not working"<<endl;
    }
    
    res = mydb1->Query("select * from Orders;");
    while (res->next()) {
        // You can use either numeric offsets...
        cout << "order id = " << res->getInt(1)<<endl; // getInt(1) returns the first column
    }
    int id = 1;
    int amt = 70531;
    string type = "withdraw";

    std::stringstream queryStream1;
    // Start building the query
    queryStream1 << "INSERT INTO transactions (account_id,amount,transaction_type) VALUES (" 
                << id << "," 
                << amt << ",'" 
                << type << "');"; 
    std::string addCustomerDetails = queryStream1.str();
    mydb->Execute(addCustomerDetails);
    

    delete mydb;
}