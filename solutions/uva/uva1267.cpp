#include <bits/stdc++.h>

using namespace std;
#define MAXN 5000

/*
 * UVA 1267 (Network)
 * DFS
 */

vector<vector<int>> graph;
vector<vector<int>> leaf;
int N, T, K, source, result = 0, biggest = 0;
bool done[MAXN];
int parent[MAXN];

void dfs(int u, int p, int le) {
    parent[u] = p;

    int kid = graph[u].size();
    if (kid == 1 && le > K) {
        leaf[le].push_back(u);
        if (biggest < le) biggest = le;
    }
    for (int v : graph[u]) {
        if (v != p) dfs(v, u, le + 1);
    }
}

void dfs2(int u, int le) {
    if (le > K) return;
    int kid = graph[u].size();
    if (kid == 1) {
        done[u] = true;
    } else {
        for (int v : graph[u]) {
            if (!done[v]) dfs2(v, le + 1);
        }
    }
}

int main() {
    cin >> T;
    while (T-- != 0) {
        result = biggest = 0;
        cin >> N >> source >> K;
        graph = vector<vector<int>>(N + 1);
        leaf = vector<vector<int>>(N + 1);
        fill(graph.begin(), graph.begin() + N, vector<int>());
        fill(leaf.begin(), leaf.begin() + N, vector<int>());
        memset(parent, 0, sizeof(parent));
        memset(done, 0, sizeof(done));

        for (int s = 0; s < N - 1; s++) {
            int n1, n2;
            cin >> n1 >> n2;
            graph[n1].push_back(n2);
            graph[n2].push_back(n1);
        }
        dfs(source, -1, 0);

        for (int u = biggest; u > K; u--) {
            if (leaf[u].size() == 0) continue;
            for (int y : leaf[u]) {
                if (!done[y]) {
                    int pa;
                    for (int e = 0; e < K; e++) {
                        pa = parent[y];
                        y = pa;
                    }
                    result++;
                    dfs2(y, 0);
                }
            }
        }
        cout << result << endl;
    }
    return 0;
}