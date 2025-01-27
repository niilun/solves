#include <iostream>
#include <cmath>

using namespace std;

// This program takes a number
// and displays it's factors

void fp(int n) {
    struct primeCounter {
        int factor;
        int power; 
    } factor;
    factor.factor = 2;

    while (n % 2 == 0) {
        factor.power++;
        n /= 2;
    }
    if (factor.power > 0) {
        cout << "    " << factor.factor << "^" << factor.power << "\n";
    }

    for (int i = 3; i <= sqrt(n); i += 2) {
        factor.factor = i;
        factor.power = 0;
        while (n % i == 0) {
            factor.power++;
            n /= i;
        }
        
        if (factor.power > 0) {
            cout << "    " << factor.factor << "^" << factor.power << "\n";
        }
    }

    if (n > 2) {
        factor.factor = n;
        factor.power = 1;
        cout << "    " << factor.factor << "^" << factor.power << "\n";
    }
}

int main() {
    int n;
    cout << "\nNumber: ";
    cin >> n;
    if(n <= 1) {
        cout<<"Number doesn't have factors or is negative.";
        return 0;
    }
    cout << "Factors:\n";
    fp(n);

    return 0;
}
