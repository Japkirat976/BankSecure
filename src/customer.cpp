#include<iostream>
#include <mysql_driver.h>
#include <mysql_connection.h>
#include <cppconn/statement.h>
#include <cppconn/exception.h>
#include <sstream>
#include "customer.h"
#include "auth.h"
#include "mysql_con.h"
#include "kyc.h"
#include "account.h"
#include "transactions.h"
#include "screens.h"

using namespace std;
using namespace sql::mysql;

Customer* Customer :: CreateObject(){
    static Customer *c1 = nullptr;

    if(c1 == nullptr) {
        c1 = new Customer();
    }

    return c1;
}

void Customer :: GetData(){

    KYC *kyc = KYC::CreateObject();
    Account *account = Account::CreateObject();
    Auth auth;
    Transactions *trans = Transactions::CreateObject();

    cout<<"Enter your Kyc and Account Details carefully as they cannot be changed."<<endl;

    std::cout << "Enter your first name : ";
    std::getline(std::cin, first_name_);

    std::cout << "Enter your middle name (if any) : ";
    std::getline(std::cin, middle_name_);

    std::cout << "Enter your last name : ";
    std::getline(std::cin, last_name_);

    std::cout << "Enter your date of birth (YYYY-MM-DD) : ";
    std::getline(std::cin, date_of_birth_);

    std::cout << "Enter your gender ('Male', 'Female', 'Other') : ";
    std::getline(std::cin, gender_);

    std::cout << "Enter your nationality : ";
    std::getline(std::cin, nationality_);

    std::cout << "Enter your residential address : ";
    std::getline(std::cin, residential_address_);

    std::cout << "Enter your mailing address (if different) : ";
    std::getline(std::cin, mailing_address_);

    std::cout << "Enter your phone number : ";
    std::getline(std::cin, phone_number_);

    std::cout << "Enter your email address : ";
    std::getline(std::cin, email_address_);

    std::cout<<"Set your bank account username."<<endl;
    username_ = auth.SetUsername();

    std::cout<<"Set your bank account password."<<endl;
    password_ = auth.SetPassword();

    std::cout<<"Set your bank pin (only four digits alloowed) : ";
    std::cin>>card_pin_;
    std::cin.ignore();

    cout<<"Fill up your Kyc Details :"<<endl;
    kyc->GetKycData();
    cout<<"Fill up your Account Details :"<<endl;
    account->GetAccountData();

    int id = CustomerId(username_);
    std::cout<<"Your bank account number is C00"+ std::to_string(id)<<endl;
    std::cout << "Bank account created successfully!" << endl;

}

int Customer :: CustomerId(string user){
    MysqlCon *my_db_object = MysqlCon::GetObject();
    std::stringstream queryStream;
    queryStream << "SELECT CustomerID FROM CustomerDetails WHERE Username = '"<<user<<"'";
    std::string query = queryStream.str();
    sql::ResultSet* res = my_db_object->Query(query);
    int id;
    if (res->next()){
        id = res->getInt("CustomerID");
    }
    return id;
}

void Customer :: EditData(){
    Auth auth;
    Screens screen;
    MysqlCon *my_db_object = MysqlCon::GetObject();
    string username;

    username = auth.Authenticate();

    int change_detail;
    screen.EditScreen();
    cin>>change_detail;

    string new_value;
    cout<<"Enter the value to be changed : ";
    cin>>new_value;

    int id = CustomerId(username);

    for(int i=0;i<3;i++){
        if(change_detail>0 && change_detail<21){
            switch(change_detail){
                case 1 : {
                    std::stringstream queryStream1;
                    queryStream1 << "UPDATE CustomerDetails SET FirstName = '" 
                    << new_value << "' WHERE Username = '"
                    << username << "';"; 
                    std::string editDetails = queryStream1.str();
                    my_db_object->Execute(editDetails);
                    cout<<"Value Updated"<<endl;
                    break;
                }
            
                case 2 : {
                    std::stringstream queryStream1;
                    queryStream1 << "UPDATE CustomerDetails SET MiddleName = '" 
                    << new_value << "' WHERE Username = '"
                    << username << "';"; 
                    std::string editDetails = queryStream1.str();
                    my_db_object->Execute(editDetails);
                    cout<<"Value Updated"<<endl;
                    break;
                }      

                case 3 : {
                    std::stringstream queryStream1;
                    queryStream1 << "UPDATE CustomerDetails SET LastName = '" 
                    << new_value << "' WHERE Username = '"
                    << username << "';"; 
                    std::string editDetails = queryStream1.str();
                    my_db_object->Execute(editDetails);
                    cout<<"Value Updated"<<endl;
                    break;
                }

                case 4 : {
                    std::stringstream queryStream1;
                    queryStream1 << "UPDATE CustomerDetails SET DateOfBirth = '" 
                    << new_value << "' WHERE Username = '"
                    << username << "';"; 
                    std::string editDetails = queryStream1.str();
                    my_db_object->Execute(editDetails);
                    cout<<"Value Updated"<<endl;
                    break;
                }

                case 5 : {
                    std::stringstream queryStream1;
                    queryStream1 << "UPDATE CustomerDetails SET Gender = '" 
                    << new_value << "' WHERE Username = '"
                    << username << "';"; 
                    std::string editDetails = queryStream1.str();
                    my_db_object->Execute(editDetails);
                    cout<<"Value Updated"<<endl;
                    break;
                }

                case 6 : {
                    std::stringstream queryStream1;
                    queryStream1 << "UPDATE CustomerDetails SET Nationality = '" 
                    << new_value << "' WHERE Username = '"
                    << username << "';"; 
                    std::string editDetails = queryStream1.str();
                    my_db_object->Execute(editDetails);
                    cout<<"Value Updated"<<endl;
                    break;
                }

                case 7 : {
                    std::stringstream queryStream1;
                    queryStream1 << "UPDATE CustomerDetails SET ResidentialAddress = '" 
                    << new_value << "' WHERE Username = '"
                    << username << "';"; 
                    std::string editDetails = queryStream1.str();
                    my_db_object->Execute(editDetails);
                    cout<<"Value Updated"<<endl;
                    break;
                }

                case 8 : {
                    std::stringstream queryStream1;
                    queryStream1 << "UPDATE CustomerDetails SET MailingAddress = '" 
                    << new_value << "' WHERE Username = '"
                    << username << "';"; 
                    std::string editDetails = queryStream1.str();
                    my_db_object->Execute(editDetails);
                    cout<<"Value Updated"<<endl;
                    break;
                }

                case 9 : {
                    std::stringstream queryStream1;
                    queryStream1 << "UPDATE CustomerDetails SET PhoneNumber = '" 
                    << new_value << "' WHERE Username = '"
                    << username << "';"; 
                    std::string editDetails = queryStream1.str();
                    my_db_object->Execute(editDetails);
                    cout<<"Value Updated"<<endl;
                    break;
                }

                case 10 : {
                    std::stringstream queryStream1;
                    queryStream1 << "UPDATE CustomerDetails SET EmailAddress = '" 
                    << new_value << "' WHERE Username = '"
                    << username << "';"; 
                    std::string editDetails = queryStream1.str();
                    my_db_object->Execute(editDetails);
                    cout<<"Value Updated"<<endl;
                    break;
                }

                case 11 : {
                    std::stringstream queryStream1;
                    queryStream1 << "UPDATE KYCDetails SET IDNumber = '" 
                    << new_value << "' WHERE CustomerID = '"
                    << id << "';"; 
                    std::string editDetails = queryStream1.str();
                    my_db_object->Execute(editDetails);
                    cout<<"Value Updated"<<endl;
                    break;
                }

                case 12 : {
                    std::stringstream queryStream1;
                    queryStream1 << "UPDATE KYCDetails SET IDType = '" 
                    << new_value << "' WHERE CustomerID = '"
                    << id << "';"; 
                    std::string editDetails = queryStream1.str();
                    my_db_object->Execute(editDetails);
                    cout<<"Value Updated"<<endl;
                    break;
                }

                case 13 : {
                    std::stringstream queryStream1;
                    queryStream1 << "UPDATE KYCDetails SET IDIssueDate = '" 
                    << new_value << "' WHERE CustomerID = '"
                    << id << "';"; 
                    std::string editDetails = queryStream1.str();
                    my_db_object->Execute(editDetails);
                    cout<<"Value Updated"<<endl;
                    break;
                }

                case 14 : {
                    std::stringstream queryStream1;
                    queryStream1 << "UPDATE KYCDetails SET IDExpiryDate = '" 
                    << new_value << "' WHERE CustomerID = '"
                    << id << "';"; 
                    std::string editDetails = queryStream1.str();
                    my_db_object->Execute(editDetails);
                    cout<<"Value Updated"<<endl;
                    break;
                }

                case 15 : {
                   std::stringstream queryStream1;
                    queryStream1 << "UPDATE AccountDetails SET AccountCurrency = '" 
                    << new_value << "' WHERE CustomerID = '"
                    << id << "';"; 
                    std::string editDetails = queryStream1.str();
                    my_db_object->Execute(editDetails);
                    cout<<"Value Updated"<<endl;
                    break;
                }

                default : 
                    cout<<"Incorrect Choice";         
            }
        } else {
            cout<<"Incorrect Choice.";
            continue;
        }
    }
}

void Customer :: DeleteCustomer(){
    Auth auth;
    MysqlCon *my_db_object = MysqlCon::GetObject();
    string username = auth.Authenticate();
    int id = CustomerId(username);

    char choice;
    cout<<"All your account details will be deleted from this database.\nShould we proceed (y/n) : ";
    cin>>choice;

    if(choice=='y') {

        std::stringstream queryStream2;
        queryStream2 << "DELETE FROM KYCDetails WHERE CustomerID='" 
                    << to_string(id) << "';"; 
        std::string deleteKycDetails = queryStream2.str();
        my_db_object->Execute(deleteKycDetails);

        std::stringstream queryStream3;
        queryStream3 << "DELETE FROM AccountDetails WHERE CustomerID='" 
                    << to_string(id) << "';"; 
        std::string deleteAccountDetails = queryStream3.str();
        my_db_object->Execute(deleteAccountDetails);

        std::stringstream queryStream4;
        queryStream4 << "DELETE FROM Transactions WHERE CustomerID='" 
                    << to_string(id) << "';"; 
        std::string deleteTransactionDetails = queryStream4.str();
        my_db_object->Execute(deleteTransactionDetails);

        std::stringstream queryStream1;
        queryStream1 << "DELETE FROM CustomerDetails WHERE Username='" 
                    << username << "';"; 
        std::string deleteCustomerDetails = queryStream1.str();
        my_db_object->Execute(deleteCustomerDetails);

        cout<<"Account Deleted."<<endl;

    } else {
        cout<<"Request Cancelled."<<endl;
    }

}

void Customer :: DataToMySQL(){

    KYC *kyc = KYC::CreateObject();
    Account *account = Account::CreateObject();
    Auth auth;
    Transactions *trans = Transactions::CreateObject();
    MysqlCon *my_db_object = MysqlCon::GetObject();


    std::stringstream queryStream1;
    // Start building the query
    queryStream1 << "INSERT INTO CustomerDetails (FirstName,MiddleName,LastName,DateOfBirth,Gender,Nationality,ResidentialAddress,MailingAddress,PhoneNumber,EmailAddress,Username,AccntPassword,CardPin) VALUES ('" 
                << first_name_ << "','" 
                << middle_name_ << "','"
                << last_name_ << "','"  
                << date_of_birth_ << "','" 
                << gender_ << "','" 
                << nationality_ << "','"
                << residential_address_ << "','" 
                << mailing_address_ << "','" 
                << phone_number_ << "','" 
                << email_address_ << "','"
                << username_ << "','"
                << password_ << "','" 
                << card_pin_ << "')"; 
    std::string addCustomerDetails = queryStream1.str();
    my_db_object->Execute(addCustomerDetails);

    int id = CustomerId(username_);

    std::stringstream queryStream2;
    queryStream2 << "INSERT INTO KYCDetails (IDNumber,IDType,IDIssueDate,IDExpiryDate,NomineeName,NomineeRelationship,CustomerID) VALUES ('"
                << kyc->id_number_ << "','" 
                << kyc->id_type_ << "','" 
                << kyc->id_issue_date_ << "','" 
                << kyc->id_expiry_date_ << "','" 
                << kyc->nominee_name_ << "','" 
                << kyc->nominee_relationship_ << "','"
                << id << "')" ; 
    std::string addKYCDetails = queryStream2.str();
    my_db_object->Execute(addKYCDetails);

    std::stringstream queryStream3;
    queryStream3 << "INSERT INTO AccountDetails (AccountType,InitialDepositAmount,AccountCurrency,DebitCard,CreditCard,InternetBanking,MobileBanking,CustomerID) VALUES ('"  
                << account->account_type_ << "','" 
                << account->initial_deposit_amount_ << "','" 
                << account->account_currency_ << "','"
                << account->debit_card_ << "','" 
                << account->credit_card_ << "','" 
                << account->internet_banking_ << "','" 
                << account->mobile_banking_ << "','"
                << id << "')";
    std::string addAccountDetails = queryStream3.str();
    my_db_object->Execute(addAccountDetails);

    std::stringstream queryStream4;
    queryStream4 << "INSERT INTO Transactions (TotalAmount,CustomerID) VALUES ('"  
                << account->initial_deposit_amount_ << "','"
                << id << "')";
    std::string addTransactionMoney = queryStream4.str();
    my_db_object->Execute(addTransactionMoney);

}

bool Customer :: DataFromMySQL(){

    KYC *kyc = KYC::CreateObject();
    Account *account = Account::CreateObject();
    Auth auth;
    Transactions *trans = Transactions::CreateObject();
    MysqlCon *my_db_object = MysqlCon::GetObject();

    try {
        // string customer[] = {"FirstName","MiddleName","LastName","DateOfBirth","Gender","Nationality","ResidentialAddress",
        //                     "MailingAddress","PhoneNumber","EmailAddress","Username","Password","CardPin"};

        string user = auth.Authenticate();

        sql::ResultSet *res = my_db_object->Query("SELECT * FROM CustomerDetails WHERE Username = '"+user+"';");
        if (res->next()){
            first_name_ = res->getString("FirstName");
            middle_name_ = res->getString("MiddleName");
            last_name_ = res->getString("LastName");
            date_of_birth_ = res->getString("DateOfBirth");
            gender_ = res->getString("Gender");
            nationality_ = res->getString("Nationality");
            residential_address_ = res->getString("ResidentialAddress");
            mailing_address_ = res->getString("MailingAddress");
            phone_number_ = res->getString("PhoneNumber");
            email_address_ = res->getString("EmailAddress");
            username_ = res->getString("Username");
            password_ = res->getString("AccntPassword");
            card_pin_ = res->getInt("CardPin");
        }

        int id = CustomerId(user);

        // string kyc[] = {"IDNumber","IDType","IDIssueDate","IDExpiryDate","NomineeName","NomineeRelationship"};

        sql::ResultSet* res1 = my_db_object->Query("SELECT * FROM KYCDetails WHERE CustomerID = "+to_string(id)+";");
        if (res1->next()) {
            kyc->id_number_ = res1->getString("IDNumber");
            kyc->id_type_ = res1->getString("IDType");
            kyc->id_issue_date_ = res1->getString("IDIssueDate");
            kyc->id_expiry_date_ = res1->getString("IDExpiryDate");
            kyc->nominee_name_ = res1->getString("NomineeName");
            kyc->nominee_relationship_ = res1->getString("NomineeRelationship");
        }
    
        // string account[] = {"AccountType","InitialDepositAmount","AccountCurrency","DebitCard","CreditCard","InternetBanking","MobileBanking"};

        sql::ResultSet* res2 = my_db_object->Query("SELECT * FROM AccountDetails WHERE CustomerID = "+to_string(id)+";");
        if (res2->next()) {
            account->account_type_ = res2->getString("AccountType");
            account->initial_deposit_amount_ = res2->getInt("InitialDepositAmount");
            //trans->total_amount_ = res2->getInt("TotalAmount");
            account->account_currency_ = res2->getString("AccountCurrency");
            account->debit_card_ = res2->getBoolean("DebitCard");
            account->credit_card_ = res2->getBoolean("CreditCard");
            account->internet_banking_ = res2->getBoolean("InternetBanking");
            account->mobile_banking_ = res2->getBoolean("MobileBanking");
        }

        delete res;
        delete res1;
        delete res2;

        return true;

    } catch (sql::SQLException &e) {
        cerr << "SQLException: " << e.what() << endl;
        cerr << "MySQL error code: " << e.getErrorCode() << endl;
        cerr << "SQLState: " << e.getSQLState() << endl;
        return false;
    }

    return true;
}

