#include <bits/stdc++.h>
using namespace std;

int N, M, dj[1001], djs[1001];
double shortest[1001][1001];
vector<pair<int, int>> v, roads;
unordered_map<int, vector<int>> m;

double dist(pair<int, int> p1, pair<int, int> p2) {
    return sqrt(pow(p1.first-p2.first, 2) + pow(p1.second-p2.second, 2));
}

int djs_root(int l) {
    if (djs[l] == l) return l;
    else return djs[l] = djs_root(djs[l]);
}

void djs_merge(int a, int b) {
    djs[djs_root(a)] = djs_root(b);
}

int dj_root(int l) {
    if (dj[l] == l) return l;
    else return dj[l] = dj_root(dj[l]);
}

void dj_merge(int a, int b) {
    dj[dj_root(a)] = dj_root(b);
}

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) shortest[i][j] = 1e9;
        int x, y;
        cin >> x >> y;
        dj[i] = i;
        djs[i] = i;
        v.emplace_back(x, y);
    }

    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        roads.emplace_back(u-1, v-1);
        dj_merge(u-1, v-1);
    }


    for (int i = 0; i < N; i++) {
        auto d = m.find(dj_root(i));
        if (d == m.end()) {
            vector<int> l;
            l.push_back(i);
            m.insert(make_pair(dj_root(i), l));
        } else {
            d->second.push_back(i);
        }
    }

    vector<pair<double, pair<int, int>>> vl;

    for (int i = 0; i < N; i++) {
        for (int j = i+1; j < N; j++) {
            if (dj_root(i) != dj_root(j)) {
                shortest[dj_root(i)][dj_root(j)] = shortest[dj_root(j)][dj_root(i)] = min(dist(v[i], v[j]), min(shortest[dj_root(i)][dj_root(j)], shortest[dj_root(j)][dj_root(i)]));
                vl.emplace_back(shortest[dj_root(i)][dj_root(j)], make_pair(dj_root(i), dj_root(j)));
            }
        }
    }

    sort(vl.begin(), vl.end());

    double total = 0;
    for (int i = 0; i < vl.size(); i++) {
        //cout << vl[i].first << endl;
        int a = vl[i].second.first, b = vl[i].second.second;
        if (djs_root(a) != djs_root(b)) {
            total += vl[i].first;
            djs_merge(a, b);
        }
    }

    printf("%.2f\n", total);
    return 0;
}
