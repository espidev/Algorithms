#include <bits/stdc++.h>
using namespace std;

int H, K, a;
vector<int> v;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> H;
    for (int i = 0; i < H; i++) {
        cin >> a;
        v.push_back(a);
    }
    sort(v.begin(), v.end());
    cin >> K;
    int l = 0, h = 1e6, ans = 1e7;
    while (l <= h) {
        int mid = (l + h) / 2, used = 1, prev = v[0] + mid;
        for (int i = 1; i < v.size(); i++) {
            if (v[i] > prev) {
                used++;
                prev = v[i] + mid;
            }
        }
        if (used <= K) {
            ans = min(mid, ans);
            h = mid-1;
        } else {
            l = mid+1;
        }
        if (l == h) break;
    }
    cout << (ans/2) << endl;
    return 0;
}
