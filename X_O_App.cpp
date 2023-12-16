#include <bits/stdc++.h>
#include "BoardGame_Classes.hpp"
#include "Pyramid_Board.h"
#include "Four_in_a_row_board.h"
#include "Five_Tic_Tac_Toe.h"
#include "Player1.h"
#include "Player2.h"
#include "Player3.h"

using namespace std;

int readchoice(int low, int high){
    cout << "\nEnter number in range " << low << " - " << high << ": ";
    int choice; cin >> choice;

    if (low <= choice && choice <= high)
        return choice;

    cout << "ERROR: invalid number...Try again\n";
    return readchoice(low, high);
}

int readmenu(vector<string> menu){
    cout << "Menu" << endl;
    for (int i = 0; i < menu.size() ; ++i) {
        cout << "\t" << i+1 << "- " << menu[i] << endl;
    }
    return readchoice(1, menu.size());
}

int main() {
    cout << "Welcome to Unbeatable FCAI X-O Game. :)\n";
    cout << "Choose the game you want to play" << endl << endl;
    vector<string> menu;
    menu.push_back("3x3 Tic-Tac-Toe");
    menu.push_back("Pyramic Tic-Tac-Toe");
    menu.push_back("Four-in-a-row");
    menu.push_back("5x5 Tic-Tac-Toe");
    menu.push_back("Exit");

    int game = readmenu(menu);
    if(game==1){
        int choice;
        Player* players[2];
        players[0] = new Player (1, 'x');

        cout << "Press 1 if you want to play with computer: ";
        cin >> choice;
        if (choice != 1)
            players[1] = new Player (2, 'o');
        else
            players[1] = new RandomPlayer ('o', 3);

        GameManager x_o_game (new X_O_Board(), players);
        x_o_game.run();
    }
    else if(game==2){
        int choice;
        Player* players[2];
        players[0] = new Player1 (1, 'x');

        cout << "Press 1 if you want to play with computer: ";
        cin >> choice;
        if (choice != 1)
            players[1] = new Player1 (2, 'o');
        else
            players[1] = new RandomPlayer ('o', 5);

        GameManager x_o_game (new Pyramid_Board(), players);
        x_o_game.run();
    }
    else if(game==3){
        int choice;
        Player* players[2];
        players[0] = new Player2 (1, 'x');

        cout << "Press 1 if you want to play with computer: ";
        cin >> choice;
        if (choice != 1)
            players[1] = new Player2 (2, 'o');
        else
            players[1] = new RandomPlayer ('o', 6);

        GameManager x_o_game (new Four_in_a_row_board(), players);
        x_o_game.run();
    }
    else if(game==4){
        int choice;
        Player* players[2];
        players[0] = new Player3 (1, 'x');

        cout << "Press 1 if you want to play with computer: ";
        cin >> choice;
        if (choice != 1)
            players[1] = new Player3(2, 'o');
        else
            players[1] = new RandomPlayer ('o', 5);

        GameManager x_o_game (new Five_Tic_Tac_Toe(), players);
        x_o_game.run();
    }
    system ("pause");
    return 0;
}
