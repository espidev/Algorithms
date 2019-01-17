#include <bits/stdc++.h>
using namespace std;
int N, M, D, a, b;
int main() {
    for (int s = 0; s < 10; s++) {
        vector<vector<pair<int, double>>> v;
        vector<double> weights;
        bool cycle = false;
        cin >> N >> M >> D;
        for (int i = 0; i <= N; i++) {
            v.emplace_back();
            weights.push_back(-0x3F3F3F3F);
        }
        for (int i = 0; i < M; i++) {
            double w;
            cin >> a >> b >> w;
            v[a].push_back(make_pair(b, -log10(w)));
        }
        weights[1] = log10(D);
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                for (pair<int, double> p : v[j]) {
                    if (weights[j] != -0x3F3F3F3F && (weights[j] + p.second - weights[p.first] > 1e-7)) {
                        if (i == N && p.first == N) cycle = true;
                        weights[p.first] = weights[j] + p.second;
                    }
                }
            }
        }
        double ans = pow(10, weights[N]);
        if (cycle || ans > 1e9) {
            cout << "Billionaire!" << endl;
        } else {
            printf("%.2f\n", ans);
        }
    }
    return 0;
}
