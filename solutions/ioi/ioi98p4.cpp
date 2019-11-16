#include <bits/stdc++.h>
using namespace std;
#define OFFSET 10004

struct event {
        int x, low, hi;
        bool state; // true: start, false: end

        event (int x, int low, int hi, bool state) {
                this->x = x;
                this->low = low;
                this->hi = hi;
                this->state = state;
        }
};

bool comp(event a, event b) {
        return a.x < b.x || (a.x == b.x && a.state && !b.state);
}

int N, arr[20010], ans = 0;
vector<event> px, py;

void solve(vector<event>& l) {
        sort(l.begin(), l.end(), comp);
        for (event e : l) {
                for (int i = e.low; i < e.hi; i++) {
                        if (e.state) {
                                if (!arr[i]) ans++;
                                arr[i]++;
                        } else {
                                arr[i]--;
                                if (!arr[i]) ans++;
                        }
                }
        }
}

int main() {
        cin.sync_with_stdio(0);
        cin.tie(0);
        cin >> N;
        for (int i = 0; i < N; i++) {
                int a, b, c, d;
                cin >> a >> b >> c >> d;
                a += OFFSET;
                b += OFFSET;
                c += OFFSET;
                d += OFFSET;
                px.push_back(event(a, b, d, true));
                px.push_back(event(c, b, d, false));
                py.push_back(event(b, a, c, true));
                py.push_back(event(d, a, c, false));
        }
        solve(px);
        //for (int i = 0; i < 20010; i++) arr[i] = 0;
        solve(py);
        cout << ans << endl;
        return 0;
}
