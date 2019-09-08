#include <bits/stdc++.h>
using namespace std;

// random simple bit manipulation

string get_binary(int num) {
	string s = "";
	while (num != 0) {
		s += to_string(num & 1);
		num >>= 1;
	}
	return s;
}
