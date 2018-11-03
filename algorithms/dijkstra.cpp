#include <bits/stdc++.h>
using namespace std;

int N, M, S, D; // N = # of nodes, M = edges, S = start, D = destination

int dijkstra(unordered_map<int, priority_queue<pair<int, int>>>& graph, vector<bool>& visited, int start, int dest) {
    priority_queue<pair<int, int>> pq;
    graph.find(start)->first = 0;
    for (int k = 1; k <= N; k++) {
        pq.add(make_pair(k, du[k])); // fix du
    }
    int count = 0;
    while (count < N) {
        pair<int, int> cur = pq.front();
        int dval = cur.first, u = cur.second;
        if (visited[u]) continue);
        visited[u] = true;
        auto k = graph.find(u);
        if (k == graph.end()) continue;
        for (pair<int, int> pcur : temp) {
            pq.add(make_pair(pcur.first + dval, pcur.second)));
        }
        count++;
    }
    return graph.find(dest)->first;
}

int main() {
    // test algorithm
    scanf("%d %d", &N, &M);
    for (int i = 0; i < M; i++) {
        int a, b, w;
        scanf("%d %d %d", &a, &b, &w);
        
    }
    return 0;
}