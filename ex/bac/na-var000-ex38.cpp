#include <iostream>
#include <cmath>
using namespace std;

bool isPrime(int num) {
    for(int i = 2; i <= sqrt(num); i++) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

int smallestDivisor(int num) {
    if (num < 1) {
        cout << "Number is not positive";
        return 0;
    }

    for(int i = 2; i <= num; i++) {
        if(isPrime(i) && (num % i == 0)) return i;
    }
}
int main() {
    int n, i, nums[100];
    bool found = false;
    cout << "Input a number: ";
    cin >> n;
    cout << "\nInput exactly " << n << " numbers: ";
    for(i = 0; i < n; i++) {
        cin >> nums[i];
        if (smallestDivisor(nums[i]) == nums[i]) {
                cout << nums[i] << " ";
                found = true;
        }
    }

    if (!found) cout << "\nNone of the numbers are their own smallest divisor.";
    return 0;
}
