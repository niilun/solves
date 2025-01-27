#include <iostream>

using namespace std;

bool isPerfectNumber(int num) {
    // 0 is not "perfect" by definition but does match the conditions to be one
    if (num == 0) return false;

    int sum = 0;
    for(int i = 1; i <= num/2; i++) {
        if (num % i == 0) sum += i;
    }

    if (sum == num) return true;
    return false;
}

void swapValues(int &x, int &y) {
    int aux;
    aux = x;
    x = y;
    y = aux;
}

int main() {
    int x, y;
    bool found = false;
    cout << "Enter an interval (x, y): "; cin >> x >> y;
    if (y < x) {
        swapValues(x, y);
        cout << "\nSwapping x and y to create a valid interval";
    }
    cout << "\nElements between " << x << " and " << y << " which are perfect:\n";

    for(int i = x; i <= y; i++) {
        if (isPerfectNumber(i)) {
            cout << i << " ";
            found = true;
        }
    }
    if (!found) cout << "None";

    return 0;
}