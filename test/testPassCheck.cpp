#include<iostream>
using namespace std;

int CheckPass(){    

    string auth_password;    
    cout<<"Enter your password : ";
    cin>>auth_password;    
    int passwordLength = auth_password.length();

    if (passwordLength<8){
        throw runtime_error("Password is too short.");
    }    
    int countSmall=0;
    int countLarge=0;
    int countInt=0;
    int countSpc=0;
    int length = auth_password.length();    
    
    for (int i=0;i<length;i++){
        
        char x = auth_password[i];
     
        if(x>='a'&&x<='z'){
            countSmall++;
        }        if(x>='A'&&x<='Z'){
            countLarge++;
        }        if(x>='0'&&x<='9'){
            countInt++;
        }        if(x=='!'||x=='@'||x=='#'||x=='$'||x=='%'||x=='^'||x=='&'||x=='*'||x=='('||x==')'){
            countSpc++;
        }    }

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

    return 0;
}

int main(){
    for (int i=0;i<5;i++){
        try{
            CheckPass();
            break;
        } catch (const runtime_error &e) {
            cerr << "Error: " << e.what() << endl;
        }
    }
    
    return 0;
}

// #include <iostream>
// #include <stdexcept>
// using namespace std;

// void process(int i) {
//     if (i < 0) {
//         throw "Negative value not allowed";
//     }
//     cout << "Processing j = " << i << endl;
// }

// int main() {
//     int j = -1;
//     for (int i=0;i<6;i++){
//         try {
//             while(j<10){
//                 process(j);
//                 j++;
//             }
//         } catch (...) {
//             cerr << "Invalid Input " << endl;
//         }
//     }

//     return 0;
// }