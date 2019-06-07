#include <bits/stdc++.h>
using namespace std;
int N, dp[1000005][26];
string s;

int lcs(string& a, string& b, int i, int j) {
    if (!i || !j) return 0;
    if (dp[i][j] != -1) return dp[i][j];
    if (a[i-1] == b[j-1]) return dp[i][j] = 1 + lcs(a, b, i-1, j-1);
    return dp[i][j] = max(lcs(a, b, i-1, j), lcs(a, b, i, j-1));
}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> s;

    memset(dp, -1, sizeof dp);

    string ns = "", alpha = "abcdefghijklmnopqrstuvwxyz";
    for (char ch : s) ns += tolower(ch);

    cout << lcs(ns, alpha, N, 26) << endl;
    
    return 0;
}
