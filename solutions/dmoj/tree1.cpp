#include <bits/stdc++.h>
using namespace std;

int edges = 0, start = -1;
bool adjList[4][4], visited[4];

bool dfs(int node, int previous) {
	visited[node] = true;

	for (int i = 0; i < 4; i++) {
		if (i == previous || i == node) continue;

		if (adjList[node][i]) {
			if (visited[i]) return false;
			if (!dfs(i, node)) return false;
		}
	}
	return true;
}

int main() {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			cin >> adjList[i][j];
			if (adjList[i][j]) start = i;
		}
	}

	if (start == -1) cout << "No" << endl;

	if (dfs(start, -1)) {
		cout << "Yes" << endl;
	} else {
		cout << "No" << endl;
	}

	return 0;
}
