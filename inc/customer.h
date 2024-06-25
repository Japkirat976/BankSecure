#ifndef CUSTOMER_H
#define CUSTOMER_H

#include<iostream>
#include "account.h"
#include "kyc.h"
#include "transactions.h"
using namespace std;

class Customer{
    public :

        // Personal details
        string first_name_;
        string middle_name_;
        string last_name_;
        string date_of_birth_;
        string gender_;
        string nationality_;

        // Contact Information
        string residential_address_;
        string mailing_address_;
        string phone_number_;
        string email_address_;

        string username_;
        string password_;
        int card_pin_;

        Account account_;
        KYC kyc_;
        Transactions trans_;


        static Customer *CreateObject();
        void GetData();
        int CustomerId(string user);
        void EditData();
        void DeleteCustomer();
        void DataToMySQL();
        bool DataFromMySQL();
};

#endif