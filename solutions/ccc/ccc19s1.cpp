#include <bits/stdc++.h>
using namespace std;

int arr[2][2] = {{1, 2}, {3, 4}};

int main() {
    string s;
    cin >> s;
    for (char c : s) {
        if (c == 'H') {
            int t = arr[0][0];
            arr[0][0] = arr[1][0];
            arr[1][0] = t;
            t = arr[0][1];
            arr[0][1] = arr[1][1];
            arr[1][1] = t;
        } else if (c == 'V') {
            int t = arr[0][0];
            arr[0][0] = arr[0][1];
            arr[0][1] = t;
            t = arr[1][0];
            arr[1][0] = arr[1][1];
            arr[1][1] = t;
        }
    }
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}
