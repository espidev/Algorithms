#include <bits/stdc++.h>
using namespace std;

int N, M, S, D; // N = # of nodes, M = edges, S = start, D = destination

// map: (node a, (node b, weight))
int dijkstra(unordered_map<int, vector<pair<int, int>>>& graph, int start, int dest) {
    // init
    int weight[N+1];
    memset(weight, 1e9, sizeof weight);
    weight[start] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq; // weight, node
    pq.push(make_pair(0, start));

    // bfs
    while (!pq.empty()) {
        pair<int, int> pv = pq.top();
        pq.pop();

        printf("%d %d\n", pv.first, pv.second);
        for (pair<int, int> p : graph.find(pv.second)->second) { // node b, weight
            if (weight[p.first] > pv.first + p.second) {
                weight[p.first] = pv.first + p.second;
                pq.push(make_pair(weight[p.first], p.first));
            }
        }
    }

    return weight[dest];
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
            v.emplace_back(b, w);
            graph.insert(make_pair(a, v));
        } else {
            d->second.emplace_back(b, w);
        }
    }
    printf("%d\n", dijkstra(graph, S, D));
    return 0;
}