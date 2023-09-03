    #include <iostream>
#include <vector>

using namespace std;

bool isSafe(vector<vector<int>>& board, int row, int col, int num) {
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
            if (j == 3 || j == 6) {
                cout << "| "; // Separate boxes
            }
            cout << (board[i][j] == 0 ? "-" : to_string(board[i][j])) << " ";
        }
        cout << endl;
        if (i == 2 || i == 5) {
            cout << "------+-------+------" << endl; // Separate boxes
        }
    }
}

int main() {
    vector<vector<int>> sudokuBoard(9, vector<int>(9, 0));

    cout << "Enter the Sudoku board (enter 0 for empty cells):" << endl;
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            cin >> sudokuBoard[i][j];
        }
    }

    if (solveSudoku(sudokuBoard)) {
        cout << "\nSudoku solved:\n" << endl;
        printBoard(sudokuBoard);
    } else {
        cout << "\nNo solution exists." << endl;
    }

    return 0;
}
