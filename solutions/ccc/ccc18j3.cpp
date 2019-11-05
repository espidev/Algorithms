#include <bits/stdc++.h>
using namespace std;

int pos[5];

int main() {
        for (int i = 1; i <= 4; i++) {
                cin >> pos[i];
                pos[i] += pos[i-1];
        }

        for (int i = 0; i < 5; i++) {
                for (int j = 0; j < 5; j++) {
                        cout << abs(pos[j] - pos[i]) << " ";
                }
                cout << endl;
        }
}
