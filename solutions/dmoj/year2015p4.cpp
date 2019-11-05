#include <bits/stdc++.h>
using namespace std;

int va, vb, m, minans = 1e9;
string ans = "";
set<pair<int, int>> oof;

struct node {
	int a, b, dist, prev;
	string trail;
	node (int a, int b, int dist, int prev, string trail) {
		this->a = a;
		this->b = b;
		this->dist = dist;
		this->prev = prev;
		this->trail = trail;
	}
};

void bfs() {

	queue<node> q;
	q.push(node(0, 0, 0, 0, ""));

	while (!q.empty()) {
		int a = q.front().a, b = q.front().b, dist = q.front().dist, prev = q.front().prev;
		string s = q.front().trail;
		q.pop();

		if (oof.find(make_pair(a, b)) != oof.end()) continue;
		if (dist != 0 && a == 0 && b == 0) continue;
		if (a == m || b == m) {
			if (dist < minans) {
				minans = dist;
				ans = s;
			}
			continue;
		}

		oof.insert(make_pair(a, b));

		if (a != va && prev != 1) {
			q.push(node(va, b, dist+1, 1, s+"fill A\n"));
		}

		if (b != vb && prev != 2) {
			q.push(node(a, vb, dist+1, 2, s+"fill B\n"));
		}

		if (prev != 3) {
			int na = a+b, nb = 0;
			if (na > va) {
				nb = na-va;
				na = va;
			}
			q.push(node(na, nb, dist+1, 3, s+"pour B A\n"));
		}

		if (prev != 4) {
			int na = 0, nb = a+b;
			if (nb > vb) {
				na = nb-vb;
				nb = vb;
			}
			q.push(node(na, nb, dist+1, 4, s+"pour A B\n"));
		}

		if (a != 0 && prev != 5) {
			q.push(node(0, b, dist+1, 5, s+"chug A\n"));
		}

		if (b != 0 && prev != 6) {
			q.push(node(a, 0, dist+1, 6, s+"chug B\n"));
		}
	}
}

int main() {
	cin >> va >> vb >> m;
	bfs();
	if (ans == "") {
		cout << "Not possible" << endl;
	} else {
		cout << ans;
	}
	return 0;
}
