#include <bits/stdc++.h>

using namespace std;
int N, a;

vector<vector<int>> rotate(vector<vector<int>> &v) {
    vector<vector<int>> r;
    for (int i = 0; i < N; i++) r.emplace_back(N);
    for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) r[i][j] = v[N-1-j][i];
    return r;
}

bool check(vector<vector<int>> v) {
    for (int i = 0; i < N; i++) {
        if (i && (v[i][0] < v[i-1][0])) return false;
        for (int j = 1; j < N; j++) if (v[i][j-1] > v[i][j]) return false;
    }
    return true;
}

int main() {
    cin >> N;
    vector<vector<int>> v(N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> a;
            v[i].push_back(a);
        }
    }
    while (!check(v)) v = rotate(v);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) cout << v[i][j] << " ";
        cout << endl;
    }
    return 0;
}
