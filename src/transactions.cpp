#include<iostream>
#include <regex>
#include "transactions.h"
#include "mysql_con.h"
#include "auth.h"
#include "customer.h"
#include "screens.h"

using namespace std;

Transactions* Transactions :: CreateObject(){
    static Transactions *trans = nullptr;

    if(trans == nullptr) {
        trans = new Transactions();
    }

    return trans;
}

int extractNum(std::string str) {
    std::regex integer_regex("\\d+");
    int extracted_integer = 0; // Variable to store the extracted integer

    // Iterate over the string, extract the first integer found, and store it
    for(std::sregex_iterator it(str.begin(), str.end(), integer_regex); it != std::sregex_iterator(); ++it) {
        extracted_integer = std::stoi((*it).str()); // Convert the matched substring to an integer
        break; // Exit the loop after extracting the first integer
    }

    // Return the extracted integer
    return extracted_integer;
}

int Transactions :: TotalAmount(int& id){
    Customer *c1 = Customer::CreateObject();
    Auth auth;
    int amount;
    MysqlCon *my_db_object = MysqlCon::GetObject();
    string user = auth.Authenticate();
    id = c1->CustomerId(user);
    sql::ResultSet* res1 = my_db_object->Query("SELECT TotalAmount FROM Transactions WHERE CustomerID = "+ std::to_string(id)+";");
    if (res1->next()) {
        total_amount_ = res1->getInt("TotalAmount");
    }
    delete res1;
    return total_amount_;
}

int Transactions :: Withdraw(){

    Customer *c1 = Customer::CreateObject();
    Auth auth;
    int amount;
    MysqlCon *my_db_object = MysqlCon::GetObject();
    Screens screen;

    string user = auth.Authenticate();
    int id = c1->CustomerId(user);
    sql::ResultSet* res1 = my_db_object->Query("SELECT TotalAmount FROM Transactions WHERE CustomerID = "+ std::to_string(id)+";");
    while (res1->next()) {
        total_amount_ = res1->getInt("TotalAmount");
    }

    sql::ResultSet* res2 = my_db_object->Query("SELECT CardPin FROM CustomerDetails WHERE CustomerID = "+ std::to_string(id)+";");    
    int card_pin;
    if (res2->next()) {
        card_pin = res2->getInt("CardPin");
    }

    withdraw_ = screen.WithdrawScreen(total_amount_);

    int i=0;

    do{
        int atmPIN;
        pinAgain:
        std::cout<<"Enter your ATM pin : ";
        std::cin>>atmPIN;
        if(atmPIN == card_pin){
            total_amount_ = total_amount_ - withdraw_;
            std::cout<<"Amount withdrwan : "<<withdraw_<<endl;
            std::cout<<"Bank Balance : "<<total_amount_<<endl;

        } else if (atmPIN != card_pin){
            std::cout<<"ATM pin entered is incorrect.\n";        
            if(i<=2){
                i++;
                goto pinAgain;
            }
            else if(i == 3){
                std::cout<<"This is your last try.\n";
                i++;
                goto pinAgain;
            }
            else if(i==4){
                break;
                }
            }
        }while(i>3);  

    std::stringstream queryStream4;
    queryStream4 << "INSERT INTO Transactions (TotalAmount,Withdraw,CustomerID) VALUES ('"  
                << total_amount_ << "','"
                << withdraw_ << "','"
                << id << "')";
    std::string addTransactionMoney = queryStream4.str();
    my_db_object->Execute(addTransactionMoney);

    delete res1;
    delete res2;

    return 0;
    }

int Transactions :: Deposit(){

    Customer *c1 = Customer::CreateObject();
    Auth auth;
    int amount;
    MysqlCon *my_db_object = MysqlCon::GetObject();
    Screens screen;

    string user = auth.Authenticate();
    int id = c1->CustomerId(user);
    sql::ResultSet* res1 = my_db_object->Query("SELECT TotalAmount FROM Transactions WHERE CustomerID = "+ std::to_string(id)+";");
    while (res1->next()) {
        total_amount_ = res1->getInt("TotalAmount");
    }
    sql::ResultSet* res2 = my_db_object->Query("SELECT CardPin FROM CustomerDetails WHERE CustomerID = "+ std::to_string(id)+";");    
    int card_pin;
    if (res2->next()) {
        card_pin = res2->getInt("CardPin");
    }

    deposit_ = screen.DepositScreen();

    int i=0;

    do{
        int atmPIN;
        pinAgain:
        std::cout<<"Enter your ATM pin : ";
        std::cin>>atmPIN;
        if(atmPIN == card_pin){
            total_amount_ = total_amount_ + deposit_;
            std::cout<<"Amount withdrwan : "<<deposit_<<endl;
            std::cout<<"Bank Balance : "<<total_amount_<<endl;

        } else if (atmPIN != card_pin){
            std::cout<<"ATM pin entered is incorrect.\n";        
            if(i<=2){
                i++;
                goto pinAgain;
            }
            else if(i == 3){
                std::cout<<"This is your last try.\n";
                i++;
                goto pinAgain;
            }
            else if(i==4){
                break;
                }
            }
        }while(i>3);  

    std::stringstream queryStream;
    queryStream << "INSERT INTO Transactions (TotalAmount,Deposit,CustomerID) VALUES ('"  
                << total_amount_ << "','"
                << deposit_ << "','"
                << id << "')";
    std::string addTransactionMoney = queryStream.str();
    my_db_object->Execute(addTransactionMoney); 

    delete res1;
    delete res2;

    return 0;
}

int Transactions :: CheckBalance(){
    Customer *c1 = Customer::CreateObject();
    Auth auth;
    MysqlCon *my_db_object = MysqlCon::GetObject();

    string user = auth.Authenticate();
    int id = c1->CustomerId(user);

    sql::ResultSet* res1 = my_db_object->Query("SELECT TotalAmount FROM Transactions WHERE CustomerID = "+ std::to_string(id)+";");
    while (res1->next()) {
        total_amount_ = res1->getInt("TotalAmount");
    }
    while (res1->next()) {
        total_amount_ = res1->getInt("TotalAmount");
    }
    std::cout << "Balance : " << total_amount_ << std::endl;
    delete res1;
    return 0;
}

void Transactions :: DataFromTransactions(){
    Customer *c1 = Customer::CreateObject();
    Auth auth;
    MysqlCon *my_db_object = MysqlCon::GetObject();

    string user = auth.Authenticate();
    int id = c1->CustomerId(user);

    sql::ResultSet* res = my_db_object->Query("SELECT TotalAmount,Withdraw,Deposit,TransactionAt FROM Transactions WHERE account_id = '"+to_string(id)+"';");
    while (res->next()) {
        total_amount_ = res->getInt("TotalAmount");
        withdraw_ = res->getInt("Withdraw");
        deposit_ = res->getInt("Deposit");
        std::string timestamp = res->getString("TransactionAT");
        std::cout << "Amount : " << total_amount_ << std::endl;
        std::cout << "Withdraw : " << withdraw_ << std::endl;
        std::cout << "Deposit : " << deposit_ << std::endl;
        std::cout << "TimeStamp : " << timestamp << std::endl;

    }

    delete res;

}