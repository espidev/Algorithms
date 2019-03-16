#include <bits/stdc++.h>

#define MAXN 2000002
#define ll long long

using namespace std;
int N, L, q[MAXN], f = 0, r = 0;
ll dp[MAXN], s[MAXN];

double slopething(int j, int k) {
    return (double) (dp[k] + s[k] * s[k] - dp[j] - s[j] * s[j]) / (2 * (s[k] - s[j]));
}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> L;
    L++;
    for (int i = 1; i <= N; i++) {
        cin >> s[i];
        s[i] += s[i - 1] + 1;

        while (f < r && slopething(q[f], q[f + 1]) <= s[i] - L) {
            f++;
        }

        dp[i] = dp[q[f]] + (s[i] - s[q[f]] - L) * (s[i] - s[q[f]] - L);

        while (f < r && slopething(q[r - 1], q[r]) > slopething(q[r], i)) {
            r--;
        }
        q[++r] = i;
    }

    cout << dp[N] << endl;
    return 0;
}
