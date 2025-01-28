#include <iostream>
#include <bits/stdc++.h>
#include <string>

using namespace std;

bool are_anagrams(string s1, string s2) {
    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());
    if (s1 == s2) return true;

    return false;
}
int main()
{
    string string1, string2;

    cin >> string1 >> string2;

    if (are_anagrams(string1, string2)) cout << "Anagrams!";
    else cout << "Not anagrams!";
    return 0;
}
