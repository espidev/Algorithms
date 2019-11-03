#include <bits/stdc++.h>
#define MAXN 100001
using namespace std;

int N, M, a, b, pho_start, trim_nodes;
vector<int> ograph[MAXN], graph[MAXN];
bool pho[MAXN];

bool trim_graph(int node, int prev, int from, int dist) {
        bool found = false;
        if (pho[node]) {
                from = node;
                dist = 0;
                found = true;
        }
        for (int n : ograph[node]) {
                if (n != prev) {
                        if (trim_graph(n, node, from, dist+1)) {
                                graph[node].push_back(n);
                                graph[n].push_back(node);
                                found = true;
                        }
                }
        }
        if (found) trim_nodes++;
        return found;
}

pair<int, int> dfs1(int node, int prev, int dist) { // furthest, dist
        bool f = false;
        pair<int, int> best = make_pair(-1, -1);
        for (int n : graph[node]) {
                if (n != prev) {
                        f = true;
                        pair<int, int> p = dfs1(n, node, dist + 1);
                        if (p.second >= best.second) best = p;
                }
        }
        if (!f) return make_pair(node, dist);
        return best;
}

int main() {
        cin.sync_with_stdio(0);
        cin.tie(0);
        cin >> N >> M;

        for (int i = 0; i < 100001; i++) {
                ograph[i] = vector<int>();
                graph[i] = vector<int>();
        }

        for (int i = 0; i < M; i++) {
                cin >> pho_start;
                pho[pho_start] = true;
        }

        for (int i = 0; i < N-1; i++) {
                cin >> a >> b;
                ograph[a].push_back(b);
                ograph[b].push_back(a);
        }

        trim_graph(pho_start, -1, -1, 0); 
        pair<int, int> p = dfs1(dfs1(pho_start, -1, 0).first, -1, 0);
        cout << (2*(trim_nodes-1)-p.second) << endl;
        return 0;
}

