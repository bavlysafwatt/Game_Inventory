// Class definition for 5*5 Tic-Tac-Toe
// Author:  Bavly Safwat-Gad Amr
// Date:    14/10/2022
//Version:1

#include "Five_Tic_Tac_Toe.h"

void Five_Tic_Tac_Toe::calculate_x_and_os() {
    x = 0, o = 0;
    for (int i = 0; i < n_rows; ++i) {
        for (int j = 0; j < n_cols-2; ++j) {
            if (board[i][j] == board[i][j+1] && board[i][j+1] == board[i][j+2]) {
                if(board[i][j] == 'X')
                    x++;
                else if(board[i][j] == 'O')
                    o++;
            }
        }
    }
    for (int i = 0; i < n_rows-2; ++i) {
        for (int j = 0; j < n_cols ; ++j) {
            if (board[i][j] == board[i+1][j] && board[i+1][j] == board[i+2][j]) {
                if(board[i][j] == 'X')
                    x++;
                else if(board[i][j] == 'O')
                    o++;
            }
        }
    }
    for (int i = 0; i < n_rows-2; ++i) {
        for (int j = 0; j < n_cols-2; ++j) {
            if (board[i][j] == board[i+1][j+1] && board[i+1][j+1] == board[i+2][j+2]) {
                if(board[i][j] == 'X')
                    x++;
                else if(board[i][j] == 'O')
                    o++;
            }
        }
    }
    for (int i = 0; i < n_rows-2; ++i) {
        for (int j = 2; j < n_cols; ++j) {
            if (board[i][j] == board[i+1][j-1] && board[i+1][j-1] == board[i+2][j-2]) {
                if(board[i][j] == 'X')
                    x++;
                else if(board[i][j] == 'O')
                    o++;
            }
        }
    }
}

Five_Tic_Tac_Toe::Five_Tic_Tac_Toe() {
    n_rows = n_cols = 5;
    board = new char*[n_rows];
    for (int i = 0; i < n_rows; i++) {
        board [i] = new char[n_cols];
        for (int j = 0; j < n_cols; j++)
            board[i][j] = ' ';
    }
}

void Five_Tic_Tac_Toe::display_board() {
    cout << setfill('-') << setw(50) << "";
    for (int i: {0,1,2,3,4}) {
        cout << "\n|";
        for (int j: {0,1,2,3,4}) {
            cout << " (" << i << "," << j << ")";
            cout << " " << board[i][j] << " |";
        }
        cout << endl;
        cout << setfill('-') << setw(50) << "";
    }
    cout << endl;
}

bool Five_Tic_Tac_Toe::update_board(int x, int y, char mark) {
    if (!(x < 0 || x > 4 || y < 0 || y > 4) && (board[x][y] == ' ')) {
        board[x][y] = toupper(mark);
        n_moves++;
        return true;
    }
    else
        return false;
}

bool Five_Tic_Tac_Toe::is_winner() {
    if(game_is_over()){
        calculate_x_and_os();
        if(x > o)
            cout << "Player (X) Wins." << endl;
        else if(o > x)
            cout << "Player (O) Wins." << endl;
    }
    return false;
}

bool Five_Tic_Tac_Toe::is_draw() {
    if(game_is_over()){
        calculate_x_and_os();
        if(x == o)
            cout << "Draw!" << endl;
    }
    return false;
}

bool Five_Tic_Tac_Toe::game_is_over() {
    return n_moves >= 24;
}