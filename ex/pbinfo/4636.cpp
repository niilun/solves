#include <iostream>
#include <fstream>

using namespace std;

ifstream in("hamiltonian.in");
ofstream out("hamiltonian.out");

int matches[100][100], n, m;

bool checkValid(int x[], int k) {
    for(int i = 1; i < k; i++) {
        // fail if two of the same node
        if (x[k] == x[i]) return false;
    }
    // if there's no edge between the two nodes, fail
    if(k > 1 && !matches[x[k-1]][x[k]]) return false;
    return true;
}

bool isSolve(int x[], int k) {
    return k == n;
}

void printSolve(int x[], int k) {
    for(int i = 1; i <= k; i++) {
        out << x[i] << ' ';
    }
    out << '\n';
}

int main() {
    int k, x[100], tmp1, tmp2;
    bool foundChain = false;
    
    in >> n >> m;
    for(int i = 1; i <= m; i++) {
        in >> tmp1 >> tmp2;
        matches[tmp1][tmp2] = 1;
        matches[tmp2][tmp1] = 1;
    }

    for(int node = 1; node <= 1; node++) {
        k = 1;
        x[k] = node;
        x[k + 1] = 0;
        while(k > 0) {
            bool successorExists = false, isValid = false;
            do {
                x[k]++;
                if(x[k] <= n) {
                    isValid = checkValid(x, k);
                    successorExists = true;
                }
            } while(successorExists && !isValid && x[k] <= n);
            if(successorExists && isValid) {
                if(isSolve(x, k)) {
                    printSolve(x, k);
                    foundChain = true;
                } else {
                    k++;
                    x[k] = 0;
                }
            } else {
                k--;
            }
        }
    }
    if(!foundChain) out << "NU EXISTA";
    return 0;
}