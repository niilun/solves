#include <iostream>

using namespace std;
int n;

bool findSuccessor(int x[], int k) {
    if(x[k] < n) {
        x[k]++;
        return true;
    }
    return false;
}

bool checkValid(int x[], int k) {
    for(int i = 0; i < k; i++) {
        if(x[i] == x[k]) return false;
    }
    return true;
}

bool isSolve(int k) {
    return n == k;
}

void printSolve(int x[], int k) {
    for(int i = 1; i < k + 1; i++) {
        cout << x[i] << ' ';
    }
    cout << '\n';
}

int main() {
    bool isValid, successorExists;
    int k = 1, x[100], solveCount = 0;
    x[k] = 0;

    cout << "n: "; cin >> n;

    while(k > 0) {
        successorExists = true; isValid = false;
        while(successorExists && !isValid) {
            successorExists = findSuccessor(x, k);
            if(successorExists) isValid = checkValid(x, k);
        }
        if(successorExists) {
            if(isSolve(k)) {
                printSolve(x, k);
                solveCount++;
            }
            else {
                k++;
                x[k] = 0;
            }
        }
        else k--;
    }
    cout << solveCount << " solves found.";
}