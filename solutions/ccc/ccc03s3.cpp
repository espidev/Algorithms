#include <bits/stdc++.h>
using namespace std;

int F, R, C; // flooring, rows, columns
string grid[64];
map<pair<int, int>, pair<int, int>> djs;
map<pair<int, int>, int> m;

pair<int, int> findSet(pair<int, int> p) {
    auto d = djs.find(p);
    if (p != d->second) d->second = findSet(d->second);
    return d->second;
}

void mergeSet(pair<int, int> p1, pair<int, int> p2) {
    pair<int, int> px = findSet(p1), py = findSet(p2);
    if (px == py) return;
    djs.find(py)->second = px;
}

int main() {
    scanf("%d %d %d", &F, &R, &C);
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            djs.insert(make_pair(make_pair(i, j), make_pair(i, j)));
        }
    }
    for (int i = 0; i < R; i++) {
        cin >> grid[i];
        for (int j = 0; j < C; j++) {
            if (grid[i][j] == '.') {
                if (i != 0 && grid[i-1][j] == '.') {
                    mergeSet(make_pair(i-1, j), make_pair(i, j));
                }
                if (j != 0 && grid[i][j-1] == '.') {
                    mergeSet(make_pair(i, j-1), make_pair(i, j));
                }
            } else {
                djs.find(make_pair(i, j))->second = make_pair(-1, -1);
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (grid[i][j] != 'I') {
                auto fs = findSet(make_pair(i, j));
                auto d = m.find(fs);
                if (d == m.end()) {
                    ans++;
                    m.insert(make_pair(fs, 1));
                } else {
                    d->second++;
                }
            }
        }
    }
    vector<int> v;
    for (auto const& d : m) {
        v.push_back(d.second);
    }
    sort(v.begin(), v.end(), greater<int>());
    int c = 0;
    for (int i : v) {
        if (F - i < 0) {
            break;
        }
        F -= i;
        c++;
    }
    if (c != 1) printf("%d rooms, %d square metre(s) left over", c, F);
    else printf("%d room, %d square metre(s) left over", c, F);
    return 0;
}
