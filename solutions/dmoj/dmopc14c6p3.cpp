#include <bits/stdc++.h>

using namespace std;

int S;

int simulate(int b_size, vector<pair<int, int>>& v) {
    bool stay = true;
    int ret = 0;
    while (stay) {
        ret++;
        int people = 0;
        stay = false;
        for (int i = 0; i < S; i++) {
            people -= v[i].second*people/100;
            if (b_size < people+v[i].first) {
                v[i].first -= b_size-people;
                people = b_size;
            } else {
                people += v[i].first;
                v[i].first = 0;
            }
            if (v[i].first > 0) stay = true;
        }
    }
    return ret;
}

int main() {
    scanf("%d", &S);
    vector<pair<int, int>> v1, v2;
    for (int i = 0; i < S; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        v1.emplace_back(a, b);
        v2.emplace_back(a, b);
    }
    cout << abs(simulate(132, v1) - simulate(251, v2)) << endl;
    return 0;
}
