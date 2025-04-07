#include <iostream>



using namespace std;

int n;



bool findSuccessorExists(int x[], int k) {

    if(x[k] < 1) {

        x[k]++;

        return true;

    }

    return false;

}



bool checkValid(int x[], int k) {

    int openCount = 0, closeCount = 0;



    for(int i = 0; i <= k; i++) {

        if (x[i] == 0) openCount++;

        else closeCount++;

        if(closeCount > openCount) return false;

    }

    return openCount <= n && closeCount <= n;

}



bool isSolve(int k) {

    return k == 2 * n - 1;

}



void printSolve(int arr[], int k) {

    for(int i = 0; i <= k; i++) {

        cout << (arr[i] == 0 ? '(' : ')');

    }

    cout << '\n';

}



int main()

{

    int x[100], k = 0, solveCount = 0;

    bool sucExists, isValid;

    x[k] = -1;



    cout << "n: "; cin >> n;



    while(k >= 0) {

        sucExists = true; isValid = false;

        while(sucExists && !isValid) {

            sucExists = findSuccessorExists(x, k);

            if(sucExists) isValid = checkValid(x, k);

        }

        if(sucExists) {

            if(isSolve(k)) {

                printSolve(x, k);

                solveCount++;

            } else {

                k++;

                x[k] = -1;

            }

        } else {

            k--;

        }

    }

    cout << solveCount << " solves found.";

    return 0;

}

