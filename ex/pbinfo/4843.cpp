#include <iostream>
#include <sstream>

using namespace std;

int main() {
    string tmp, result, ln;
    bool usedSwap = false;
    getline(cin, ln); // read
    istringstream stream(ln);

    while (stream >> tmp) {
        if (tmp.size() % 2 == 0) {
            size_t half = tmp.size() / 2;
            result += tmp.substr(half) + tmp.substr(0, half);
            usedSwap = true;
        } else {
            result += tmp;
        }
        result += ' ';
    }
    if(usedSwap) {
        cout << result;
    }
    else cout << "No swap occured.";
}