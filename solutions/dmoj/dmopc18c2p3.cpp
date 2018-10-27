#include <bits/stdc++.h>
using namespace std;

int N, M, K, A, B;
vector<int> v[100001];
bool sell[100001], visited[100001];
int s[100001], s2[100001];

int main() {
    cin >> N >> M >> K >> A >> B;
    int comp[K];
    for (int i = 0; i < K; i++) {
        v[i] = vector<int>();
        int d;
        scanf("%d", &d);
        sell[d] = true;
        s[d] = 1e9;
        s2[d] = 1e9;
        comp[i] = d;
    }
    for (int i = 0; i < M; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        v[a].push_back(b);
        v[b].push_back(a);
    }

    queue<pair<int, int>> q;
    q.push(make_pair(A, 0));
    while (!q.empty()) {
        int f = q.front().first;
        //cout << f << " d " << q.front().second << endl;
        if (sell[f]) {
            s[f] = min(s[f], q.front().second);
        //    printf("%d PP\n", s[f]);
        }
            visited[f] = true;
            for (int i = 0; i < v[f].size(); i++) {
                if (!visited[v[f][i]]) {
                    q.push(make_pair(v[f][i], q.front().second+1));
                }
            }
        
        q.pop();
    }

    q.push(make_pair(B, 0));
    memset(visited, 0, N+1);
    while (!q.empty()) {
        int f = q.front().first;
      //  cout << f << " l " << q.front().second << endl;
        if (sell[f]) {
        //    cout << s2[f] << " PP" << endl;
            s2[f] = min(s2[f], q.front().second);
        } 
            visited[f] = true;
            for (int i = 0; i < v[f].size(); i++) {
                if (!visited[v[f][i]]) {
                    q.push(make_pair(v[f][i], q.front().second+1));
                }
            }
        
        q.pop();
    }
    int m = 1e9;
    for (int i = 0; i < K; i++) {
        m = min(m, s[comp[i]] + s2[comp[i]]);
    }
    printf("%d", m);
    return 0;
}