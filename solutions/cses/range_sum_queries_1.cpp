#include <bits/stdc++.h>
using namespace std;

long long N, Q, arr[10000001], prefix[10000001];


int main() {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> Q;

    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
        prefix[i] = prefix[i-1] + arr[i];
    }

    for (int i = 0; i < Q; i++) {
        int l, r;
        cin >> l >> r;
        cout << (prefix[r] - prefix[l-1]) << endl;
    }
    return 0;
}
