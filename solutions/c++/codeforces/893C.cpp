#include <bits/stdc++.h>

using namespace std;
int N, M;

/*
 * Codeforces 893C
 */

int gold[100000];
unordered_map<int, vector<int>> path;
vector<bool> v(100000);

int dfs(int c) {
    v[c] = true;
    int mi = gold[c];
    auto d = path.find(c);
    if(d == path.end()) return mi;
    for(int i = 0; i < d->second.size(); i++) {
        if(!v[d->second[i]]) {
            mi = min(mi, dfs(d->second[i]));
        }
    }
    return mi;
}

int main() {
    cin >> N >> M;
    for(int i = 0; i < N; i++) {
        cin >> gold[i];
    }
    for(int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        auto c = path.find(a), d = path.find(b);
        if(c == path.end()) {
            vector<int> l;
            l.push_back(b);
            path.insert(make_pair(a, l));
        }
        else {
            c->second.push_back(b);
        }
        if(d == path.end()) {
            vector<int> l;
            l.push_back(a);
            path.insert(make_pair(b, l));
        }
        else {
            d->second.push_back(a);
        }
    }
    bool see;
    int ret = 0;
    do {
        see = false;
        int found;
        for(int i = 0; i < N; i++) {
            if(!v[i]) {
                see = true;
                found = i;
                break;
            }
        }
        if(see) {
            int num = dfs(found);
            ret += num;
        }
    } while(see);
    cout << ret << endl;
    return 0;
}
