#include <bits/stdc++.h>
using namespace std;
#define ll long long

int N, M, a, b, c, dj[200001];
vector<pair<int, pair<int, int>>> paths;

int dj_find(int x) {
        if (dj[x] != x) dj[x] = dj_find(dj[x]);
        return dj[x];
}

void dj_merge(int a, int b) {
        dj[dj_find(a)] = dj_find(b);
}



int main() {
        cin.sync_with_stdio(0);
        cin.tie(0);
        for (int i = 0; i < 200001; i++) dj[i] = i;

        cin >> N >> M;
        for (int i = 0; i < M; i++) {
                cin >> a >> b >> c;
                paths.push_back(make_pair(c, make_pair(a, b)));
        }

        sort(paths.begin(), paths.end());

        ll ans = 0;
        for (pair<int, pair<int, int>> p : paths) {
                if (dj_find(p.second.first) != dj_find(p.second.second)) {
                        ans += p.first;
                        dj_merge(p.second.first, p.second.second);
                }
        }

        int num = dj_find(1);
        for (int i = 2; i <= N; i++) {
                if (dj_find(i) != num) {
                        cout << "IMPOSSIBLE" << endl;
                        return 0;
                }
        }
        cout << ans << endl;
        return 0;
}

