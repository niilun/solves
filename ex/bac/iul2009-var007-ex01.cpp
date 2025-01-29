#include <iostream>
#include <cstring>

using namespace std;

int main() {
    char input[255], voc[] = "aeiouAEIOU";
    cin.get(input, 255);
    
    // find the first non match for vocals and shift the entire string to the left
    for (int i = 0; i < strlen(input); i++) {
        if (strchr(voc, input[i]) == NULL) {
            strcpy(input + i, input + i + 1);
            break;
        }
    }
    
    // backwards
    for (int i = strlen(input); i > 0; i--) {
        if (strchr(voc, input[i]) == NULL) {
            strcpy(input + i, input + i + 1);
            break;
        }
    }

    cout << input;
    return 0;
}