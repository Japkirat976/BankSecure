#ifndef AUTH_H
#define AUTH_H

#include<iostream>
using namespace std;

class Auth {
private:
    std::string auth_password_;
    std::string auth_username_;

public:
    string SetPassword();
    string CheckPassword();
    string IfErrorInUsername();
    string SetUsername();
    string Authenticate();
};

#endif