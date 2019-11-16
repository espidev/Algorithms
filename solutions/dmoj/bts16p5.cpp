#include <bits/stdc++.h>
#define ll long long
using namespace std;

struct state {
	ll cherries, bweight, ans;
	state (ll cherries, ll bweight, ll ans) {
		this->cherries = cherries;
		this->bweight = bweight;
		this->ans = ans;
	}
};

int N, C, K, weight[10001];
vector<pair<int, int>> v[10001];

state dfs(int n, int prev) {
	ll c = weight[n], w = 0, ans = 0;
	for (pair<int, int> p : v[n]) {
		if (p.first == prev) continue;

		state s = dfs(p.first, n);
		if ((s.bweight+p.second <= K) && s.cherries >= C) ans++;
		ans += s.ans;
		c += s.cherries;
		w += s.bweight + p.second;
	}
	return state(c, w, ans);
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> C >> K;
	for (int i = 1; i <= N; i++) cin >> weight[i];
	for (int i = 0; i < N-1; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		v[a].push_back(make_pair(b, c));
		v[b].push_back(make_pair(a, c));
	}

	cout << dfs(1, -1).ans << endl;
	return 0;
}
