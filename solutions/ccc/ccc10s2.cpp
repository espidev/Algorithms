#include <bits/stdc++.h>
using namespace std;

int K;
unordered_map<string, string> m;

int main() {
	cin >> K;
	for (int i = 0; i < K; i++) {
		string s, s2;
		cin >> s >> s2;
		m.insert(make_pair(s2, s));
	}
	string s, cur = "", output = "";
	cin >> s;
	for (int i = 0; i < s.length(); i++) {
		cur += s[i];
		auto d = m.find(cur);
		if (d != m.end()) {
			output += d->second;
			cur = "";
		}
	}
	cout << output << endl;
	return 0;
}
