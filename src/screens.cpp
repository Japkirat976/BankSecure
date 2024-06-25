#include<iostream>
#include "screens.h"
#include "customer.h"
#include "kyc.h"
#include "account.h"
#include "auth.h"
#include "encrypt.h"

using namespace std;

void Screens::MainScreen(){
    std::string str = R"(
MENU FOR BANK MANAGEMENT SYSTEM
 1.Create account
 2.View account details
 3.Withdraw money
 4.Deposit money
 5.Check balance
 6.Edit account details
 7.Delete account
 8.Exit

Enter your choice : )";

    cout<<str;
}

void Screens::ViewAccountScreen(){

    Customer *c1 = Customer::CreateObject();
    
    KYC *kyc = KYC::CreateObject();
    Account *account = Account::CreateObject();

    // string customer[] = {"FirstName","MiddleName","LastName","DateOfBirth","Gender","Nationality","ResidentialAddress",
    //                     "MailingAddress","PhoneNumber","EmailAddress","Username","Password","CardPin"}

    std::cout << "First Name : " << c1->first_name_ << std::endl;
    std::cout << "Middle Name : " << c1->middle_name_ << std::endl;
    std::cout << "Last Name : " << c1->last_name_ << std::endl;
    std::cout << "Date of Birth : " << c1->date_of_birth_ << std::endl;
    std::cout << "Gender : " << c1->gender_ << std::endl;
    std::cout << "Nationality : " << c1->nationality_ << std::endl;
    std::cout << "Residential Address : " << c1->residential_address_ << std::endl;
    std::cout << "Mailing Address : " << c1->mailing_address_ << std::endl;
    std::cout << "Phone Number : " << c1->phone_number_ << std::endl;
    std::cout << "Email Address : " << c1->email_address_ << std::endl;
    std::cout << "Username : " << c1->username_ << std::endl;


    // string kyc[] = {"IDNumber","IDType","IDIssueDate","IDExpiryDate","NomineeName","NomineeRelationship"}

    std::cout << "ID Number : " << kyc->id_number_ << std::endl;
    std::cout << "ID Type : " << kyc->id_type_ << std::endl;
    std::cout << "ID Issue Date : " << kyc->id_issue_date_ << std::endl;
    std::cout << "ID Expiry Date : " << kyc->id_expiry_date_ << std::endl;
    std::cout << "Nominee Name : " << kyc->nominee_name_ << std::endl;
    std::cout << "Nominee Relationship : " << kyc->nominee_relationship_ << std::endl;


    // string account[] = {"AccountType","InitialDepositAmount","AccountCurrency","DebitCard",
    //                     "CreditCard","InternetBanking","MobileBanking"}

    std::cout << "AccountType : " << account->account_type_ << std::endl;
    std::cout << "InitialDepositAmount : " << account->initial_deposit_amount_ << std::endl;
    std::cout << "AccountCurrency : " << account->account_currency_ << std::endl;
    std::cout << "DebitCard : " << account->debit_card_ << std::endl;
    std::cout << "CreditCard : " << account->credit_card_ << std::endl;
    std::cout << "InternetBanking : " << account->internet_banking_ << std::endl;
    std::cout << "MobileBanking : " << account->mobile_banking_ << std::endl;
}

string Screens::GetPassword(){
    Encrypt encrypt;
    string password;
    cout<<"Your password should be "<<endl;
    cout<<" 1.Atleast 8 characters long"<<endl;
    cout<<" 2.Contain one capital and small letter."<<endl;
    cout<<" 3.Contain one integer."<<endl;
    cout<<" 4.Contain one special character(!@#$%^&*())."<<endl;
    password = encrypt.PassInput();
    return password;
}

string Screens::GetUsername(){
    string username;
    cout<<"Enter your username : ";
    std::getline(cin,username);
    return username;
}

int Screens::WithdrawScreen(int amount){
    int withdraw_money;
    for(int i=0;i<4;i++){
        cout<<"Enter the amount to be withdrawn : ";
        std::cin>>withdraw_money;
        cin.ignore();
        if(amount < withdraw_money){
            cout<<"Bank Balance : "<<amount;
            cout<<"Enteret amount is more than the bank balance."<<endl;
            cout<<"If you want to re-enter the amount to be withdrawn press 1."<<endl;
            cout<<"If you want to cancel press 2."<<endl;
            continue;
        } else if (amount >= withdraw_money){
            return withdraw_money;
            break;
        }
    }
    
    return withdraw_money;
}

int Screens::DepositScreen(){
    int deposit_money;
    cout<<"Enter the amount to be deposited : ";
    cin>>deposit_money;
    cin.ignore();
    return deposit_money;
}

void Screens::EditScreen(){
    
    std::string str = R"(1. First Name
2. Middle Name
3. Last Name
4. Date of Birth
5. Gender
6. Nationality
7. Residential Address
8. Mailing Address
9. Phone Number
10. Email Address
11. ID Number
12. ID Type
13. ID Issue Date
14. ID Expiry Date
15. Account Currency
)";
  cout<<str;
    cout<<"Enter the field number you want to change from the above list : ";

}