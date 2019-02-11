#include <bits/stdc++.h>
using namespace std;
int N, T, in;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> T;
	for (int i = 0; i < T; i++) {
		stack<int> s, mountain;
		int counter = 1;
		cin >> N;
		for (int j = 0; j < N; j++) {
			cin >> in;	
			mountain.push(in);
		}
		while (!mountain.empty()) {
			if (mountain.top() == counter) {
				mountain.pop();
				counter++;
			} else if (!s.empty() && s.top() == counter) {
				s.pop();
				counter++;
			} else {
				s.push(mountain.top());
				mountain.pop();
			}
		}
		bool fail = false;
		while (!s.empty()) {
			if (s.top() != counter) {
				fail = true;
				break;
			}
			counter++;
			s.pop();
		}
		if (fail) {
			cout << "N" << endl;
		} else {
			cout << "Y" << endl;
		}
	}

	return 0;
}

