#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long
int N, arr[1000001];
// todo iterate up to sqrt(N);
ull rec(ull k) {
	if (arr[k]) return arr[k];
	if (k == 1) return 1;
	ull ans = 0;
	for (ull i = 2; k/i <= sqrt(k); i++) {
		ans += rec(k/i);
	}
	ans += (k-sqrt(k))*rec(k-1);
	arr[k] = ans;
	return ans;
}

int main() {
	cin >> N;
	cout << rec(N) << endl;
	return 0;
}
