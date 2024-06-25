#ifndef ENCYRPT_H
#define ENCYRPT_H

#include <iostream>
#include <termios.h>
#include <unistd.h>
using namespace std;

class Encrypt{
    
    private :
        struct termios oldt_, newt_;

    public :
        int SetNonCanonical();
        int RestoreTerminalSettings();
        string PassInput();

};

#endif