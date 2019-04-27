#include <bits/stdc++.h>

using namespace std;

// https://www.hackerearth.com/practice/basic-programming/recursion/recursion-and-backtracking/practice-problems/algorithm/divide-number-a410603f/description/

long long T, N;
unordered_map<int, vector<long long>> pre;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    for (int i = 2; i < sqrt(40001); i++) {
        for (int j = i; j <= 40001; j += i) {
            auto d = pre.find(j);
            if (d == pre.end()) {
                vector<long long> v;
                v.push_back(i);
                pre.insert(make_pair(j, v));
            } else {
                d->second.push_back(i);
            }
        }
    }

    for (int i = 2; i < 40001; i++) {
        auto d = pre.find(i);
        if (d == pre.end()) continue;
        int t = d->second.size();
        for (int j = 0; j < t; j++) {
            d->second.push_back(i / d->second[j]);
        }
    }

    cin >> T;

    for (int i = 0; i < T; i++) {
        cin >> N;


        auto d = pre.find(N);
        if (d == pre.end()) {
            cout << -1 << endl;
            continue;
        }
        long long m = -1;
        for (int j = 0; j < d->second.size(); j++) {
            for (int k = j; k < d->second.size(); k++) {
                for (int l = k; l < d->second.size(); l++) {
                    int n = N-d->second[j]-d->second[k]-d->second[l];
                    if (n < 1 || N%n != 0) continue;
                    m = max(d->second[j]*d->second[k]*d->second[l]*n, m);
                }
            }
        }
        cout << m << endl;
    }
    return 0;
}
