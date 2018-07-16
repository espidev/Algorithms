#include <bits/stdc++.h>
using namespace std;

#define MAXN 1000000

int N, M, p, q;
vector<vector<int>> v (MAXN);

bool dfs1(int node) {
	if (node == q) return true;
	if (v[node].size() == 0) return false;
	for (int i = 0; i < v[node].size(); i++) {
		if (dfs1(v[node][i])) {
			return true;
		}
	}
}

bool dfs2(int node) {
        if (node == p) return true;
        if (v[node].size() == 0) return false;
        for (int i = 0; i < v[node].size(); i++) { 
                if (dfs2(v[node][i])) {
			return true;
		}
        }
}


int main() {
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int x, y;
		cin >> x >> y;
		v[x].push_back(y);
	}
	cin >> p >> q;
	if (dfs1(p)) {
		cout << "yes" << endl;
	} else if (dfs2(q)) {
		cout << "no" << endl;
	} else {
		cout << "unknown" << endl;
	}
	return 0;
}
