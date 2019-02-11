#include <bits/stdc++.h>
using namespace std;

#define MAXN 1000000

int N, M, p, q;
vector<vector<int>> v (MAXN);

bool dfs(int node, int compare) {
	if (node == q) return true;
	if (v[node].size() == 0) return false;
	for (int i = 0; i < v[node].size(); i++) {
		if (dfs(v[node][i], compare)) return true;
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
	if (dfs(p, q)) {
		cout << "yes" << endl;
	} else if (dfs(q, p)) {
		cout << "no" << endl;
	} else {
		cout << "unknown" << endl;
	}
	return 0;
}
