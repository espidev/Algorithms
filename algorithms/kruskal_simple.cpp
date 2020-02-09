#include <bits/stdc++.h>
#define MAXN 1000001
using namespace std;

// simple kruskal + disjoint set
// no ranking optimization

int dj[MAXN];

int dj_find(int n) {
	if (dj[n] != n) dj[n] = dj_find(dj[n]);
	return dj[n];
}

void dj_merge(int a, int b) {
	dj[dj_find(b)] = dj_find(a);
}

vector<pair<int, int>> kruskal(vector<pair<int, pair<int, int>>>& edges) { // <dist, <p1, p2>>
	sort(edges.begin(), edges.end()); // sort edges first (ascending)

	vector<pair<int, int>> mst;

	// loop through edges (already sorted ascending)
	for (auto edge : edges) {
		int dist = edge.first, p1 = edge.second.first, p2 = edge.second.second;

		if (dj_find(p1) != dj_find(p2)) { // if the two groups have not been merged yet, add to mst and merge
			dj_merge(p1, p2);
			mst.push_back(make_pair(p1, p2));
		}
	}
	return mst;
}

