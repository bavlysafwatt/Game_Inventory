#ifndef X_O_2_FOUR_IN_A_ROW_BOARD_H
#define X_O_2_FOUR_IN_A_ROW_BOARD_H
#include <bits/stdc++.h>
#include "BoardGame_Classes.hpp"

using namespace std;

class Four_in_a_row_board : public Board{
public:
    Four_in_a_row_board();
    bool update_board (int x, int y, char mark);
    void display_board();
    bool is_winner();
    bool is_draw();
    bool game_is_over();
};


#endif //X_O_2_FOUR_IN_A_ROW_BOARD_H
