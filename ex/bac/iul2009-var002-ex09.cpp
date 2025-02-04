#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

int main() {
    char str[256], *p;

    cin.get(str, 256);

    for(int i = strlen(str) - 1; i >= 0; i--) {
        cout << str << '\n';
        str[i] = NULL;
    }

    return 0;
}