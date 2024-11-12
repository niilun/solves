#include <iostream>
#include <cmath>

using namespace std;

// 1
long long repeat_adds(int a, int b) {
    if (b==1) return a;
    else return repeat_adds(a, b-1) + a;
}

// 2
long long power(int n, int pow) {
    if (pow==1) return n;
    else return power(n, pow-1) * n;
}

// 3
int ack(int m, int n) {
    if (m==0) return n+1;
    else if (n==0) return ack(m - 1, 1);
    else return ack(m - 1, ack(m, n - 1));
}

// 4 (polynomial)
long long cebasev(int val, int x) {
    if (val==0) return 1;
    else if (val==1) return x;
    else if (val>=2) return 2 * x * cebasev(val-1, x) - cebasev(val-2, x);
    else return 0;
}

// 5 (polynomial)
long long hermite(int val, int x) {
    if (val==0) return 1;
    else if (val==1) return x;
    else if (val>1) return hermite(val-1, x) - (val - 1) * hermite(val-2, x);
    else return 0;
}

// 6
long long algo1(int n) {
    if (n==1) return 2;
    else return algo1(n-1) + (pow(-1, n+1) * n * (2 * n));
}

// 7
long long algo2(int n) {
    if (n==1) return 1;
    else return n * algo2(n-1);
}

int count_consonants(int num) {
    continue //todo
}

int main()
{
    return 0;
}
