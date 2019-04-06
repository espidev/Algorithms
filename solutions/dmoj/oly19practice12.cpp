#include <bits/stdc++.h>
using namespace std;

int N, K, dp[2][20002], psa[20002], best[2][20002], pre = 0, cur = 1;

// array DP with optimization (prefix sum array "best" for speeding up)

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin >> N >> K;

    memset(dp, -0x3f, sizeof dp);
    memset(best, -0x3f, sizeof best);

    for (int i = 0; i < N; i++) {
        cin >> psa[i+1];
        psa[i+1] += psa[i];
    }

    dp[0][0] = 0;
    best[0][0] = 0;
    dp[1][0] = 0;

    for (int i = 1; i <= N; i++) {
        for (int k = 1; k <= K; k++) dp[cur][k] = max(dp[pre][k], best[pre][k-1] + psa[i]);
        for (int k = 0; k <= K; k++) best[cur][k] = max(best[pre][k], dp[cur][k] - psa[i]);
        swap(pre, cur);
    }
    printf("%d\n", dp[pre][K]);
    return 0;
}