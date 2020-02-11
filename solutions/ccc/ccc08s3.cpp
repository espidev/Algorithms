#include <bits/stdc++.h>
using namespace std;

int T, R, C, w[21][21];
char grid[21][21];

bool check(int x, int y, int dist) {
    return w[x][y] > dist+1 && x >= 0 && x < R && y >= 0 && y < C && grid[x][y] != '*';
}

int dij() {
    for (int i = 0; i < 21; i++) for (int j = 0; j < 21; j++) w[i][j] = 1e9;

    queue<pair<int, pair<int, int>>> q;
    q.push({0, {0, 0}});
    w[0][0] = 0;
    while (!q.empty()) {
        int x = q.front().second.first, y = q.front().second.second, dist = q.front().first;
        q.pop();
        if (grid[x][y] == '+' || grid[x][y] == '-') {
            if (check(x, y+1, dist)) {
                w[x][y+1] = dist+1;
                q.push({dist+1, {x, y+1}});
            }
            if (check(x, y-1, dist)) {
                w[x][y-1] = dist+1;
                q.push({dist+1, {x, y-1}});
            }
        }
        if (grid[x][y] == '+' || grid[x][y] == '|') {
            if (check(x+1, y, dist)) {
                w[x+1][y] = dist+1;
                q.push({dist+1, {x+1, y}});
            }
            if (check(x-1, y, dist)) {
                w[x-1][y] = dist+1;
                q.push({dist+1, {x-1, y}});
            }
        }
    }
    return w[R-1][C-1];
}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> T;

    for (int i = 0; i < T; i++) {
        cin >> R >> C;
        for (int j = 0; j < R; j++) {
            string s;
            cin >> s;
            for (int k = 0; k < s.size(); k++) {
                grid[j][k] = s[k];
            }
        }
        int v = dij();
        cout << (v == 1e9 ? -1 : v+1) << endl;
    }

    return 0;
}
