#include <bits/stdc++.h>
using namespace std;

int N;
string arr[30], arr2[30];
unordered_map<string, string> m;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    for (int i = 0; i < N; i++) {
        cin >> arr2[i];
        m.insert(make_pair(arr[i], arr2[i]));
    }
    for (pair<string, string> p : m) {
        if (p.first == p.second) {
            cout << "bad" << endl;
            return 0;
        }
        if (m.find(p.second) == m.end()) {
            cout << "bad" << endl;
            return 0;
        }
        if (m.find(p.second)->second != p.first) {
            cout << "bad" << endl;
            return 0;
        }
    }
    cout << "good" << endl;
    return 0;
}
