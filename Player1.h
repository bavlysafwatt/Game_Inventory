#ifndef X_O_PLAYER1_H
#define X_O_PLAYER1_H
#include "BoardGame_Classes.hpp"
#include <iostream>
class Player1 : public Player{
public:
    Player1(int order, char symbol): Player(order, symbol){}

    void get_move(int &x, int &y) override{
        cout << "\nPlease enter your move x (0 to 2) and y (0 to 4) separated by spaces: ";
        cin >> x >> y;
    }
};


#endif //X_O_PLAYER1_H
