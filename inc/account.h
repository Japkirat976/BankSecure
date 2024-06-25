#ifndef ACCOUNT_H
#define ACCOUNT_H

#include<iostream>
using namespace std;

class Account {
    public :
        // Account Information
        string account_type_;
        double initial_deposit_amount_;
        string account_currency_;

        // Additional Services
        bool debit_card_;
        bool credit_card_;
        bool internet_banking_;
        bool mobile_banking_;

        static Account* CreateObject();
        void GetAccountData();
};


#endif