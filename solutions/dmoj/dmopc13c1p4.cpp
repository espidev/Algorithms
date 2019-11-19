#include <bits/stdc++.h>
using namespace std;

int N, L, W, weight[51][51];
int sx, sy, dx, dy;
vector<string> v;

bool check(int x, int y, int dist) {
        return weight[x][y] > dist+1 && x >= 0 && x < W && y >= 0 && y < L && (v[x][y] == 'O' || v[x][y] == 'W');
}

int main() {
        cin.sync_with_stdio(0);
        cin.tie(0);
        cin >> N;
        for (int i = 0; i < N; i++) {
                cin >> L >> W;
                v.clear();
                for (int i = 0; i < 51; i++) for (int j = 0; j < 51; j++) weight[i][j] = 1e9;
                for (int j = 0; j < W; j++) {
                        string s;
                        cin >> s;
                        v.push_back(s);
                        for (int k = 0; k < L; k++) {
                                if (s[k] == 'C') {
                                        sx = j;
                                        sy = k;
                                } else if (s[k] == 'W') {
                                        dx = j;
                                        dy = k;
                                }
                        }
                }

                int ans = 1e9;
                queue<pair<int, int>> q;
                q.push(make_pair(sx, sy));
                weight[sx][sy] = 0;

                while (!q.empty()) {
                        int x = q.front().first, y = q.front().second, dist = weight[x][y];
                        q.pop();
                        if (dist == 60) continue;

                        if (x == dx && y == dy) {
                                ans = min(ans, dist);
                        } else {
                                if (check(x+1, y, dist)) {
                                        weight[x+1][y] = dist+1;
                                        q.push(make_pair(x+1, y));
                                }
                                if (check(x-1, y, dist)) {
                                        weight[x-1][y] = dist+1;
                                        q.push(make_pair(x-1, y));
                                }
                                if (check(x, y+1, dist)) {
                                        weight[x][y+1] = dist+1;
                                        q.push(make_pair(x, y+1));
                                }
                                if (check(x, y-1, dist)) {
                                        weight[x][y-1] = dist+1;
                                        q.push(make_pair(x, y-1));
                                }
                        }
                }

                if (ans == 1e9 || ans >= 60) {
                        cout << "#notworth" << endl;
                } else {
                        cout << ans << endl;
                }
        }
        return 0;
}

