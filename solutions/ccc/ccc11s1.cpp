#include <bits/stdc++.h>
using namespace std;

int N, ts, ss;

int main() {
        cin >> N;
        cin.ignore();
        for (int i = 0; i < N; i++) {
                string s;
                getline(cin, s);
                for (char ch : s) {
                        if (ch == 't' || ch == 'T') ts++;
                        if (ch == 's' || ch == 'S') ss++;
                }
        }
        cout << (ts > ss ? "English" : "French") << endl;
        return 0;
}
