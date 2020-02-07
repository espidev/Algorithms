#include <bits/stdc++.h>
using namespace std;

int N, arr[1000001], lengths[2001];
unordered_map<int, int> m;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
        lengths[arr[i]]++;
    }

    for (int i = 1; i < 2001; i++) {
        if (lengths[i] > 1) {
            if (m.find(i+i) == m.end()) m.insert(make_pair(i+i, 0));
            m[i+i] += lengths[i]/2;
        }
        for (int j = i+1; j < 2001; j++) {
            if (lengths[i] && lengths[j]) {
                if (m.find(i+j) == m.end()) m.insert(make_pair(i+j, 0));
                m[i+j] += min(lengths[i], lengths[j]);
            }
        }
    }

    int len = 0, diff = 0;
    for (pair<int, int> p : m) {
        if (p.second > len) {
            len = p.second;
            diff = 1;
        } else if (p.second == len) {
            diff++;
        }
    }
