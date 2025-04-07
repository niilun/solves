#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

// initialize all to 0
int char_frequency[26] = {};

int main()
{
    char vowels[] = "aeiou", str[100], str_upper_vowels[100], *p, x[100], y[100], last_word[100];
    int vow_count;
    vector<string> split;

    cin.get(str, 100);
    cin.get();
    cin.get(x, 100);
    cin.get();
    cin.get(y, 100);

    // lower
    strlwr(str);
    strcpy(str_upper_vowels, str);

    // iterate to get vowels, freq and uppercase
    for(int i = 0; i < strlen(str); i++) {
        // if vowel increment count and uppercase letter at i
        if(strchr(vowels, str[i]) != NULL) {
                vow_count++;
                str_upper_vowels[i] -= 32;
        }
        if(str[i] != ' ') char_frequency[str[i] - 'a']++;

    }

    // tokenize input into a vector
    p = strtok(str, " .,-");
    while(p) {
        strcpy(last_word, p);
        if(strcmp(p, x) == 0) strcpy(p, y);
        split.push_back(p);
        p = strtok(NULL, " .,-");
    }

    cout << "vowels: " << vow_count << '\n';
    cout << "uppercase vowels: " << str_upper_vowels << '\n';
    for(int i = 0; i < 26; i++) {
        cout << "char " << char(i + 97) << " appeared " << char_frequency[i] << " times" << '\n';
    }

    cout << "alphabetically ordered: " << '\n' << '\n';

    // sort alphabetically
    sort(split.begin(), split.end());
    for(string word : split) {
        cout << word << '\n';
    }
    return 0;
}
