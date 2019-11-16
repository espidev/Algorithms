#include <bits/stdc++.h>
using namespace std;

int N;
vector<int> v[8];

pair<bool, bool> dfs(int n, set<int>& vv) { // <rightans, allmarked>
	if (v[n].size() == 0) {
		return make_pair(true, vv.find(n) != vv.end());
	}
	bool mustmark = vv.find(n) != vv.end(), allmarked = mustmark;

	for (int l : v[n]) {
		pair<bool, bool> p = dfs(l, vv);
		if (!p.second) allmarked = false;
		if (!p.first || (mustmark && !p.second)) return make_pair(false, false);
	}
	return make_pair(true, allmarked);
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	for (int i = 1; i < N; i++) {
		int l;
		cin >> l;
		v[l].push_back(i);
	}

	int ans = 1;
	for (int i = 1; i < pow(2, N); i++) {
		set<int> vv;
		for (int j = 0; j < pow(2, N); j++) {
			if (i & (1 << j)) {
				vv.insert(j+1);
			}
		}
		if (vv.find(N) == vv.end() && dfs(N, vv).first) {
			ans++;
		}
	}

	cout << ans << endl;
	return 0;
}
