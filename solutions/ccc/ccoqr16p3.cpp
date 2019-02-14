#include <bits/stdc++.h>
#define ll long long

using namespace std;
ll N, M, row, col, ans = 0;
map<ll, ll> m;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        cin >> row >> col;
        auto d = m.find(col);
        if (d == m.end()) {
            m.insert(make_pair(col, N - row + 1));
        } else {
            d->second = max(d->second, N - row + 1);
        }
    }

    ll prevMax = 0;
    for (pair<ll, ll> p : m) {
        //cout << p.first << " " << ans << " " << prevMax << " " << p.first << " " << p.second << endl;
        if (p.first <= prevMax) {
            ll rsize = prevMax - p.first + 1; // pyramid height at point
            if (p.second > rsize) {
                ans += ((p.second * (p.second + 1)) / 2) - ((rsize * (rsize + 1)) / 2);
                prevMax = max(prevMax, p.first + p.second-1);
            }
        } else {
            prevMax = p.first + p.second-1;
            ans += (p.second * (p.second + 1)) / 2;
        }
    }
    cout << ans << endl;
    return 0;
}
