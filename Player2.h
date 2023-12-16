#ifndef X_O_2_PLAYER2_H
#define X_O_2_PLAYER2_H
#include "BoardGame_Classes.hpp"
#include <iostream>
class Player2 :public Player{
public:
    Player2(int order, char symbol): Player(order, symbol){}

    void get_move(int& x, int& y) override{
        cout << "\nPlease enter your move y (0 to 6): ";
        cin >> y;
        x = 0;
    }
};


#endif //X_O_2_PLAYER2_H
