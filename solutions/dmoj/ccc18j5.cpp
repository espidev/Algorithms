#include <bits/stdc++.h>

using namespace std;

/*
 * CCC 18 J5
 */

int N;

vector<vector<int>> v;

int main() {
    cin >> N;
    vector<bool> visited(N);
    vector<int> weight(N, 1000000000);
    for(int i = 0; i < N; i++) {
        int l;
        cin >> l;
        v.emplace_back(static_cast<unsigned long>(l));
        for(int j = 0; j < l; j++) {
            int t;
            cin >> t;
            v[i][j] = t-1;
        }
    }
    queue<int> q;
    q.push(0);
    visited[0] = true;
    weight[0] = 1;
    while(!q.empty()) {
        int t = q.front();
        q.pop();
        for(int i = 0; i < v[t].size(); i++) {
            if(!visited[v[t][i]]) {
                visited[v[t][i]] = true;
                q.push(v[t][i]);
                weight[v[t][i]] = min(weight[v[t][i]], weight[t]+1);
            }
        }
    }
    bool d = false;
    int shortest = 1000000000;
    for(int i = 0; i < N; i++) {
        if(!visited[i]) {
            d = true;
        }
        if(weight[i] < shortest && v[i].empty()) {
            shortest = weight[i];
        }
    }
    if(d) {
        cout << "N" << endl;
    } else {
        cout << "Y" << endl;
    }
    cout << shortest << endl;
    return 0;
}
