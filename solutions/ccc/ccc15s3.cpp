#include <bits/stdc++.h>

using namespace std;
int G, P, p;
set<int, greater<int>> g;

int main() {
    cin >> G >> P;
    for (int i = 1; i <= G; i++) g.insert(i);
    for (int i = 0; i < P; i++) {
        cin >> p;
        if (g.lower_bound(p) == g.end()) {
            cout << i << endl;
            return 0;
        }
        g.erase(g.lower_bound(p));
    }
    cout << P << endl;
    return 0;
}

