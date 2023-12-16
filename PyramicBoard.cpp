

#include "BoardGame_Classes.hpp"
#include <random>
#include <iostream>
#include <iomanip>

using namespace std;


PyramicBoard::PyramicBoard() {
    n_rows = 3;
    n_cols = 5;
    board = new char*[n_rows];
    //initialize the board with zeros
    for (int i = 0; i < n_rows; i++) {
        board[i] = new char[n_cols];
        for (int j = 0; j < n_cols; j++) {
            board[i][j] = 0;
        }
    }

    n_moves = 0;
}

bool PyramicBoard::update_board(int x, int y, char mark) {
    // Check if the move is valid
    if (!isvalid(x,y)) {
        return false;
    }
    // Update the board
    board[x][y] = mark;
    n_moves++;

    return true;
}




bool PyramicBoard::isvalid(int x, int y) {
    // Check if the coordinates are within the bounds of the board
    if (x < 0 || x >= n_rows || y < 0 || y >= n_cols) {
        return false;
    }
 
    // Check if the cell at those coordinates is empty
    if (board[x][y] != 0) {
        return false;
    }
 
    // Check for restricted cells
    if ((x == 0 && y != 2) || (x == 1 && (y == 0 || y == 4))) {
        return false;
    }
 
    return true;
}

void PyramicBoard::display_board() {
    for (int i=0;i<n_rows;i++) {
        for (int j=0;j<n_cols;j++) {
            if(isvalid(i,j))
                cout << "(" << i << "," << j << ")";
            else
                cout<<"     ";
            cout << setw(2) << board [i][j] << " |";

        }
        cout << "\n";
    }
    cout << endl;

}

bool PyramicBoard::is_winner() {
    char row_win=0, col_win[2]={0}, diag_win[2]={0};

    row_win=board[0][2]&board[1][2]&board[2][2];
    diag_win[0] = board[2][4] & board[1][3] & board[0][2];
    diag_win[1] = board[2][0] & board[1][1] & board[0][2];
    col_win[0]=board[1][1]&board[1][2]&board[1][3];
    for (int i = 0; i < 3; ++i) {
        col_win [1]|= (board[2][i] & board[2][i + 1] & board[2][i + 2]);
    }


    if((col_win[1]&&col_win[1]==board[2][2])||(col_win[0]&&col_win[0]==board[1][1])||
       (row_win&&row_win==board[1][2])){
        return true;
    }

    else if ((diag_win[0] && diag_win[0] == board[0][2]) ||
             (diag_win[1] && diag_win[1] == board[0][2]))
    {return true;}
    return false;

};






