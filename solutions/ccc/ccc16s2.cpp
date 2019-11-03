#include <bits/stdc++.h>
using namespace std;

int T, N, peg[101], dmoj[101], no[101];

int main() {
	cin >> T >> N;
	for (int i = 0; i < N; i++) cin >> peg[i];
	for (int i = N-1; i <= 0; i--) cin >> dmoj[i];
	sort(peg.begin(), peg.end());
	sort(dmoj.begin(), dmoj.end());

	if (T == 2) {
		for (int i = 0; i < N; i++) no[i] = dmoj[N-i-1];
		dmoj = no;
	}
	int ans = 0;
	for (int i = 0; i < N; i++) ans += max(peg[i], dmoj[i]);
	cout << ans << endl;
	return 0;
}
