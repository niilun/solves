#include <iostream>

using namespace std;
int n;

bool findSuccessorExists(bool sucExists, int x[], int k) {
    if(x[k] < 2 * n) {
        x[k] += 2;
        sucExists = true;
    }
    else sucExists = false;
    return sucExists;
}

bool checkValid(bool isValid, int x[], int k) {
    isValid = true;
    for(int i = 0; i < k; i++) {
        if(x[i] == x[k]) isValid = false;
    }
    return isValid;
}

bool isSolve(int k) {
    return k == n;
}

void printSolve(int arr[], int k) {
    for(int i = 1; i < n + 1; i++) {
        cout << arr[i] << ' ';
    }
    cout << '\n';
}

int main()
{
    int x[100], k = 1, solveCount = 0;
    bool sucExists, isValid;
    x[k] = 0;

    cout << "n: "; cin >> n;

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
