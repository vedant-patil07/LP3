#include <iostream>
#include <vector>
#include<math.h>

using namespace std;

void printBoard(const vector<int>& board) {
    int N = board.size();
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            cout << (board[i] == j ? "Q " : ". ");
        cout << endl;
    }
    cout << endl;
}

bool isSafe(const vector<int>& board, int row, int col) {
    for (int i = 0; i < row; i++) {
        if (board[i] == col || abs(board[i] - col) == abs(i - row))
            return false;
    }
    return true;
}

void solveNQueens(vector<int>& board, int row, int& solutionCount) {
    int N = board.size();
    if (row == N) {
        printBoard(board);
        solutionCount++; // Increment the solution count
        return;
    }
    for (int col = 0; col < N; col++) {
        if (isSafe(board, row, col)) {
            board[row] = col; // Place queen
            solveNQueens(board, row + 1, solutionCount); // Recur for next row
        }
    }
}

int main() {
    int N;
    cout << "Enter the number of queens (N): ";
    cin >> N;
    vector<int> board(N, -1); // Initialize board
    int solutionCount = 0; // Variable to count solutions
    solveNQueens(board, 0, solutionCount);
    cout << "Total number of solutions: " << solutionCount << endl; // Print the count
    return 0;
}

