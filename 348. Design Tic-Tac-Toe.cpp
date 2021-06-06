/*
Link: https://leetcode.com/problems/design-tic-tac-toe/

Assume the following rules are for the tic-tac-toe game on an n x n board between two players:

A move is guaranteed to be valid and is placed on an empty block.
Once a winning condition is reached, no more moves are allowed.
A player who succeeds in placing n of their marks in a horizontal, vertical, or diagonal row wins the game.
Implement the TicTacToe class:

TicTacToe(int n) Initializes the object the size of the board n.
int move(int row, int col, int player) Indicates that player with id player plays at the cell (row, col) of the board. The move is guaranteed to be a valid move.
Follow up:
Could you do better than O(n2) per move() operation?

*/

// Milon

class TicTacToe {
public:
    /** Initialize your data structure here. */
    TicTacToe(int n) {
        N = n;
        row.resize(person, vector<int>(n, 0));
        column.resize(person, vector<int>(n, 0));
        leftDiag.resize(person, 0);
        rightDiag.resize(person, 0);
    }

    /** Player {player} makes a move at ({row}, {col}).
        @param row The row of the board.
        @param col The column of the board.
        @param player The player, can be either 1 or 2.
        @return The current winning condition, can be either:
                0: No one wins.
                1: Player 1 wins.
                2: Player 2 wins. */
    int move(int r, int c, int player) {
        row[player-1][r]++;
        column[player-1][c]++;
        if (r == c)
            leftDiag[player-1]++;
        if ((r+c) == (N-1))
            rightDiag[player-1]++;
        if (row[player-1][r] == N || column[player-1][c] == N || leftDiag[player-1] == N || rightDiag[player-1] == N)
            return player;
        return 0;
    }
private:
    const int person = 2;
    vector<vector<int>> row, column;
    vector<int> leftDiag;
    vector<int> rightDiag;
    int N;
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe* obj = new TicTacToe(n);
 * int param_1 = obj->move(row,col,player);
 */
