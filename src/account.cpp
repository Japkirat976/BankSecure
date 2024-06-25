#include<iostream>
#include "account.h"
#include "transactions.h"

using namespace std;

Account* Account :: CreateObject(){
    static Account *account = nullptr;

    if(account == nullptr) {
        account = new Account();
    }

    return account;
}

void Account :: GetAccountData(){

    Transactions *trans = Transactions::CreateObject();

    std::cout << "Enter the type of account (Savings, Checking, Business, Joint, Others) : ";
    std::getline(std::cin, account_type_);

    std::cout << "Enter the initial deposit amount : ";
    std::cin >> initial_deposit_amount_;
    std::cin.ignore(); // Clear the newline character from the input buffer
    trans->total_amount_ = initial_deposit_amount_;

    std::cout << "Enter the account currency : ";
    std::getline(std::cin, account_currency_);

    char choice;
    std::cout << "Do you want a debit card (y/n) : ";
    std::cin >> choice;
    debit_card_ = (choice == 'y' || choice == 'Y');

    std::cout << "Do you want a credit card (y/n) : ";
    std::cin >> choice;
    credit_card_ = (choice == 'y' || choice == 'Y');

    std::cout << "Do you want internet banking (y/n) : ";
    std::cin >> choice;
    internet_banking_ = (choice == 'y' || choice == 'Y');

    std::cout << "Do you want mobile banking (y/n) : ";
    std::cin >> choice;
    mobile_banking_ = (choice == 'y' || choice == 'Y');
    
}