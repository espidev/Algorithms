#include <bits/stdc++.h>

using namespace std;
int T, N, K, W, arr[30001], dp[501][30001], sum[30001];

// simple dp ("simple")

int gsum(int a, int b) {
    if (b >= N) b = N - 1;
    if (a < 0) a = 0;
    return sum[b] - ((a == 0) ? 0 : sum[a - 1]);
}

int main() {
    cin.sync_with_stdio(1);
    cin.tie(0);
    cin >> T;
    for (int i = 0; i < T; i++) {
        memset(dp, 0, sizeof dp);
        cin >> N >> K >> W;
        for (int j = 0; j < N; j++) {
            cin >> arr[j];
            sum[j] = (j == 0) ? arr[j] : sum[j - 1] + arr[j];
        }

        for (int i = 0; i < N; i++) dp[1][i] = max(gsum(i, i+W-1), (i == 0) ? 0 : dp[1][i-1]);

        for (int i = 2; i <= K; i++) {
            for (int j = W*(i-1); j < N; j++) {
                dp[i][j] = max(dp[i-1][j-W] + gsum(j, j+W-1), dp[i][j-1]);
            }
        }

        cout << dp[K][N-1] << endl;
    }
    return 0;
}
