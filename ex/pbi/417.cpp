#include <iostream>
#include <fstream>

using namespace std;

ifstream in("maxgrade.in");
ofstream out("maxgrade.out");

int matches[100][100] = {0};

int getMatches(int node, int n) {
    int counter = 0;
    for(int i = 1; i <= n; i++) {
        if (matches[node][i]) counter++;
    }

    return counter;
}

int main() {
    int n, m, tmp1, tmp2, max;

    in >> n;
    while(in >> tmp1 >> tmp2) {
        matches[tmp1][tmp2] = 1;
        matches[tmp2][tmp1] = 1;
    }

    for(int i = 1; i <= n; i++) {
        int matches = getMatches(i, n);
        if (matches > max) max = matches;
    }
    out << max - 1 << ' ';

    for(int i = 1; i <= n; i++) {
        if (getMatches(i, n) == max) out << i << ' ';
    }
    return 0;
}