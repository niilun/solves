#include <iostream>
#include <cstring>

using namespace std;

int main() {
    char to_change_1, to_change_2, string[250];
    cin.get(to_change_1);
    cin.get();
    cin.get(to_change_2);
    cin.get();
    cin.get(string, 250);
    
    char changed_string[250];
    strcpy(changed_string, string);
    
    for(int i = 0; i < strlen(string); i++) {
        if(string[i] == to_change_1) changed_string[i] = to_change_2;
        if(string[i] == to_change_2) changed_string[i] = to_change_1;
    }
    
    cout << '\n' << string << '\n' << changed_string;
    
    return 0;
}