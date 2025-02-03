#include <iostream>
#include <cstring>

using namespace std;

int main() {
    char str[255], voc[] = "aeiou";

    cin.get(str, 255);
    strlwr(str);

    for(int i = 0; i < strlen(str); i++) {
        if(strchr(voc, str[i]) != NULL) str[i] -= 32;
    }

    cout << str;

    return 0;
}