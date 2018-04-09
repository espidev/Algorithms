#include <bits/stdc++.h>

/*
 * USACO
 * Your Ride Is Here
 */

using namespace std;

long long conv(string str) {
    long long ret = 1;
    for (int i = 0; i < str.length(); i++) {
        ret *= str[i] - 'A' + 1;
    }
    return ret;
}

int main() {
    ofstream fout ("ride.out");
    ifstream fin ("ride.in");
    string comet, name;
    fin >> comet >> name;
    if((conv(comet) % 47) == (conv(name) % 47)) {
        fout << "GO" << endl;
    } else {
        fout << "STAY" << endl;
    }
    return 0;
}
