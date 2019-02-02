#include <bits/stdc++.h>
using namespace std;
int N, k, l;

int main() {
        cin.tie(0);
        cin.sync_with_stdio(0);
        cin >> N;
        for (int i = 0; i < N; i++) {
                cin >> l;
                k ^= l;
        }
        cout << k << endl;
}
