#include <iostream>
#include <fstream>

using namespace std;

ifstream in("checkchain.in");
ofstream out("checkchain.out");
int matches[105][105] = {0}, chain[105][105], len[105];

void checkChainType(int chain_num) {
    bool has_differing_nums = true;
    bool chain_valid = true;
    for (int i = 1; i <= len[chain_num]; i++) {
        for (int j = 1; j <= len[chain_num]; j++) {
            if (i != j && chain[chain_num][i] == chain[chain_num][j]) {
                has_differing_nums = false;
                break;
            }
        }
    }

    for (int i = 1; i < len[chain_num]; i++) {
        if (!matches[chain[chain_num][i]][chain[chain_num][i + 1]]) {
            chain_valid = false;
            break;
        }
    }

    if (chain_valid) {
        if (has_differing_nums) {
            out << "ELEMENTARY" << '\n';
        }
        else out << "NONELEMENTARY" << '\n';
    }
    else out << "NOTACHAIN\n";
}

int main() {
    int n, m, k, tmp1, tmp2;

    in >> n >> m;
    for (int i = 1; i <= m; i++) {
        in >> tmp1 >> tmp2;
        matches[tmp1][tmp2] = 1;
        matches[tmp2][tmp1] = 1;
    }
    in >> k;
    for (int i = 1; i <= k; i++) {
        in >> len[i];
        for (int j = 1; j <= len[i]; j++) {
            in >> chain[i][j];
        }
    }

    for (int i = 1; i <= k; i++) checkChainType(i);
}