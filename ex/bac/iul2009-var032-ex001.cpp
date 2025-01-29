#include <iostream>
#include <cstring>

using namespace std;

int main() {
    char string[70], voc[] = "aeiouAEIOU";
    int pair_count = 0, i;
    cin.get(string, 70);
    
    for(i = 0; i < strlen(string) - 1; i++) {
        if(strchr(voc, string[i]) != NULL && strchr(voc, string[i + 1]) != NULL) {
            cout << "(" << string[i] << ", " << string[i + 1] << ')';
            pair_count++;
        }
    }
    
    cout << "\nPair count: " << pair_count;
    
    return 0;
}