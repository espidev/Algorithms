#include <bits/stdc++.h>

#define ull unsigned long long
using namespace std;

// unfinished, can't pass batches with D != 0

ull N, M, D, dj[200001];
set<pair<ull, pair<int, int>>> cur, mst;
map<ull, vector<pair<int, int>>> all;
map<pair<int, int>, vector<ull>> m;

int dj_find(int a) {
    if (dj[a] != a) dj[a] = dj_find(dj[a]);
    return dj[a];
}

void dj_merge(int a, int b) {
    dj[dj_find(a)] = dj_find(b);
}

int main() {
    for (int i = 0; i < 200001; i++) dj[i] = i;
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M >> D;
    for (int i = 0, a, b, c; i < M; i++) {
        cin >> a >> b >> c;
        if (i < N - 1) {
            cur.insert(make_pair(c, make_pair(a, b)));
        }
        all[c].push_back(make_pair(a, b));
        m[make_pair(a, b)].push_back(c);
    }

    // mst
    vector<pair<ull, pair<int, int>>> last;
    for (pair<ull, vector<pair<int, int>>> p : all) {
        vector<pair<int, int>> v;
        bool lastUsed = false;
        for (pair<int, int> ab : p.second) {
            if (cur.find({p.first, ab}) != cur.end()) {
                if (dj_find(ab.second) != dj_find(ab.first)) {
                    dj_merge(ab.first, ab.second);
                    if (!lastUsed) {
                        lastUsed = true;
                        last.clear();
                    }
                    last.emplace_back(p.first, ab);
                    mst.insert(make_pair(p.first, ab));
                }
            } else {
                v.push_back(ab);
            }
        }
        for (pair<int, int> ab : v) {
            if (dj_find(ab.second) != dj_find(ab.first)) {
                dj_merge(ab.first, ab.second);
                if (!lastUsed) {
                    lastUsed = true;
                    last.clear();
                }
                last.emplace_back(p.first, ab);
                mst.insert(make_pair(p.first, ab));
            }
        }
    }

    // determine D
    for (auto las : last) {
        if (cur.find(las) == cur.end()) {
            bool d = false;
            for (ull l : m[las.second]) {
                if ((cur.find(make_pair(l, las.second)) != cur.end())) {
                    mst.erase(las);
                    mst.insert(make_pair(l, las.second));
                    d = true;
                    break;
                }
            }
            if (!d) {
                for (ull l : m[make_pair(las.second.second, las.second.first)]) {
                    if ((cur.find(make_pair(l, make_pair(las.second.second, las.second.first))) != cur.end())) {
                        mst.erase(las);
                        mst.insert(make_pair(l, las.second));
                        break;
                    }
                }
            }
        }
    }

    int deactivate = 0;
    for (pair<ull, pair<int, int>> p : cur) {
        auto d = mst.find(p);
        if (mst.find(p) == mst.end()) {
            deactivate++;
        } else {
            mst.erase(d);
        }
    }

    cout << max(deactivate, (int) mst.size()) << endl;

    return 0;
}

