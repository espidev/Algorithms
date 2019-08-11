#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long
#define mod 1000000007

ull N, dp[1000003];

ull dfs(int left) {
    if (left == 0) return 1;
    if (dp[left]) return dp[left] % mod;
    ull d = 0;
    for (int i = 1; i <= min(6, left); i++) d += dfs(left-i);
    return dp[left] = d % mod;
}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    cout << dfs(N) << endl;
    return 0;
}
