#include <bits/stdc++.h>
using namespace std;

int N, B, arr[100001], qi, ans = 1;
set<pair<int, int>> used;
unordered_map<int, int> leftt, rightt;

int main() {
        cin.sync_with_stdio(0);
        cin.tie(0);
        cin >> N >> B;
        for (int i = 0; i < N; i++) {
                cin >> arr[i];
                if (arr[i] == B) {
                        qi = i;
                }
        }

        for (int l = qi-1, ll = 0; l >= 0; l--) {
                ll += arr[l] > B ? 1 : -1;
                leftt[ll]++;
        }
        for (int r = qi+1, rr = 0; r <= N-1; r++) {
                rr += arr[r] > B ? 1 : -1;
                rightt[rr]++;
        }

        for (pair<int, int> p : leftt) {
                //printf("h %d %d %d %d\n", p.first, p.second, -p.first, rightt[-p.first]);
                ans += rightt[-p.first] * p.second;
        }
        ans += rightt[0] + leftt[0];

        cout << ans << endl;
}
