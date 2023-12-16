// Class definition for Four-in-a-row Board
// Author:  Gad Amr Gadelhaq
// Date:    12/10/2022
// Version: 1


#include "Four_in_a_row_board.h"

Four_in_a_row_board::Four_in_a_row_board() {
    n_rows = 6, n_cols = 7;
    board = new char*[n_rows];
    for (int i = 0; i < n_rows; i++) {
        board [i] = new char[n_cols];
        for (int j = 0; j < n_cols; j++)
            board[i][j] = ' ';
    }
}

void Four_in_a_row_board::display_board() {
    cout << setfill('-') << setw(71) << "";
    for (int i: {0,1,2,3,4,5}) {
        cout << "\n|";
        for (int j: {0,1,2,3,4,5,6}) {
            cout << " (" << i << "," << j << ")";
            cout << " " << board[i][j] << " |";
        }
        cout << endl;
        cout << setfill('-') << setw(71) << "";
    }
    cout << endl;
}

bool Four_in_a_row_board::update_board(int x, int y, char mark) {
    if(y >= 0 && y <= 6){
        for (int i = n_rows-1 ; i >= 0 ; --i) {
            if(board[i][y]==' '){
                board[i][y] = toupper(mark);
                n_moves++;
                return true;
            }
        }
    }
    return false;
}

bool Four_in_a_row_board::is_winner() {
    for (int i = 0; i < n_rows; ++i) {
        for (int j = 0; j < n_cols-3; ++j) {
            if (board[i][j] == board[i][j+1] && board[i][j+1] == board[i][j+2] &&
                board[i][j+2] == board[i][j+3] && board[i][j]!=' ') {
                return true;
            }
        }
    }
    for (int i = 0; i < n_rows-3; ++i) {
        for (int j = 0; j < n_cols ; ++j) {
            if (board[i][j] == board[i+1][j] && board[i+1][j] == board[i+2][j] &&
                board[i+2][j] == board[i+3][j] && board[i][j]!=' ') {
                return true;
            }
        }
    }
    for (int i = 0; i < n_rows-3; ++i) {
        for (int j = 0; j < n_cols-3; ++j) {
            if (board[i][j] == board[i+1][j+1] && board[i+1][j+1] == board[i+2][j+2] &&
                board[i+2][j+2] == board[i+3][j+3] && board[i][j]!=' ') {
                return true;
            }
        }
    }
    for (int i = 0; i < n_rows-3; ++i) {
        for (int j = 3; j < n_cols; ++j) {
            if (board[i][j] == board[i+1][j-1] && board[i+1][j-1] == board[i+2][j-2] &&
                board[i+2][j-2] == board[i+3][j-3] && board[i][j]!=' ') {
                return true;
            }
        }
    }
    return false;
}

bool Four_in_a_row_board::is_draw() {
    return (n_moves == 42 && !is_winner());
}

bool Four_in_a_row_board::game_is_over() {
    return n_moves >= 42;
}