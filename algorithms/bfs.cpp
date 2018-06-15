
void bfs(int startingNode, vector<vector<int>>& graph) {
	queue<int> q;
	q.push(startingNode);
	int[MAXN] visited;
	while (!q.empty()) {

		// do something to node (q.top())

		for(int i : graph[q.top()]) {
			if(!visited[i]) q.push(i);
		}
		q.pop();
	}
}
