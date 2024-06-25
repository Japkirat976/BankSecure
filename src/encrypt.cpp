#include<iostream>
#include "encrypt.h"
using namespace std;

int Encrypt :: SetNonCanonical(){

    tcgetattr(STDIN_FILENO, &oldt_); // Save old terminal settings

    // Set terminal to non-canonical mode to read input character by character
    newt_ = oldt_;
    newt_.c_lflag &= ~(ICANON | ECHO); // Disable canonical mode and echoing
    tcsetattr(STDIN_FILENO, TCSANOW, &newt_); // Apply new terminal settings
    return 0;
}

int Encrypt ::  RestoreTerminalSettings(){
    // Restore original terminal settings
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt_);
    return 0;

}

string Encrypt :: PassInput(){
    cout << "Enter your password : ";
    string password;
    char ch;
    while (cin.get(ch) && ch != '\n') {
        password.push_back(ch);
        cout << "*"; // Print '*' instead of actual character
    }
    cout << endl;
    return password;
}
