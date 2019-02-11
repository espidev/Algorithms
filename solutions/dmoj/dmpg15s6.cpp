#include <bits/stdc++.h>
using namespace std;
int N, M;
double in;

unordered_map<string, double> um;
map<string, vector<pair<string, double>>> m;
vector<pair<pair<string, string>, double>> v;
int main() {
        string s, s2;
        cin.tie(0);
        cin.sync_with_stdio(0);
        cin >> N >> M;
        for (int i = 0; i < N; i++) {
                cin >> s;
                um.insert(make_pair(s, 0));
                m.insert(make_pair(s, vector<pair<string, double>>()));
        }
        for (int i = 0; i < M; i++) {
                cin >> s >> s2 >> in;
                v.push_back(make_pair(make_pair(s, s2), in));
        }
        um["APPLES"] = 1.0;
        double sl;
        for (int i = 0; i <= N; i++) {
                for (pair<pair<string, string>, double> p : v) {
                        um[p.first.second] = max(um[p.first.second], um[p.first.first] * p.second);
                }
                if (i == N-1) sl = um["APPLES"];
        }
        cout << ((um["APPLES"]-sl > 0.01) ? "YA" : "NAW") << endl;
        return 0;
}
