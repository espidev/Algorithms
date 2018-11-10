#include <bits/stdc++.h>
using namespace std;

int N, M, S, D; // N = # of nodes, M = edges, S = start, D = destination

int dijkstra(unordered_map<int, vector<pair<int, int>>>& graph, int start, int dest) {
    int dist[N+1];
    memset(dist, 1e9, sizeof dist);
    dist[start] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push(make_pair(start, 0));

    while (!pq.empty()) {
        pair<int, int> pv = pq.top();
        pq.pop();
        printf("%d %d\n", pv.first, pv.second);
        if (pv.second == dest) break;
        vector<pair<int, int>> v = graph.find(pv.second)->second;
        for (pair<int, int> p : v) {
            if (dist[p.first] > pv.second + p.second) {
                dist[p.first] = pv.second + p.second;
                pq.push(make_pair(dist[p.first], p.first));
            }
        }
    }
    return dist[dest];
}

int main() {
    // test algorithm
    scanf("%d %d %d %d", &N, &M, &S, &D);
    unordered_map<int, vector<pair<int, int>>> graph; // node a, node b, weight
    for (int i = 0; i < M; i++) {
        int a, b, w;
        scanf("%d %d %d", &a, &b, &w);
        auto d = graph.find(a);
        if (d == graph.end()) {
            vector<pair<int, int>> v;
            v.push_back(make_pair(b, w));
            graph.insert(make_pair(a, v));
        } else {
            d->second.push_back(make_pair(b, w));
        }
    }
    printf("%d\n", dijkstra(graph, S, D));
    return 0;
}