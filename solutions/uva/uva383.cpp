#include <bits/stdc++.h>
using namespace std;i
#define MAXN 62

int NS, M, N, P, weight[MAXN];
string s, a, b;
unordered_map<string, int> m;
vector<int> graph[MAXN];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> NS;
	cout << "SHIPPING ROUTES OUTPUT" << endl << endl;
	for (int i = 0; i < NS; i++) {
		cout << "DATA SET " << (i+1) << endl << endl;

		for (int j = 0; j < MAXN; j++) graph[j] = vector<int>();
		m.clear();

		cin >> M >> N >> P;
		for (int j = 0; j < M; j++) {
			cin >> s;
			m.insert(make_pair(s, j));
		}
		for (int j = 0; j < N; j++) {
			cin >> a >> b;
			graph[m[a]].push_back(m[b]);
			graph[m[b]].push_back(m[a]);			
		}

		for (int j = 0; j < P; j++) {
			int siz, u, v;
			cin >> siz >> a >> b;
		       	u = m[a];
			v = m[b];
			for (int i = 0; i < MAXN; i++) weight[i] = 1e9;

			queue<pair<int, int>> q; // dist, node
			q.push(make_pair(0, u));
			while (!q.empty()) {
				int dist = q.front().first, node = q.front().second;
				q.pop();
				if (weight[node] < dist) continue;
				weight[node] = dist;
				for (int l : graph[node]) {
					if (weight[l] > dist+1) {
						q.push(make_pair(dist+1, l));
					}
				}
			}

			if (weight[v] == 1e9) {
				cout << "NO SHIPMENT POSSIBLE" << endl;
			} else {
				cout << "$" << (siz*weight[v]*100) << endl;
			}
		}
		cout << endl;
	}
	cout << "END OF OUTPUT";
	return 0;
}

