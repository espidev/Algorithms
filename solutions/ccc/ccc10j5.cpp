#include <bits/stdc++.h>

using namespace std;

int x, y, dx, dy;

bool visited[9][9];
queue<pair<int, pair<int, int>>> q;

bool test(int cur, int xx, int yy) {
    if (xx < 9 && xx > 0) {
        if (yy < 9 && yy > 0) {
            if (!visited[xx][yy]) {
                if (xx == dx && yy == dy) return true;
                q.push(make_pair(cur+1, make_pair(xx, yy)));
            }
        }
    }
    return false;
}

int main() {
    cin >> x >> y >> dx >> dy;

    if (x == dx && y == dy) {
        cout << 0 << endl;
        return 0;
    }

    q.push(make_pair(0, make_pair(x, y)));

    while (!q.empty()) {
        pair<int, pair<int, int>> p = q.front();

        bool b = false;
        b = max(b, test(p.first, p.second.first+2, p.second.second+1));
        b = max(b, test(p.first, p.second.first+2, p.second.second-1));
        b = max(b, test(p.first, p.second.first+1, p.second.second+2));
        b = max(b, test(p.first, p.second.first+1, p.second.second-2));
        b = max(b, test(p.first, p.second.first-2, p.second.second+1));
        b = max(b, test(p.first, p.second.first-2, p.second.second-1));
        b = max(b, test(p.first, p.second.first-1, p.second.second+2));
        b = max(b, test(p.first, p.second.first-1, p.second.second-2));

        if (b) {
            cout << (p.first + 1) << endl;
            break;
        }

        q.pop();
    }

    return 0;
}
