#include <bits/stdc++.h>
using namespace std;

#define MAXN 999999

int N, M, S, D, a, b, w; //# of nodes, # of edges, start, end
vector<pair<int, pair<int, int>>> edges;
int dist[MAXN];

int main() {
    scanf("%d %d %d %d", N, M, S, D);
    memset(dist, 1e9, sizeof dist);
    for (int i = 0; i < N; i++) {
        scanf("%d %d %d", a, b, w);
        edges.push_back(make_pair(a, make_pair(b, w)));
    }
    dist[S] = 0;
    bool flag;
    for (int t = 0; t < N; t++) {
        flag = 0;
        for (pair<int, pair<int, int>> p: edges) {
            if (dist[p.second.first] > dist[p.first] + p.second.second) {
                dist[p.second.first] = dist[p.first] + p.second.second;
                flag = true;
            }
        }
        if (!flag) break;
    }
    if (!flag) {
        for (pair<int, pair<int, int>> p: edges) {
            if (dist[p.second.first] > dist[p.first] + p.second.second) {
                dist[p.second.first] = dist[p.first] + p.second.second;
                puts("Negative cycle detected");
                break;
            }
        }
    }
    for (int a : dist) printf("%d", a);
}