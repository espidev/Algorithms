#include <bits/stdc++.h>
using namespace std;

int N, m, a, b;
set<pair<int, int>> markedPos = {{1, 0}, {2, 0}, {3, 0}, {2, 1}};
set<pair<int, int>> specialPos = {{1, 1}, {2, 2}, {3, 1}};

bool recurse(int cm, int x, int y) {
        if (cm == 1) {
                return markedPos.find({x, y}) != markedPos.end();
        }
        if (recurse(cm-1, x/5, y/5)) {
                return true;
        } else if (specialPos.find({x/5, y/5}) != specialPos.end()) {
                return markedPos.find({x%5, y%5}) != markedPos.end();
        } else {
                return false;
        }
}

int main() {
        cin.sync_with_stdio(0);
        cin.tie(0);
        cin >> N;
        for (int i = 0; i < N; i++) {
                cin >> m >> a >> b;
                if (recurse(m, a, b)) {
                        cout << "crystal" << endl;
                } else {
                        cout << "empty" << endl;
                }
        }
        return 0;
}
