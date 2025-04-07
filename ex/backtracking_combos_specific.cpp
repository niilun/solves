#include <iostream>

using namespace std;
int n = 5, p;

// {1, 3, 5, 8, 9}

bool findSuccessorExists(bool sucExists, int x[], int k) {
    if(x[k] == 0) x[k] = 1;
    else if(x[k] == 1) x[k] = 3;
    else if(x[k] == 3) x[k] = 5;
    else if(x[k] == 5) x[k] = 8;
    else if(x[k] == 8) x[k] = 9;
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
