#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll N, W, weight[102], value[102], dp[2][100002];

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> W;
    for (int i = 0; i < N; i++) {
        cin >> weight[i] >> value[i];
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= W; j++) {
            if (weight[i-1] <= j) {
                dp[i % 2][j] = max(dp[(i - 1) % 2][j], value[i - 1] + dp[(i - 1) % 2][j - weight[i - 1]]);
            } else {
                dp[i%2][j] = dp[(i-1)%2][j];
            }
        }
    }

    cout << dp[N%2][W] << endl;
    return 0;
}

