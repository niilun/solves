#include <iostream>
#include <cstring>

using namespace std;

int main() {
    char str[40];
    char voc[] = "aeiou";

    cin.get(str, 40);
    for(int i = 0; i < strlen(str); i++) {
        if (strchr(voc, str[i]) != NULL) cout << str[i] << ' ';
    }

    return 0;
}