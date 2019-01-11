#include <bits/stdc++.h>
using namespace std;

int get_val(char ch) {
    if (ch == 'I') return 1;
    if (ch == 'V') return 5;
    if (ch == 'X') return 10;
    if (ch == 'L') return 50;
    if (ch == 'C') return 100;
    if (ch == 'D') return 500;
    if (ch == 'M') return 1000;
}

int main() {
    string s;
    cin >> s;
    int prev = 0, prevchar = 1001, cur = 0;
    for (int i = 0; i < s.length(); i+=2) {
        if (get_val(s[i+1]) > prevchar) cur -= prev*2;
        cur += get_val(s[i+1]) * (s[i] - '0');
        prevchar = get_val(s[i+1]);
        prev = get_val(s[i+1]) * (s[i] - '0');
    }
    cout << cur << endl;
    return 0;
}

