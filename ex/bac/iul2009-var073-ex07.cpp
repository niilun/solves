#include <iostream>
#include <cstring>

using namespace std;

int main() {
    char str1[255], str2[255], rim1[255], rim2[255];
    int p;

    cin.get(str1, 255);
    cin.get();
    cin.get(str2, 255);
    cin >> p;
    
    for(int i = 0; i < p; i++) {
        strcpy(rim1 + i, str1 + strlen(str1) - i - 1);
        strcpy(rim2 + i, str2 + strlen(str2) - i - 1);
    }

    if(strcmp(rim1, rim2) == 0) cout << "rime!";
    else cout << "nu sunt rime!";

}