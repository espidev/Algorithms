#include <bits/stdc++.h>
using namespace std;

#define MAXN 969691 // max N

/*
 * Sparse Table (min value queries) RMQSQ - Range Minimum Query
 */

int N, Q;
int arr[MAXN][30]; // sparse table (N, log2(N))
int in[MAXN];

void generate() {
	for (int i = 0; i < N; i++) {
		arr[i][0] = in[i]; // function here
	}
	int levels = floor(log2(N));
	for (int i = 1; i <= levels; i++) {
		for (int j = 0; j < N; j++) {
			arr[j][i] = min(arr[j][i-1], arr[j + (1 << (i - 1))][i-1]); // function 
here
		}
	}
}

int query(int l, int r) {
	int level = floor(log2(r-l+1));
	return min(arr[l][level], arr[r - (1 << level) + 1][level]);
}

int main() {
	cin >> N;
	for (int i = 0 ; i < N; i++) {
		cin >> in[i];
	}
	generate();
	cin >> Q;
	for (int i = 0; i < Q; i++) {
		int a, b;
		cin >> a >> b;
		cout << query(a, b) << endl;
	}
	return 0;
}
