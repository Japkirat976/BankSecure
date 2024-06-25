#include<iostream>
#include<string.h>
#include<cctype>
#include<openssl/sha.h>
#include "auth.h"
#include "encrypt.h"
#include "mysql_con.h"
#include "screens.h"

using namespace std;
using namespace sql::mysql;

string Auth :: CheckPassword(){
    Encrypt encrypt;
    Screens screen;
    
    encrypt.SetNonCanonical();
    auth_password_ = screen.GetPassword();
    encrypt.RestoreTerminalSettings();

    int passwordLength = auth_password_.length();

    if (passwordLength<8){
        throw runtime_error("Password is too short.");
    } 

    int countSmall=0;
    int countLarge=0;
    int countInt=0;
    int countSpc=0;
    int length = auth_password_.length();

    for (int i=0;i<length;i++){
        char x = auth_password_[i];
        
        if(x>='a'&&x<='z'){
            countSmall++;
        }

        if(x>='A'&&x<='Z'){
            countLarge++;
        }

        if(x>='0'&&x<='9'){
            countInt++;
        }

        if(x=='!'||x=='@'||x=='#'||x=='$'||x=='%'||x=='^'||x=='&'||x=='*'||x=='('||x==')'){
            countSpc++;
        }

    }

    if(countSmall<1){
        throw runtime_error("Password did not include lower case alphabets.");
    }

    if(countLarge<1){
        throw runtime_error("Password did not include upper case alphabets.");
    }
    if(countInt<1){
        throw runtime_error("Password did not include integers.");
    }
    if(countSpc<1){
        throw runtime_error("Password did not include special characters.");
    }

    return auth_password_;

}

string Auth :: SetPassword(){
    string password;
    for (int i=0;i<5;i++){
        try{
            password = CheckPassword();
            break;
        } catch (const runtime_error &e) {
            cerr << e.what() << endl;
            continue;
        }
    }
    return password;
}

bool CheckUsername(string username){

    MysqlCon *my_db_object = MysqlCon::GetObject(); 

    // Execute a query to check if the name exists
    sql::ResultSet* res = my_db_object->Query("SELECT COUNT(*) AS count FROM CustomerDetails WHERE Username = '" + username + "'");

    // Process the result
    if (res->next()) {
        int count = res->getInt("Count");
        return count > 0;  // Return true if the name exists
    }    
    
    return false;
}

string Auth :: IfErrorInUsername(){
    Screens screen;
    for(int i=0;i<5;i++){
        auth_username_ = screen.GetUsername();
        if(CheckUsername(auth_username_)){
            throw runtime_error("Username already exists");
            continue;
        } else {
            break;
        }
    }
    return auth_username_;
}

string Auth :: SetUsername(){
    string username;
    for(int i=0;i<5;i++){
        try{
            username = IfErrorInUsername();
            break;
        } catch(const runtime_error &e) {
            cerr << e.what() << endl;
            continue;
        }
    }
    return username;
}

string IfUsernameExists(){
    Screens screen;
    string f_user;
    for(int i=0;i<5;i++){
    f_user = screen.GetUsername();
        if(CheckUsername(f_user)){
            return f_user;
            break;
        } else {
            throw runtime_error("Username dosen't exist");
            continue;
        }
    }
    return f_user;
}

string Auth :: Authenticate(){
    
    Encrypt encrypt;
    Screens screen;
    MysqlCon *my_db_object = MysqlCon::GetObject();

    string user,pass;

    for(int i=0;i<5;i++){
        try {
            user = IfUsernameExists();
            break;
        } catch(const runtime_error &e) {
            cerr << e.what() << endl;
            continue;
        }
    }
    
    sql::ResultSet* res = my_db_object->Query("SELECT AccntPassword FROM CustomerDetails WHERE Username='"+user+"';");
    if (res->next()) {
        pass = res->getString("AccntPassword");
    }
        
    string checkpass;
    int i=0;
    for (i=0;i<3;i++){
        encrypt.SetNonCanonical();
        checkpass = encrypt.PassInput();
        encrypt.RestoreTerminalSettings();

        if(checkpass.compare(pass) == 0){
            return user;
            break;
        }
        if(i==2){
            cout<<"Too many attempts, try later."<<endl;
            break;
        }
        else{
            cout<<"Entered password is incorrect."<<endl;
            continue;
        }   
    }
    return user;
} 



