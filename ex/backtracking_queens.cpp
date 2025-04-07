#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<int> board; // Represents the permutation of queen positions
int solveCount = 0;

// Function to check if the current permutation is a valid solution
bool isValid(const vector<int>& board) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            // Check if queens threaten each other diagonally
            if (abs(board[i] - board[j]) == abs(i - j)) {
                return false;
            }
        }
    }
    return true;
}

// Function to print the solution
void printSolution(const vector<int>& board) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i] == j) {
                cout << "Q ";
            } else {
                cout << ". ";
            }
        }
        cout << '\n';
    }
    cout << '\n';
}

int main() {
    cout << "n: ";
    cin >> n;

    // Initialize the board with a permutation of column indices
    board.resize(n);
    for (int i = 0; i < n; i++) {
        board[i] = i;
    }

    // Generate all permutations of the board
    do {
        if (isValid(board)) {
            printSolution(board);
            solveCount++;
        }
    } while (next_permutation(board.begin(), board.end()));

    cout << solveCount << " solutions found.\n";
    return 0;
}
