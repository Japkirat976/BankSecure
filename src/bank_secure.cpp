#include<iostream>
#include "customer.h"
#include "transactions.h"
#include "mysql_con.h"
#include "screens.h"

using namespace std;

int main(){
    int mainChoice;
    
    MysqlCon *my_db_object = MysqlCon::GetObject();
    Customer *c1 = Customer::CreateObject();
    Screens screen;

    Transactions trans;
    do{
        screen.MainScreen();
        cin>>mainChoice;
        std::cin.ignore();
        switch(mainChoice){
            case 1 : 
                c1->GetData();
                c1->DataToMySQL();
                break;
            case 2 : {
                for(int i=0;i<2;i++){
                    bool op = c1->DataFromMySQL();
                if(op){
                    screen.ViewAccountScreen();
                    break;
                } else {
                    cout<<"Wrong credential details."<<endl;
                    continue;
                }
                }
                break;
            }
            case 3 :
                trans.Withdraw();
                break;
            case 4 :
                trans.Deposit();
                break;
            case 5 :
                trans.CheckBalance();
                break;
            case 6 :
                c1->EditData();                
                break;
            case 7 :
                c1->DeleteCustomer();
                break;
            defualt :
                cout<<"Enter a correct choice"<<endl;
        }
    }while(mainChoice != 8);

    return 0;
}
