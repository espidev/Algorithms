#include <bits/stdc++.h>
using namespace std;

int main() {
	int N, a = 100, b = 100, ai, bi;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> ai >> bi;
		if (ai > bi) {
			b -= ai;
		} else if (ai < bi) {
			a -= bi;
		}
	}
	cout << a << endl << b << endl;
}
