#include<iostream>
#include<vector>

using namespace std;

bool isSafe(vector<vector<int>>& board,
            int row,
            int col,
            int n) {

    // Check left side
    for(int i = 0; i < col; i++) {

        if(board[row][i] == 1)
            return false;
    }

    // Upper diagonal
    for(int i = row, j = col;
        i >= 0 && j >= 0;
        i--, j--) {

        if(board[i][j] == 1)
            return false;
    }

    // Lower diagonal
    for(int i = row, j = col;
        i < n && j >= 0;
        i++, j--) {

        if(board[i][j] == 1)
            return false;
    }

    return true;
}

bool solveNQueen(vector<vector<int>>& board,
                 int col,
                 int n) {

    // All queens placed
    if(col >= n)
        return true;

    for(int row = 0; row < n; row++) {

        if(isSafe(board,
                  row,
                  col,
                  n)) {

            // Place queen
            board[row][col] = 1;

            // Recursive call
            if(solveNQueen(board,
                           col + 1,
                           n))
                return true;

            // Backtrack
            board[row][col] = 0;
        }
    }

    return false;
}

void printBoard(vector<vector<int>>& board,
                int n) {

    cout << "\nSolution:\n";

    for(int i = 0; i < n; i++) {

        for(int j = 0; j < n; j++) {

            cout << board[i][j] << " ";
        }

        cout << endl;
    }
}

int main() {

    int n;

    cout << "Enter Value of N: ";
    cin >> n;

    vector<vector<int>> board(
        n,
        vector<int>(n, 0));

    if(solveNQueen(board, 0, n)) {

        printBoard(board, n);
    }
    else {

        cout << "Solution Not Possible";
    }

    return 0;
}