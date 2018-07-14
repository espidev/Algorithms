#include <bits/stdc++.h>
using namespace std;
 
#define MAXN 1000
 
/*
 * Given a tree T of N nodes, where each node i has Ci coins attached with it. You have to choose a subset of nodes such that no two adjacent 
 * nodes(i.e. nodes connected directly by an edge) are chosen and sum of coins attached with nodes in chosen subset is maximum.
 */

int N;
vector<int> v[MAXN];
int coins[MAXN];
int worth[MAXN];
bool visited[MAXN];
 
int dfs(int node, bool pickup) {
    if (worth[node] != 0) return worth[node];
    visited[node] = true;
    if (pickup) {
        int c = coins[node];
        for (int k : v[node]) {
            if (!visited[k]) c += dfs(k, false);
        }
        return c;
    } else {
        if (v[node].size() == 0) {
            return 0;
        }
        int c = 0;
        for (int k : v[node]) {
            if (!visited[k]) {
			int num = max(dfs(k, true), dfs(k, false));
			c += num;
			worth[k] = num;
		}
        }
        return c;
    }
}
 
int main () {
    cin >> N;
    int a, b;
    string s;
 
    for (int i = 0; i < N-1; i++) {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    for (int i = 1; i <= N; i++) cin >> coins[i];
 
    cout << max(dfs(1, true), dfs(1, false));
}