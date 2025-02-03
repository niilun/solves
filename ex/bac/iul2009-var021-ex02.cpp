#include <iostream>
#include <cstring>

using namespace std;

int main() {
    char str[250];
    cin.get(str, 250);

    for(int i = 0; i <= strlen(str); i++) {
        if ((str[i] == str[i + 1]) && strchr(" *", str[i]) == NULL && strchr(" *", str[i + 1]) == NULL) cout << str[i] << str[i + 1] << '\n';
    }
    
    return 0;
}