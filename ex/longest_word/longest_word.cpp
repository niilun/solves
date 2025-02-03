#include <iostream>
#include <cstring>
#include <fstream>
#include <string>

using namespace std;

ifstream cuvin("lw.txt");

int main() {
    if(!cuvin) {
        cout << "File access error";
        return 1;
    }
    int maxlen = 0;
    string maxlen_word;
    string str;

    while (cuvin >> str) {
        if (str.length() >= maxlen) {
            maxlen = str.length();
            maxlen_word = str;
        }
    }
    cout << "The longest word is: " << maxlen_word << " with length " << maxlen << endl;
    cuvin.close();
    return 0;
}