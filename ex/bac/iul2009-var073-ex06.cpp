#include <iostream>
#include <cstring>

using namespace std;

int main() {
    char str[255], voc[] = "aeiou", longest_str[255];
    int n, i, j, voc_count, longest_voc_count = 0;

    cin >> n;
    cin.ignore();
    for(i = 0; i < n; i++) {
        cin.getline(str, 255);
        voc_count = 0;
        for(j = 0; j < strlen(str); j++) {
            if(strchr(voc, str[j]) != NULL) voc_count++;
        }

        if (voc_count >= longest_voc_count) {
            longest_voc_count = voc_count;
            strcpy(longest_str, str);
        }
    }

    cout << longest_str;
    return 0;
}