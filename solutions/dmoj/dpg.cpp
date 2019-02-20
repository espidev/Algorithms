#include <bits/stdc++.h>
using namespace std;
int N, M, a, b;
vector<int> adj[200001];
int dp[200001];

int dfs(int node) {
    if (dp[node]) return dp[node];
    if (adj[node].size() == 0) return 0;
    int m = dfs(adj[node][0]);
    for (int i = 1; i < adj[node].size(); i++) {
        m = max(m, dfs(adj[node][i]));
    }
    dp[node] = m+1;
    return dp[node];
}

set<int> s;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        cin >> a >> b;
        adj[a].push_back(b);
        s.insert(a);
    }
    int ans = 0;
    for (int l : s) {
        ans = max(ans, dfs(l));
    }
    cout << ans << endl;
    return 0;
}
