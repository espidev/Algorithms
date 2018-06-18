#include <bits/stdc++.h>
using namespace std;

int main() {
	int limit, speed;
	cin >> limit >> speed;
	if (speed <= limit) {
		cout << "Congratulations, you are within the speed limit!" << endl;
	} else if (speed > limit && speed < limit + 21) {
		cout << "You are speeding and your fine is $100." << endl;
	} else if (speed > limit && speed < limit + 31) {
		cout << "You are speeding and your fine is $270." << endl;
	} else {
		cout << "You are speeding and your fine is $500." << endl;
	}
	return 0;
}
