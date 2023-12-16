// Class definition for Pyramid board class
// Author:  Bavly Safwat
// Date:    10/10/2022
// Version: 1

#ifndef X_O_PYRAMID_BOARD_H
#define X_O_PYRAMID_BOARD_H
#include <bits/stdc++.h>
#include "BoardGame_Classes.hpp"

using namespace std;

class Pyramid_Board : public Board{
    bool valid(int i, int j);
public:
    Pyramid_Board();
    bool update_board (int x, int y, char mark);
    void display_board();
    bool is_winner();
    bool is_draw();
    bool game_is_over();
};


#endif //X_O_PYRAMID_BOARD_H
