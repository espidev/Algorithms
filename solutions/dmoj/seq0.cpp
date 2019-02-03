#include <bits/stdc++.h>
using namespace std;
long long N, a, dp[1000000][2];

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> a;
    dp[0][true] = a;
    for (int i = 1; i < N; i++) {
        cin >> a;
        dp[i][true] = dp[i-1][false] + a;
        dp[i][false] = max(dp[i-1][true], dp[i-1][false]);
    }
    long long ans = max(dp[N-1][true], dp[N-1][false]);
    cout << ((ans < 0) ? 0 : ans) << endl;
    return 0;
}

