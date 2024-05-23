#include <iostream>
#include <vector>
#include <string>

using namespace std;

const int SIZE = 9;

// Function to print the board
void printBoard(const vector<vector<int>>& board) {
    for (int row = 0; row < SIZE; ++row) {
        for (int col = 0; col < SIZE; ++col) {
            if (col == 3 || col == 6)
                cout << " | ";
            cout << (board[row][col] ? to_string(board[row][col]) : ".") << " ";
        }
        if (row == 2 || row == 5) {
            cout << endl;
            for (int i = 0; i < SIZE; ++i)
                cout << "---";
        }
        cout << endl;
    }
}

// Function to check if a move is valid
bool isValidMove(const vector<vector<int>>& board, int row, int col, int num) {
    for (int x = 0; x < SIZE; ++x) {
        if (board[row][x] == num || board[x][col] == num)
            return false;
    }

    int startRow = row - row % 3, startCol = col - col % 3;
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            if (board[i + startRow][j + startCol] == num)
                return false;

    return true;
}

// Function to check if the board is complete
bool isBoardComplete(const vector<vector<int>>& board) {
    for (int row = 0; row < SIZE; ++row)
        for (int col = 0; col < SIZE; ++col)
            if (board[row][col] == 0)
                return false;
    return true;
}

int main() {
    vector<vector<int>> board = {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}
    };

    vector<vector<int>> initialBoard = board; // Keep track of the initial puzzle

    while (!isBoardComplete(board)) {
        printBoard(board);
        int row, col, num;
        cout << "Enter row (1-9), column (1-9) and number (1-9) to place, or 0 to clear cell (or -1 to exit): ";
        cin >> row;
        system("cls");
        if (row == -1) {
            cout << "Exiting..." << endl;
            break;
        }
        cin >> col >> num;
        system("cls");
        row--; col--; // adjust to 0-indexed

        if (num == 0) {
            if (initialBoard[row][col] == 0) {
                board[row][col] = 0;
                cout << "Cell cleared." << endl;
            } else {
                cout << "Cannot clear a cell from the initial puzzle." << endl;
            }
        } else if (board[row][col] == 0 && isValidMove(board, row, col, num)) {
            board[row][col] = num;
        } else {
            cout << "Invalid move. Try again." << endl;
        }
    }

    if (isBoardComplete(board)) {
        cout << "Congratulations! You've completed the Sudoku puzzle!" << endl;
    }

    return 0;
}