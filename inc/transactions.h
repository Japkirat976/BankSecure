#ifndef TRANSACTIONS_H
#define TRANSACTIONS_H

#include<iostream>
using namespace std;

class Transactions{
    public :

        int total_amount_;
        int deposit_;
        int withdraw_;

        static Transactions* CreateObject();
        int TotalAmount(int& id);
        int Withdraw();
        int Deposit();
        int CheckBalance();
        void DataFromTransactions();
};

#endif