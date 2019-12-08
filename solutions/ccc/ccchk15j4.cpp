#include <bits/stdc++.h>
using namespace std;

int L, N;

int main() {
        cin.sync_with_stdio(0);
        cin.tie(0);
        cin >> L >> N;

        map<int, vector<bool>> m;

        for (int i = 0; i < N; i++) {
                int a, b;
                cin >> a >> b;
                m[a].push_back(true);
                m[b].push_back(false);
        }
        int num = 0, ans = 0, since = 0;
        for (pair<int, vector<bool>> p : m) {
                if (num == 0) ans = max(ans, p.first - since);
                for (bool b : p.second) num += b ? 1 : -1;
                if (num != 0) since = -1;
                if (num == 0 && since == -1) since = p.first;
        }
        if (num == 0) ans = max(ans, L-since);
        cout << ans << endl;
        return 0;
}
