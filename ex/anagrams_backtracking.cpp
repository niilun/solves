#include <iostream>
#include <cstring>
using namespace std;

int n,k;
char s[256];

bool succesor(bool hasSuccessor, int x[100], int k) {
    if (x[k] < n){
        x[k]++;
        hasSuccessor = true;
    }
    else hasSuccessor = false;
    return hasSuccessor;
}

bool valid(bool &isValid, int x[100], int k){
    isValid=true;
    for(int i = 1;i < k;i++){
        if(x[k]==x[i])isValid=false;
    }
    return isValid;
}

int checkSolve(int k){
    return k == n;
}

void printSolve(int x[100], int k){
    for(int i=1;i<=k;i++){
        cout<<s[x[i] - 1]<<' ';
    }
    cout<<endl;
}
int main()
{
    int x[100], count = 0;
    bool hasSuccessor, isValid;
    cout << "word: ";
    cin.get(s, 256);
    n = strlen(s);
    k = 1;
    while(k>0){
        hasSuccessor=true; isValid=false;
        while(hasSuccessor&&!isValid) {
            hasSuccessor=succesor(hasSuccessor,x,k);
            if (hasSuccessor) isValid=valid(isValid,x,k);
        }
        if(hasSuccessor)
            if (checkSolve(k)) {
                    printSolve(x, k);
                    count++;
            }
            else {
                k++;
                x[k] = 0;
            }
        else k--;
    }
    cout << "found " << count << " solutions.";
    return 0;
}
