#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include <mysql_driver.h>
#include <mysql_connection.h>
#include <iostream>
#include <string>
#include "../inc/kyc.h"

using namespace std;
using namespace sql;

int main(){
    try {
        KYC kyc;
        sql::mysql::MySQL_Driver *driver= sql::mysql::get_mysql_driver_instance();
        unique_ptr<sql::Connection> con(driver->connect("tcp://localhost:3306", "japkirat", "password"));
        unique_ptr<sql::Statement> stmt(con->createStatement());

        // Connect to the specific database
        con->setSchema("bankDatabase");

        sql::ResultSet* res1 = stmt->executeQuery("SELECT * FROM KYCDetails WHERE CustomerID = 7;");
        if (res1->next()) {
            kyc.id_number_ = res1->getString("IDNumber");
            kyc.id_type_ = res1->getString("IDType");
            kyc.id_issue_date_ = res1->getString("IDIssueDate");
            kyc.id_expiry_date_ = res1->getString("IDExpiryDate");
            kyc.nominee_name_ = res1->getString("NomineeName");
            kyc.nominee_relationship_ = res1->getString("NomineeRelationship");
        }

        std::cout << "ID Number : " << kyc.id_number_ << std::endl;
        std::cout << "ID Type : " << kyc.id_type_ << std::endl;
        std::cout << "ID Issue Date : " << kyc.id_issue_date_ << std::endl;
        std::cout << "ID Expiry Date : " << kyc.id_expiry_date_ << std::endl;
        std::cout << "Nominee Name : " << kyc.nominee_name_ << std::endl;
        std::cout << "Nominee Relationship : " << kyc.nominee_relationship_ << std::endl;

    } catch (sql::SQLException &e) {
        cerr << "SQLException: " << e.what() << endl;
        cerr << "SQLState: " << e.getSQLState() << endl;
        cerr << "ErrorCode: " << e.getErrorCode() << endl;
    }
}