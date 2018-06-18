#include <bits/stdc++.h>
using namespace std;

int main() {
	int N, a = 0, b = 0;
	string str;
	cin >> N >> str;
	for (char ch : str) {
		if (ch == 'A') {
			a++;
		} else {
			b++;
		}
	}
	if (a == b) {
		cout << "Tie" << endl;
	} else if (a > b) {
		cout << "A" << endl;
	} else {
		cout << "B" << endl;
	}
}
