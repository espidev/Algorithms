#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;

    for (int i = 0; i < 5; i++) {
        int N, cp = 0;
        cin >> N;
        for (int j = 0; j <= N; j++) {
            while (getline(cin, s)) {
                if (s == "") break;
                for (char c : s) if (c == '#') cp++;
            }
        }
        cout << ceil(1.0*cp / 25) << endl;
    }
    return 0;
}