#include <bits/stdc++.h>
using namespace std;
double w, h;
int main() {
	cin >> w >> h;
	double bmi = (w/(h*h));
	if (bmi > 25) {
		cout << "Overweight" << endl;
	} else if (bmi >= 18.5) {
		cout << "Normal weight" << endl;
	} else {
		cout << "Underweight" << endl;
	}
	return 0;
}
