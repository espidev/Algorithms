#include <bits/stdc++.h>

using namespace std;
#define ll long long

ll N, a, b, dp[200001][2];
vector<int> adjList[200001];

ll dfs(int node, bool take, int from) {
    if (dp[node][take]) return dp[node][take];
    ll sum = 1;
    for (int i : adjList[node]) {
        if (i == from) continue;
        if (!take) {
            sum = (sum*(dfs(i, false, node) + dfs(i, true, node))) % ((ll) 1e9 + 7);
        } else {
            sum = (sum*dfs(i, false, node)) % ((ll)1e9 + 7);
        }
    }
    return dp[node][take] = sum;
}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for (int i = 0; i < N - 1; i++) {
        cin >> a >> b;
        adjList[a].push_back(b);
        adjList[b].push_back(a);
    }
    cout << ((dfs(1, false, -1) + dfs(1, true, -1)) % ((ll) 1e9 + 7)) << endl;
    return 0;
}
