#include <bits/stdc++.h>
using namespace std;
#define ll long long
int N, A, B, C;
ll prefix[1000001], dp[1000001];

ll findO(int r, int l) {
    ll ls = prefix[r] - prefix[l];
    return A*ls*ls + B*ls + C;
}

/*
 * Quadrangle inequality (easier optimization)
 */

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> A >> B >> C;
    memset(dp, -0x3f, sizeof dp);
    dp[0] = 0;
    for (int i = 1, last = 0; i <= N; i++) {
        cin >> prefix[i];
        prefix[i] += prefix[i-1];
        for (int j = last; j < i; j++) {
            if (dp[j] + findO(i, j) >= dp[i]) {
                dp[i] = dp[j] + findO(i, j);
                last = j;
            }
        }
    }
    cout << dp[N] << endl;
    return 0;
}

