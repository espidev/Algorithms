#include <bits/stdc++.h>
using namespace std;

int dfn[2001], low[2001], visited[2001], ind;
vector<int> graph[2001];

void tarjan(stack<int>& s, int node) {
	dfn[node] = low[node] = ++ind;
	s.push(node);
	visited[node] = true;

	for (int v : graph[n]) {
		if (!visited[v]) {
			dfs(s, v);
			low[node] = min(low[node], low[v]);
		} else if (s.find(v) != s.end()) {
			low[node] = min(low[min], dfn[node]);
		}
	}

	// return to root
	if (dfn[node] == low[node]) {
		cout << "SCC: " << endl;
		while (!s.empty() && s.top() != node) {
			cout >> s.top() << endl;
			s.pop();
		}
	}
}

int main() {

	return 0;
}
