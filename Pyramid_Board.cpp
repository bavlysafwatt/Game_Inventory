// Class definition for Pyramid board class
// Author:  Bavly Safwat
// Date:    10/10/2022
// Version: 1

#include "Pyramid_Board.h"

bool Pyramid_Board::valid(int i, int j) {
    if(i == 0){
        if(j == 2 && board[i][j] == ' ')
            return true;
        return false;
    }
    else if(i == 1){
        if(j >= 1 && j <= 3 && board[i][j] == ' ')
            return true;
        return false;
    }
    else if(i == 2){
        if(j >= 0 && j <= 4 && board[i][j] == ' ')
            return true;
        return false;
    }
    return false;
}

Pyramid_Board::Pyramid_Board() {
    n_rows = 3, n_cols = 5;
    board = new char*[n_rows];
    for (int i = 0; i < n_rows; i++) {
        board [i] = new char[n_cols];
        for (int j = 0; j < n_cols; j++)
            board[i][j] = ' ';
    }
}

void Pyramid_Board::display_board() {
    cout << setfill(' ');
    cout << setw(18) << "";
    cout << setfill('-') << setw(11) << "";
    cout << endl;
    for (int i: {0,1,2}) {
        cout << setfill(' ');
        if(i==0){
            cout << setw(20) << "|" << " ";
            for(int j : {2}) {
                cout << "(" << i << "," << j << ")";
                cout << " " << board[i][j] << " |";
            }
            cout << endl << setw(9) << "" << setfill('-') << setw(31) << "" << endl;
        }
        else if(i==1){
            cout << setfill(' ') << setw(9) << "";
            cout << "|";
            for(int j : {1,2,3}) {
                cout << " (" << i << "," << j << ")";
                cout << " " << board[i][j] << " |";
            }
            cout << endl << setfill('-') << setw(51) << "";
            cout << endl;
        }
        else{
            cout << "|";
            for(int j : {0,1,2,3,4}) {
                cout << " (" << i << "," << j << ")";
                cout << " " << board[i][j] << " |";
            }
            cout << endl << setfill('-') << setw(51) << "";
        }
    }
    cout << endl;
}

bool Pyramid_Board::update_board(int x, int y, char mark) {
    if(valid(x, y)){
        board[x][y] = toupper(mark);
        n_moves++;
        return true;
    }
    return false;
}

bool Pyramid_Board::is_winner() {
    char diag_win[2];
    diag_win[0] = board[0][2] & board[1][3] & board[2][4];
    diag_win[1] = board[0][2] & board[1][1] & board[2][0];
    char row2_win = board[1][1] & board[1][2] & board[1][3];
    char col2_win = board[0][2] & board[1][2] & board[2][2];

    if ((diag_win[0] && diag_win[0] == board[1][3] && board[1][3] != ' ') ||
        (diag_win[1] && diag_win[1] == board[1][1] && board[1][1] != ' ') ||
        (row2_win && row2_win == board[1][2] && board[1][2] != ' ') ||
        (col2_win && col2_win == board[2][2] && board[2][2]!=' '))
    {return true;}

    int cnt = 1;
    for(int col = 1 ; col < 5 ; col++){
        if(board[2][col] != board[2][col-1]){
            cnt = 1;
            continue;
        }
        if(board[2][col] == board[2][col-1] && board[2][col]!=' ')
            cnt++;
        if(cnt == 3)
            return true;
    }
    return false;
}

bool Pyramid_Board::is_draw() {
    return (n_moves == 9 && !is_winner());
}

bool Pyramid_Board::game_is_over() {
    return n_moves >= 9;
}