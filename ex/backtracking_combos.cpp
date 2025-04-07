#include <iostream>

using namespace std;
int n, p;

bool findSuccessorExists(bool sucExists, int x[], int k) {
    if(x[k] < n) {
        x[k]++;
        sucExists = true;
    }
    else sucExists = false;
    return sucExists;
}

bool checkValid(bool isValid, int x[], int k) {
    isValid = true;
    for(int i = 1; i < k; i++) {
        if(k > 1) {
            if(x[k] < x[k - 1]) isValid = false;
        }
        if(x[i] == x[k]) isValid = false;
    }
    return isValid;
}

bool isSolve(int k) {
    return k == p;
}

void printSolve(int arr[], int k) {
    for(int i = 1; i < p + 1; i++) {
        cout << arr[i] << ' ';
    }
    cout << '\n';
}

int main() {
    int x[100], k = 1, solveCount = 0;
    bool sucExists, isValid;
    x[k] = 0;

    cout << "n: "; cin >> n;
    cout << "p: "; cin >> p;

    while(k > 0) {
        sucExists = true; isValid = false;
        while(sucExists && !isValid) {
            sucExists = findSuccessorExists(sucExists, x, k);
            if(sucExists) isValid = checkValid(isValid, x, k);
        }
        if(sucExists) {
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
    return 0;
}
