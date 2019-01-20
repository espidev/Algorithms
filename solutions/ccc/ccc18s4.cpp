#include <bits/stdc++.h>

using namespace std;
#define ull unsigned long long
#define MAXN 10000001
ull N, arr[MAXN];

ull rec(ull k) {
    if (k < MAXN && arr[k]) return arr[k];
    if (k == 1) return 1;
    ull sum = 0;
    for (ull i = 1; i <= k / 2;) {
        ull d = k / i, d2 = k / (i + 1);
        sum += (d - d2) * rec(i);
        i = k / d2;
    }
    if (k < MAXN) arr[k] = sum;
    return sum;
}

int main() {
    cin >> N;
    cout << rec(N) << endl;
    return 0;
}
