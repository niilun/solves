#include <iostream>
#include <cstring>

using namespace std;

int main() {
    char str[255];
    int lower_count = 0;
    cin.get(str, 255);

    for(int i = 0; i < strlen(str); i++) {
        if (str[i] >= 'a' && str[i] <= 'z') lower_count++;
    }

    cout << "Count: " << lower_count;
    return 0;
}