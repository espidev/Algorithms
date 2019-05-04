#include <bits/stdc++.h>
using namespace std;
int N, M, dp[1001][1001];

int lcs(vector<int>& a, vector<int>& b, int i, int j) {
    if (!i || !j) return 0;
    if (dp[i][j] != -1) return dp[i][j];
    if (a[i-1] == b[j-1]) return dp[i][j] = 1 + lcs(a, b, i-1, j-1);
    return dp[i][j] = max(lcs(a, b, i-1, j), lcs(a, b, i, j-1));
}


int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    vector<int> a(N), b(M);

    for (int i = 0; i < N; i++) cin >> a[i];
    for (int i = 0; i < M; i++) cin >> b[i];

    memset(dp, -1, sizeof dp);
    printf("%d\n", lcs(a, b, N, M));
    return 0;
}
