#include <bits/stdc++.h>

using namespace std;

/*
 * CCC05J5
 */

int main() {
    while (true) {
        string in;
        cin >> in;
        if(in == "X") break;
        int s = 0;
        bool leave = false;
        bool n = true;
        for (int i = 0; i < in.length(); i++) {
            char ch = in[i];
            if (ch == 'S') {
                n = false;
                if (s > 0) {
                    s--;
                } else {
                    cout << "NO" << endl;
                    leave = true;
                    break;
                }
                if(in[i-1] == 'B' || in[i-1] == 'N') {
                    cout << "NO" << endl;
                    leave = true;
                    break;
                }
            }
            if (ch == 'B') {
                if(!n) {
                    cout << "NO" << endl;
                    leave = true;
                    break;
                }
                s++;
                n = true;
            }
            if (ch == 'A') {
                if(!n) {
                    cout << "NO" << endl;
                    leave = true;
                    break;
                }
                n = false;
            }
            if (ch == 'N') {
                if (n) {
                    cout << "NO" << endl;
                    leave = true;
                    break;
                } else {
                    n = true;
                }
            }
        }
        if(leave) continue;
        if (s != 0) {
            cout << "NO" << endl;
        } else if (n) {
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
        }
    }
    return 0;
}
