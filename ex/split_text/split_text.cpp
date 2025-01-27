#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

ifstream in("input.in");
ofstream outmax("maxlen.out");
ofstream outpalindrome("palindrome.out");
ofstream outsorted("sorted.out");

bool check_palindrome(char word[256]) {
    // lower so chars are equal in ASCII encoding
    word = strlwr(word);
    char reverse[256];
    strcpy(reverse, word);
    strrev(reverse);
    
    // strcmp returns 0 if strings are equal
    if (strcmp(word, reverse) == 0) return true;
    return false;
}

int main() {
    char str[256], maxword[256];
    vector<string> split_input;
    int i = 0;

    if (!in || !outmax || !outpalindrome || !outsorted) cout << "Error when opening one or more files for read/write."; return 1;
    
    // read and check for words matching conditions
    while(in >> str) {
        if (strlen(str) > strlen(maxword)) strcpy(maxword, str);
        // if it's a palindrome stdout to file
        if (check_palindrome(str)) outpalindrome << str;

        // finally, add it to a vector to iterate later on
        split_input.push_back(str);
    }

    sort(split_input.begin(), split_input.end());
    for (string word : split_input) outsorted << word << '\n';

    // get the longest word and it's length to outmax
    outmax << strlen(maxword) << '\n' << maxword;
    cout << "Completed, check output files.";
    return 0;
}
