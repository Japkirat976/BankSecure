#ifndef SCREENS_H
#define SCREENS_H

class Screens {
    public :
        void MainScreen();
        void ViewAccountScreen();
        std::string GetPassword();
        std::string GetUsername();
        int WithdrawScreen(int amount);
        int DepositScreen();
        void EditScreen();
};

#endif