// Class definition for 5*5 Tic-Tac-Toe
// Author:  Bavly Safwat-Gad Amr
// Date:    14/10/2022
//Version:1

#ifndef X_O_3_FIVE_TIC_TAC_TOE_H
#define X_O_3_FIVE_TIC_TAC_TOE_H
#include "BoardGame_Classes.hpp"
#include <bits/stdc++.h>
using namespace std;

class Five_Tic_Tac_Toe : public Board{
    void calculate_x_and_os();
public:
    int x;
    int o;
    Five_Tic_Tac_Toe();
    bool update_board (int x, int y, char mark);
    void display_board();
    bool is_winner();
    bool is_draw();
    bool game_is_over();
};


#endif //X_O_3_FIVE_TIC_TAC_TOE_H
