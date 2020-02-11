#include <bits/stdc++.h>
using namespace std;

vector<int> adj[51];
pair<int, int> con[22] = {{2, 6}, {1, 6}, {6, 7}, {3, 6}, {4, 6}, {5, 6}, {3, 4}, {4, 5}, {3, 5}, {3, 15}, {15, 13}, {12, 13}, {13, 14}, {12, 9}, {12, 11}, {11, 10}, {10, 9}, {8, 9}, {7, 8}, {18, 16}, {18, 17}, {17, 16}};

int visited[51];

int deg(int y, int cur, int dist) {
        visited[cur] = true;
        if (cur == y) return dist;
        int ans = 1e9;
        for (int i : adj[cur]) {
                if (!visited[i]) {
                        ans = min(ans, deg(y, i, dist+1));
                        visited[i] = false;
                }
        }
        return ans;
}

int main() {
        for (int i = 0; i < 22; i++) {
                pair<int, int> p = con[i];
                adj[p.first].push_back(p.second);
                adj[p.second].push_back(p.first);
        }

        char q;
        cin >> q;
        int x, y;
        while (q != 'q') {
                if (q == 'i') {
                        cin >> x >> y;
                        if (find(adj[x].begin(), adj[x].end(), y) == adj[x].end()) {
                                adj[x].push_back(y);
                                adj[y].push_back(x);
                        }
                } else if (q == 'd') {
                        cin >> x >> y;
                        auto d = find(adj[x].begin(), adj[x].end(), y);
                        if (d != adj[x].end()) adj[x].erase(d);
                        d = find(adj[y].begin(), adj[y].end(), (x));
                        if (d != adj[y].end()) adj[y].erase(d);
                } else if (q == 'n') {
                        cin >> x;
                        cout << adj[x].size() << endl;
                } else if (q == 'f') {
                        cin >> x;
                        set<int> s, ss;
                        for (int i : adj[x]) ss.insert(i);
                        for (int i : adj[x]) {
                                for (int j : adj[i]) {
                                        if (j != x && (ss.find(j) == ss.end())) {
                                                s.insert(j);
                                        }
                                }
                        }
                        cout << s.size() << endl;
                } else if (q == 's') {
                                cin >> x >> y;
                                int nu = deg(y, x, 0);
                                visited[x] = false;
                                if (nu == 1e9) {
                                        cout << "Not connected" << endl;
                                } else {
                                        cout << nu << endl;
                                }
                }
                cin >> q;
        }
}
