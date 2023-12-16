#ifndef X_O_3_PLAYER3_H
#define X_O_3_PLAYER3_H
#include "BoardGame_Classes.hpp"

class Player3 : public Player{
public:
    Player3(int order, char symbol) : Player(order, symbol) {}

    void get_move(int& x, int& y) override{
        cout << "\nPlease enter your move x and y (0 to 4) separated by spaces: ";
        cin >> x >> y;
    }
};


#endif //X_O_3_PLAYER3_H
