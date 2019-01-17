#include <bits/stdc++.h>
using namespace std;
int N, T, K, D, cost[5001], price[5001], a, b, c;
vector<vector<pair<int, int>>> adj;

// simple dijkstra implementation

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    for (int i = 0; i < 5001; i++) {
        cost[i] = 1e9;
        price[i] = -1;
    }
    cin >> N >> T;
    adj = vector<vector<pair<int, int>>>(N+1);
    for (int i = 0; i < T; i++) {
        cin >> a >> b >> c;
        adj[a].push_back(make_pair(b, c));
        adj[b].push_back(make_pair(a, c));
    }
    cin >> K;
    for (int i = 1; i <= K; i++) {
        cin >> a >> b;
        price[a] = b;
    }
    cin >> D;
    // dijkstra
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    q.push(make_pair(0, D));
    cost[D] = 0;
    while (!q.empty()) {
        for (pair<int, int> p : adj[q.top().second]) {
            if (p.second + q.top().first < cost[p.first]) {
                cost[p.first] = p.second + q.top().first;
                q.push(make_pair(cost[p.first], p.first));
            }
        }
        q.pop();
    }

    int m = 1e9; // minimum cost
    for (int i = 1; i <= N; i++) {
        if (cost[i] + price[i] < m && price[i] != -1) {
            m = cost[i] + price[i];
        }
    }
    cout << m << endl;
    return 0;
}
