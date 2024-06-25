#include<iostream>
#include "kyc.h"

using namespace std;

KYC *KYC :: CreateObject(){
    static KYC *kyc = nullptr;

    if(kyc == nullptr) {
        kyc = new KYC();
    }

    return kyc;
}

void KYC :: GetKycData(){
    
    std::cout << "Enter your ID number : ";
    std::getline(std::cin, id_number_);

    std::cout << "Enter your ID type (Passport, Driver’s License, National ID, etc.) : ";
    std::getline(std::cin, id_type_);

    std::cout << "Enter ID issue date (YYYY-MM-DD) : ";
    std::getline(std::cin, id_issue_date_);
    cout<<id_issue_date_;

    std::cout << "Enter ID expiry date (YYYY-MM-DD) : ";
    std::getline(std::cin, id_expiry_date_);

    std::cout << "Enter the nominee's name (if any) : ";
    std::getline(std::cin, nominee_name_);

    std::cout << "Enter the nominee's relationship : ";
    std::getline(std::cin, nominee_relationship_);
}


