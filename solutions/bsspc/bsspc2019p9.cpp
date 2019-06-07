#include <bits/stdc++.h>
using namespace std;

unsigned long long N, K, dp[1<<25], arr[30][30];

int main() {
    scanf("%d", &N);

    for (int i = 0; i < 1<<25; i++) dp[i] = INT_MAX;

    dp[0] = 0;

    for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) {
        scanf("%d", &arr[i][j]);
    }

    for (int i = 0; i < 1<<N; i++) {
        int x = __builtin_popcount(i);
        for (int j = 0; j < N; j++) {
            if (!(i & (1<<j))) dp[i|(1<<j)] = min(dp[i|(1<<j)], dp[i]+arr[x][j]);
        }
    }
    printf("%llu\n", dp[(1<<N)-1]);
    return 0;
}
