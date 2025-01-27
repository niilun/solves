#include <iostream>

using namespace std;

int main() {
    int mat[100][100], n;
    float max = INT_MIN;
    // input & get max
    cout << "Enter a number: "; cin >> n;
    
    if(n > 100) {
        cout << "Matrix is too big, please use a number less than 100";
        return 0;
    }
    cout << "\nEnter a matrix of " << n << " lines & columns:\n";
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++) {
            cin>>mat[i][j];
            if(mat[i][j] > max) max = mat[i][j];
        }
    
    cout << "Max is " << max;
    return 0;
}