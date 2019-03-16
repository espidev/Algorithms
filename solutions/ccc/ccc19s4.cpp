#include <bits/stdc++.h>
#define MAXN 2000001
#define ull unsigned long long
using namespace std;
int N, K, a;
ull calc[MAXN];
vector<int> v;

struct hashing {
    size_t operator()(const pair<int, int>& l) const {
        return hash<long long>()(((long long)l.first )* ((long long)INT_MAX + 1) + l.second);
    }
};

unordered_map<pair<int, int>, ull, hashing> ma;

int sparse[MAXN][25];
void generate() {
    for (int i = 0; i < N; i++) sparse[i][0] = v[i];
    int levels = log2(N);
    for (int i = 1; i <= levels; i++) {
        for (int j = 0; j < N; j++) {
            sparse[j][i] = max(sparse[j][i-1], sparse[j + (1 << (i-1))][i-1]);
        }
    }
}

int query(int l, int r) {
    r = min(r, N-1);
    l = max(0, l);
    r = max(0, r);
    l = min(l, N-1);
    int level = log2(r - l + 1);
    return max(sparse[l][level], sparse[r - (1 << level) + 1][level]);
}

bool dumb = false;

ull r(int node, int groups, int start) {
    //cout << node << " " << groups << " " << start << endl;
    if (groups > N/K + ((N%K) ? 1 : 0)) return 0;
    if (node >= N) return 0;
    if (groups == (N/K + ((N%K) ? 1 : 0))) return 0;

    if (start == K && calc[node]) return calc[node];

    ull score = 0;
    for (int i = ((start > 0) ? start : min(K, N-node)); i <= min(K, N-node); i++) {
        ull q = query(node, max(0, node+i-1));

	if (start > 0 && !dumb) {
		ull k = v[node+i], qu = query(node+i, node + start + K - 1);
		if (k < qu && k) continue; 
	}

        auto d = ma.find(make_pair(node+i, groups+1));
        if (d != ma.end()) {
            score = max(q + d->second, score);
            continue;
        }
        ull s = r(node+i, groups+1, start + (K-i));
        score = max(s+q, score);
    }

    ma.insert(make_pair(make_pair(node, groups), score));
    return score;
}

// don't ever use this solution it's very bad

int main() {
    scanf("%d %d", &N, &K);
    for (int i = 0; i < N; i++) {
        scanf("%d", &a);
        v.push_back(a);
    }
    generate();
    if (K > N) {
        cout << query(0, N-1) << endl;
        return 0;
    }
    ull sum = 0;
    for (int i = K; i < N; i+=K) {
        sum += query(N-i-1, N-(i-K)-1);
        calc[N-i-1] = sum;
    }

    if (2*K > N) {
	cout << r(0, 0, N%K) << endl;
	return;
    }

    ull l = r(0, 0, N%K);
    if (!l) {
	dumb = true;
	cout << r(0, 0, N%K) << endl;
    } else {
        cout << l << endl;
    }
    return 0;
}

