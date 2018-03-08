#include <bits/stdc++.h>

using namespace std;

int main() {
    int N, P1, P2, P3, played = 0;
    cin >> N >> P1 >> P2 >> P3;
    while(true) {
        if(++P1 == 35) {
            N += 30;
            P1 = 0;
        }
        N--;
        played++;
        if(N == 0) break;
        if(++P2 == 100) {
            N += 60;
            P2 = -0;
        }
        N--;
        played++;
        if(N == 0) break;
        if(++P3 == 10) {
            N += 9;
            P3 = 0;
        }
        N--;
        played++;
        if(N == 0) break;
    }
    cout << "Martha plays " << played << " times before going broke." << endl;
    return 0;
}
