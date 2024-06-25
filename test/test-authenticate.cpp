#include<iostream>
#include "../inc/mysql_con.h"

using namespace std;

sql::mysql::MySQL_Driver *driver= sql::mysql::get_mysql_driver_instance();
unique_ptr<sql::Connection> con(driver->connect("tcp://localhost:3306", "japkirat", "password"));
unique_ptr<sql::Statement> stmt(con->createStatement());

bool CheckUsername(string username){

    try {
        
        // Connect to the specific database
        con->setSchema("mydatabase");

        // Execute a query to check if the name exists
        sql::ResultSet* res(stmt->executeQuery("SELECT COUNT(*) AS count FROM Customers WHERE first_name = '" + username + "'"));

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

    return false; 
}

string IfUsernameExists(){
    string User;
    for(int i=0;i<5;i++){
        cout<<"Enter your username : ";
        getline(cin,User);
        if(CheckUsername(User)){
            return User;
            break;
        } else {
            throw runtime_error("Username dosen't exist");
            continue;
        }
    }
    return User;
}

int main(){

    string username,pass;
    for(int i=0;i<5;i++){
        try {
            username = IfUsernameExists();
            cout<<username;
            break;
        } catch(const runtime_error &e) {
            cerr << e.what() << endl;
            continue;
        }
    }

    cout<<username<<endl;
    
    sql::ResultSet* res = stmt->executeQuery("SELECT last_name FROM Customers WHERE first_name='"+username+"';");
    if (res->next()) {
        pass = res->getString("last_name");
        cout<<pass;
    }
        
    string checkpass;
    int i=0;
    for (i=0;i<3;i++){
        cout<<"Enter your account password : ";
        getline(cin,checkpass);

        if(checkpass.compare(pass) == 0){
            break;
        }
        if(i==2){
            cout<<"Too many attempts, try later."<<endl;
        }
        else{
            cout<<"Entered password is incorrect."<<endl;
            continue;
        }   
    }
}