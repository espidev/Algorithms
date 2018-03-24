#include <bits/stdc++.h>

using namespace std;

int N;

/*
 * Bitmask (find all subsets)
 */

int main() {
    cin >> N;
    string num[N];
    for(int i = 0; i < N; i++) {
        cin >> num[i];
    }
    for (int j = 0; j < (1 << N); j++) {
        int k = j;
        for (int v = 0; k > 0; v++) {
            if ((k & 1) != 0) {
                cout << num[v] << " ";
            }
            k = k >> 1;
        }
        cout << endl;
    }
    return 0;
}
