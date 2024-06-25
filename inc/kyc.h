#ifndef KYC_H
#define KYC_H

#include<iostream>
using namespace std;

class KYC {
    public:
        // Identification Documents
        string id_number_;
        string id_type_;
        string id_issue_date_;
        string id_expiry_date_;

        // Nominee/Beneficiary Information
        string nominee_name_;
        string nominee_relationship_;

        static KYC* CreateObject();
        void GetKycData();

};

#endif