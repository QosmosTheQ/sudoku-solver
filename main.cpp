#include <iostream>
#include <vector>

using namespace std;

bool isSafe(vector<vector<int>>& board, int row, int col, int num) {
    // Check if 'num' is not present in the current row, current column, and the current 3x3 subgrid
    for (int i = 0; i < 9; ++i) {
        if (board[row][i] == num || board[i][col] == num ||
            board[row - row % 3 + i / 3][col - col % 3 + i % 3] == num) {
            return false;
        }
    }
    return true;
}

bool findEmptyLocation(vector<vector<int>>& board, int& row, int& col) {
    for (row = 0; row < 9; ++row) {
        for (col = 0; col < 9; ++col) {
            if (board[row][col] == 0) {
                return true;
            }
        }
    }
    return false;
}

bool solveSudoku(vector<vector<int>>& board) {
    int row, col;

    if (!findEmptyLocation(board, row, col)) {
        return true; // All cells filled
    }

    for (int num = 1; num <= 9; ++num) {
        if (isSafe(board, row, col, num)) {
            board[row][col] = num;
            if (solveSudoku(board)) {
                return true; // Successfully solved
            }
            board[row][col] = 0; // Backtrack if solution not found
        }
    }
    return false; // No solution found
}

void printBoard(const vector<vector<int>>& board) {
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    vector<vector<int>> sudokuBoard = {
        {1, 0, 0, 0, 0, 0, 0, 0, 3},
        {0, 0, 7, 2, 6, 0, 4, 8, 0},
        {4, 0, 0, 9, 3, 5, 0, 0, 6},
        {0, 3, 0, 4, 8, 0, 2, 0, 0},
        {0, 4, 1, 6, 0, 9, 3, 0, 0},
        {0, 0, 6, 0, 0, 0, 8, 9, 0},
        {5, 7, 8, 0, 4, 0, 0, 0, 2},
        {0, 0, 0, 3, 0, 0, 0, 7, 0},
        {2, 0, 0, 0, 0, 0, 0, 0, 5}
    };

    if (solveSudoku(sudokuBoard)) {
        printBoard(sudokuBoard);
    } else {
        cout << "No solution exists." << endl;
    }

    return 0;
}
