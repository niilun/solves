#include <iostream>
#include <cstring>

using namespace std;

void splitString(const char* str, char* result) {
    size_t len = strlen(str);
    size_t half = len / 2;

    memcpy(result, str + half, half);
    memcpy(result, str, half);

    result[len] = '\0';
}

void clearbuf(char* str) {
    str[0] = '\0'; // clear buffer
}

int main() {
    char *p, text[256], final[256], tmp[256];
    
    cin.get(text, 256);

    p = strtok(text, " ");
    while(p != NULL) {
        clearbuf(tmp);

        if(strlen(p) % 2 == 0) {
            cout << "DEBUG: " << "hit " << p << '\n';
            splitString(p, tmp);
        }
        else strcpy(tmp, p);

        strcat(final, tmp);
        strcat(final, " ");

        p = strtok(NULL, " ");
    }
    cout << final;
    return 0;
}